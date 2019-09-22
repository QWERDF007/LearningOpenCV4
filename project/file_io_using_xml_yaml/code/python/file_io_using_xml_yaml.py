import cv2
import numpy as np

if __name__ == "__main__":
    filename = "readme.xml"
    # READ
    fs = cv2.FileStorage(filename, cv2.FileStorage_WRITE)
    fs.write('ones', np.ones([3, 3], np.uint8))
    fs.write("num_int", 1)
    fs.write("num_float", 2.)
    fs.write("map", (1, 2, 3, 4))
    fs.release()

    # WRITE
    fs = cv2.FileStorage(filename, cv2.FileStorage_READ)
    node_ones = fs.getNode("ones")
    num_int = fs.getNode("num_int").real()
    node_map = fs.getNode("map").mat()
    print(node_ones.mat())
    print(num_int)
    print(node_map)
    fs.release()
