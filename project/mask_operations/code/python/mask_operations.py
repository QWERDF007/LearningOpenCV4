import cv2
import numpy as np
import time


def saturated(sum_value):
    if sum_value > 255:
        sum_value = 255
    if sum_value < 0:
        sum_value = 0
    return sum_value


def sharpen(image):
    height, width = image.shape[:2]
    channels = None
    if len(image.shape) == 3:
        channels = image.shape[2]
    dst = np.zeros(image.shape, dtype=np.uint8)
    for i in range(1, height - 1):
        for j in range(1, width - 1):
            if channels is None:
                sum_value = 5 * image[i, j] - image[i - 1, j] - image[i + 1, j] \
                            - image[i, j - 1] - image[i, j - 1]
                dst[i, j] = saturated(sum_value)
            else:
                for k in range(channels):
                    sum_value = 5 * image[i, j, k] - image[i - 1, j, k] - image[i + 1, j, k] \
                                - image[i, j - 1, k] - image[i, j + 1, k]
                    dst[i, j, k] = saturated(sum_value)
    return dst


def main():
    filepath = './car.jpg'
    src = cv2.imread(filepath)
    if src is None:
        print("Can't open image:", filepath)
        return -1
    t = time.time()
    dst0 = sharpen(src)
    print('Hand written function sharpen elapsed time: {:.4f}'.format(time.time() - t))

    t = time.time()
    kernel = np.array([[0, -1, 0], [-1, 5, -1], [0, -1, 0]], dtype=np.float32)
    dst1 = cv2.filter2D(src, -1, kernel=kernel)
    print('Build-in function filter2D elapsed time: {:.4f}'.format(time.time() - t))
    cv2.imshow('src', src)
    cv2.imshow('sharpen', dst0)
    cv2.imshow('filter2D', dst1)
    cv2.waitKey()


if __name__ == "__main__":
    main()
