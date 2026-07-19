#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Student
{
    string name;
    string className;
};

int main()
{
    unordered_map<int, Student> students;
    string s;

    while (getline(cin, s))
    {
        if (s.empty()) continue;

        // Insert(ID,Name,Class)
        if (s.find("Insert") == 0)
        {
            int p1 = s.find("(");
            int p2 = s.find(",");
            int p3 = s.find(",", p2 + 1);
            int p4 = s.find(")");

            int id = stoi(s.substr(p1 + 1, p2 - p1 - 1));
            string name = s.substr(p2 + 1, p3 - p2 - 1);
            string cls = s.substr(p3 + 1, p4 - p3 - 1);

            students[id] = {name, cls};
        }

        // Delete(ID)
        else if (s.find("Delete") == 0)
        {
            int p1 = s.find("(");
            int p2 = s.find(")");

            int id = stoi(s.substr(p1 + 1, p2 - p1 - 1));

            students.erase(id);
        }

        // Infor(ID)
        else if (s.find("Infor") == 0)
        {
            int p1 = s.find("(");
            int p2 = s.find(")");

            int id = stoi(s.substr(p1 + 1, p2 - p1 - 1));

            if (students.count(id))
                cout << students[id].name << "," << students[id].className << endl;
            else
                cout << "NA,NA" << endl;
        }
    }

    return 0;
}