#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
        string determinator = ",";
        int password = PasswordGeneration(8);
        out_file << login << "," << password << "," << userType;
        out_file.close();
    }
};