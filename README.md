# QMLPrototyper

Простое приложение для ОС Аврора 4 и старше для прототипирования, создания и проверки работы QML интерфейсов.

Пишите и проверяйте QML-код прямо на устройстве под управлением ОС Аврора 4 / 5

Исходный код проверен на устройствах F+ R570E, F+ Lifetab+

# Приложение для создания кода интерфейса на QML прямо на телефоне или планшете под управлением ОС Аврора

Создавайте, сохраняйте и проверяйте QML-код приложения прямо на устройстве под управлением ОС Аврора. 

The source code of the project is provided under
[the license](LICENSE.BSD-3-CLAUSE.md),
that allows it to be used in third-party applications.

## Project Structure

The project has a common structure
of an application based on C++ and QML for Aurora OS.

* **[ru.mastercond.QmlPrototyper.pro](ru.mastercond.QmlPrototyper.pro)** file
  describes the project structure for the qmake build system.
* **[icons](icons)** directory contains application icons for different screen resolutions.
* **[qml](qml)** directory contains the QML source code and the UI resources.
  * **[cover](qml/cover)** directory contains the application cover implementations.
  * **[icons](qml/icons)** directory contains the custom UI icons.
  * **[pages](qml/pages)** directory contains the application pages.
  * **[QmlPrototyper.qml](qml/QmlPrototyper.qml)** file
    provides the application window implementation.
* **[rpm](rpm)** directory contains the rpm-package build settings.
  **[ru.mastercond.QmlPrototyper.spec](rpm/ru.mastercond.QmlPrototyper.spec)** file is used by rpmbuild tool.
  It is generated from **[ru.mastercond.QmlPrototyper.yaml](rpm/ru.mastercond.QmlPrototyper.yaml)** file.
* **[src](src)** directory contains the C++ source code.
  * **[main.cpp](src/main.cpp)** file is the application entry point.
* **[translations](translations)** directory contains the UI translation files.
* **[ru.mastercond.QmlPrototyper.desktop](ru.mastercond.QmlPrototyper.desktop)** file
  defines the display and parameters for launching the application.