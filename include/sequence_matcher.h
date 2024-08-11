#pragma once

#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>

#include <span>
#include <vector>

namespace seqslam {
class SequenceMatcher {
public:
  SequenceMatcher(int sequence_legth);

private:
  int sequence_length;

public:
  cv::Mat calculateDifferenceMatrix(const std::span<cv::Mat> &map_images,
                                    const std::span<cv::Mat> &query_images);

  // For the templated version of calculateDifferenceMatrix function, the user
  // should define an absdiff method that returns an absolute distance metric
  // between two instances of the class that they wish to use.
  template <typename T>
  cv::Mat calculateDifferenceMatrix(const std::span<T> &map_entities,
                                    const std::span<T> &query_entities);

  cv::Mat contrastEnhancement(const cv::Mat &diffMatrix);
  std::vector<int> findOptimalPath(const cv::Mat &enhanced_matrix,
                                   int sequence_length);
};
} // namespace seqslam