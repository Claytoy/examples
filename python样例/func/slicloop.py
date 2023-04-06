import cv2
from skimage.segmentation import slic
from skimage.segmentation import mark_boundaries
from skimage.util import img_as_float
import numpy as np
from PIL import Image
import random
from osgeo import osr, gdal,ogr
#os.environ["OPENCV_IO_MAX_IMAGE_PIXELS"] = pow(2,40).__str__()
from threading import Thread
def cv_Slic(inpath, outpath):
    print("slic start")
    Seg = 'seg.tif'  # 分割结果路径
    Shp = 'seg.shp'  # 矢量数据文件路径#

    img = cv2.imread(inpath)
    img_array = np.asarray(img, np.float32)
    print(img)
    segments = slic(img_as_float(img_array), n_segments=50, compactness=10, sigma=2)


    print("np.unique(segments):", np.unique(segments))

    out = mark_boundaries(img_as_float(cv2.cvtColor(img, cv2.COLOR_BGR2RGB)), segments)
    out = out * 255  # io的灰度读取是归一化值，若读取彩色图片去掉该行

    segImg = Image.fromarray(np.uint8(out))
    seg_img_name = '超像素分割.tif'
    segImg.save(outpath + '\\' + seg_img_name)  # 显示并保存加上分割线后的图片,此时仍缺少坐标信息

    # print(outpath + '\\' + seg_img_name)
    # self.assign_spatial_reference_byfile(inpath, outpath + '\\' + seg_img_name)

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    mask = np.zeros(img.shape[:2], dtype="uint8")

    # print("segments:\n", segments)
    for (i, segVal) in enumerate(np.unique(segments)):
        img[segments == segVal] = random.randint(0, 255)
    cv2.imwrite(outpath + '\\' + Seg, img)

    '''赋予坐标及投影信息'''
    src_path = inpath
    dst_path = outpath + '\\' + Seg
    assign_spatial_reference_byfile(src_path, dst_path)

    '''从tif文件提取shp文件并存储'''
    RASTER = outpath + '\\' + Seg
    shape = outpath + '\\' + Shp
    raster_to_shape(RASTER, shape)
    print("ok")

    # 添加坐标


def assign_spatial_reference_byfile(src_path, dst_path):
    src_ds = gdal.Open(src_path, gdal.GA_ReadOnly)
    sr = osr.SpatialReference()
    sr.ImportFromWkt(src_ds.GetProjectionRef())
    geoTransform = src_ds.GetGeoTransform()
    dst_ds = gdal.Open(dst_path, gdal.GA_Update)
    dst_ds.SetProjection(sr.ExportToWkt())
    dst_ds.SetGeoTransform(geoTransform)
    dst_ds = None
    src_ds = None

#这个可以正常运行，你把控制台关了就行
#出错的是界面文件

def raster_to_shape(rasterfile, shapefile):
    data = gdal.Open(rasterfile, gdal.OF_UPDATE)
    inband = data.GetRasterBand(1)
    drv = ogr.GetDriverByName('ESRI Shapefile')
    Polygon = drv.CreateDataSource(shapefile)
    prj = osr.SpatialReference()
    # prj.ImportFromEPSG(4326)
    prj.ImportFromWkt(data.GetProjection())  ## 使用栅格的投影信息
    Polygon_layer = Polygon.CreateLayer(shapefile, srs=prj, geom_type=ogr.wkbMultiPolygon)
    newField = ogr.FieldDefn('Value', ogr.OFTInteger)
    Polygon_layer.CreateField(newField)
    gdal.Polygonize(inband, None, Polygon_layer, 0)

    ## 读取图像，解决imread不能读取中文路径的问题
def cv_imread(file_path):
    cv_img = cv2.imdecode(np.fromfile(file_path, dtype=np.uint8), -1)
    return cv_img


if __name__ =="__main__":
    inpath =  "E:/0code/py/formqgis/algo/6.tif"
    outpath = 'E:/Cache/images/outfile'

    # inpath = inpath.replace('/', '\\')
    # outpath = outpath.replace('/', '\\')
    t1 = Thread(target=cv_Slic,args=(inpath, outpath))
    # self.firstClip(inpath, outpath)
    t1.start()
    t1.join()
    #cv_Slic(inpath,outpath)