#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void Gaussian_Noise(Mat& img, Mat& noisy_img) {

	double mean = 0.0;
	double std = 25.0;
	
	Mat noise(img.rows, img.cols, img.type());
	randn(noise, mean, std);
	noisy_img = img + noise;
}

void Salt_Pepper_Noise(Mat& img) {

	double saltProb = 0.02;
	double pepperProb = 0.02;
	RNG rng;

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {

			float rand_value = rng.uniform(0.0f, 1.0f);

			if (rand_value < saltProb) {
				 img.at<Vec3b>(i, j) = Vec3b(255, 255, 255);
			}
			else if (rand_value > 1.0 - pepperProb) {
				 img.at<Vec3b>(i, j) = Vec3b(0,0,0);
			}
		}
	}


}



int main() {

	Mat image = imread("C:/Users/LENOVO/Documents/python d/image_data/image_1008.jpg");

	if (image.empty())
	{
		cout << "Görüntü yüklenemedi.";
		return 1;
	}

	Mat gaussian_img;

	imshow("Orijinal görüntü:", image);
	//imwrite("C:/Users/LENOVO/Documents/python d/gürültü eklenmiş fotoğraflar/original_image.jpg", image);
	waitKey(0);

	Gaussian_Noise(image,gaussian_img);
	imshow("Gaussian Noise Image", gaussian_img);
	//imwrite("C:/Users/LENOVO/Documents/python d/gürültü eklenmiş fotoğraflar/gaussian_noise_image.jpg",gaussian_img);
	waitKey(0);

	Salt_Pepper_Noise(image);
	imshow("Salt Pepper Noise Image",image);
	//imwrite("C:/Users/LENOVO/Documents/python d/gürültü eklenmiş fotoğraflar/salt_pepper_noise_image.jpg", image);
	waitKey(0);

}
