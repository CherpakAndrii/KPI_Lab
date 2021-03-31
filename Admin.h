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

    void AddUser(string login, string userType) {

        ofstream out_file(path, ios::out | ios::app);
        int password = PasswordGeneration(8);
        out_file << login << "," << password << "," << userType;
        out_file.close();
        cout << login << " : " << password << endl;
    }

    void DelUser(string login) {
        vector<vector <string>> accounts = readlines("logData.csv");
        ofstream out_file(path);
        for (vector <string> line : accounts) {
            if (line[0] == login) continue;
            for (int i = 0; i < line.size(); i++) { out_file << line[i]; if (i<line.size()-1) out_file << ",";
            }
        }
        out_file.close();
    }
};
