#ifndef UTILITIES_H
#define UTILITIES_H

#include "main.h"

std::vector<std::string> readElement(const std::string &input, const std::string &delimiter);
std::string stringToHex(const std::string &input);
std::vector<lemlib::Pose> getData(const asset &path);
void generateAssetsFromFolder(const std::string &folderPath);
 

#endif // UTILITIES_H