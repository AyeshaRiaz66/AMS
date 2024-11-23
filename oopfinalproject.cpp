#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Include for numeric_limits
#include <cstddef> // Include for NULL
#include <iomanip> // Include for setw()

using namespace std;

// Base class for Person
class Person {
public:
    string name;

    Person() : name("") {}

    Person(string n) : name(n) {}
};

// Base class for Course
class Course {
public:
    virtual float calculateTotalMarks(float quizMarks1, float quizMarks2, float assignmentMarks1, float assignmentMarks2, float finalMarks) = 0;
    virtual char calculateGrade(float totalMarks, int aThreshold) = 0;
    virtual string getCourseName() = 0;
};

// Derived class for OOP Course
class OOPCourse : public Course {
public:
    float calculateTotalMarks(float quizMarks1, float quizMarks2, float assignmentMarks1, float assignmentMarks2, float finalMarks) {
        return (quizMarks1 + quizMarks2) + (assignmentMarks1 + assignmentMarks2) + (finalMarks);
    }

    char calculateGrade(float totalMarks, int aThreshold) {
        if (totalMarks >= aThreshold)
            return 'A';
        else if (totalMarks >= aThreshold - 2)
            return 'B';
        else if (totalMarks >= aThreshold - 4)
            return 'C';
        else if (totalMarks >= aThreshold - 6)
            return 'D';
        else
            return 'F';
    }

    string getCourseName() {
        return "OOP";
    }
};

// Derived class for Linear Algebra Course
class LinearAlgebraCourse : public Course {
public:
    float calculateTotalMarks(float quizMarks1, float quizMarks2, float assignmentMarks1, float assignmentMarks2, float finalMarks) {
        return (quizMarks1 + quizMarks2) + (assignmentMarks1 + assignmentMarks2) + (finalMarks);
    }

    char calculateGrade(float totalMarks, int aThreshold) {
        if (totalMarks >= aThreshold)
            return 'A';
        else if (totalMarks >= aThreshold - 2)
            return 'B';
        else if (totalMarks >= aThreshold - 4)
            return 'C';
        else if (totalMarks >= aThreshold - 6)
            return 'D';
        else
            return 'F';
    }

    string getCourseName() {
        return "Linear Algebra";
    }
};

// Derived class for Statistics Course
class StatisticsCourse : public Course {
public:
    float calculateTotalMarks(float quizMarks1, float quizMarks2, float assignmentMarks1, float assignmentMarks2, float finalMarks) {
        return (quizMarks1 + quizMarks2) + (assignmentMarks1 + assignmentMarks2) + (finalMarks);
    }

    char calculateGrade(float totalMarks, int aThreshold) {
        if (totalMarks >= aThreshold)
            return 'A';
        else if (totalMarks >= aThreshold - 2)
            return 'B';
        else if (totalMarks >= aThreshold - 4)
            return 'C';
        else if (totalMarks >= aThreshold - 6)
            return 'D';
        else
            return 'F';
    }

    string getCourseName() {
        return "Statistics";
    }
};

// Derived class for Database Course
class DatabaseCourse : public Course {
public:
    float calculateTotalMarks(float quizMarks1, float quizMarks2, float assignmentMarks1, float assignmentMarks2, float finalMarks) {
        return (quizMarks1 + quizMarks2) + (assignmentMarks1 + assignmentMarks2) + (finalMarks);
    }

    char calculateGrade(float totalMarks, int aThreshold) {
        if (totalMarks >= aThreshold)
            return 'A';
        else if (totalMarks >= aThreshold - 2)
            return 'B';
        else if (totalMarks >= aThreshold - 4)
            return 'C';
        else if (totalMarks >= aThreshold - 6)
            return 'D';
        else
            return 'F';
    }

    string getCourseName() {
        return "Database";
    }
};

// Derived class for Student
class Student : public Person {
public:
    string regNo;
    float quizMarks1;
    float quizMarks2;
    float assignmentMarks1;
    float assignmentMarks2;
    float finalMarks;
    float totalMarks;
    char grade;
    string courseName;

    Student() : Person(), regNo(""), quizMarks1(0.0), quizMarks2(0.0), assignmentMarks1(0.0), assignmentMarks2(0.0), finalMarks(0.0), totalMarks(0.0), grade('F'), courseName("") {}

    Student(string n, string reg, float quiz1, float quiz2, float assign1, float assign2, float final, string course)
        : Person(n), regNo(reg), quizMarks1(quiz1), quizMarks2(quiz2), assignmentMarks1(assign1), assignmentMarks2(assign2), finalMarks(final), totalMarks(0.0), grade('F'), courseName(course) {}

    void calculateGrade(Course *course, int aThreshold) {
        totalMarks = course->calculateTotalMarks(quizMarks1, quizMarks2, assignmentMarks1, assignmentMarks2, finalMarks);
        grade = course->calculateGrade(totalMarks, aThreshold);
        courseName = course->getCourseName();
    }

