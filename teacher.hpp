//
//  teacher.hpp
//  kpi_lab
//
//  Created by Anatoliy Khramchenko on 31.03.2021.
//

#ifndef teacher_hpp
#define teacher_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

class Teacher {
public:
    void addMark(string studentName, int mark);
    void watchMarks();
};

#endif /* teacher_hpp */
