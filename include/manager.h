#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <vector>
#include "student.h"
#include "teacher.h"

class Manager : public Identity
{
public: 

    Manager(); // 默认构造

    Manager(string name, string pwd); // 有参构造

    virtual void openMenu(); // 菜单界面

    void addPerson(); // 添加账号

    void showPerson(); // 查看账号

    void showComputer(); // 查看机房信息

    void clearFile(); // 清空预约记录;

    void initVector(); // 初始化容器

    vector<Student> vStu; // 学生容器

    vector<Teacher> vTea; // 教师容器

    // 检测重复 参数：（传入id, 传入类型） 返回值：（true 代表有重复, false 代表没有重复）
    bool checkRepeat(int id, int type);
};