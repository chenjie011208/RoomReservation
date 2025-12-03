#pragma once
#include <iostream>
using namespace std;
#include "identity.h"

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
};