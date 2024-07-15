#ifndef DIFFERENCE_CALCULATOR_H
#define DIFFERENCE_CALCULATOR_H

#include <opencv2/opencv.hpp>

namespace seqslam{
class DifferenceCalculator{
public:
    double calculateDifference(const cv::Mat& image1, const cv::Mat& image2);
};
} // namespace seqslam

#endif // DIFFERENCE_CALCULATOR_H