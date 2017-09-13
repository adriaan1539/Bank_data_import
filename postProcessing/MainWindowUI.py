# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'main.ui'
#
# Created by: PyQt5 UI code generator 5.7
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(370, 200)
        MainWindow.setMinimumSize(QtCore.QSize(370, 200))
        MainWindow.setMaximumSize(QtCore.QSize(370, 200))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setAutoFillBackground(False)
        self.centralwidget.setStyleSheet("background-color: #666")
        self.centralwidget.setObjectName("centralwidget")
        self.barButton = QtWidgets.QPushButton(self.centralwidget)
        self.barButton.setGeometry(QtCore.QRect(10, 10, 161, 151))
        self.barButton.setAutoFillBackground(False)
        self.barButton.setStyleSheet("font-size: 60px; background-color: #FFF;")
        self.barButton.setObjectName("barButton")
        self.plotButton = QtWidgets.QPushButton(self.centralwidget)
        self.plotButton.setGeometry(QtCore.QRect(190, 10, 161, 151))
        self.plotButton.setAutoFillBackground(False)
        self.plotButton.setStyleSheet("font-size: 60px; background-color: #FFF;")
        self.plotButton.setObjectName("plotButton")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 370, 28))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Bank Import & Graph Output (BINGO)"))
        self.barButton.setText(_translate("MainWindow", "📊"))
        self.plotButton.setText(_translate("MainWindow", "📈"))

