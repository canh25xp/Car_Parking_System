import cv2
import urllib.request
import numpy as np
from concurrent.futures import ProcessPoolExecutor

url='http://192.168.137.30/cam-hi.jpg'
im=None

def run1():
    cv2.namedWindow("live transmission", cv2.WINDOW_AUTOSIZE)
    while True:
        img_resp=urllib.request.urlopen(url)
        imgnp=np.array(bytearray(img_resp.read()),dtype=np.uint8)
        im = cv2.imdecode(imgnp,-1)

        cv2.imshow('live transmission',im)
        key=cv2.waitKey(5)
        if key==ord('q'):
            break

    cv2.destroyAllWindows()


if __name__ == '__main__':
    print("Live Stream Started")
    with ProcessPoolExecutor() as executer:
            f1=executer.submit(run1)