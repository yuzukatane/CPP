#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

bool readFile(std::string const& fileName, std::string& content) {
	std::ifstream inputFile(fileName);
	if (!inputFile) {
		std::cerr << "Could not open " << fileName << std::endl;
		return false;
	}
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    content = buffer.str();
    return true;
}

bool writeFile(std::string const& fileName, std::string& content) {
    std::string outputFileName = fileName + ".replace";
    std::ofstream outputFile(outputFileName);
	if (!outputFile) {
		std::cerr << "Could not open " << outputFileName << std::endl;
		return false;
	}
    outputFile << content;
    return true;
}

int replace(std::string const& fileName, std::string const& src, std::string const& dst) {

    std::string content;
    std::string replaced = "";

    if (readFile(fileName, content) == false)
        return 1;

    if (!(src.empty())) {

        int srcLen = src.length();
        while (1) {
            size_t index = content.find(src);
            if (index != std::string::npos) {
                std::string rest = content.substr(index + srcLen);
                content.erase(index).insert(index, dst);
                replaced += content;
                content = rest;
            } else {
                replaced += content;
                break ;
            }
        }
    } else {
        replaced = content;
    }
    if (writeFile(fileName, replaced) == false)
        return 1;

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }
    return (replace(argv[1], argv[2], argv[3]));
}
