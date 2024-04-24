################################################################################
##
## Copyright (C) 2022 ru.mastercond
## 
## This file is part of the Приложение для создания кода интерфейса на QML прямо на телефоне или планшете под управлением ОС Аврора project.
##
## Redistribution and use in source and binary forms,
## with or without modification, are permitted provided
## that the following conditions are met:
##
## * Redistributions of source code must retain the above copyright notice,
##   this list of conditions and the following disclaimer.
## * Redistributions in binary form must reproduce the above copyright notice,
##   this list of conditions and the following disclaimer
##   in the documentation and/or other materials provided with the distribution.
## * Neither the name of the copyright holder nor the names of its contributors
##   may be used to endorse or promote products derived from this software
##   without specific prior written permission.
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
## AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
## THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
## FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
## IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
## FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
## OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
## PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
## LOSS OF USE, DATA, OR PROFITS;
## OR BUSINESS INTERRUPTION)
## HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
## WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE)
## ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
## EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
##
################################################################################

TARGET = ru.mastercond.QmlPrototyper

CONFIG += \
    auroraapp \
    resources_big

PKGCONFIG += \

SOURCES += \
    prototyper.cpp \
    src/main.cpp \

HEADERS += \
    prototyper.h

DISTFILES += \
    qml/pages/EditSourceCodeToPaste.qml \
    qml/pages/QMLEditComponents.qml \
    qml/pages/QMLViewComponent.qml \
    qml/pages/Settings.qml \
    rpm/ru.mastercond.QmlPrototyper.spec \
    AUTHORS.md \
    CODE_OF_CONDUCT.md \
    CONTRIBUTING.md \
    LICENSE.BSD-3-CLAUSE.md \
    README.md

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n qml_debug declarative_debug testlib

TRANSLATIONS += \
    translations/ru.mastercond.QmlPrototyper.ts \
    translations/ru.mastercond.QmlPrototyper-ru.ts \

DEPLOYMENT_PATH = /usr/share/$${TARGET}/qml/pages
sources.files=sources
sources.path=$${DEPLOYMENT_PATH}

INSTALLS += sources
