import cv2
import numpy as np
import time

if __name__ == "__main__":
    image_path = './scene.jpg'
    image = cv2.imread(image_path, cv2.IMREAD_COLOR)
    if image is not None:
        table = np.empty(256, dtype=np.uint8)
        for i in range(256):
            table[i] = i // 10 * 10

        dst_image = image.copy()
        print("image shape:", image.shape)
        start = time.clock()
        for row in range(image.shape[0]):
            for col in range(image.shape[1]):
                for channel in range(image.shape[2]):
                    dst_image[row, col, channel] = table[dst_image[row, col, channel]]
        # element 修改成功但 dst_image 没变化
        # for element in dst_image.flat:
        #     element = element // 10 * 10
        # print(dst_image)
        end = time.clock()
        print('time: {}s'.format(end - start))
        # cv2.imshow('src', image)
        # cv2.imshow('dst', dst_image)
        # cv2.waitKey()
