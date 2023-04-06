import sys
from PyQt5.QtWidgets import QFileDialog, QWidget, QMessageBox
from pathlib import Path
from threading import Thread
from qgis.core import QgsVectorLayer, QgsRasterLayer
from PyQt5.uic.properties import QtWidgets
from qgis._core import QgsApplication
"""algo lib"""
import cv2
from skimage import segmentation
#from skimage.segmentation import slic
from skimage.segmentation import mark_boundaries
from skimage.util import img_as_float
import numpy as np
from PIL import Image
import random
from osgeo import osr, gdal,ogr
import os
from func.slicloop import cv_Slic
"""ui lib"""
from uifile.child01UI import Ui_Dialog
#from func.mainwindow import PROJECT



class ChildWindow(QWidget, Ui_Dialog):
    def __init__(self):
        super(ChildWindow, self).__init__()
        self.setupUi(self)
        print("child01 open")
        self.setWindowTitle("child01")
        self.paths = []



        #--------btn 链接----------
        self.pushButton_1.clicked.connect(self.getPath_1)
        self.pushButton_2.clicked.connect(self.getPath_2)
        self.pushButton.clicked.connect(self.customslic)




    def getPath_1(self):
        pathTemp, ext = QFileDialog.getOpenFileName(self, '打开', '', '所有文件(*)')
        self.lineEdit_1.setText(pathTemp)
    def getPath_2(self):
        pathTemp = QFileDialog.getExistingDirectory(None, "选取存储文件夹")
        self.lineEdit_2.setText(pathTemp)
    def customslic(self):
        # if self.lineEdit_1.text()=="":
        #     QMessageBox.information(self, '信息',"路径为空！！")
        #     return

        inpath = self.lineEdit_1.text()
        outpath = self.lineEdit_2.text()
        t1 = Thread(target=cv_Slic,args=(inpath, outpath))
        #self.firstClip(inpath, outpath)
        t1.start()
        t1.join()
        layer = QgsRasterLayer(data_file, os.path.basename(data_file))






# if __name__ =="__main__":
# # 应用入口，使用GUI
#     qgs = QgsApplication([], True)
#     # 设置，qgis安装路径，这里写相对路径，如果是源码运行，这行可不写
#     qgs.setPrefixPath('qgis', True)
#     # 初始化
#     qgs.initQgis()
#
#     child001 = ChildWindow()
#     child001.show()
#
#     exit_code = qgs.exec_()
#     # 退出
#     qgs.exitQgis()





