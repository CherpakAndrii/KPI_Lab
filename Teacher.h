//  Created by Anatoliy Khramchenko on 31.03.2021.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "authentication.h"

using namespace std;

class Teacher {
    string name;
public:
    Teacher(string login) { name = login; }
    void addMark(string login, int mark) {
        vector<vector <string>> data = readlines("rating.csv");
        ofstream out_file("rating.csv");
        for (vector <string> line : data) {
            for (int i = 0; i < line.size(); i++) {
                out_file << line[i]; if (i < line.size() - 1) out_file << ",";
            }
            if (line[0]==login) out_file << "," << mark;
            out_file << endl;
        }
        out_file.close();
    }

    void watchMarks() {
        ifstream inFile("rating.csv");
        string s;
        while (!inFile.eof()) {
            getline(inFile, s);
            cout << s<< endl;
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
