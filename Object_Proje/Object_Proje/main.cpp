/**
 * @file main.cpp
 * @brief Main file for executing LineDetection and CornerDetection examples.
 */

#include "LineDetection.h"
#include "CornerDetection.h"

 /**
  * @brief Main function to demonstrate LineDetection and CornerDetection.
  * @return 0 on successful execution.
  */
int main() {
    try {
        // Line Detection Example
        LineDetection lineDetection("image.png");

        lineDetection.detectLines();
        lineDetection.showRgbOnViewer();
        lineDetection.visualizeFeatures();
        lineDetection.writeFeaturesToFile("C:/Users/aeren/OneDrive/Masaüstü/lines.txt");
        lineDetection.readFeaturesFromFile("C:/Users/aeren/OneDrive/Masaüstü/lines.txt");
        cout << lineDetection;

        // Corner Detection Example
        CornerDetection cornerDetection("image.png");
        cornerDetection.detectCorners();
        cornerDetection.visualizeFeatures();
        cornerDetection.writeFeaturesToFile("C:/Users/aeren/OneDrive/Masaüstü/corner.txt");
        cornerDetection.readFeaturesFromFile("C:/Users/aeren/OneDrive/Masaüstü/corner.txt");
        cout << cornerDetection;

    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
