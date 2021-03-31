//
//  teacher.cpp
//  kpi_lab
//
//  Created by Anatoliy Khramchenko on 31.03.2021.
//

#include "teacher.hpp"

void teacher::addMark(string studentName, int mark) {
    fstream file1;
    file1.open(rating.csv);
    string s;
    string name;
    while (!file1.eof()) {
        getline(file1,s,'\n');
        name = "";
        for (int i=0; s[i]!=','; i++) {name += s[i]}
        if (name != studentName) {
            cout << "Такого студента не існує";
        } else {
            file1 << to_string(mark);
            cout << "Файл додано успішно";
        }
    }
}
