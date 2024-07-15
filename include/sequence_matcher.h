#ifndef SEQUENCE_MATCHER_H
#define SEQUENCE_MATCHER_H

#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

namespace seqslam{
class SequenceMatcher{
public:
    int findBestMatch(const std::vector<cv::Mat>& images, const cv::Mat& query);
};
} // namespace seqslam

#endif // SEQUENCE_MATCHER_H