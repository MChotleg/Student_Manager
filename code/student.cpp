#include "student.h"

Student::Student(string i,string n,string ge,vector<double>* gr) noexcept
    :id(i),name(n),gender(ge){
        if(gr){
            grades = new vector<double>(*gr);
        }
}
Student::Student(const Student &rhs){
    id = rhs.id;
    name = rhs.name;
    gender = rhs.gender;
    grades = rhs.grades ? new vector<double>(*rhs.grades):nullptr;
}
Student& Student::operator = (const Student &obj){
    delete grades;
    id = obj.id;
    name = obj.name;
    gender = obj.gender;
    grades = obj.grades ? new vector<double>(*obj.grades):nullptr;
    return *this;
}
string Student::get_id(){
    return id;
}
string Student::get_name(){
    return name;
}
string Student::get_gender(){
    return gender;
}
vector<double>* Student::get_grades(){
    return grades;
}
Student::~Student() noexcept{
    delete grades;
}
