import cv2
import numpy as np


def main():
    image_path = "./car.jpg"
    # 读取图像
    src = cv2.imread(image_path)
    gray = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    if src is None:
        print("Can't open image!")
        return
    x, y = 10, 10
    gray_intensity = gray[x,y] #第11行，11列
    blue = src[x, y, 0]
    green = src[x, y, 1]
    red = src[x, y, 2]
    
    # 修改图像
    gray[x,y] = 255
    hsv = cv2.cvtColor(src, cv2.COLOR_BGR2HSV)
    f32_img = src.astype(np.float32)
    
    # ROI
    roi = src[:10, :10, :] # 前10行,10列
    
    # copy
    src_copy = src.copy() # 直接 '='，得到的是对原数组的引用
    
    # 写入文件
    cv2.imwrite('gray.jpg', gray)
    
    # 可视化
    cv2.namedWindow("src", cv2.WINDOW_AUTOSIZE)
    cv2.namedWindow("hsv", cv2.WINDOW_NORMAL)
    cv2.imshow("src", src)
    cv2.imshow("gray", gray)
    cv2.imshow("hsv", hsv)
    key = cv2.waitKey()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