    // Friend function to allow Teacher class to update student's marks directly
    friend void updateStudentMarks(Student &student, float quiz1, float quiz2, float assign1, float assign2, float final);

    // Modified overloaded insertion operator for easy printing of student details
    friend ostream &operator<<(ostream &out, const Student &student) {
        out << "Name: " << student.name << "\n"
            << "Registration Number: " << student.regNo << "\n"
            << "Quiz Marks 1: " << student.quizMarks1 << "\n"
            << "Quiz Marks 2: " << student.quizMarks2 << "\n"
            << "Assignment Marks 1: " << student.assignmentMarks1 << "\n"
            << "Assignment Marks 2: " << student.assignmentMarks2 << "\n"
            << "Final Marks: " << student.finalMarks << "\n"
            << "Total Marks: " << student.totalMarks << "\n"
            << "Grade: " << student.grade << "\n"
            << "Course: " << student.courseName << "\n";
        return out;
    }

    // Overloaded extraction operator for easy reading of student details
    friend istream &operator>>(istream &in, Student &student) {
        getline(in, student.name);
        getline(in, student.regNo);
        in >> student.quizMarks1 >> student.quizMarks2 >> student.assignmentMarks1 >> student.assignmentMarks2 >>
            student.finalMarks >> student.totalMarks >>
            student.grade;
        in.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the newline after grade
        getline(in, student.courseName);
        return in;
    }
};

// Function
// Function to allow Teacher class to update student's marks directly
void updateStudentMarks(Student &student, float quiz1, float quiz2, float assign1, float assign2, float final) {
    student.quizMarks1 = quiz1;
    student.quizMarks2 = quiz2;
    student.assignmentMarks1 = assign1;
    student.assignmentMarks2 = assign2;
    student.finalMarks = final;
}

// Derived class for Teacher
class Teacher : public Person {
private:
    string username;
    string password;
    Course *course; // Pointer to access all courses instead of creating separate objects for each course
    bool loggedIn;

public:
    Teacher(string user, string pass, Course *c)
        : username(user), password(pass), course(c), loggedIn(false) {}

    bool login(string user, string pass) {
        if (username == user && password == pass) {
            loggedIn = true;
            return true;
        }
        return false;
    }

    bool isLoggedIn() {
        return loggedIn;
    }

    Course *getCourse() {
        return course;
    }
    string getCourseName() {
        return course->getCourseName();
    }
};

void storeData(Student students[], int studentCount) {
    ofstream file("student_records.txt"); // Truncate mode, overwriting the existing file
    for (int i = 0; i < studentCount; ++i) {
        file << students[i].name << '\n'
             << students[i].regNo << '\n'
             << students[i].quizMarks1 << ' ' << students[i].quizMarks2 << ' '
             << students[i].assignmentMarks1 << ' ' << students[i].assignmentMarks2 << ' '
             << students[i].finalMarks << ' '
             << students[i].totalMarks << ' '
             << students[i].grade << '\n'
             << students[i].courseName << '\n';
    }
    file.close();
}

// Function to load student records from a file
int loadData(Student students[], int maxStudents) {
    ifstream file("student_records.txt");
    int i = 0;
    if (file.is_open()) {
        while (i < maxStudents && file.good()) {
            getline(file, students[i].name);
            getline(file, students[i].regNo);
            file >> students[i].quizMarks1 >> students[i].quizMarks2 >>
                 students[i].assignmentMarks1 >> students[i].assignmentMarks2 >>
                 students[i].finalMarks >> students[i].totalMarks >>
                 students[i].grade;
            file.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the newline after grade
            getline(file, students[i].courseName);
            i++;
        }
        file.close();
    }
    return i; // Return the number of students loaded
}

