/**
 * @file CornerDetection.h
 * @brief Definition of the CornerDetection class.
 */

#pragma once
#include "Detection.h"

 /**
  * @class CornerDetection
  * @brief A class for corner detection, extending the Detection class.
  */
class CornerDetection : public Detection
{
private:
    static int objectCounter; /**< Static counter to keep track of CornerDetection objects. */
    int blockSize; /**< Size of the neighborhood for corner detection. */
    int apertureSize; /**< Aperture parameter for the Sobel operator. */
    double k; /**< Harris detector free parameter. */
    int thresh; /**< Threshold for corner detection. */
    const int max_thresh = 255; /**< Maximum threshold for corner detection. */

public:
    /**
     * @brief Constructor for CornerDetection.
     * @param filePath The path to the image file for corner detection.
     * @param Thresh Threshold for corner detection.
     * @param bs Size of the neighborhood for corner detection.
     * @param as Aperture parameter for the Sobel operator.
     * @param K Harris detector free parameter.
     */
    CornerDetection(const string& filePath, int Thresh = 150, int bs = 2, int as = 3, double K = 0.04);

    /**
     * @brief Destructor for CornerDetection.
     */
    ~CornerDetection();

    /**
     * @brief Performs corner detection on the image.
     */
    void detectCorners();

    /**
     * @brief Gets the static counter for CornerDetection objects.
     * @return The current value of the static object counter.
     */
    static int getObjectCounter();

    /**
     * @brief Sets the static counter for CornerDetection objects.
     * @param counter The new value for the static object counter.
     */
    static void setObjectCounter(int counter);

    // Getter and setter methods for private members

    /**
     * @brief Gets the size of the neighborhood for corner detection.
     * @return The size of the neighborhood.
     */
    int getBlockSize() const;

    /**
     * @brief Sets the size of the neighborhood for corner detection.
     * @param blockSize The new size of the neighborhood.
     */
    void setBlockSize(int blockSize);

    /**
     * @brief Gets the aperture parameter for the Sobel operator.
     * @return The aperture parameter value.
     */
    int getApertureSize() const;

    /**
     * @brief Sets the aperture parameter for the Sobel operator.
     * @param apertureSize The new aperture parameter value.
     */
    void setApertureSize(int apertureSize);

    /**
     * @brief Gets the Harris detector free parameter.
     * @return The Harris detector free parameter value.
     */
    double getK() const;

    /**
     * @brief Sets the Harris detector free parameter.
     * @param k The new Harris detector free parameter value.
     */
    void setK(double k);

    /**
     * @brief Gets the threshold for corner detection.
     * @return The threshold value.
     */
    int getThresh() const;

    /**
     * @brief Sets the threshold for corner detection.
     * @param thresh The new threshold value.
     */
    void setThresh(int thresh);

    /**
     * @brief Gets the maximum threshold for corner detection.
     * @return The maximum threshold value.
     */
    int getMaxThresh() const;
};
