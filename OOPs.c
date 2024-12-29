#include <iostream>
using namespace std;

class teacher {
    protected:
    string teacherName;

    public:
    void setTeacherDetail(string name) {
        teacherName = name;
    }

    void printTeacher() {
        cout << "Teacher's name is " << teacherName << endl;
    }
};



class school {
    protected:
    string schoolName;

    public:
    void setSchoolDetail(string name) {
        schoolName = name;
    }

    void printSchool() {
        cout << "School name is " << schoolName << endl;
    }
};

class student : public teacher, public school { // Inheriting from both
    public:
    int rollno;
    string studentName;

    void setStudentDetail(string name, int roll) {
        studentName = name;
        rollno = roll;
    }

    void printStudent() {
        cout << "Student's name is " << studentName 
             << ", roll number is " << rollno 
             << ", studies at " << schoolName 
             << ", and is taught by " << teacherName << "." << endl;
    }
};

int main() {
    student s1;

    // Set details for school, teacher, and student
    s1.setSchoolDetail("GIET University");
    s1.setTeacherDetail("Mr. Sharma");
    s1.setStudentDetail("Rajesh Rana", 29);

    // Print details
    s1.printSchool();    // Prints school details
    s1.printTeacher();   // Prints teacher details
    s1.printStudent();   // Prints student details
    teacher t1;
    t1.setTeacherDetail("Mr. rajesh");
    t1.printTeacher();

    return 0;
}
