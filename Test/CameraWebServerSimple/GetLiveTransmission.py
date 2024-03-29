import cv2
from urllib.request import urlopen
import numpy as np

url = 'http://192.168.137.128/cam-hi.jpg'

def run():
    cv2.namedWindow("live transmission", cv2.WINDOW_AUTOSIZE)
    while True:
        img_resp = urlopen(url)
        imgnp = np.array(bytearray(img_resp.read()), dtype=np.uint8)
        img = cv2.imdecode(imgnp, cv2.IMREAD_COLOR)

        cv2.imshow('live transmission', img)
        key = cv2.waitKey(5)
        if key == ord('q'):
            break

    cv2.destroyAllWindows()


def getStillImage():
    img_resp = urlopen(url)
    imgnp = np.array(bytearray(img_resp.read()), dtype=np.uint8)
    img = cv2.imdecode(imgnp, cv2.IMREAD_COLOR)

    cv2.imshow('live transmission', img)
    cv2.waitKey(0)

    cv2.destroyAllWindows()  


if __name__ == '__main__':
    print("Live Stream Started")
    run()