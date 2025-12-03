#pragma once
#include <iostream>
using namespace std;
#include "identity.h"

class Student : public Identity
{
public:

    Student(); // 默认构造

    Student(int id, string name, string pwd); // 有参构造

    virtual void openMenu(); // 菜单界面

    void applyOtder(); // 申请预约
    
    void showMyOrder(); // 查看自身预约
    
    void showAllOrder(); // 查看所有预约
    
    void cancelOrder(); // 取消预约

    int m_ID; // 学生学号

}
