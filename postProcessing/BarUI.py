# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'plot.ui'
#
# Created by: PyQt5 UI code generator 5.7
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Bar(object):
    def setupUi(self, BarDialog, title):
        BarDialog.setObjectName("BarDialog")
        BarDialog.resize(640, 480)
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setSpacing(2)
        self.verticalLayout.setObjectName("verticalLayout")
        self.plot_layout = QtWidgets.QHBoxLayout()
        self.plot_layout.setObjectName("plot_layout")
        self.verticalLayout.addLayout(self.plot_layout)
        self.gridLayout.addLayout(self.verticalLayout, 1, 0, 1, 1)
        self.widget = QtWidgets.QWidget(BarDialog)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.widget.sizePolicy().hasHeightForWidth())
        self.widget.setSizePolicy(sizePolicy)
        self.widget.setMaximumSize(QtCore.QSize(16777215, 100))
        self.widget.setBaseSize(QtCore.QSize(0, 100))
        self.widget.setObjectName("widget")
        self.yearCombo = QtWidgets.QComboBox(self.widget)
        self.yearCombo.setGeometry(QtCore.QRect(20, 20, 103, 36))
        self.yearCombo.setObjectName("yearCombo")
        self.gridLayout.addWidget(self.widget, 0, 0, 1, 1)
        self.title = title

        self.retranslateUi(BarDialog)
        QtCore.QMetaObject.connectSlotsByName(BarDialog)

    def retranslateUi(self, BarDialog):
        _translate = QtCore.QCoreApplication.translate
        BarDialog.setWindowTitle(_translate("BarDialog", self.title))

