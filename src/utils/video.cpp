#include<opencv2/opencv.hpp>
#include<iostream>
#include<sstream>

using namespace std;
using namespace cv;


int main() {
    const char* video_path = "./../video_data/vid.mp4";
    VideoCapture v_capture(video_path);
    if (!v_capture.isOpened()) {
        cout << "Error opening video file" << endl;
        return -1;
    }   

    int frame_number = 0;
    Mat frame;
    /*read frame&save*/
    while (v_capture.read(frame)) {
        stringstream ss;
        ss << "frame_" << frame_number << ".jpg";
        string filename = ss.str();
        imwrite(filename, frame);
        frame_number++;
    }

    cout << "video has been saved as frames" << endl;
    return 0;
}