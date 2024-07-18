#ifndef SEQUENCE_MATCHER_H
#define SEQUENCE_MATCHER_H

#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

namespace seqslam{
class SequenceMatcher{
public: 
    SequenceMatcher(int sequence_legth);

private:
    int sequence_length;

public:
    double calculateDifference(const cv::Mat& image1, const cv::Mat& image2);
    int findBestMatch(const std::vector<cv::Mat>& images, const cv::Mat& query);
    int findSequence(const std::vector<cv::Mat>& images, const cv::Mat& query);
};
} // namespace seqslam

#endif // SEQUENCE_MATCHER_H