#include "JoinVectorToString.h"

std::string JoinVector(std::vector<std::string> vec, std::string delimiter) {
	std::string output = "";
	for(int i=0; i < vec.size(); i++) {
		output.append(vec[i]);
		if(i < vec.size() - 1) {
			output.append(delimiter);
		}
	}
	return output;
}

std::string JoinVector(std::vector<int> vec, std::string delimiter) {
	std::string output = "";
	for(int i=0; i < vec.size(); i++) {
		output.append(std::to_string(vec[i]));
		if(i < vec.size() - 1) {
			output.append(delimiter);
		}
	}
	return output;
}
