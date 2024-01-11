#include "Detection.h"

Detection::Detection(const string& filePath)
    : CommonProcesses(filePath)
{
}

ostream& operator<<(ostream& os, const Detection& detection) {
    os << "Features:" << endl;

    if (!detection.getLines().empty()) {
        for (const auto& line : detection.getLines()) {
            os << "Line: (" << line[0] << ", " << line[1] << ") to ("
                << line[2] << ", " << line[3] << ")" << endl;
        }
    }
    if (!detection.getCorners().empty()) {
        for (const auto& corner : detection.getCorners()) {
            os << "Corner: (" << corner.x << ", " << corner.y << ")" << endl;
        }
    }
    return os;
}

void Detection::readFeaturesFromFile(const string& filePath) {
    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        throw runtime_error("Error: Unable to open the input file.");
    }

    if (!lines.empty() || !cornerPoints.empty()) {
        lines.clear();
        cornerPoints.clear();

        string lineData;

        while (getline(inputFile, lineData)) {
            if (lineData.find("Line:") != string::npos) {
                Vec4i line;
                istringstream iss(lineData);

                string dummy;
                char c;
                iss >> dummy >> c >> line[0] >> dummy >> line[1] >> dummy >> c >> line[2] >> dummy >> line[3];

                lines.push_back(line);
            }
            else if (lineData.find("Corner:") != string::npos) {
                Point2f corner;
                istringstream iss(lineData);

                string dummy;
                char c;
                iss >> dummy >> c >> corner.x >> dummy >> corner.y;

                cornerPoints.push_back(corner);
            }
        }
    }

    cout << "Features read from file: " << filePath << endl;
    inputFile.close();
}

void Detection::writeFeaturesToFile(const string& filePath) {

    ofstream outputFile(filePath);

    if (!outputFile.is_open()) {
        throw runtime_error("Error: Unable to open the output file.");
    }

    if (!lines.empty()) {
        for (const auto& line : lines) {
            outputFile << "Line: (" << line[0] << ", " << line[1] << ")  (" << line[2] << ", " << line[3] << ")" << endl;
        }
    }
    if (!cornerPoints.empty()) {
        for (const auto& corner : cornerPoints) {
            outputFile << "Corner: (" << corner.x << ", " << corner.y << ")" << endl;
        }
    }

    cout << "Features written to file: " << filePath << endl;
}

void Detection::visualizeFeatures() {
    if (lines.empty()) {
        cout << "No features (lines) detected to visualize." << endl;
    }
    else {

        GrayToRGB();

        for (const auto& line : lines) {

            Point startPoint(line[0], line[1]);
            Point endPoint(line[2], line[3]);

            cv::line(getRgbData(), startPoint, endPoint, Scalar(0, 0, 255), 1);
        }

        showRgbOnViewer();
    }
    if (cornerPoints.empty()) {
        cout << "No features (corners) detected to visualize." << endl;
    }
    else {

        GrayToRGB();

        for (const auto& corner : cornerPoints) {
            circle(getRgbData(), corner, 5, Scalar(255, 0, 0), 1);
        }

        showRgbOnViewer();
    }
}

const vector<Vec4i>& Detection::getLines() const {
    return lines;
}

void Detection::setLines(const vector<Vec4i>& newLines) {
    lines = newLines;
}

const vector<Point2f>& Detection::getCorners() const {
    return cornerPoints;
}

void Detection::setCorners(const vector<Point2f>& newCorners) {
    cornerPoints = newCorners;
}

