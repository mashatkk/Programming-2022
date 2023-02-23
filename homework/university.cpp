//Створити клас Університет, та класи Студент та Курс. Клас університету повинен мати поля назва університету та місце розташування,
 //а також масив студентів та масив курсів. Клас Студент повинен мати поля для імені студента, ідентифікаційного номера та спеціальності.
 // Клас Курс повинен мати поля для назви курсу, номера курсу, спеціальність, для якої цей курс проводиться. 
 // В класі Університет додати методи для додавання-видалення студентів та курсів, а також метод для формування
  // за вказаним курсом списку студентів, які мали б цей курс прослухати і метод формування списку курсів,
  //  які би мав цей студент прослухати, метод виведення всіх студентів та метод виведення всіх курсів. 
   // Ввести дані про університет, надати меню для додавання-видалення курсів та студентів, а також формування списку студентів 
  //  за вказаним курсом та список курсів для вказаного студента
#include<iostream>
#include<string>
using namespace std;

class Course{
private:
    string courseName;
    string courseSpecialty;
    int courseNumber;
public:
    Course():courseName(" "), courseSpecialty(" "), courseNumber(0){}
    Course(string name, string specialty, int number):courseName(name), courseSpecialty(specialty), courseNumber(number){}
    Course(const Course& course): courseName(course.courseName), courseSpecialty(course.courseSpecialty), courseNumber(course.courseNumber){}

    string get_CourseName(){
        return courseName;
    }

    string get_CourseSpecialty(){
        return courseSpecialty;
    }

    int get_CourseNumber(){
        return courseNumber;
    }

    friend istream& operator>>(istream& is, Course& course) {
        cout << "Enter course name:" << endl;
        is >> course.courseName;
        cout << "Enter course specialty:" << endl;
        is >> course.courseSpecialty;
        cout << "Enter course number:" << endl;
        is >> course.courseNumber;

        return is;
    }
    friend ostream& operator<<(ostream& os, Course& course) {
        os <<"Course: "<<endl<< "Name: " << course.courseName << endl << "Specialty: " << course.courseSpecialty <<
        endl << "Number: "<< course.courseNumber << endl;
    }
};
class Student{
private:
    string name;
    string specialty;
    int id;
public:
    Student():name(" "), specialty(" "), id(0){}
    Student(string name, string specialty, int id):name(name), specialty(specialty), id(id){}
    Student(const Student& student): name(student.name), specialty(student.specialty), id(student.id){}

    string get_Name(){
        return name;
    }

    string get_Specialty(){
        return specialty;
    }

    int get_Id(){
        return id;
    }

    friend istream& operator>>(istream& is, Student& student) {
        cout << "Enter name:" << endl;
        is >> student.name;
        cout << "Enter specialty:" << endl;
        is >> student.specialty;
        cout << "Enter ID:" << endl;
        is >> student.id;

        return is;
    }
    friend ostream& operator<<(ostream& os, Student& student) {
        os << "Name: " << student.name << endl << "Specialty: " << student.specialty << endl << "ID: "
           << student.id << endl;
    }
};



class University{
private:
    string universityName;
    string universityLocation;
    Student* studentArray;
    Course* courseArray;
    int countStudent;
    int countCourse;
public:
    University():universityName(" "), universityLocation(" "), countStudent(0), countCourse(0){
        studentArray = new Student[0];
        courseArray = new Course[0];
    }
    University(string univName, string univLoc):universityName(univName), countStudent(0),
    universityLocation(univLoc), countCourse(0){
        studentArray = new Student[100];
        courseArray = new Course[100];
    }
    Student* getStudentArray(){
        return studentArray;
    }
    Course* getCourseArray(){
        return courseArray;
    }
    string getUniversityName(){
        return universityName;
    }
    string getUniversityLocation(){
        return universityLocation;
    }
    void addStudent(Student student){
        studentArray[countStudent] = student;
        countStudent++;
    }
    void addCourse(Course course){
        courseArray[countCourse] = course;
        countCourse++;
    }
    void removeStudent(Student student){
        for(int i = 0; i < countStudent; i++){
            if(studentArray[i].getId_number() == student.getId_number()){
                for(int j = i; j < countStudent; j++){
                    studentArray[j] = studentArray[j+1];
                }
            }
        }
        countStudent--;
    }
    void removeCourse(Course course){
        for(int i = 0; i < countCourse; i++){
            if(courseArray[i].getCourseName() == course.getCourseName()){
                for(int j = i; j < countCourse; j++){
                    courseArray[j] = courseArray[j+1];
                }
            }
        }
    }
    void studentForCourse(string courseName) {
        cout<<courseName<<" suitable for such students: "<<endl<<endl;
        for(int i = 0; i < countCourse; i++){
            if(courseName==courseArray[i].getCourseName()){
                for(int j = 0; j<countStudent; j++){
                    if(courseArray[i].getCourseSpecialty()==studentArray[j].getSpecialty()){
                        cout<<studentArray[j]<<endl;
                    }
                }
            }
        }
    }
    void courseForStudent(string name){
        cout<<name<<" these courses will do:"<<endl<<endl;
        for(int i = 0; i < countStudent; i++){
            if(name==studentArray[i].getName()){
                for(int j = 0; j<countCourse; j++){
                    if(studentArray[i].getSpecialty()==courseArray[j].getCourseSpecialty()){
                        cout<<courseArray[j];
                    }
                }
            }
        }
    }

    void printStudent(){
        for(int i = 0; i < countStudent;i++) {
            if (studentArray[i].getName() != " ") {
                cout<<"Student: "<<endl;
                cout << "Name: " << studentArray[i].getName() << endl << "Speciality: "
                     << studentArray[i].getSpecialty() << endl
                     << "ID number: " << studentArray[i].getId_number() << endl<<endl;
            }
        }
    }
    void printCourse(){
        for(int i = 0; i < countCourse; i++) {
            if (courseArray[i].getCourseNumber() != 0) {
                cout<<"Course:"<<endl;
                cout << "Name: " << courseArray[i].getCourseName() << endl << "Speciality: "
                     << courseArray[i].getCourseSpecialty()
                     << endl << "Number: " << courseArray[i].getCourseNumber() << endl<<endl;
            }
        }
    }
};