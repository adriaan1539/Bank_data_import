# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'rode.ui'
#
# Created by: PyQt5 UI code generator 5.9
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class PlotForm(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(1032, 651)

        self.verticalLayout = QtWidgets.QVBoxLayout(Form)
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalWidget = QtWidgets.QWidget(Form)
        self.horizontalWidget.setMaximumSize(QtCore.QSize(16777215, 100))
        self.horizontalWidget.setBaseSize(QtCore.QSize(0, 100))
        self.horizontalWidget.setObjectName("horizontalWidget")

        self.options_layout = QtWidgets.QHBoxLayout(self.horizontalWidget)
        self.options_layout.setSizeConstraint(QtWidgets.QLayout.SetFixedSize)
        self.options_layout.setContentsMargins(0, 0, 0, 0)
        self.options_layout.setObjectName("options_layout")

        self.gridWidget = QtWidgets.QWidget(self.horizontalWidget)
        self.gridWidget.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.gridWidget.setBaseSize(QtCore.QSize(0, 0))
        self.gridWidget.setObjectName("gridWidget")
        self.gridLayout = QtWidgets.QGridLayout(self.gridWidget)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")

        self.yearCombo = QtWidgets.QComboBox(self.gridWidget)
        self.yearCombo.setObjectName("yearCombo")

        self.gridLayout.addWidget(self.yearCombo, 1, 1, 1, 1)

        self.label = QtWidgets.QLabel(self.gridWidget)
        self.label.setObjectName("label")

        self.gridLayout.addWidget(self.label, 1, 0, 1, 1)

        self.options_layout.addWidget(self.gridWidget)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")

        self.pushButton = QtWidgets.QPushButton(self.horizontalWidget)
        self.pushButton.setObjectName("pushButton")
        self.verticalLayout_2.addWidget(self.pushButton)
        self.options_layout.addLayout(self.verticalLayout_2)
        self.verticalLayout.addWidget(self.horizontalWidget)
        self.horizontalWidget_2 = QtWidgets.QWidget(Form)
        self.horizontalWidget_2.setAutoFillBackground(False)
        self.horizontalWidget_2.setStyleSheet("background-color:black;\n"
"color: #FFF;")
        self.horizontalWidget_2.setObjectName("horizontalWidget_2")
        self.plot_layout = QtWidgets.QHBoxLayout(self.horizontalWidget_2)
        self.plot_layout.setContentsMargins(0, 0, 0, 0)
        self.plot_layout.setObjectName("plot_layout")
        self.verticalLayout.addWidget(self.horizontalWidget_2)

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "Form"))
        self.label.setText(_translate("Form", "Year"))
        self.pushButton.setText(_translate("Form", "Push de button"))
