using System;

namespace Project
{
    public class User
    {
        private Admin _admin;
        private Student _student;
        private Teacher _teacher;

        public void Interface(int userType)
        {
            if (userType == 1)
            {
                Console.WriteLine("Wellcome back, admin");
                /*Console.WriteLine("Enter a path to data base directory:");
                string path = Console.ReadLine();*/
                _admin = new Admin(path);
                Console.WriteLine("Enter a number to use your functional (1 - to add user; 2 - to delete; 3 - to change student's group; 4 - to change student's course)");
                int operation = Int32.Parse(Console.ReadLine());
                Console.WriteLine("Enter user's login:");
                string login = Console.ReadLine();
                if (operation == 1)
                {
                    Console.WriteLine("Enter type of the creating user:");
                    string userType = Console.ReadLine();
                    _admin.AddUser(login, userType);
                }
                else if (operation == 2) _admin.RemoveUser(login);
                else if (operation == 3) _admin.ChangeGroup(login);
                else if (operation == 4) _admin.ChangeCourse(login);
            }
            else if (userType == 2)
            {
                Console.WriteLine("Wellcome back, teacher");
                _teacher = new Teacher();
                Console.WriteLine("Enter a number to use your functional (1 - to change student's marks; 2 - to check someone's marks)");
                int operation = Int32.Parse(Console.ReadLine());
                Console.WriteLine("Enter a student name:");
                string studentName = Console.ReadLine();
                if (operation == 1) _teacher.AddMarks(studentName);
                else if (operation == 2) _teacher.ViewMarks(studentName);
            }
            else if (userType == 3)
            {
                Console.WriteLine("Wellcome back, student");
                _student = new Student();
                Console.WriteLine("Enter a number to use your functional (1 - to check your marks; 2 - to change your group; 3 - to request group changing)");
                int operation = Int32.Parse(Console.ReadLine());
                if (operation == 1) _student.CheckMarks();
                else if (operation == 2)
                {
                    Console.WriteLine("Enter a group which you want to join:");
                    string group = Console.ReadLine();
                    _student.ChangeGroup(group);
                }
                else if (operation == 3) _student.ChangeGroup();
            }
        }
    }
}