#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

std::vector<std::vector <std::string>> readlines(std::string);
std::vector<std::string> split(std::string, char);

std::vector<std::vector <std::string>> readlines(std::string name) {
	std::ifstream f(name);
	std::vector<std::vector <std::string>> lines;
	int count = 0;
	while (!f.eof()) {
		std::string line;
		getline(f, line);
		if (line == "") continue;
		lines.push_back(split(line, ','));
		count++;
	}
	f.close();
	return lines;
}

std::vector<std::string> split(std::string line, char sep = ' ') {
	std::vector<std::string> res;
	std::string slice = "";
	line += sep;
	for (int i = 0; i < int(line.length()); i++) {
		if (line[i] == sep) {
			if (slice.length() > 0) res.push_back(slice);
			slice = "";
		}
		else slice += line[i];
	}
	return res;
}
