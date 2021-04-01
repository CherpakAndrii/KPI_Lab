#pragma once
#include "authentication.h"

using namespace std;

class Admin {
    string path;
    int PasswordGeneration(int size) {
        srand(time(NULL));
        int passw = 0;
        for (int i = 0; i < size; i++) {
            passw = passw * 10 + rand() % 10;
        }
        return passw;
    }

    double get_rating(string login) {
        vector<vector <string>> data = readlines("rating.csv");
        int sum = 0;
        for (vector <string> line : data) {
            if (line[0] == login) {
                for (int i = 1; i < line.size(); i++) {
                    sum += stoi(line[i]);
                }
                return sum / 100;
            }
        }
    }

public:
    Admin(string p = "") {
        path = p + "logData.csv";
    }

    void AddUser(string login, int userType) {
        string group;
        ofstream out_file(path, ios::out | ios::app);
        int course, password = PasswordGeneration(8);
        out_file << login << "," << password << "," << userType << endl;
        out_file.close();
        cout << login << " : " << password << endl;
        if (userType == 3) {
            ofstream out_file1("students_info.csv", ios::out | ios::app);
            cout << "Enter the group: "; cin >> group;
            cout << "\nEnter the course: "; cin >> course; cout << endl;
            out_file1 << login << "," << group << "," << course << endl;
            out_file1.close();
            ofstream out_file2("rating.csv", ios::out | ios::app);
            out_file2 << login << endl;
            out_file2.close();
        }
    }

    void DelUser(string login) {
        vector<string> files = {"logData.csv", "rating.csv", "student_info.csv"};
        for (string f : files) {
            vector<vector <string>> data = readlines(f);
            ofstream out_file(f);
            for (vector <string> line : data) {
                if (line[0] == login) continue;
                for (int i = 0; i < line.size(); i++) {
                    out_file << line[i]; if (i < line.size() - 1) out_file << ",";
                }
                out_file << endl;
            }
            out_file.close();
        }
    }
    
    void ChangeGroup(string login) {
        string group;
        cout << "Enter the new group: "; cin >> group; cout << endl;
        vector<vector <string>> data = readlines("student_info.csv");
        ofstream out_file("student_info.csv");
        for (vector <string> line : data) {
            if (line[0] == login) {
                out_file << line[0] << "," << group << "," << line[2] << endl;
                continue;
            }
            for (int i = 0; i < line.size(); i++) {
                out_file << line[i]; if (i < line.size() - 1) out_file << ",";
            }
            out_file << endl;
        }
        out_file.close();
    }

    void ChangeCourse(string login) {
        vector<vector <string>> data = readlines("student_info.csv");
        ofstream out_file("student_info.csv");
        for (vector <string> line : data) {
            if (line[0] == login and get_rating(login)>0.6) {
                out_file << line[0] << "," << line[1] << "," << stoi(line[2])+1 << endl;
                continue;
            }
            for (int i = 0; i < line.size(); i++) {
                out_file << line[i]; if (i < line.size() - 1) out_file << ",";
            }
            out_file << endl;
        }
        out_file.close();
    }
    void watchMarks() {
        ifstream inFile("rating.csv");
        string s;
        while (!inFile.eof()) {
            getline(inFile, s);
            cout << s << endl;
        }
        inFile.close();
    }
    void watchInfo() {
        ifstream inFile("students_info.csv");
        string s;
        while (!inFile.eof()) {
            getline(inFile, s);
            cout << s << endl;
        }
        inFile.close();
    }
};
