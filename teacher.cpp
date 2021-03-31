//
//  teacher.cpp
//  kpi_lab
//
//  Created by Anatoliy Khramchenko on 31.03.2021.
//

#include "teacher.hpp"

void teacher::addMark(string studentName, int mark) {
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
    }
}
