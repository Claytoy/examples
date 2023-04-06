from qgis.PyQt import QtCore
from qgis.PyQt.QtCore import Qt
from qgis.PyQt.QtGui import QIcon
from qgis.core import QgsApplication

from func.mainwindow import MainWindow

def Start():
    # 适应高分辨率
    QgsApplication.setAttribute(Qt.AA_EnableHighDpiScaling)
    # 设置窗口风格
    QgsApplication.setStyle("Fusion")
    # 创建对QgsApplication的引用，第二个参数设置为False将禁用GUI
    qgs = QgsApplication([], True)
    # 提供qgis安装位置的路径(windows默认：C:\Program Files\QGIS 3.4\apps\qgis-ltr)
    qgs.setPrefixPath("qgis", True)
    # 初始化
    qgs.initQgis()
    # 主窗口
    mainform = MainWindow()
    mainform.show()
    # 脚本完成后，调用exitQgis()从内存中删除提供者和图层注册
    qgs.exec_()
    qgs.exitQgis()

if __name__ =="__main__":
    #app = QApplication(sys.argv)
    Start()

