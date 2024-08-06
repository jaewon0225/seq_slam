#include "sequence_matcher.h"

namespace seqslam {
double SequenceMatcher::calculateDifference(const cv::Mat &image1, const cv::Mat &image2) {
    cv::Mat diff;
    cv::absdiff(image1, image2, diff);
    return cv::sum(diff)[0];
} 

int SequenceMatcher::findBestMatch(const std::vector<cv::Mat>& images, const cv::Mat& query) {

}

int SequenceMatcher::findSequence(const std::vector<cv::Mat>& images, const cv::Mat& query) {

}
} // namespace seqslam