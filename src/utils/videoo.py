import cv2

vidcap = cv2.VideCapture('/../../video_data/vid.mp4')
success, image = vidcap.read() 
count = 1 
while success:
    cv.imwrite("/../../image_data/image_%d.jpg" % count, image)
    print('Saved Image %', count)
    count += 1
    success, image = vidcap.read()

vidcap.release()
