import os
from qgis.PyQt.QtWidgets import QMainWindow, QFileDialog, QHBoxLayout, QVBoxLayout, QMessageBox
from qgis.core import QgsVectorLayer, QgsProject, QgsLayerTreeModel, QgsDataSourceUri, QgsRasterLayer,QgsLayerTree
from qgis.gui import QgsMapCanvas, QgsMapToolZoom, QgsMapToolPan, QgsMapToolIdentifyFeature, QgsLayerTreeView, \
    QgsLayerTreeMapCanvasBridge

from uifile.mainwindow import Ui_MainWindow
from func import custommenu
from func import child01
#全局实例
PROJECT = QgsProject.instance()
paths = []

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.setupUi(self)
        self.setWindowTitle('改良025')
        # 调整窗口大小
        self.resize(800, 600)
        # -----------canvas,treeview功能初始化start----------
        self.first_flag = True
        # 初始化图层树
        vl = QVBoxLayout(self.dockWidgetContents)
        self.layerTreeView = QgsLayerTreeView(self)
        vl.addWidget(self.layerTreeView)
        # 初始化地图画布
        self.mapCanvas = QgsMapCanvas(self)
        hl = QHBoxLayout(self.frame)
        hl.setContentsMargins(0, 0, 0, 0)
        hl.addWidget(self.mapCanvas)

        # 建立桥梁
        self.model = QgsLayerTreeModel(PROJECT.layerTreeRoot(), self)
        self.model.setFlag(QgsLayerTreeModel.AllowNodeRename)
        self.model.setFlag(QgsLayerTreeModel.AllowNodeReorder)
        self.model.setFlag(QgsLayerTreeModel.AllowNodeChangeVisibility)
        self.model.setFlag(QgsLayerTreeModel.ShowLegendAsTree)
        self.model.setAutoCollapseLegendNodes(10)
        self.layerTreeView.setModel(self.model)
        self.layerTreeBridge = QgsLayerTreeMapCanvasBridge(PROJECT.layerTreeRoot(), self.mapCanvas, self)
        # -----------canvas,treeview功能初始化end----------
        # 显示经纬度
        self.mapCanvas.xyCoordinates.connect(self.showLngLat)
        self.statusbar.showMessage(f'经度:, 纬度:')


        #----------menu链接----------------
        self.actionimport_file.triggered.connect(self.actionGeotiffTriggered)
        self.actioncsv.triggered.connect(self.actionCsvTriggered)
        self.actionQgs_Project.triggered.connect(self.actionOpenTriggered)
        self.actionprocess01.triggered.connect(self.showChild_1)

        #---------鼠标右键菜单重构链接----------
        self.customMenuProvider = custommenu.CustomMenuProvider(self.layerTreeView, self.mapCanvas)
        self.layerTreeView.setMenuProvider(self.customMenuProvider)


    def actionOpenTriggered(self):
        """打开工程（qgis文件）"""
        data_file, ext = QFileDialog.getOpenFileName(self, '打开', '', '工程文件(*.qgs , *.qgz)')
        if data_file:
            PROJECT.read(data_file)

    def actionGeotiffTriggered(self):
        """加载geotiff和shp"""
        data_file, ext = QFileDialog.getOpenFileName(self, '打开', '', '所有文件(*)')
        if data_file:
            if data_file.endswith('.tif'):
                layer = QgsRasterLayer(data_file, os.path.basename(data_file))
            elif data_file.endswith('.shp'):
                layer = QgsVectorLayer(data_file, os.path.basename(data_file), "ogr")
            else:
                print("cant read this")
                return
            self.addLayer(layer)
            paths.append(data_file)
        else:
            print("open cancel")

    def actionCsvTriggered(self):
        """加载csv数据"""
        data_file, ext = QFileDialog.getOpenFileName(self, '打开', '', '*.csv')
        if data_file:
            # 去掉盘符，否则图层无效
            data_file = os.path.splitdrive(data_file)[1]
            uri = f"file://{data_file}?delimiter=,&xField=x&yField=y"
            print(uri)
            layer = QgsVectorLayer(uri, "point", "delimitedtext")
            self.addLayer(layer)




    def addLayer(self, layer):
        """数据链接至图像查看frame"""
        if layer.isValid():
            if self.first_flag:
                self.mapCanvas.setDestinationCrs(layer.crs())
                self.mapCanvas.setExtent(layer.extent())
                self.first_flag = False
            PROJECT.addMapLayer(layer)
            layers = [layer] + [PROJECT.mapLayer(i) for i in PROJECT.mapLayers()]
            self.mapCanvas.setLayers(layers)
            self.mapCanvas.refresh()
        else:
            print('图层无效.')

    def showLngLat(self, point):
        x = point.x()
        y = point.y()
        self.statusbar.showMessage(f'经度:{x}, 纬度:{y}')


    def showChild_1(self):
        self.childform = child01.ChildWindow()
        self.childform.paths = paths
        if len(self.childform.paths)>0:
            self.childform.lineEdit_1.setText(paths[0])
        self.childform.show()


