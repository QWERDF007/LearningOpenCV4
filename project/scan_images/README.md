# 扫描图像

## Goals

- 遍历图像的每个像素
- 测量算法的时间性能
- 了解与使用查找表

## Code

- [cpp](./code/cpp)
- [python](./code/python)

## Result

![result](https://github.com/QWERDF007/LearningOpenCV4/blob/master/project/scan_images/result/result.jpg)

Windows:

| Method                              | Debug Time | Release Time |
| ----------------------------------- | ---------- | ------------ |
| C style operator[] (pointer) access | 43ms       | 7ms          |
| Iterator                            | 687ms      | 21ms         |
| On-The-Fly RA                       | 1680ms     | 19ms         |
| LUT                                 | 19ms       | 11ms         |

## Reference

- [How to scan images, lookup tables and time measurement with OpenCV](<https://docs.opencv.org/4.1.0/db/da5/tutorial_how_to_scan_images.html>)
- [clock](http://www.cplusplus.com/reference/ctime/clock/)
- [cv::getTickCount](<https://docs.opencv.org/4.1.0/db/de0/group__core__utils.html#gae73f58000611a1af25dd36d496bf4487>)
- [cv::getTickFrequency](<https://docs.opencv.org/4.1.0/db/de0/group__core__utils.html#ga705441a9ef01f47acdc55d87fbe5090c>)
- [cv::Mat::isContinuous()](<https://docs.opencv.org/4.1.0/d3/d63/classcv_1_1Mat.html#aa90cea495029c7d1ee0a41361ccecdf3>)

