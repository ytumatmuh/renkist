#include<opencv2/opencv.hpp>
#include<iostream>
#include<sstream>

using namespace std;
using namespace cv;


int main() {
    char* video_path = "./../video_data/vid.mp4";
    Videocapture v_capture("./../video_data/vid.mp4");
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