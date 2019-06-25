import cv2

def main():
    image_path1 = './japan.jpg'
    image_path2 = './beach.jpg'
    src1 = cv2.imread(image_path1)
    src2 = cv2.imread(image_path2)
    if src1 is None or src2 is None:
        print("Can't open images!")
        return
    alpha = 0.5
    beta = 1 - alpha
    dst = cv2.addWeighted(src1, alpha, src2, beta, 0.0)
    cv2.imshow("dst", dst)
    cv2.waitKey()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
