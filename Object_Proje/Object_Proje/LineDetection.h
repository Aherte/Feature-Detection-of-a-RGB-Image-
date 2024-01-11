/**
 * @file LineDetection.h
 * @brief Definition of the LineDetection class.
 */
#pragma once
#include "Detection.h"
 /**
  * @class LineDetection
  * @brief A class for line detection based on the Detection class.
  */

class LineDetection : public Detection
{

private:
    int Canny_lowThreshold; /**< Canny edge detection low threshold. */
    int ratio; /**< Canny edge detection ratio. */
    int kernel_size; /**< Canny edge detection kernel size. */
    const int max_lowThreshold = 200; /**< Maximum Canny edge detection low threshold. */
    int Hough_threshold; /**< Hough line detection threshold. */
    int Hough_MinLineLength; /**< Hough line detection minimum line length. */
    int Hough_MaxLineGap; /**< Hough line detection maximum line gap. */
    static int objectCounter; /**< Static counter to keep track of LineDetection objects. */

public:
        /**
     * @brief Constructor for LineDetection.
     * @param filePath The path to the image file for line detection.
     * @param C_Thres Canny edge detection threshold.
     * @param C_ratio Canny edge detection ratio.
     * @param C_kernel Canny edge detection kernel size.
     * @param H_Thres Hough line detection threshold.
     * @param H_LineL Hough line detection minimum line length.
     * @param H_LineG Hough line detection maximum line gap.
     */
    LineDetection(const string& filePath, int C_Thres = 50, int C_ratio = 3, int C_kernel = 3, int H_Thres = 50, int H_LineL = 50, int H_LineG = 10);

        /**
     * @brief Performs line detection on the image.
     */
    void detectLines();

    // Getter and setter methods for private members

    int getCannyLowThreshold() const;
    void setCannyLowThreshold(int value);

    int getRatio() const;
    void setRatio(int value);

    int getKernelSize() const;
    void setKernelSize(int value);

    int getMaxLowThreshold() const;

    int getHoughThreshold() const;
    void setHoughThreshold(int value);

    int getHoughMinLineLength() const;
    void setHoughMinLineLength(int value);

    int getHoughMaxLineGap() const;
    void setHoughMaxLineGap(int value);

    static int getObjectCounter();
    static void setObjectCounter(int counter);
        /**
     * @brief Destructor for LineDetection.
     */
    ~LineDetection();
};