#include "CommonProcesses.h"

CommonProcesses::CommonProcesses(const string& filePath) 
{
    readRgbFromFile(filePath);
}

void CommonProcesses::readRgbFromFile(const string& filePath) {
    // Read RGB data from file
    rgbData = imread(filePath, IMREAD_UNCHANGED);
    if (rgbData.empty()) {
        throw runtime_error("Error: Unable to read image file or empty image");
    }
}

void CommonProcesses::writeRgbToFile(const std::string& filePath) {
    // Write RGB data to file
    if (!rgbData.empty()) {
        imwrite(filePath, rgbData);
    }
    else {
        throw runtime_error("Error: Unable to read image file or empty image");
    }
}

void CommonProcesses::showRgbOnViewer() {
    // Display RGB data on the viewer
    if (!rgbData.empty()) {

            imshow("RGB Viewer", rgbData);
            waitKey(0); 
    }
    else {
        throw runtime_error("Error: Unable to read image file or empty image");
    }
}

void CommonProcesses::rescale(double scaleFactor) {
    // Rescale the RGB data
    if (!rgbData.empty()) {

        resize(rgbData, rgbData, Size(), scaleFactor, scaleFactor); // resize and overwrite the rgbdata by scaleFactor

        normalize(rgbData, rgbData, 0, 255, NORM_MINMAX); // scale the pixel values to (0-255) interval
        rgbData.convertTo(rgbData, CV_8U); // convert pixel values to unsigned 8 bits value
    }
    else {
        throw runtime_error("Error: Unable to read image file or empty image");
    }
}

void CommonProcesses::filterNoise(int filterValue) {
    if (!rgbData.empty()) {
        switch (filterValue) {
        case 3:
            GaussianBlur(rgbData, rgbData, Size(3, 3), 0);
            break;
        case 4:
            GaussianBlur(rgbData, rgbData, Size(4, 4), 0);
            break;
        case 5:
            GaussianBlur(rgbData, rgbData, Size(5, 5), 0);
            break;
        case 6:
            GaussianBlur(rgbData, rgbData, Size(6, 6), 0);
            break;
        case 7:
            GaussianBlur(rgbData, rgbData, Size(7, 7), 0);
            break;
        default:
            cout << "enter 3,4,5,6 or 7 to filter" << endl;
            break;
        }
 
    }
    else {
        throw runtime_error("Error: Unable to read image file or empty image");
    }
}

void CommonProcesses::rgbToGrayscale() {
    // Convert RGB to grayscale
    if (!rgbData.empty()) {
        cvtColor(rgbData, rgbData, COLOR_BGR2GRAY);
    }
    else {
        throw runtime_error("Error: Unable to read image file or empty image");
    }
}

Mat CommonProcesses::getRgbData() const {
    return rgbData;
}

void CommonProcesses::setRgbData(const Mat& newRgbData) {
    rgbData = newRgbData;
}

void CommonProcesses::GrayToRGB() {
    if (!rgbData.empty()) {
        cvtColor(rgbData, rgbData, COLOR_GRAY2BGR);
    }
    else {
        throw runtime_error("Error: Unable to read image file or empty image");
    }
}

CommonProcesses::~CommonProcesses() {
    // rgbData Mat object already calls its own destructor,
    // so no need to do anything special.
}