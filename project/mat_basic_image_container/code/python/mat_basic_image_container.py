import cv2
import numpy as np

def main():
    A = cv2.imread('./car.jpg', cv2.IMREAD_COLOR)
    B = A
    # 拷贝构造
    C = A.copy()
    # print(B is A, C is A)  # True, False
    # 创建400X400的3通道矩阵，填充红色(0,0,255)
    D = np.full((400, 400, 3), (0, 0, 255), np.uint8)
    # ROI
    E = D[:100, :100, :]  # 前100行列所有通道
    # 修改 D 的前100行列为绿色(0,255,0)
    E[:] = (0, 255, 0)
    F = np.zeros((7, 7), np.uint8)
    F = np.ones((7, 7), np.uint8)
    F = np.eye(3, 3, dtype=np.uint8)
    # print(F)
    # cv2.imshow("D", D)
    # cv2.imshow("E", E)
    # cv2.waitKey()

if __name__ == "__main__":
    main()
    