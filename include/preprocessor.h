#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <filesystem>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

namespace seqslam {
class Preprocessor {
public:
  Preprocessor(const std::string &directory_path);

private:
  std::vector<cv::Mat> original;
  std::vector<cv::Mat> result;

public:
  std::vector<cv::Mat> &getResult();

private:
  void preprocess();
  void loadImagesFromDirectory(const std::string &directory_path);
};
} // namespace seqslam

#endif // PREPROCESSOR_H