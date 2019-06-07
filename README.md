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
| [加载与显示图像](/project/load_display) | [cpp](/project/load_display/code/cpp/)  [python](/project/load_display/code/python/) | [README.md](/project/load_display/README.md) | [Tutorial](https://docs.opencv.org/master/db/deb/tutorial_display_image.html) |
| [加载、修改和保存](/project/load_modify_save) | [cpp](/project/load_modify_save/code/cpp/)  [python](/project/load_modify_save/code/python/) | [README.md](/project/load_modify_save/README.md) | [Tutorial](https://docs.opencv.org/master/db/d64/tutorial_load_save_image.html) |
| [基本图像容器](/project/mat_basic_image_container) | [cpp](/project/mat_basic_image_container/code/cpp)  [python](/project/mat_basic_image_container/code/python) | [README.md](/project/mat_basic_image_container/README.md) | [Tutorial](<https://docs.opencv.org/master/d6/d6d/tutorial_mat_the_basic_image_container.html>) |
|  |  |  |  |


