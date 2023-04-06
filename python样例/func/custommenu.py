from qgis.PyQt.QtWidgets import QMenu, QAction
from qgis.core import QgsLayerTreeNode, QgsLayerTree, QgsMapLayerType
from qgis.gui import QgsLayerTreeViewMenuProvider, QgsLayerTreeView, QgsLayerTreeViewDefaultActions, QgsMapCanvas
from uifile import attributeUI

class CustomMenuProvider(QgsLayerTreeViewMenuProvider):
    #鼠标右键菜单重构
    def __init__(self, layerTreeView: QgsLayerTreeView, mapCanvas: QgsMapCanvas, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.layerTreeView = layerTreeView
        self.mapCanvas = mapCanvas

    def createContextMenu(self):
        menu = QMenu()
        actions: QgsLayerTreeViewDefaultActions = self.layerTreeView.defaultActions()
        if not self.layerTreeView.currentIndex().isValid():
            # 不在图层上右键
            self.actionAddGroup = actions.actionAddGroup(menu)
            menu.addAction(self.actionAddGroup)
            menu.addAction('Expand All', self.layerTreeView.expandAll)
            menu.addAction('Collapse All', self.layerTreeView.collapseAll)
            return menu

        node: QgsLayerTreeNode = self.layerTreeView.currentNode()

        if QgsLayerTree.isGroup(node):
            # 图组操作
            print('group')
            pass
        elif QgsLayerTree.isLayer(node):
            print('layer')
            self.actionZoomToLayer = actions.actionZoomToLayer(self.mapCanvas, menu)
            menu.addAction(self.actionZoomToLayer)
            # 图层操作
            layer = self.layerTreeView.currentLayer()
            if layer.type() == QgsMapLayerType.VectorLayer:
                # 矢量图层
                actionOpenAttributeDialog = QAction('open Attribute Table', menu)
                actionOpenAttributeDialog.triggered.connect(lambda: self.openAttributeDialog(layer))
                menu.addAction(actionOpenAttributeDialog)
            else:
                # 栅格图层
                pass
        else:
            print('node type is none')

        return menu

    def openAttributeDialog(self, layer):
        self.attributeDialog = attributeUI.AttributeDialog(self.mapCanvas, parent=self.mapCanvas.parent())
        self.attributeDialog.openAttributeDialog(layer)
        self.attributeDialog.show()