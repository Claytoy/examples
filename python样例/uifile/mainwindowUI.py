# -*- coding: utf-8 -*-

# Form implementation generated from reading uifile file 'mainwindow.uifile'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(806, 562)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayout = QtWidgets.QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName("gridLayout")
        self.frame = QtWidgets.QFrame(self.centralwidget)
        self.frame.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.frame.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.frame.setObjectName("frame")
        self.gridLayout.addWidget(self.frame, 0, 0, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 806, 23))
        self.menubar.setObjectName("menubar")
        self.menu = QtWidgets.QMenu(self.menubar)
        self.menu.setObjectName("menu")
        self.menuopen = QtWidgets.QMenu(self.menu)
        self.menuopen.setObjectName("menuopen")
        self.menutools = QtWidgets.QMenu(self.menubar)
        self.menutools.setObjectName("menutools")
        self.menuview = QtWidgets.QMenu(self.menubar)
        self.menuview.setObjectName("menuview")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.dockWidget = QtWidgets.QDockWidget(MainWindow)
        self.dockWidget.setObjectName("dockWidget")
        self.dockWidgetContents = QtWidgets.QWidget()
        self.dockWidgetContents.setObjectName("dockWidgetContents")
        self.dockWidget.setWidget(self.dockWidgetContents)
        MainWindow.addDockWidget(QtCore.Qt.DockWidgetArea(1), self.dockWidget)
        self.actiontif_shp = QtWidgets.QAction(MainWindow)
        self.actiontif_shp.setObjectName("actiontif_shp")
        self.actionimport_file = QtWidgets.QAction(MainWindow)
        self.actionimport_file.setObjectName("actionimport_file")
        self.menu.addAction(self.menuopen.menuAction())
        self.menu.addAction(self.actionimport_file)
        self.menubar.addAction(self.menu.menuAction())
        self.menubar.addAction(self.menuview.menuAction())
        self.menubar.addAction(self.menutools.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.menu.setTitle(_translate("MainWindow", "project"))
        self.menuopen.setTitle(_translate("MainWindow", "open"))
        self.menutools.setTitle(_translate("MainWindow", "tools"))
        self.menuview.setTitle(_translate("MainWindow", "layer view"))
        self.actiontif_shp.setText(_translate("MainWindow", "tif shp"))
        self.actionimport_file.setText(_translate("MainWindow", "import file"))
