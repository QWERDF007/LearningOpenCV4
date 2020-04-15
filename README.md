# 学习 OpenCV4

本项目的目的是通过 OpenCV 的教程和例子来学习 OpenCV4，顺便学习C++，代码主要用 C++，尽可能完成 Python 的。

## 编译

- cpp
    - Windows
    
        ```powershell
        # 项目 cpp 目录下
        # mkdir bin
        mkdir build
        cd build
        # VS2017 Win64
        cmake -G "Visual Studio 15 2017 Win64" ..
        # VS2015 Win64
        cmake -G "Visual Studio 14 2015 Win64" ..
        # 接着在 VS 中编译刚刚生成的项目
        ```
        
    - Linux
    
        ```shell
        # 项目 cpp 目录下
        mkdir bin build
        cd build
        cmake ..
        make
        ```
    
- python

    ```shell
    python xxx.py
    ```

## 项目列表

| 项目名称  | code | Introduction | OpenCV Docs |
| -------- | :---- | :---- | -------- |
| [加载与显示图像](/project/load_display) | [cpp](/project/load_display/code/cpp/)  [python](/project/load_display/code/python/) | [README](/project/load_display/README.md) | [Tutorial](https://docs.opencv.org/4.1.0/db/deb/tutorial_display_image.html) |
| [加载、修改和保存](/project/load_modify_save) | [cpp](/project/load_modify_save/code/cpp/)  [python](/project/load_modify_save/code/python/) | [README](/project/load_modify_save/README.md) | [Tutorial](https://docs.opencv.org/4.1.0/db/d64/tutorial_load_save_image.html) |
| [基本图像容器](/project/mat_basic_image_container) | [cpp](/project/mat_basic_image_container/code/cpp)  [python](/project/mat_basic_image_container/code/python) | [README](/project/mat_basic_image_container/README.md) | [Tutorial](<https://docs.opencv.org/4.1.0/d6/d6d/tutorial_mat_the_basic_image_container.html>) |
| [扫描图像](/project/scan_images) | [cpp](/project/scan_images/code/cpp)  [python](/project/scan_images/code/python) | [README](/project/scan_images/README.md) | [Tutorial](<https://docs.opencv.org/4.1.0/db/da5/tutorial_how_to_scan_images.html>) |
| [掩码操作](/project/mask_operations) | [cpp](/project/mask_operations/code/cpp)  [python](/project/mask_operations/code/python) | [README](/project/mask_operations/README.md) | [Tutorial](<https://docs.opencv.org/4.1.0/d7/d37/tutorial_mat_mask_operations.html>) |
| [图像相关操作](/project/operations_with_images) | [cpp](/project/operations_with_images/code/cpp)  [python](/project/operations_with_images/code/python) | [README](/project/operations_with_images/README.md) | [Tutorial](<https://docs.opencv.org/4.1.0/d5/d98/tutorial_mat_operations.html>) |
| [混合图像](/project/blend_images) | [cpp](/project/blend_images/code/cpp)  [python](/project/blend_images/code/python) | [README](/project/blend_images/README.md) | [Tutorial](<https://docs.opencv.org/4.1.0/d3/dc1/tutorial_basic_linear_transform.html>) |
| [修改对比度和亮度](/project/change_contrast_brightness) | [cpp](/project/change_contrast_brightness/code/cpp)  [python](/project/change_contrast_brightness/code/python) | [README](/project/change_contrast_brightness/README.md) | [Tutorial](<https://docs.opencv.org/4.1.0/d3/dc1/tutorial_basic_linear_transform.html>) |
| [离散傅里叶变换](/project/discrete_fourier_transform) | [cpp](/project/discrete_fourier_transform/code/cpp)  [python](/project/discrete_fourier_transform/code/python) | [README](/project/discrete_fourier_transform/README.md) | [Tutorial](<https://docs.opencv.org/4.1.0/d8/d01/tutorial_discrete_fourier_transform.html>) |
| [XML&YML文件输入输出](/project/file_io_using_xml_yaml) | [cpp](/project/file_io_using_xml_yaml/code/cpp) [python](/project/file_io_using_xml_yaml/code/python) | [README](/project/file_io_using_xml_yaml/README.md) | [Tutorial](<https://docs.opencv.org/4.1.0/dd/d74/tutorial_file_input_output_with_xml_yml.html>) |
| [基础绘制](/project/basic_drawing) | [cpp](/project/basic_drawing/code/cpp) [python](/project/basic_drawing/code/python) | [README](/project/basic_drawing/README.md) | [Tutorial](<https://docs.opencv.org/4.1.0/d3/d96/tutorial_basic_geometric_drawing.html>) |
|  |  |  |  |

