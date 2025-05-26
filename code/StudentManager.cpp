#include "StudentManager.h"
#include "student.h"

StudentManager::StudentManager(fstream &fs){
        string id,name,gender;
        int grade_count;
        while(fs >> id >> name >> gender >> grade_count) {
                vector<double>* grades = new vector<double>;
                len ++;
                double grade;
                for(int i = 0;i < grade_count;++i){
                        fs>>grade;
                        grades->push_back(grade);
                }
                Student new_student(id,name,gender,grades);
                students.push_back(new_student);
        }
}

void StudentManager::show_menu(){
        cout<<"*****************************************************"<<endl;
        cout<<"**************   欢迎使用学生管理系统   **************"<<endl;
        cout<<"****************    0.退出管理系统   *****************"<<endl;
        cout<<"****************    1.增加学生信息   *****************"<<endl;
        cout<<"****************    2.显示学生信息   *****************"<<endl;
        cout<<"****************    3.删除学生信息   *****************"<<endl;
        cout<<"****************    4.修改学生信息   *****************"<<endl;
        cout<<"****************    5.查找学生信息   *****************"<<endl;
        cout<<"****************    6.按照成绩排序   *****************"<<endl;
        cout<<"****************    7.清空所有信息   *****************"<<endl;
        cout<<"*****************************************************"<<endl;
        cout<<endl;
}
void StudentManager::exist_system(){
        cout<<"欢迎下次使用"<<endl;
        system("pause");
        exit(0);
}
void StudentManager::append_student(){
        cout<<"请输入添加学生数量："<<endl;
        cin>>student_count;
        if(student_count>0){
                for(int i = 0;i <student_count;++i){
                        string id,name,gender;
                        int grade_count;                       
                        cout<<"请输入学生学号："<<endl;
                        cin>>id;
                        cout<<"请输入学生姓名："<<endl;
                        cin>>name;
                        cout<<"请输入学生性别："<<endl;
                        cin>>gender;
                        cout<<"请输入科目数量："<<endl;
                        cin>>grade_count;
                        cout<<"请输入各科成绩："<<endl;
                        double grade;
                        vector<double>* grades = new vector<double>;
                        for(int i = 0;i < grade_count;++i){
                                cin>>grade;
                                grades->push_back(grade);
                        }
                        Student new_student(id,name,gender,grades);
                        students.push_back(new_student);
                }
                len = students.size();
                cout<<"成功添加"<<student_count<<"名学生"<<endl;
        }
        else{
                cout<<"输入数据有误"<<endl;
        }
        system("pause");
        system("cls");
}
void StudentManager::save(){
        fstream fs;
        fs.open(filename,ios::app);
        for(int i = len - student_count;i < len;++i){
                fs<<students[i].get_id()<<"\t";
                fs<<students[i].get_name()<<"\t";
                fs<<students[i].get_gender()<<"\t";
                int len_grades = students[i].get_grades()->size();
                fs << len_grades << '\t';
                for(int j = 0;j < len_grades;++j){
                        fs<<(*students[i].get_grades())[j]<<" ";
                }
                fs<<endl;
        }
        fs.close();
}
void StudentManager::show_students(){
        fstream fs;
        fs.open("../text1.txt",ios::in);
        if(fs){
                StudentManager Student_show(fs);
                cout << "学号\t姓名\t性别\t学科成绩"<<endl;
                for(int i = 0; i <Student_show.len; i ++) {
                        cout << Student_show.students[i].get_id() << '\t'
                             << Student_show.students[i].get_name() << '\t'
                             << Student_show.students[i].get_gender() << '\t';
                        int len_grades = Student_show.students[i].get_grades()->size();
                        for(int j = 0;j < len_grades;++j){
                                cout<<(*Student_show.students[i].get_grades())[j]<<" ";
                        }
                        cout << endl;
                }
        }
        else{
                cout<<"Error: failed to open file."<<endl;
                // system("pause");
                // system("cls");
        }
        fs.close();
        system("pause");
        system("cls");
}

void StudentManager::delete_student() {
        fstream fs;
        fs.open("../text1.txt",ios::in);
        StudentManager Student_show(fs);
        cout << "请输入删除学生的学号:" << endl;
        string id;
        cin >> id;
        for(int i = 0; i < (int)Student_show.students.size(); i ++) {
                if(Student_show.students[i].get_id() == id) Student_show.students.erase(Student_show.students.begin() + i);
        }
        fs.close();
        fs.open("../text1.txt", ios::out);
        for(int i = 0; i < (int)Student_show.students.size(); ++i){
                fs << Student_show.students[i].get_id()<<"\t";
                fs << Student_show.students[i].get_name()<<"\t";
                fs << Student_show.students[i].get_gender()<<"\t";
                int len_grades = Student_show.students[i].get_grades()->size();
                fs << len_grades << '\t';
                for(int j = 0;j < len_grades;++j){
                        fs<<(*Student_show.students[i].get_grades())[j]<<" ";
                }
                fs<<endl;
        }
        
        fs.close();
        cout << "已将学号为:" << id << "的学生的信息删除" << endl;
        system("pause");
        system("cls");
}