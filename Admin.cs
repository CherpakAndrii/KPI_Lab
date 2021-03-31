using System;
using System.Text;
using System.IO;

namespace Project
{
    public class Admin
    {
        private string path;

        public Admin(string path)
        {
            this.path = path + "logData.csv";
        }
        private string PasswordGeneration(int size)
        {
            StringBuilder sb = new StringBuilder();
            Random rand = new Random();
            char item;
            for (int i = 0; i < size; i++)
            {
                item = Convert.ToChar(Convert.ToInt32(Math.Floor(25 * rand.NextDouble() + 65)));
                sb.Append(item);
            }
            return sb.ToString();
        }
        public void AddUser(string login)
        {
            if (!File.Exists(path))
            {
                using (File.Create(path)) { }
            }
            string determinator = ",";
            string password = PasswordGeneration(8);
            string line = login + determinator + password;
            File.AppendAllText(path, line.ToString() + Environment.NewLine);
        }
    }
}