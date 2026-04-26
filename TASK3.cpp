#include<iostream>
using namespace std;

class Course{
	private :
		string courseCode;
		string courseName;
		string instructor;
		int creditHours;
		int enrolledStudents;
		static int totalCourses;
		static int totalEnrollments;
		static int maxEnrollmentSeen;
		
	public :
    Course(){
        courseCode = " ";
        courseName = " ";
        instructor = " ";
        creditHours = 0;
        enrolledStudents = 0;
    }

    Course(string cCode, string cName , string inst , int cHours , int eStudents){
        courseCode = cCode;
        courseName = cName;
        instructor = inst;
        creditHours = cHours;
        enrolledStudents = eStudents;

        totalCourses++;
        totalEnrollments += enrolledStudents;
        if(enrolledStudents > maxEnrollmentSeen){
            maxEnrollmentSeen = enrolledStudents;
        }
    }

    Course(const Course &s){
        courseCode = s.courseCode;
        courseName = s.courseName;
        instructor = s.instructor;
        creditHours = s.creditHours;
        enrolledStudents = s.enrolledStudents;

        cout << "COURSE RECORD DUPLICATED : " << courseCode << endl;
    }

    void display() const{
        cout << "COURSE CODE : " << courseCode << endl;
        cout << "COURSE NAME : " << courseName << endl;
        cout << "INSTRUCTOR : " << instructor << endl;
        cout << "CREDIT HOURS : " << creditHours << endl;
        cout << "ENROLLED STUDENTS : " << enrolledStudents << endl;
        cout << endl;
    }

    string getCourseCode() const{
        return courseCode;
    }

    int getEnrolledStudents() const{
        return enrolledStudents;
    }

    void addStudents(int n){
        enrolledStudents += n;
        totalEnrollments += n;
        if(enrolledStudents > maxEnrollmentSeen){
            maxEnrollmentSeen = enrolledStudents;
        } 
    }

    void changeInstructor(string newInstructor){
        instructor = newInstructor;
    }

    static int getTotalCourse(){
        return totalCourses;
    }

    static int getTotalEnrollments(){
        return totalEnrollments;
    }

    static int getMaxEnrollmentSeen(){
        return maxEnrollmentSeen;
    }
};

int Course :: totalCourses = 0;
int Course :: totalEnrollments = 0;
int Course :: maxEnrollmentSeen = 0;

int main(){

    Course s1( "CL1004" , "OOP LAB" , "BEHRAM SHAH" , 1 , 20);
    s1.display();
    
    Course s2("CS1004" , "OOP THEORY" , "BILAL KHAN" , 3 , 30);
    s2.display();

    Course s3("EE1005" , "DLD" , "SULEMAN MIR" , 3 , 40);
    s3.display();

    Course s4("MT1008" , "MVC" , "ASKER ALI" , 3 , 50);
    s4.display();

    cout << "TOTAL COURSES : " << Course ::getTotalCourse() << endl;
    cout << "TOTAL ENROLLMENTS : " << Course ::getTotalEnrollments() << endl;
    cout << "MAXIMUM ENROLLMENTS : " << Course ::getMaxEnrollmentSeen() << endl; 

    cout << endl;
    Course s5(s1);
    s5.display();

    cout << "TOTAL COURSES : " << Course ::getTotalCourse() << endl;
    cout << "TOTAL ENROLLMENTS : " << Course ::getTotalEnrollments() << endl;
    cout << "MAXIMUM ENROLLMENTS : " << Course ::getMaxEnrollmentSeen() << endl << endl; 

    const Course student = s5;
    student.display();
    
	cout << "COURSE CODE : " << student.getCourseCode() << endl;
    // /*ADD STUDENTS AND CHANGE INSTRUCTOR WON'T BE CALLED BECAUSE THEY ARE NOT CONSTS*/
    // student.addStudents(50);
    // student.changeInstructor("IMRAN");

    s1.addStudents(30);
    cout << "TOTAL ENROLLMENTS : " << Course ::getTotalEnrollments() << endl;
    cout << "GET MAX ENROLLMENTS : " << Course ::getMaxEnrollmentSeen() << endl;

    return 0;

}
