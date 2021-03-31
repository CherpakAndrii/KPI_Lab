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

/*void teacher::addMark(string studentName, int mark) {
    void addMark(string studentName, int mark) {
        ifstream file1;
        char *teka1 = "rating.csv";
        char *teka2 = "rating1.csv";
        ofstream file2(teka2);
        file1.open(teka1);
        string s;
        string name;
        bool f = 0;
        if (file1.is_open()) {
            while (!file1.eof()) {
                getline(file1, s);
                if (s[s.size()-1] == '\r') {
                    s.erase(s.end()-1);
                }
                name = "";
                for (int i=0; s[i]!=','; i++) {name += s[i];}
                if (name == studentName) {
                    s = s + "," + to_string(mark);
                    f=1;
                }
                s = s + '\n';
                file2 << s;
            }
            if (!f) {
                cout << "Такого студента не існує";
            } else {
                cout << "Оцінку додано успішно";
            }
        }
        file1.close();
        int k = rename(teka2, teka1);
        file2.close();
    }*/