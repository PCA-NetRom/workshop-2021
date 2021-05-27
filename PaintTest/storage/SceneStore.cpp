#include "SceneStore.h"

#include <QFile>
#include <QFileInfo>
#include <QJsonArray>
#include <QGraphicsItem>
#include <QJsonObject>
#include <QJsonDocument>

static const QString kStartPosX = "startPosX";

bool SceneStore::saveScene(PaintView* view, const QString& path)
{
    QString fileExtension = QFileInfo(QFile(path)).suffix();
    if (fileExtension == "jpg" || fileExtension == "png")
    {
        SceneStore::saveToImage(view, path);
    }
    else if (fileExtension == "json")
    {
        return SceneStore::saveToJson(view, path);
    }

    return true;
}



bool SceneStore::loadSceneFromJson(PaintView* view, const QString& path)
{
    QFile file(path);

    if (file.open(QIODevice::ReadOnly))
    {
        view->scene()->clear();

        QJsonArray jsonArray = QJsonDocument().fromJson(file.readAll()).array();

        for (const QJsonValue& jsonVal : jsonArray)
        {
            int type = jsonVal["type"].toInt();

            switch (type)
            {
            case QGraphicsLineItem::Type:
            {
                QGraphicsLineItem* lineItem = SceneStore::jsonToLine(jsonVal);
                view->scene()->addItem(lineItem);

                break;
            }
            default:
                // log unkown item
                break;
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}

void SceneStore::saveToImage(PaintView* view, const QString& path)
{
    QPixmap pixMap = view->grab();
    pixMap.save(path);
}

bool SceneStore::saveToJson(PaintView* view, const QString& path)
{
    QFile file(path);

    if (file.open(QIODevice::WriteOnly))
    {
        QJsonArray objArray;

        QList<QGraphicsItem*> itemList = view->scene()->items();

        for (QGraphicsItem* item : itemList)
        {
            switch (item->type())
            {
            case QGraphicsLineItem::Type:
            {
                QJsonObject jsonLineObj = SceneStore::lineToJson(item);

                objArray.push_back(jsonLineObj);
            }
            default:
                break;
            }
        }

        QJsonDocument jsonDoc(objArray);
        file.write(jsonDoc.toJson());
    }
    else
    {
        return false;
    }

    return true;
}

QJsonObject SceneStore::lineToJson(QGraphicsItem* item)
{
    QGraphicsLineItem* lineItem = dynamic_cast<QGraphicsLineItem*>(item);
    if (!lineItem)
        return QJsonObject();

    QLineF line = lineItem->line();

    QJsonObject jsonObj;

    jsonObj[kStartPosX] = line.x1();
    jsonObj["startPosY"] = line.y1();

    jsonObj["endPosX"] = line.x2();
    jsonObj["endPosY"] = line.y2();

    jsonObj["lineWidth"] = lineItem->pen().width();
    jsonObj["color"] = lineItem->pen().color().name();

    jsonObj["type"] = lineItem->type();

    return jsonObj;
}

QGraphicsLineItem* SceneStore::jsonToLine(QJsonValue item)
{
    QGraphicsLineItem* lineItem = new QGraphicsLineItem();

    QPointF startPos(item[kStartPosX].toDouble(), item["startPosY"].toDouble());
    QPointF endPos(item["endPosX"].toDouble(), item["endPosY"].toDouble());

    QLineF line(startPos, endPos);

    QPen pen;
    pen.setWidth(item["lineWidth"].toInt());
    pen.setColor(QColor(item["color"].toString()));

    lineItem->setPen(pen);
    lineItem->setLine(line);

    return lineItem;
}

