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


int authentication() {
	std::vector<std::vector <std::string>> accounts = readlines("logData.csv");
	std::string name, passw = "", inp_passw;
	int access;
	while (1) {
		std::cout << "Enter your nickname, please: "; std::getline(std::cin, name); std::cout << std::endl;
		if (name=="exit") exit(0);
		for (std::vector <std::string> ln : accounts) {
			if (ln[0] == name) {
				passw = ln[1];
				access = std::stoi(ln[2]);
			}
		}
		if (passw == "") std::cout << "\033[1;31mSuch account doesn't exist! Try again or print \033[1;35mexit\033[1;31m.\033[0m" << std::endl;
		else {
			system("CLS");
			std::cout << "\033[1;32mSuccess!\033[0m" << std::endl;
			break;
		}
	}

	for (int i = 0; i < 3; i++) {
		std::cout << "Enter your password, please: "; std::getline(std::cin, inp_passw); std::cout << std::endl;
		if (inp_passw == "exit") exit(0);
		else if (inp_passw != passw) std::cout << "\033[1;31mIncorrect password! Try again or print \033[1;35mexit\033[1;31m.\033[0m" << std::endl;
		else {
			system("CLS");
			std::cout << "\033[1;32mSuccess!\033[0m" << std::endl;
			return access;
		}
	}
	std::cout << "\033[1;31mToo many attemptions! Try again later.\033[0m" << std::endl;
	time_t t0 = clock(); while ((clock() - t0) / CLOCKS_PER_SEC < 4);
	return 0;
}

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
