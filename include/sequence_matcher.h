#pragma once

#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>

#include <vector>

namespace seqslam {
class SequenceMatcher {
public:
  SequenceMatcher(int sequence_legth);

private:
  int sequence_length;

public:
  cv::Mat calculateDifferenceMatrix(const std::vector<cv::Mat> &map_images,
                                    const std::vector<cv::Mat> &query_images);
  cv::Mat contrastEnhancement(const cv::Mat &diffMatrix);
  std::vector<int> findOptimalPath(const cv::Mat &enhanced_matrix,
                                   int sequence_length);
};
} // namespace seqslam