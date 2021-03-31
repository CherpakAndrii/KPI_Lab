#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Student {

	string name;

public:

	Student(string str) { name = str; };

	void show_marks() {
        ifstream inFile("rating.csv");
        if (inFile.is_open()) {
            string str;
            while (!inFile.eof()) {
                getline(inFile, str);
                if (str.substr(0, str.find(',')) == name) {
                    cout << "Your marks: " << str.substr((str.find(',') + 1), (str.length() - str.find(','))) << ";\n";
                }
            }
        }
        else {
            cout << "File open error!!!\n";
        }
        inFile.close();
	}

	void show_group_and_course() {
        ifstream inFile("students_info.csv");
        if (inFile.is_open()) {
            string str;
            while (!inFile.eof()) {
                getline(inFile, str);
                if (str.substr(0, str.find(',')) == name) {
                    cout << "Your group: " << str.substr((str.find(',') + 1), 4) << ";\n";
                    cout << "Your course: " << str.substr((str.find(',') + 6), 1) << ";\n";
                }
            }
        }
        else {
            cout << "File open error!!!\n";
        }
        inFile.close();
	}

};
