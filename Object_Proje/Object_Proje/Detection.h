/**
 * @file Detection.h
 * @brief Definition of the Detection class.
 */

#pragma once
#include "CommonProcesses.h"

 /**
  * @class Detection
  * @brief A class for general detection processes, extending CommonProcesses.
  */
class Detection : public CommonProcesses
{
	friend ostream& operator<<(ostream& os, const Detection& detection);

private:
	vector<Vec4i> lines; /**< Detected lines. */
	vector<Point2f> cornerPoints; /**< Detected corner points. */

public:
	/**
	 * @brief Default constructor for Detection.
	 * @param filePath The path to the file for detection.
	 */
	Detection(const string& filePath = {});

	/**
	 * @brief Writes features to a file.
	 * @param filePath The path to the file where features will be written.
	 */
	void writeFeaturesToFile(const string& filePath);

	/**
	 * @brief Visualizes the detected features.
	 */
	void visualizeFeatures();

	/**
	 * @brief Reads features from a file.
	 * @param filePath The path to the file from which features will be read.
	 */
	void readFeaturesFromFile(const string& filePath);

	/**
	 * @brief Gets the detected lines.
	 * @return The vector of detected lines.
	 */
	const vector<Vec4i>& getLines() const;

	/**
	 * @brief Sets the detected lines.
	 * @param newLines The new vector of detected lines.
	 */
	void setLines(const vector<Vec4i>& newLines);

	/**
	 * @brief Gets the detected corner points.
	 * @return The vector of detected corner points.
	 */
	const vector<Point2f>& getCorners() const;

	/**
	 * @brief Sets the detected corner points.
	 * @param newCorners The new vector of detected corner points.
	 */
	void setCorners(const vector<Point2f>& newCorners);
};
