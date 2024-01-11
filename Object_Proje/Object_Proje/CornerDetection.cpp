#include "CornerDetection.h"
int CornerDetection::objectCounter = 0;

CornerDetection::CornerDetection(const string& filePath, int Thresh, int bs, int as, double K)
    : Detection(filePath),
    blockSize(bs),
    apertureSize(as),
    k(K)
{
    setThresh(Thresh);
    objectCounter++;
    cout << "CornerDetection object is created" << endl << "Number of CornerDetection object: " << objectCounter << endl;
}

void CornerDetection::detectCorners() {

    rgbToGrayscale();

    Mat temp = getRgbData();

    cornerHarris(temp, temp, blockSize, apertureSize, k);

    normalize(temp, temp, 0, 255, NORM_MINMAX, CV_32FC1, Mat());

    Mat temp_scaled;

    convertScaleAbs(temp, temp_scaled);

    vector<Point2f> TempCornerPoints = getCorners();

    for (int i = 0; i < temp.rows; i++)
    {
        for (int j = 0; j < temp.cols; j++)
        {
            if ((int)temp.at<float>(i, j) > thresh)
            {
                TempCornerPoints.push_back(Point2f(j, i));
            }
        }
    }
    setCorners(TempCornerPoints);
    setRgbData(temp_scaled);
}

int CornerDetection::getObjectCounter() {
    return objectCounter;
}

void CornerDetection::setObjectCounter(int value) {
    objectCounter = value;
}

int CornerDetection::getBlockSize() const {
    return blockSize;
}

void CornerDetection::setBlockSize(int value) {
    blockSize = value;
}

int CornerDetection::getApertureSize() const {
    return apertureSize;
}

void CornerDetection::setApertureSize(int value) {
    apertureSize = value;
}

double CornerDetection::getK() const {
    return k;
}

void CornerDetection::setK(double value) {
    k = value;
}

int CornerDetection::getThresh() const {
    return thresh;
}

void CornerDetection::setThresh(int value) {
    if (value >= 0 && value <= max_thresh)
    {
        thresh = value;
    }
    else {
        throw runtime_error("Error: Corner thresh value out of range");
    }
}

int CornerDetection::getMaxThresh() const {
    return max_thresh;
}

CornerDetection::~CornerDetection() {
    cout << "CornerDetection object is erased" << endl;
    objectCounter--;
    cout << "Number of CornerDetection object left: " << objectCounter << endl;
}