#include<iostream>
#include"Complex.h"
using namespace std;

int main()
{
	Complex c1(3, 5);     //用复数3+5i初始化c1
	Complex c2 = 4.5;    //用实数4.5初始化c2
	c1.add(c2);          //将c1与c2相加，结果保存在c1中
	c1.show();           //将c1输出
}