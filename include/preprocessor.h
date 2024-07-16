#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

namespace seqslam{
class Preprocessor{
public:
    Preprocessor(const std::string& directory_path);

public:
    void loadImagesFromDirectory(const std::string& directory_path);
    std::vector<cv::Mat>& getResult();

private:
    std::vector<cv::Mat> original;
    std::vector<cv::Mat> result;
    void preprocess();
};
} // namespace seqslam

#endif // PREPROCESSOR_H