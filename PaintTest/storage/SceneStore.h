#ifndef SCENESTORE_H
#define SCENESTORE_H

#include "PaintView.h"

class SceneStore
{
public:
	static bool saveScene(PaintView* view, const QString& path);
	static bool	loadSceneFromJson(PaintView* view, const QString& path);

private:
	static void saveToImage(PaintView* view, const QString& path);
	static bool	saveToJson(PaintView* view, const QString& path);

	static QJsonObject lineToJson(QGraphicsItem* item);
	static QGraphicsLineItem* jsonToLine(QJsonValue item);
};

#endif