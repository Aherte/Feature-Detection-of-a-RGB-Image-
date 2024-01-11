# Computer Vision Project

This project demonstrates basic computer vision operations using OpenCV, with a focus on line and corner detection.

## Overview

The project includes two main components:

1. **Line Detection:** Utilizes the LineDetection class to detect lines in an image. It showcases the detection process, visualization of features, and the ability to save and load feature data.

2. **Corner Detection:** Uses the CornerDetection class to identify corners in an image. Similar to line detection, it demonstrates the corner detection process, feature visualization, and feature data storage functionalities.

## Getting Started

To run the project, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/computer-vision-project.git
    ```

2. Build the project using your preferred build system.

3. Run the executable:

    ```bash
    ./computer-vision-project
    ```

## Dependencies

The project relies on the following libraries:

- [OpenCV](https://opencv.org/): An open-source computer vision and machine learning software library.

## Usage

The `main.cpp` file in the project demonstrates how to use the LineDetection and CornerDetection classes. It loads an image, performs detection, visualizes features, and saves/loads feature data.

```cpp
// Include necessary headers
#include "LineDetection.h"
#include "CornerDetection.h"

int main() {
    try {
        // Line Detection Example
        LineDetection lineDetection("image.png");

        lineDetection.detectLines();
        lineDetection.showRgbOnViewer();
        lineDetection.visualizeFeatures();
        lineDetection.writeFeaturesToFile("lines.txt");
        lineDetection.readFeaturesFromFile("lines.txt");
        cout << lineDetection;

        // Corner Detection Example
        CornerDetection cornerDetection("image.png");
        cornerDetection.detectCorners();
        cornerDetection.visualizeFeatures();
        cornerDetection.writeFeaturesToFile("corner.txt");
        cornerDetection.readFeaturesFromFile("corner.txt");
        cout << cornerDetection;

    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
