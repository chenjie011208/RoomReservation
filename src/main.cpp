#include <iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

// 进入管理员子菜单界面
void managerMenu(Identity* &manager)
{
    while (true)
    {
        // 调用管理员子菜单
        manager->openMenu();

        // 将父类的指针转为子类的指针,调用子类里其它接口
        Manager * man = (Manager*)manager;

        int select = 0;
        // 接受用户的选择
        cin >> select;

        if (select == 1) // 添加账号
        {
            cout << "添加账号" << endl;
            man->addPerson();
        }
        else if (select == 2) // 查看账号
        {
            cout << "查看账号" << endl;
            man->showPerson();
        }
        else if (select == 3) // 查看机房
        {
            cout << "查看机房" << endl;
            man->showComputer();
        }
        else if (select == 4) // 清空预约
        {
            cout << "清空预约" << endl;
            man->clearFile();
        }
        else
        {
            delete manager; // 销毁掉堆区对象
            cout << "注销成功" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            system("bash -c \"read -n 1 -s -p '按任意键继续...'\"");
            system("clear");
            return;
        }
    }
}

// 登录功能 参数1 操作文件名 参数2 操作身份类型
void LoginIn(string fileName, int type)
{
    // 父类指针， 用于指向子类对象
    Identity* person = NULL;

    // 读文件
    ifstream ifs;
    ifs.open(fileName, ios::in);

    // 判断文件是否存在
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    // 准备接受用户的信息
    int id = 0;
    string name;
    string pwd;

    // 判断身份
    if (type == 1) // 学生身份
    {
        cout << "请输入你的学号" << endl;
        cin >> id;
    }
    else if (type == 2) // 老师身份
    {
        cout << "请输入您的职工号" << endl;
        cin >> id;
    }

    cout << "请输入用户名" << endl;
    cin >> name;

    cout << "请输入密码" << endl;
    cin >> pwd;

    if (type == 1)
    {
        // 学生身份验证
        int fId; // 从文件中获取的id号
        string fName; // 从文件中获取的姓名
        string fPwd; // 从文件中获取的密码
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd) // 与用户输入信息做对比
            {
                cout << "学生验证登录成功" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                system("bash -c \"read -n 1 -s -p '按任意键继续...'\"");
                system("clear");
                person = new Student(id, name, pwd);

                return;
            }

        }
    }
    else if (type == 2)
    {
        // 教师身份验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd)
            {
                cout << "教师验证登录成功" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                system("bash -c \"read -n 1 -s -p '按任意键继续...'\"");
                system("clear");
                person = new Teacher(id, name, pwd);
                return;
            }


        }
    }
    else if (type == 3)
    {
        // 管理员身份验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd)
        {
            if (name == fName && pwd == fPwd)
            {
                cout << "验证登录成功" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                system("bash -c \"read -n 1 -s -p '按任意键继续...'\"");
                system("clear");
                person = new Manager(name, pwd);
                managerMenu(person);
                return;
            }
        }
    }   

    cout << "验证登录失败" << endl;
    cin.clear();
    cin.ignore(1024, '\n');
    system("bash -c \"read -n 1 -s -p '按任意键继续...'\"");
    system("clear");

    return;
}


int main()
{
    int select = 0; // 用于接受用户的选择
    
    while(true)
    {
        
    
    cout << "==================== 欢迎来到工大机房预约系统 ====================" << endl;
    cout << endl << "请输入您的身份" << endl;
    cout << "\t\t ----------------------------------------\n";
    cout << "\t\t|                                        |\n";
    cout << "\t\t|                1.学生代表              |\n";
    cout << "\t\t|                                        |\n";
    cout << "\t\t|                2.老    师              |\n";
    cout << "\t\t|                                        |\n";
    cout << "\t\t|                3.管 理 员              |\n";
    cout << "\t\t|                                        |\n";
    cout << "\t\t|                0.退    出              |\n";
    cout << "\t\t|                                        |\n";
    cout << "\t\t ----------------------------------------\n";
    cout << "请输入您的选择：";

    cin >> select; // 接受用户选择
    
    switch(select) // 根据用户选择 实现不同接口
    {
    case 1: // 学生身份
        LoginIn(STUDENT_FILE, 1);
	    break;
	case 2: // 老师身份
        LoginIn(TEACHER_FILE, 2);
	    break;
	case 3: // 管理员身份
        LoginIn(ADMIN_FILE, 3);
	    break;
	case 0: // 退出系统
	    cout << "欢迎下一次使用" << endl;
	    cin.clear();
	    cin.ignore(1024, '\n');
	    system("bash -c \"read -n 1 -s -p '按任意键继续...'\"");
	    return 0;
	    break;
	default:
	    cout << "输入有误，请重新选择" << endl;
	    cin.clear();
	    cin.ignore(1024, '\n');
	    system("bash -c \"read -n 1 -s -p '按任意键继续...'\"");
        system("clear");
	    break;
    
    
    }


    }
    cin.clear();
    cin.ignore(1024, '\n');
    system("bash -c \"read -n 1 -s -p '按任意键继续...'\"");
    return 0;
}
