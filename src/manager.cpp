#include "manager.h" 
#include <fstream>
#include "globalFile.h"
#include <vector>

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
    // 初始化管理员信息
    this->m_Name = name;
    this->m_Pwd = pwd;

    this->initVector(); // 初始化容器
}

void Manager::openMenu()
{
    cout << "欢迎管理员：" <<this->m_Name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          1.添加账号              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          2.查看账号              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          3.查看机房              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          4.清空预约              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

void Manager::addPerson()
{


    cout << "请输入添加账号的类型" << endl;
    cout << "1、添加学生" << endl;
    cout << "2、添加老师" << endl;

    string fileName;
    string tip;
    ofstream ofs;

    int select = 0;
    cin >> select;

    string errorTip; // 重复错误提示

    if (select == 1)
    {
        fileName = STUDENT_FILE;
        tip = "请输入学号: ";
        errorTip = "学号重复，请重新输入";
    }
    else
    {
        fileName = TEACHER_FILE;
        tip = "请输入职工编号：";
        errorTip = "职工编号重复，请重新输入";
    }

    ofs.open(fileName, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    cout << tip << endl;

    while (true)
    {
        cin >> id;

        bool ret = this->checkRepeat(id, select);

        if (ret)
        {
            cout << errorTip << endl;
        }
        else
        {
            break;
        }
    }

    cout << "请输入姓名：" << endl;
    cin >> name;

    cout << "请输入密码：" << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功！" << endl;

    cin.clear();
    cin.ignore(1024, '\n');
    system("bash -c \"read -n 1 -s -p '按任意键继续...'\"");
    system("clear");

    ofs.close();
}

void Manager::showPerson()
{

}

void Manager::showComputer()
{

}

void Manager::clearFile()
{
    
}

void Manager::initVector()
{
    // 读取学生文件中信息
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    vStu.clear();
    vTea.clear();

    Student s;
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
    {
        vStu.push_back(s);
    }
    cout << "当前学生的数量为：" << vStu.size() << endl;
    ifs.close(); // 学生初始化

    ifs.open(TEACHER_FILE, ios::in);

    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
    {
        vTea.push_back(t);
    }
    cout << "当前教师数量为：" << vTea.size() << endl;

    ifs.close(); // 教师初始化
}

bool Manager::checkRepeat(int id, int type)
{
    if (type == 1) // 学生
    {
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
        {
            if (id == it->m_Id)
            {
                return true;
            }
        }
    }
    else
    {
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
        {
            if (id == it->m_EmpId)
            {
                return true;
            }
        }
    }
    return false;
}