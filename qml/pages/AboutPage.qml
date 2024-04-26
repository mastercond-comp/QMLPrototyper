/*******************************************************************************
**
** Copyright (C) 2022 ru.mastercond
**
** This file is part of the Приложение для создания кода интерфейса на QML прямо на телефоне или планшете под управлением ОС Аврора project.
**
** Redistribution and use in source and binary forms,
** with or without modification, are permitted provided
** that the following conditions are met:
**
** * Redistributions of source code must retain the above copyright notice,
**   this list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice,
**   this list of conditions and the following disclaimer
**   in the documentation and/or other materials provided with the distribution.
** * Neither the name of the copyright holder nor the names of its contributors
**   may be used to endorse or promote products derived from this software
**   without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
** THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
** FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
** OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS;
** OR BUSINESS INTERRUPTION)
** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
** EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
*******************************************************************************/

import QtQuick 2.6
import Sailfish.Silica 1.0
import ru.mastercond.QmlPrototyper 1.0

Page {
    objectName: "aboutPage"
    allowedOrientations: Orientation.All
    backgroundColor: Theme.overlayBackgroundColor

     Prototyper {id: prototyper }

    SilicaFlickable {
        objectName: "flickable"
        anchors.fill: parent
        contentHeight: layout.height + Theme.paddingLarge



        Column {
            id: layout
            objectName: "layout"
            width: parent.width

            PageHeader {
                objectName: "pageHeader"
                title: qsTr("About Application")
            }

            Label {
                objectName: "descriptionText"
                anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
                color: palette.highlightColor
                font.pixelSize: Theme.fontSizeSmall
                textFormat: Text.RichText
                wrapMode: Text.WordWrap
                text: qsTr("<b>QML прототип (версия 0.4)</b><br><br>Приложение предназначено для прототипирования QML интерфейсов (страниц и компонентов) прямо на устройстве под управлением ОС Аврора.<br><br>Рабочий каталог приложения - Документы/QML прототипы/.<br><br><i>Рекомендация - для корректного отображения созданных в приложении страниц обязательно используйте в компоненте Page свойство background.color (например, backgroundColor: Theme.overlayBackgroundColor).</i><br><br>Для вставки шаблонов кода - до нажатия на кнопку + в правой части экрана установите курсор в нужное для вставки место кода, далее при помощи кнопки + вставьте нужный шаблон элемента в код. <br><br>Приложение создано в Аврора IDE 4.0.2.249-base, протестировано на планшете F+ LifeTab+ под управлением Аврора 4.0.2.303, смартфоне F+ R570E под управлением Аврора 5.0.1.22<br><br>")
            }

            SectionHeader {
                objectName: "licenseHeader"
                text: qsTr("3-Clause BSD License")
            }

            Label {
                objectName: "licenseText"
                anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
                color: palette.highlightColor
                font.pixelSize: Theme.fontSizeSmall
                textFormat: Text.RichText
                wrapMode: Text.WordWrap
                text: qsTr("Разрешается повторное распространение и использование как в виде исходного кода, так и в двоичной форме, с изменениями или без, при соблюдении следующих условий:<br><br>

                           1) При повторном распространении исходного кода должно оставаться указанное выше уведомление об авторском праве, этот список условий и последующий отказ от гарантий.<br><br>

                           2) При повторном распространении двоичного кода должно сохраняться информация об авторском праве, этот список условий и последующий отказ от гарантий в документации и/или в других материалах, поставляемых при распространении.<br><br>

                           3) Ни название Организации, ни имена ее сотрудников не могут быть использованы в качестве поддержки или продвижения продуктов, основанных на этом ПО без предварительного письменного разрешения.<br><br>

                           ЭТА ПРОГРАММА ПРЕДОСТАВЛЕНА БЕСПЛАТНО ВЛАДЕЛЬЦАМИ АВТОРСКИХ ПРАВ И/ИЛИ ДРУГИМИ СТОРОНАМИ <b>КАК ОНА ЕСТЬ</b> БЕЗ КАКОГО-ЛИБО ВИДА ГАРАНТИЙ, ВЫРАЖЕННЫХ ЯВНО ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ, НО НЕ ОГРАНИЧИВАЯСЬ ИМИ, ПОДРАЗУМЕВАЕМЫЕ ГАРАНТИИ КОММЕРЧЕСКОЙ ЦЕННОСТИ И ПРИГОДНОСТИ ДЛЯ КОНКРЕТНОЙ ЦЕЛИ. НИ В КОЕМ СЛУЧАЕ, ЕСЛИ НЕ ТРЕБУЕТСЯ СООТВЕТСТВУЮЩИМ ЗАКОНОМ, ИЛИ НЕ УСТАНОВЛЕНО В УСТНОЙ ФОРМЕ, НИ ОДИН ВЛАДЕЛЕЦ АВТОРСКИХ ПРАВ И НИ ОДНО ДРУГОЕ ЛИЦО, КОТОРОЕ МОЖЕТ ИЗМЕНЯТЬ И/ИЛИ ПОВТОРНО РАСПРОСТРАНЯТЬ ПРОГРАММУ, КАК БЫЛО СКАЗАНО ВЫШЕ, НЕ НЕСЁТ ОТВЕТСТВЕННОСТИ, ВКЛЮЧАЯ ЛЮБЫЕ ОБЩИЕ, СЛУЧАЙНЫЕ, СПЕЦИАЛЬНЫЕ ИЛИ ПОСЛЕДОВАВШИЕ УБЫТКИ, В СЛЕДСТВИИ ИСПОЛЬЗОВАНИЯ ИЛИ НЕВОЗМОЖНОСТИ ИСПОЛЬЗОВАНИЯ ПРОГРАММЫ (ВКЛЮЧАЯ, НО НЕ ОГРАНИЧИВАЯСЬ ПОТЕРЕЙ ДАННЫХ, ИЛИ ДАННЫМИ, СТАВШИМИ НЕПРАВИЛЬНЫМИ, ИЛИ ПОТЕРЯМИ ПРИНЕСЕННЫМИ ИЗ-ЗА ВАС ИЛИ ТРЕТЬИХ ЛИЦ, ИЛИ ОТКАЗОМ ПРОГРАММЫ РАБОТАТЬ СОВМЕСТНО С ДРУГИМИ ПРОГРАММАМИ), ДАЖЕ ЕСЛИ ТАКОЙ ВЛАДЕЛЕЦ ИЛИ ДРУГОЕ ЛИЦО БЫЛИ ИЗВЕЩЕНЫ О ВОЗМОЖНОСТИ ТАКИХ УБЫТКОВ.<br><br>")
            }

           Button {
                            anchors { left: parent.left; right: parent.right; margins: Theme.horizontalPageMargin }
                            text: "Исходный код"

                            //onClicked: { copySourceCodes(); outputNotifications.close(); outputNotifications.previewBody = qsTr("Экспорт исходных кодов приложения выполнен в папку Документы, файл sources-QmlPrototyper-0.4.zip"); outputNotifications.publish(); }
                            onClicked: { copySourceCodes(); Notices.show("Экспорт исходных кодов приложения выполнен в папку <b>Документы</b>,<br> файл <b>sources-QmlPrototyper-0.4.zip</b>", Notice.Long, Notice.Center); }

                        }
                    }
                }

                function copySourceCodes()
                {
                    prototyper.copySources();
                }


        }

