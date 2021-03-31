#pragma once
#include "authentication.h"
#include "Admin.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;
class User {
    Admin _admin;
    Student _student;
    Teacher _teacher;

    void Interface(int userType) {
        int operation;
        string login, userType;
        if (userType == 1) {
            cout << "Wellcome back, admin" << endl;
            Admin _admin("");
            cout << "Enter a number to use your functional (1 - to add user; 2 - to delete; 3 - to change student's group; 4 - to change student's course): ";
            cin >> operation; cout << endl;
            cout << "Enter user's login: ";
            cin >> login; cout << endl;
            switch (operation) {
            case 1:
                cout << "Enter type of the creating user: ";
                cin >> userType; cout << endl;
                _admin.AddUser(login, userType);
                break;
            case 2:
                _admin.DelUser(login);
                break;
            case 3:
                _admin.ChangeGroup(login);
                break;
            case 4:
                _admin.ChangeCourse(login);
                break;
            default:
                cout << "Incorrect input!" << endl;
            }
        }
        else if (userType == 2)
        {
            int mark;
            cout << "Wellcome back, teacher" << endl;
            Teacher _teacher(login);
            cout << "Enter a number to use your functional (1 - to change student's marks; 2 - to check someone's marks): ";
            cin >> operation; cout << endl;
            cout << "Enter a student name:";
            cin >> login; cout << endl;
            cout << "Enter a mark: ";
            cin >> mark; cout << endl;
            switch (operation) {
            case 1:
                _teacher.addMark(login, mark);
                break;
            case 2:
                _teacher.watchMarks();
                break;
            }
        }
        else if (userType == 3)
        {
            cout << "Wellcome back, student!";
            Student _student(login);
            cout << "Enter a number to use your functional (1 - to check your marks; 2 - to check your group): ";
            cin >> operation; cout << endl;
            switch (operation) {
            case 1:
                _student.show_marks();
                break;
            case 2:
                _student.show_group_and_course();
                break;
            }

        }
    }
};
