# workshop-2021
Application development


# Prerequisites
1. Download Visual Studio 2019 (Community Edition)
    * https://visualstudio.microsoft.com/downloads/
- - - -
2. Download Qt Installer (Open source)
    * https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4
4. Install Qt version 5.15 msvc2019 64-bit
    * Sign-up for Qt
    * Select Custom installation for Qt (preferably also D as the installation drive - aprox 2GB disk space will be needed) 
    * Expand Qt 5.15.2 and select msvc2019 64-bit. Leave all other options as default.
    ![image](https://user-images.githubusercontent.com/81954334/113565191-46b8e700-9613-11eb-91ab-551844b5a9e9.png)
- - - -
4. Qt Visual Studio Tools (installed from Visual Studio)
    * Menu -> Manage Extensions -> Search for Qt
![image](https://user-images.githubusercontent.com/81954334/113562528-ecb62280-960e-11eb-8539-4845550ee73d.png)
5. Download and Close Visual Studio 2019 (so the extension can be applied).
6. Configure Qt versions in Visual studio
    * Menu -> Extensions -> Qt VS tools -> Qt versions
    * Add the installed version by navigating to the installation dir _\Qt\5.15.2\msvc2019_64\bin_ folder.
    * Set it as default (see default checkbox)
    ![image](https://user-images.githubusercontent.com/81954334/113566341-30ac2600-9615-11eb-9b96-120c3f3e7c65.png)
7. Configure Visual Studio project with Qt version
    * Right Click on PaintTest -> Qt -> Qt project Settings
    ![image](https://user-images.githubusercontent.com/81954334/113566644-c6e04c00-9615-11eb-8660-79538e0e6355.png)
    * Make sure the Version is $(DefaultQtVersion)
- - - -
8. Rebuild project
    * ========== Rebuild All: 1 succeeded, 0 failed, 0 skipped ==========
