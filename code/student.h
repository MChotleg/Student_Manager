#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student{
private:
    string id;
    string name;
    string gender;
    vector<double>* grades;
public: 
    Student(string i = "",string n = "",string ge = "",vector<double>* gr = nullptr) noexcept;
    Student(const Student &rhs);
    Student& operator = (const Student &obj);
    ~Student() noexcept;
    friend istream& operator >> (istream& is,Student &rhs);
    friend ostream& operator << (ostream& os,const Student &rhs);
    string get_id();
    string get_name();
    string get_gender();
    vector<double>* get_grades();
    friend class StudentManager;
};

#endif