#pragma once
#include "authentication.h"
#include "Admin.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;
class User {
    int userType;
    string login;

public:
    User(pair<string, int> p) {
        login = p.first; userType = p.second;
    }

    void Interface() {
        int operation, newUserType;
        string stud_login;
        while (1) {
            if (userType == 1) {
                cout << "Wellcome back, admin" << endl;
                Admin _admin("");
                cout << "Enter a number to use your functional (0 - to exit; 1 - to add user; 2 - to delete; 3 - to change student's group; 4 - to change student's course; 5 - to check someone's marks; 6 - to check group info): ";
                cin >> operation; cout << endl;
                switch (operation) {
                case 0:
                    exit(0);
                case 1:
                    cout << "Enter user's login: "; cin.ignore();
                    getline(cin, stud_login); cout << endl;
                    cout << "Enter type of the creating user: ";
                    cin >> newUserType; cout << endl;
                    _admin.AddUser(stud_login, newUserType);
                    break;
                case 2:
                    cout << "Enter user's login: "; cin.ignore();
                    getline(cin, stud_login); cout << endl;
                    _admin.DelUser(stud_login);
                    break;
                case 3:
                    cout << "Enter user's login: "; cin.ignore();
                    getline(cin, stud_login); cout << endl;
                    _admin.ChangeGroup(stud_login);
                    break;
                case 4:
                    cout << "Enter user's login: "; cin.ignore();
                    getline(cin, stud_login); cout << endl;
                    _admin.ChangeCourse(stud_login);
                    break;
                case 5:
                    _admin.watchMarks();
                    break;
                case 6:
                    _admin.watchInfo();
                default:
                    cout << "Incorrect input!" << endl;
                }
            }
            else if (userType == 2)
            {
                int mark;
                cout << "Wellcome back, teacher" << endl;
                Teacher _teacher(login);
                cout << "Enter a number to use your functional (0 - to exit; 1 - to change student's marks; 2 - to check someone's marks; 3 - to check group info): ";
                cin >> operation; cout << endl;
                switch (operation) {
                case 0:
                    exit(0); 
                case 1:
                    cout << "Enter user's login: "; cin.ignore();
                    getline(cin, stud_login); cout << endl;
                    cout << "Enter a mark: ";
                    cin >> mark; cout << endl;
                    _teacher.addMark(stud_login, mark);
                    break;
                case 2:
                    _teacher.watchMarks();
                    break;
                case 3:
                    _teacher.watchInfo();
                default:
                    cout << "Incorrect input!" << endl;
                }
            }
            else if (userType == 3) {
                cout << "Wellcome back, student!";
                Student _student(login);
                cout << "Enter a number to use your functional (0 - to exit; 1 - to check your marks; 2 - to check your group): ";
                cin >> operation; cout << endl;
                switch (operation) {
                case 0:
                    exit(0);
                case 1:
                    _student.show_marks();
                    break;
                case 2:
                    _student.show_group_and_course();
                    break;
                default:
                    cout << "Incorrect input!" << endl;
                }

            }
            else exit(0);
        }
    }
};
