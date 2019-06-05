import cv2

if __name__ == "__main__":
    image_path = './car.jpg'
    image = cv2.imread(image_path)
    if image is None:
        print("Could not open image: {}".format(image_path))
    else:
        cv2.namedWindow('Display window', cv2.WINDOW_NORMAL)
        cv2.imshow('Display window', image)
        cv2.waitKey()