import cv2
import numpy as np


def main():
    # 读取
    image_path = './car.jpg'
    src = cv2.imread(image_path)
    gray = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    if src is None:
        print("can't open image!")
        return
    x, y = 10, 10
    gray_intensity = gray[x, y]
    blue = src[x, y, 0]
    green = src[x, y, 1]
    red = src[x, y, 2]
    # 修改
    gray[x, y] = 255
    hsv = cv2.cvtColor(src, cv2.COLOR_BGR2HSV)
    f32_image = src.astype(np.float32)
    # roi、copy
    roi = src[10:10+20, 10:10+20, :] # 第10到30行列
    src_copy = src.copy()
    # 写入文件
    cv2.imwrite('gray.jpg', gray)
    # 可视化
    cv2.namedWindow("src", cv2.WINDOW_AUTOSIZE)
    cv2.namedWindow("gray", cv2.WINDOW_NORMAL)
    cv2.imshow("src", src)
    cv2.imshow("gray", gray)
    cv2.imshow("hsv", hsv)
    cv2.waitKey()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
