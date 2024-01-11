#include "LineDetection.h"

int LineDetection::objectCounter = 0;

LineDetection::LineDetection(const string& filePath, int C_Thres, int C_ratio, int C_kernel, int H_Thres, int H_LineL, int H_LineG) :
    Detection(filePath),
    ratio(C_ratio),
    kernel_size(C_kernel),
    Hough_threshold(H_Thres),
    Hough_MinLineLength(H_LineL),
    Hough_MaxLineGap(H_LineG)
{
    setCannyLowThreshold(C_Thres);
    objectCounter++;
    cout << "LineDetection object is created" << endl << "Number of LineDetection object: " << objectCounter << endl;
}

void LineDetection::detectLines() {

    vector<Vec4i> tempLines;

    filterNoise();

    rgbToGrayscale();

    Canny(getRgbData(), getRgbData(), Canny_lowThreshold, Canny_lowThreshold * ratio, kernel_size);

    HoughLinesP(getRgbData(), tempLines, 1, CV_PI / 180, Hough_threshold, Hough_MinLineLength, Hough_MaxLineGap);

    setLines(tempLines);

}

int LineDetection::getCannyLowThreshold() const {
    return Canny_lowThreshold;
}

void LineDetection::setCannyLowThreshold(int value) {
    if (value >= 0 && value <= max_lowThreshold) 
    { 
        Canny_lowThreshold = value; 
    }
    else {
        throw runtime_error("Error: Canny low threshold out of range");
    }
}

int LineDetection::getRatio() const {
    return ratio;
}

void LineDetection::setRatio(int value) {
    ratio = value;
}

int LineDetection::getKernelSize() const {
    return kernel_size;
}

void LineDetection::setKernelSize(int value) {
    kernel_size = value;
}

int LineDetection::getMaxLowThreshold() const {
    return max_lowThreshold;
}

int LineDetection::getHoughThreshold() const {
    return Hough_threshold;
}

void LineDetection::setHoughThreshold(int value) {
    Hough_threshold = value;
}

int LineDetection::getHoughMinLineLength() const {
    return Hough_MinLineLength;
}

void LineDetection::setHoughMinLineLength(int value) {
    Hough_MinLineLength = value;
}

int LineDetection::getHoughMaxLineGap() const {
    return Hough_MaxLineGap;
}

void LineDetection::setHoughMaxLineGap(int value) {
    Hough_MaxLineGap = value;
}

int LineDetection::getObjectCounter() {
    return objectCounter;
}

void LineDetection::setObjectCounter(int counter) {
    objectCounter = counter;
}

LineDetection::~LineDetection() {
    cout << "LineDetection object is erased" << endl;
    objectCounter--;
    cout << "Number of LineDetection object left: " << objectCounter << endl;
}