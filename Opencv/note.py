import cv2 as cv
import sys

def show_image(path):
    """show a picture"""
    img = cv.imread(cv.samples.findFile(path))

    if img is None:
        sys.exit("Could not read the image.")

    cv.imshow("Display window", img)
    k = cv.waitKey(0)

    if k == ord("s"):
        cv.imwrite("starry_night.png", img)
    elif k == ord("q"):
        sys.exit("Done")

if __name__ == "__main__":
    show_image("./img/p001.jpg")