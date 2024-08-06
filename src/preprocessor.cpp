#include "preprocessor.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <filesystem>
#include <string>

namespace seqslam {
void Preprocessor::loadImagesFromDirectory(
    const std::string &directory_path) {
  for (const auto &entry :
       std::filesystem::directory_iterator(directory_path)) {
    if (entry.is_regular_file()) {
      std::string file_path = entry.path().string();
      cv::Mat image = cv::imread(file_path);

      if (!image.empty()) {
        original.push_back(image);
      } else {
        std::cerr << "Failed to load image from: " << file_path << std::endl;
      }
    }
  }
}

std::vector<cv::Mat> &Preprocessor::getResult() { return result; }

void Preprocessor::preprocess() {
  cv::Mat gray, resized;
  for (const auto &image : original) {
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::resize(gray, resized, cv::Size(64, 64));
    result.push_back(resized);
  }
}

Preprocessor::Preprocessor(const std::string &directory_path) {
  loadImagesFromDirectory(directory_path);
  preprocess();
}
} // namespace seqslam