int main() {
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int studentCount = loadData(students, MAX_STUDENTS); // Load student records from the file
    int choice;

    // Initialize courses
    OOPCourse oopCourse;
    LinearAlgebraCourse laCourse;
    StatisticsCourse statsCourse;
    DatabaseCourse dbCourse;

    // Initialize teachers for each course
    Teacher teachers[] = {
        Teacher("oopteacher", "oop123", &oopCourse),
        Teacher("lateacher", "la123", &laCourse),
        Teacher("statsteacher", "stats123", &statsCourse),
        Teacher("dbteacher", "db123", &dbCourse),
    };
    const int numTeachers = sizeof(teachers) / sizeof(teachers[0]);

    while (true) {
        cout << "Main Menu\n";
        cout << "1. Teacher Login\n";
        cout << "2. Student Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            Teacher *loggedInTeacher = NULL;
            for (int i = 0; i < numTeachers; i++) {
                if (teachers[i].login(username, password)) {
                    loggedInTeacher = &teachers[i];
                    break;
                }
            }

            if (loggedInTeacher != NULL) {
                cout << "Welcome, " << endl;
                while (loggedInTeacher->isLoggedIn()) {
                    int teacherChoice;
                    cout << "Teacher Menu\n";
                    cout << "1. Add Student\n";
                    cout << "2. Update Student Marks\n";
                    cout << "3. Calculate Student Grade\n";
                    cout << "4. View Student Details\n";
                    cout << "5. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> teacherChoice;

                    if (teacherChoice == 1) {
                        string name, regNo;
                        float quizMarks1, quizMarks2, assignmentMarks1, assignmentMarks2, finalMarks;
                        int aThreshold;
                        cout << "Enter student name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter student registration number: ";
                        getline(cin, regNo);
                        cout << "Enter quiz marks 1: ";
                        cin >> quizMarks1;
                        cout << "Enter quiz marks 2: ";
                        cin >> quizMarks2;
                        cout << "Enter assignment marks 1: ";
                        cin >> assignmentMarks1;
                        cout << "Enter assignment marks 2: ";
                        cin >> assignmentMarks2;
                        cout << "Enter final marks: ";
                        cin >> finalMarks;
                        cout << "Enter threshold for A grade: ";
                        cin >> aThreshold;

                        students[studentCount] = Student(name, regNo, quizMarks1, quizMarks2, assignmentMarks1, assignmentMarks2, finalMarks, loggedInTeacher->getCourseName());
                        students[studentCount].calculateGrade(loggedInTeacher->getCourse(), aThreshold);
                        studentCount++;
                        storeData(students, studentCount); // Store the new student record
                        cout << "Student added successfully.\n";
                    } else if (teacherChoice == 2) {
                        string regNo;
                        cout << "Enter student registration number: ";
                        cin.ignore();
                        getline(cin, regNo);
                        bool found = false;
                        for (int i = 0; i < studentCount; i++) {
                            if (students[i].regNo == regNo) {
                                float quizMarks1, quizMarks2, assignmentMarks1, assignmentMarks2, finalMarks;
                                int aThreshold;
                                cout << "Enter new quiz marks 1: ";
                                cin >> quizMarks1;
                                cout << "Enter new quiz marks 2: ";
                                cin >> quizMarks2;
                                cout << "Enter new assignment marks 1: ";
                                cin >> assignmentMarks1;
                                cout << "Enter new assignment marks 2: ";
                                cin >> assignmentMarks2;
                                cout << "Enter new final marks: ";
                                cin >> finalMarks;
                                cout << "Enter threshold for A grade: ";
                                cin >> aThreshold;

                                updateStudentMarks(students[i], quizMarks1, quizMarks2, assignmentMarks1, assignmentMarks2, finalMarks);
                                students[i].calculateGrade(loggedInTeacher->getCourse(), aThreshold);
                                storeData(students, studentCount); // Update the student record in the file
                                cout << "Marks updated successfully.\n";
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "No student found with registration number: " << regNo << endl;
                        }
                    } else if (teacherChoice == 3) {
                        string regNo;
                        int aThreshold;
                        cout << "Enter student registration number: ";
                        cin.ignore();
                        getline(cin, regNo);
                        cout << "Enter threshold for A grade: ";
                        cin >> aThreshold;
                        bool found = false;
                        for (int i = 0; i < studentCount; i++) {
                            if (students[i].regNo == regNo) {
                                students[i].calculateGrade(loggedInTeacher->getCourse(), aThreshold);
                                storeData(students, studentCount); // Update the student record in the file
                                cout << "Grade calculated successfully.\n";
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "No student found with registration number: " << regNo << endl;
                        }
                    } 
                    else if (teacherChoice == 4) {
    // Displaying student details as a spreadsheet-like output
    cout << "Student Details:\n";
    cout << "---------------------------------------------------------------------\n";
    cout << "| Registration Number | Name            | Total Marks | Grade | Course  |\n";
    cout << "---------------------------------------------------------------------\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "| " << students[i].regNo << "         | " << setw(15) << students[i].name << " | "
             << setw(11) << students[i].totalMarks << " | " << setw(5) << students[i].grade << " | "
             << setw(7) << students[i].courseName << " |\n";
    }
}

					else if (teacherChoice == 5) {
                        loggedInTeacher = NULL;
                        cout << "Logged out successfully.\n";
                    }
                }
            } else {
                cout << "Invalid username or password.\n";
            }
        } else if (choice == 2) {
            string regNo;
            cout << "Enter student registration number: ";
            cin.ignore();
            getline(cin, regNo);
            bool found = false;
            for (int i = 0; i < studentCount; i++) {
                if (students[i].regNo == regNo) {
                    cout << students[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "No student found with registration number: " << regNo << endl;
            }
        } else if (choice == 3) {
            break;
        }
    }
    return 0;
}
