#include "main.h"
#include "headers/odometry.hpp"
#include <cmath>
#include <deque>
#include <fstream>
#include <filesystem>
// #include <algorithm>

/**
 * Splits a string into elements based on a specified delimiter.
 *
 * @param {string} input - The input string to be split.
 * @param {string} delimiter - The delimiter used to identify boundaries between elements.
 * @returns {Array<string>} An array of substrings obtained by splitting the input string.
 */
std::vector<std::string> readElement(const std::string &input, const std::string &delimiter)
{
	std::string token;
	std::string s = input;
	std::vector<std::string> output;
	size_t pos = 0;

	// main loop
	while ((pos = s.find(delimiter)) != std::string::npos)
	{							  // while there are still delimiters in the string
		token = s.substr(0, pos); // processed substring
		output.push_back(token);
		s.erase(0, pos + delimiter.length()); // remove the read substring
	}

	output.push_back(s); // add the last element to the returned string

	return output;
}

/**
 * Converts a string to its hexadecimal representation.
 *
 * @param {string} input - The input string to be converted to hexadecimal.
 * @returns {string} - The hexadecimal representation of the input string.
 */
std::string stringToHex(const std::string &input)
{
	static const char hex_digits[] = "0123456789ABCDEF";

	std::string output;
	output.reserve(input.length() * 2);
	for (unsigned char c : input)
	{
		output.push_back(hex_digits[c >> 4]);
		output.push_back(hex_digits[c & 15]);
	}
	return output;
}

/**
 * Gets the data from an asset and returns it as a vector of poses
 * @param name of the asset
 * @return A vector containing the path
 */
std::vector<lemlib::Pose> getData(const asset &path)
{
	std::vector<lemlib::Pose> robotPath;

	// format data from the asset
	const std::string data(reinterpret_cast<char *>(path.buf), path.size);
	const std::vector<std::string> dataLines = readElement(data, "\n");

	// read the points until 'endData' is read
	for (std::string line : dataLines)
	{
		lemlib::infoSink()->debug("read raw line {}", stringToHex(line));
		if (line == "endData" || line == "endData\r")
			break;
		const std::vector<std::string> pointInput = readElement(line, ", "); // parse line
		// check if the line was read correctly
		if (pointInput.size() != 3)
		{
			lemlib::infoSink()->error("Failed to read path file! Are you using the right format? Raw line: {}",
									  stringToHex(line));
			break;
		}
		lemlib::Pose pathPoint(0, 0);
		pathPoint.x = std::stof(pointInput.at(0));	   // x position
		pathPoint.y = std::stof(pointInput.at(1));	   // y position
		pathPoint.theta = std::stof(pointInput.at(2)); // velocity
		robotPath.push_back(pathPoint);				   // save data
		lemlib::infoSink()->debug("read point {}", pathPoint);
	}

	return robotPath;
}
