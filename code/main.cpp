#include "student.h"
#include "StudentManager.h"

int main(){
    StudentManager sm;
    int choice = 0;
    while(1){
        sm.show_menu();
        cout<<"请输入你的选择："<<endl;
        cin>>choice;
        switch (choice){
            case 0: //退出
                sm.exist_system();
                break;
            case 1: //增加
                sm.append_student();
                sm.save();
                break;
            case 2: //显示
                sm.show_students();
                break;
            case 3: //删除

            
                break;
            case 4: //修改
                break;
            case 5: //查找
                break;
            case 6: //排序
                break;
            case 7: //清空
                break;
            default:
                system("cls");
                break;
        }
    }
    system("pause");
    return 0;
}