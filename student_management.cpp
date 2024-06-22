#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    int rollno, age;
    string name;

public:
    Student(int stdRollno, const string &stdName, int stdAge)
        : rollno(stdRollno), name(stdName), age(stdAge) {}

    void setRollno(int stdRollno) { rollno = stdRollno; }
    int getRollno() const { return rollno; }

    void setName(const string &stdName) { name = stdName; }
    string getName() const { return name; }

    void setAge(int stdAge) { age = stdAge; }
    int getAge() const { return age; }

    void displayStudent() const {
        cout << "Roll No: " << rollno << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

void DeleteStudent(vector<Student> &students) {
    string name;
    cout << "Enter name to delete: ";
    cin.ignore();
    getline(cin, name);
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getName() == name) {
            students.erase(it);
            cout << "\t\tStudent deleted" << endl;
            return;
        }
    }
    cout << "\t\tStudent not found" << endl;
}

void UpdateStudent(vector<Student> &students) {
    string name;
    bool found = false;
    int choice;
    cout << "\t\tEnter name to update record: ";
    cin.ignore();
    getline(cin, name);
    for (auto &student : students) {
        if (student.getName() == name) {
            found = true;
            cout << "\t\t--Student found---" << endl;
            cout << "\t\t1. Update roll number" << endl;
            cout << "\t\t2. Update name" << endl;
            cout << "\t\t3. Update age" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    int rno;
                    cout << "\t\tEnter new roll number: ";
                    cin >> rno;
                    student.setRollno(rno);
                    break;
                }
                case 2: {
                    string newname;
                    cout << "\t\tEnter new name: ";
                    cin >> newname;
                    student.setName(newname);
                    break;
                }
                case 3: {
                    int nage;
                    cout << "\t\tEnter new age: ";
                    cin >> nage;
                    student.setAge(nage);
                    break;
                }
                default:
                    cout << "\t\tInvalid choice" << endl;
            }
            cout << "\t\tRecord updated" << endl;
            return;
        }
    }
    if (!found) {
        cout << "\t\tStudent not found" << endl;
    }
}

void SearchStudent(const vector<Student> &students) {
    int rollno;
    cout << "\t\tEnter roll number: ";
    cin >> rollno;
    for (const auto &student : students) {
        if (student.getRollno() == rollno) {
            cout << "\t\t-------Student found-----" << endl;
            student.displayStudent();
            return;
        }
    }
    cout << "\t\tStudent not found" << endl;
}

void DisplayAllStudent(const vector<Student> &students) {
    if (students.empty()) {
        cout << "\t\tNo students found" << endl;
        return;
    }
    for (const auto &student : students) {
        student.displayStudent();
        cout << endl;
    }
}

void addNewStudent(vector<Student> &students) {
    int rollno, age;
    string name;

    cout << "Enter roll number: ";
    cin >> rollno;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;

    Student newStudent(rollno, name, age);
    students.push_back(newStudent);

    cout << "Student added successfully!" << endl;
}

int main() {
    vector<Student> students;
    students.push_back(Student(1, "Matteo", 23));
    char choice;
    do {
        system("cls");
        int op;
        cout << "\t\t------------------------------" << endl;
        cout << "\t\tStudent Management System" << endl;
        cout << "1. Add new student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Search student" << endl;
        cout << "4. Update student" << endl;
        cout << "5. Delete student" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> op;
        switch (op) {
            case 1:
                addNewStudent(students);
                break;
            case 2:
                DisplayAllStudent(students);
                break;
            case 3:
                SearchStudent(students);
                break;
            case 4:
                UpdateStudent(students);
                break;
            case 5:
                DeleteStudent(students);
                break;
            case 6:
                return 0;
            default:
                cout << "\t\tInvalid choice" << endl;
        }
        cout << "\t\tDo you want to continue [y/n]? : ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
