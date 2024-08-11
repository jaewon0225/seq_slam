#include "sequence_matcher.h"
#include <vector>

namespace seqslam {
cv::Mat SequenceMatcher::calculateDifferenceMatrix(
    const std::span<cv::Mat> &map_images,
    const std::span<cv::Mat> &query_images) {
  int n = map_images.size();
  int m = query_images.size();
  cv::Mat diff_matrix = cv::Mat::zeros(n, m, CV_32F);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cv::Mat diff;
      absdiff(map_images[i], query_images[j], diff);
      diff_matrix.at<float>(i, j) = sum(diff)[0];
    }
  }
  return diff_matrix;
}

template<typename T>
cv::Mat SequenceMatcher::calculateDifferenceMatrix(const std::span<T>& map_entities, const std::span<T>& query_entities) {
  int n = map_entities.size();
  int m = query_entities.size();
  cv::Mat diff_matrix = cv::Mat::zeros(n, m, CV_32F);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      diff_matrix.at<float>(i, j) = (map_entities - query_entities).absdiff();;
    }
  }
}

cv::Mat SequenceMatcher::contrastEnhancement(const cv::Mat &diff_matrix) {
  cv::Mat enhanced;
  normalize(diff_matrix, enhanced, 0, 1, cv::NORM_MINMAX);
  pow(enhanced, 2, enhanced); // Contrast enhancement
  return enhanced;
}

std::vector<int>
SequenceMatcher::findOptimalPath(const cv::Mat &enhanced_matrix,
                                 int sequence_length) {
  int n = enhanced_matrix.rows;
  int m = enhanced_matrix.cols;
  std::vector<int> path(m, -1);
  std::vector<float> cost(m, FLT_MAX);

  for (int j = 0; j < m; j++) {
    cost[j] = enhanced_matrix.at<float>(0, j);
  }

  for (int i = 1; i < n; i++) {
    std::vector<float> new_cost(m, FLT_MAX);
    for (int j = 0; j < m; j++) {
      for (int k = std::max(0, j - sequence_length);
           k <= std::min(m - 1, j + sequence_length); k++) {
        float c = cost[k] + enhanced_matrix.at<float>(i, j);
        if (c < new_cost[j]) {
          new_cost[j] = c;
          path[j] = k;
        }
      }
    }
    cost = new_cost;
  }

  return path;
}
} // namespace seqslam