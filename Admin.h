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
public:
    Admin(string p) {
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
            ofstream out_file("students_info.csv", ios::out | ios::app);
            cout << "Enter the group: "; cin >> group;
            cout << "\nEnter the course: "; cin >> course; cout << endl;
            out_file << login << "," << group << "," << course << endl;
            out_file.close();
            ofstream out_file("rating.csv", ios::out | ios::app);
            out_file << login << endl;
            out_file.close();
        }
    }

    void DelUser(string login) {
        vector<string> files = {"logData.csv", "rating", "student_info"};
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
    
    void ChangeGroup(string login, string group) {
        vector<vector <string>> data = readlines("student_info");
        ofstream out_file("student_info");
        for (vector <string> line : data) {
            if (line[0] == login) {
                out_file << line[0] << group << line[2] << endl;
                continue;
            }
            for (int i = 0; i < line.size(); i++) {
                out_file << line[i]; if (i < line.size() - 1) out_file << ",";
            }
            out_file << endl;
        }
        out_file.close();
    }
};
