#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "student.h"
#include <fstream>
#define filename "../text1.txt"
using namespace std;

class StudentManager{
private:
    vector<Student> students;
    int len;
    int student_count;
public:
    StudentManager(fstream &fs);
    StudentManager() {}
    void show_menu();
    void exist_system();
    void append_student();
    void save();
    void show_students();
    void delete_student();
    void modify_student();
    void find_student();
    void clear_students();
    void sort_students();
};

#endif