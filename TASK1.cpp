/*Student Counter with Static Members
Create a Student class that tracks the total number of students created:
Private members:
• string name
• int rollNo
• static int totalStudents - tracks count of all students
Public members:
• Constructor that increments totalStudents

• Destructor that decrements totalStudents
• static int getTotalStudents() - returns count
• void display() const - displays student info
Create multiple Student objects and demonstrate that the static 
counter correctly tracks the total number of students.*/

#include<iostream>
using namespace std;

class Student{
    private :
    string name;
    int rollno;
    static int totalStudents;

    public :
    
    Student(){
        name = "unknown";
        rollno = 0;
    }

    Student(string n , int r){
        name = n;
        rollno = r;

        totalStudents++;
    }

    ~Student(){
        totalStudents--;
    }

    static int getTotalStudents(){
        return totalStudents;
    }

    void display() const{
        cout << "NAME : " << name << endl;
        cout << "ROLLNO : " << rollno << endl;  
    }
};

int Student :: totalStudents;

int main(){

    Student s1("AYESHA" , 20);
    s1.display();
    cout << "TOTAL STUDENTS : " << s1.getTotalStudents() << endl;
    cout << endl;

    Student s2("ALI" , 10);
    s2.display();
    cout << "TOTAL STUDENTS : " << s2.getTotalStudents() << endl;
    cout << endl;

    Student s3("FATIMA" , 15);
    s3.display();
    cout << "TOTAL STUDENTS : " << s3.getTotalStudents() << endl;
    cout << endl;

    s2.~Student();
    cout << "TOTAL STUDENTS : " << s2.getTotalStudents() << endl;

    return 0;
}

