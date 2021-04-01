#pragma once
#include "authentication.h"
#include "Admin.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;
class User {
    int userType;
    string login;
    pair<string, int> authentication() {
        vector<vector <string>> accounts = readlines("logData.csv");
        string name, passw = "", inp_passw;
        int access;
        while (1) {
            cout << "Enter your nickname, please: "; getline(std::cin, name); std::cout << std::endl;
            if (name == "exit") exit(0);
            for (vector <string> ln : accounts) {
                if (ln[0] == name) {
                    passw = ln[1];
                    access = std::stoi(ln[2]);
                }
            }
            if (passw == "") std::cout << "\033[1;31mSuch account doesn't exist! Try again or print \033[1;35mexit\033[1;31m.\033[0m" << std::endl;
            else {
                system("CLS");
                cout << "\033[1;32mSuccess!\033[0m" << endl;
                break;
            }
        }

        for (int i = 0; i < 3; i++) {
            std::cout << "Enter your password, please: "; std::getline(std::cin, inp_passw); std::cout << std::endl;
            if (inp_passw == "exit") exit(0);
            else if (inp_passw != passw) std::cout << "\033[1;31mIncorrect password! Try again or print \033[1;35mexit\033[1;31m.\033[0m" << std::endl;
            else {
                system("CLS");
                std::cout << "\033[1;32mSuccess!\033[0m" << std::endl;
                return { name, access };
            }
        }
        std::cout << "\033[1;31mToo many attemptions! Try again later.\033[0m" << std::endl;
        time_t t0 = clock(); while ((clock() - t0) / CLOCKS_PER_SEC < 4);
        return { name, 0 };
    }
public:
    User() {
        pair<string, int> p = authentication();
        login = p.first; userType = p.second;
    }

    void Interface() {
        int operation, newUserType;
        string stud_login;
            if (userType == 1) {
                cout << "Wellcome back, admin" << endl;
                while (1) {
                    Admin _admin("");
                    cout << "Enter a number to use your functional (0 - to exit; 1 - to add user; 2 - to delete user; 3 - to change student's group; 4 - to change student's course; 5 - to check marks; 6 - to check group info): ";
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
                        system("CLS");
                        cout << "\033[1;32mSuccess!\033[0m" << endl;
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
                        system("CLS");
                        cout << "\033[1;32mSuccess!\033[0m" << endl;
                        break;
                    case 4:
                        cout << "Enter user's login: "; cin.ignore();
                        getline(cin, stud_login); cout << endl;
                        _admin.ChangeCourse(stud_login);
                        system("CLS");
                        cout << "\033[1;32mSuccess!\033[0m" << endl;
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
            }
            else if (userType == 2){
                int mark;
                cout << "Wellcome back, teacher" << endl;
                Teacher _teacher(login);
                while (1) {
                    cout << "Enter a number to use your functional (0 - to exit; 1 - to add student's marks; 2 - to check someone's marks; 3 - to check group info): ";
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
                        system("CLS");
                        cout << "\033[1;32mSuccess!\033[0m" << endl; 
                        break;
                    case 2:
                        _teacher.watchMarks();
                        break;
                    case 3:
                        _teacher.watchInfo();
                        break;
                    default:
                        cout << "Incorrect input!" << endl;
                    }
                }
            }
            else if (userType == 3) {
                cout << "Wellcome back, student!";
                while (1) {
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
            }
            else exit(0);
        }
};
