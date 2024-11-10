import cv2
import os

vidcap = cv2.VideoCapture('../../video_data/vid.mp4')
success, image = vidcap.read() 
count = 1 
while success:
    cv2.imwrite("../../image_data/image_%d.jpg" % count, image)
    print('Saved Image %', count)
    count += 1
    success, image = vidcap.read()
    
print('Toplam fotoğraf sayısı: ', count-1)

vidcap.release()
#delete_images()



 #def delete_images():
  #  directory = "../../image_data"
   # for filename in os.listdir(directory):
    #    if filename.endswith(".jpg"):
     #       os.remove(os.path.join(directory, filename))
    #print("Tüm fotoğraflar silindi.")
 
#delete_images() fotoları silmek için aktif et
