#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


void disect(const Mat &image)
{
    vector<vector<Point> > contours;

    findContours(image, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);

    for (vector<vector<Point> >::iterator it = contours.begin(); it != contours.end(); ++it) {
        for (vector<Point>::iterator pt = it->begin(); pt != it->end(); ++pt) {
            cout << pt << "  ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " filename.jpg" << endl;
        return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

    if (!image.data) {
        cout << "Could not open or find image" << endl;
        return -1;
    }
    
    disect(image);

    cout << "got it, boss" << endl;

    return 0;
}


