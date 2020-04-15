import cv2
import numpy as np

def main():
    w, h = 400, 400
    r, a, b = 20, 100, 25
    center = (w // 2, h // 2) # 中心点 cv::Point 用 tuple
    # 创建两个空白画布, cv读取后也是 np.array 格式
    atom_image = np.zeros((w, h, 3), dtype=np.uint8)
    rect_image = np.zeros((w, h, 3), dtype=np.uint8)
    cv2.circle(atom_image, center, r, (0,0,255), cv2.FILLED)
    cv2.ellipse(atom_image, center, (a, b), 0, 0, 360, (255,0,0))
    cv2.ellipse(atom_image, center, (a, b), 45, 0, 360, (255,0,0))
    cv2.ellipse(atom_image, center, (a, b), -45, 0, 360, (255,0,0))
    cv2.ellipse(atom_image, center, (a, b), 90, 0, 360, (255,0,0))
    # 多个点可以用 np.array 存储
    pts = np.array([[100, 100], [50, 300], [350, 300], [300, 100]])
    cv2.fillPoly(rect_image, [pts], (255,255,255))
    # cv::Rect 也用 tuple ?
    cv2.rectangle(rect_image, (170,50,50,50), [0,255,0], 4)
    cv2.imshow('atom', atom_image)
    cv2.imshow('rect', rect_image)
    cv2.waitKey()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
