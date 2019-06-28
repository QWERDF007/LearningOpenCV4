import cv2
import numpy as np


def main():
    alpha = 1.5
    beta = 25
    image_path = './car.jpg'
    src = cv2.imread(image_path)
    if src is None:
        print("Can't load image!")
        return
    dst = np.zeros(src.shape, np.uint8)
    # for row in range(src.shape[0]):
    #     for col in range(src.shape[1]):
    #         for c in range(src.shape[2]):
    #             dst[row, col, c] = np.clip(alpha * src[row, col, c] + beta, 0, 255)
    dst = cv2.convertScaleAbs(src, alpha=alpha, beta=beta)
    cv2.imshow('src', src)
    cv2.imshow('dst', dst)
    cv2.waitKey()


if __name__ == "__main__":
    main()