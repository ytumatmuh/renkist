import cv2

vidcap = cv2.VideoCapture('video_data/vid.mp4')
success, image = vidcap.read() 
count = 1 
while success:
    cv2.imwrite("image_data/image_%d.jpg" % count, image)
    print('Saved Image %', count)
    count += 1
    success, image = vidcap.read()
    
print('Toplam fotoğraf sayısı: ', count-1)

vidcap.release()
