#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <opencv2/opencv.hpp>

namespace seqslam{
class Preprocessor{
public:
    cv::Mat preprocess(const cv::Mat& image);
};
} // namespace seqslam

#endif // PREPROCESSOR_H