# Windows环境使用C++进行Yolov8实例分割和NvidiaTensorRT加速

## 环境搭建
1. CUDA 和 Cudnn 安装教程在 [Windows 安装 Nvidia CUDA 以及 cuDNN](https://hongzhuoxx.xyz:8088/archives/341)
2. 下载并安装OpenCV
[下载OpenCV](https://opencv.org/releases/)
将OpenCV解压到自定义目录，稍后再VisualStudio项目中会使用。(个人习惯会直接放到C盘根目录或C盘下指定文件夹)

3. 下载并安装 Nvidia TensorRT
[Nvidia TensorRT 下载地址](https://developer.nvidia.com/nvidia-tensorrt-download)
将TensorRT保存到自定义,稍后再VisualStudio项目中会使用。(个人习惯会直接放到C盘根目录或C盘下指定文件夹)
并将lib目录配置到环境变量Path中
```sh
# 例如
C:\TensorRT-8.6.1.6\lib\
```

## VisualStudio 中配置相关依赖
### 配置属性-> VC++目录 -> 包含目录
```sh
# opencv
C:\opencv\build\include
# tensorrt
C:\TensorRT-8.6.1.6\include
# cuda
C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.6\include
```

### 配置属性-> VC++目录-> 库目录
```sh
# tensorrt
C:\TensorRT-8.6.1.6\lib
# opencv
C:\opencv\build\x64\vc16\lib
# cuda
C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.6\lib\x64
```

### 配置属性-> 链接器-> 输入
附加依赖项
这里我引用的比较多,可能有一些用不上的也引用进来了.

**而且这里有一项特别需要注意的！**
**引用的lib后面带d的是调试模式使用的,不带d的是发布模式使用的。**
**例如:opencv_world470d.lib就是调试模型使用的库,而opencv_world470.lib则为发布模式使用的库,如果弄错了那么执行结果会出现异常。**


```sh
nvinfer.lib
nvinfer_dispatch.lib
nvinfer_lean.lib
nvinfer_plugin.lib
nvinfer_vc_plugin.lib
nvonnxparser.lib
nvparsers.lib
cublas.lib
cublasLt.lib
cuda.lib
cudadevrt.lib
cudart.lib
cudart_static.lib
cudnn.lib
cudnn64_8.lib
cudnn_adv_infer.lib
cudnn_adv_infer64_8.lib
cudnn_adv_train.lib
cudnn_adv_train64_8.lib
cudnn_cnn_infer.lib
cudnn_cnn_infer64_8.lib
cudnn_cnn_train.lib
cudnn_cnn_train64_8.lib
cudnn_ops_infer.lib
cudnn_ops_infer64_8.lib
cudnn_ops_train.lib
cudnn_ops_train64_8.lib
cufft.lib
cufftw.lib
cufilt.lib
curand.lib
cusolver.lib
cusolverMg.lib
cusparse.lib
nppc.lib
nppial.lib
nppicc.lib
nppidei.lib
nppif.lib
nppig.lib
nppim.lib
nppist.lib
nppisu.lib
nppitc.lib
npps.lib
nvblas.lib
nvjpeg.lib
nvml.lib
nvptxcompiler_static.lib
nvrtc-builtins_static.lib
nvrtc.lib
nvrtc_static.lib
OpenCL.lib
opencv_world470d.lib
```
