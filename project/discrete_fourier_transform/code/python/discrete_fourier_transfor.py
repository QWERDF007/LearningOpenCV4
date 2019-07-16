import cv2
import numpy as np

def main():
    img_path = "./car.jpg"
    src = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
    if src is None:
        print("Can't load image!")
        return -1
    rows, cols = src.shape
    m = cv2.getOptimalDFTSize(rows)
    n = cv2.getOptimalDFTSize(cols)
    # 0填充至DFT最佳大小，2/3/5的倍数
    padded = cv2.copyMakeBorder(src, 0, m - rows, 0, n - cols, 
                                cv2.BORDER_CONSTANT, value=[0,0,0])
    planes = [np.float32(padded), np.zeros(padded.shape, np.float32)]
    complex_img = cv2.merge(planes)  # 合成双通道以容纳复值图像
    
    complex_img = cv2.dft(complex_img)
    planes = cv2.split(complex_img)  # planes[0] = Re(DFT(I)), planes[1] = Im(DFT(I))
    magnitude_img = cv2.magnitude(planes[0], planes[1])  # magnitude = sqrt(Re^2 + Im^2)
    
    # 用log(1+mag)压缩，便于显示
    magnitude_img += 1
    magnitude_img = cv2.log(magnitude_img)
    
    mag_rows, mag_cols = magnitude_img.shape
    # crop
    magnitude_img = magnitude_img[0:(mag_rows & -2), 0:(mag_cols & -2)]
    cx = int(mag_rows/2)
    cy = int(mag_cols/2)
    
    # 重新排列使得原点在图像中心
    q0 = magnitude_img[0:cx, 0:cy]
    q1 = magnitude_img[cx:cx+cx, 0:cy]
    q2 = magnitude_img[0:cx, cy:cy+cy]
    q3 = magnitude_img[cx:cx+cx, cy:cy+cy]
    
    tmp = q0.copy()
    magnitude_img[0:cx, 0:cy] = q3
    magnitude_img[cx:cx+cx, cy:cy+cy] = tmp
    tmp = q1.copy()
    magnitude_img[cx:cx+cx, 0:cy] = q2
    magnitude_img[0:cx, cy:cy+cy] = tmp
    
    cv2.normalize(magnitude_img, magnitude_img, 0, 1, cv2.NORM_MINMAX)
    
    cv2.imshow("Src", src)
    cv2.imshow("Spectrum magnitude", magnitude_img)
    cv2.waitKey()
    
    
if __name__ == "__main__":
    main()