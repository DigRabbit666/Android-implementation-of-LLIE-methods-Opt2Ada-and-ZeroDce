# Android-implementation-of-LLIE-methods-Opt2Ada-and-ZeroDce
![微信截图_20230819105006](https://github.com/DigRabbit666/Android-implementation-of-LLIE-methods-Opt2Ada-and-ZeroDce/assets/73062847/2cbae610-9bb0-40a6-bd2b-87d57bcc8076)

# Sketch
Low-light image enhancement (LLIE) is a method of improving the visual quality of images captured in weak illumination conditions. In such conditions, the images tend to be noisy, hazy, and have low contrast, making them difficult to distinguish details. LLIE techniques have many practical applications in various fields, including surveillance, astronomy, medical imaging, and consumer photography.

The Android implementations of LLIE methods Opt2Ada and ZeroDce are given in this repository. Here, NCNN is used for optimization and deployment of ZeroDce. Therefore, the NCNN model of ZeroDce and the testing code are also provide.

Here is an output of the optimized NCNN ZeroDce model.

![微信截图_20230819102841](https://github.com/DigRabbit666/Android-implementation-of-LLIE-methods-Opt2Ada-and-ZeroDce/assets/73062847/9f513343-06a7-403e-9284-2d7810cedf4e)

# Demonstration 

A demonstration can be found here:
https://www.bilibili.com/video/BV1v3411G7zi/

Models are tested in reality. The noise is inevitably amplified and the effectiveness of the methods heavily depends on camera specification.

![vszerodce](https://github.com/DigRabbit666/Android-implementation-of-LLIE-methods-Opt2Ada-and-ZeroDce/assets/73062847/78558e1c-1ed3-4a85-85b7-5533c65c1741)

# Compile
1. Complie with Visual Studio

Add the following to the C++ include directory:

~\ncnn-master\build-vs2019\install\include

~\ncnn-master\src

~\ncnn-master\build-vs2019\src

~\protobuf-3.11.2\build-vs2019\install\include

~\opencv420\opencv\build\include

Add the following to the C++ library directory:

~\ncnn-master\build-vs2019\install\lib

~\protobuf-3.11.2\build-vs2019\install\lib

~\opencv420\opencv\build\x64\vc14\lib

Add the following to the linker:

ncnn.lib;

libprotobuf.lib;

opencv_world420.lib;

2. Complie with Cmake

Just use cmake.. and make. Modifications on the path of directories are needed.

3. Complie with Android Studio

Incorporate the wrapper class into the following project and add the model files into the project's asset. There are also some modifications need. Then make the project within Android Studio.

https://github.com/nihui/ncnn-android-nanodet



# References

https://github.com/Li-Chongyi/Zero-DCE

https://li-chongyi.github.io/Proj_Zero-DCE.html

https://content.iospress.com/articles/journal-of-intelligent-and-fuzzy-systems/ifs222644

https://github.com/Tencent/ncnn

