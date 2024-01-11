/**
 * @file CommonProcesses.h
 * @brief Header file for the CommonProcesses class.
 */

#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp> 
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;
using namespace cv;

/**
 * @class CommonProcesses
 * @brief A class for common image processing operations.
 */
class CommonProcesses {
private:
    Mat rgbData; ///< Holds the RGB image data.

public:
    /**
     * @brief Constructor for CommonProcesses class.
     * @param filePath The path to the image file.
     */
    CommonProcesses(const string& filePath);

    /**
     * @brief Destructor for CommonProcesses class.
     */
    ~CommonProcesses();

    /**
     * @brief Gets the RGB image data.
     * @return The RGB image data as a Mat object.
     */
    Mat getRgbData() const;

    /**
     * @brief Sets the RGB image data.
     * @param newRgbData The new RGB image data to set.
     */
    void setRgbData(const Mat& newRgbData);

    /**
     * @brief Reads RGB data from a file.
     * @param filePath The path to the image file.
     */
    void readRgbFromFile(const string& filePath);

    /**
     * @brief Writes RGB data to a file.
     * @param filePath The path to save the image file.
     */
    void writeRgbToFile(const string& filePath);

    /**
     * @brief Displays RGB data on a viewer.
     */
    void showRgbOnViewer();

    /**
     * @brief Rescales the RGB data.
     * @param scaleFactor The scale factor for resizing (default is 1).
     */
    void rescale(double scaleFactor = 1);

    /**
     * @brief Applies a noise filter to the RGB data.
     * @param filterValue The size of the filter (default is 5).
     */
    void filterNoise(int filterValue = 5);

    /**
     * @brief Converts RGB to grayscale.
     */
    void rgbToGrayscale();

    /**
     * @brief Converts grayscale to RGB.
     */
    void GrayToRGB();
};
