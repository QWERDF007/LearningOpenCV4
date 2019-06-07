import cv2

if __name__ == "__main__":
    image_path = './car.jpg'
    image = cv2.imread(image_path)
    if image is not None:      
        gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        cv2.imwrite("result.jpg", gray_image)
    else:
        print("Could not open image: {}".format(image_path))