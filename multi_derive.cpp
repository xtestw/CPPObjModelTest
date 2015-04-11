/*************************************************************************
    > File Name: multi_derive.cpp
    > Author: xtestw
    > Mail: xuwei8091@163.com 
    > Created Time: 2015年04月11日 星期六 17时01分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

class base1{
	public:
		int a;
		virtual void f1(){cout<<"f1"<<endl;}
		virtual void f4(){cout<<"base1 f4"<<endl;}
};

class base2{
	public:
		int b;
		virtual void f2(){cout<<"f2"<<endl;}
		virtual void f4(){cout<<"base2 f4"<<endl;}
};

class derived:public base1,public base2{
	public:
		int c;
		virtual void f3(){cout<<"f3"<<endl;}
		virtual void f4(){cout<<"derived f4"<<endl;}
};
typedef void(*Fun)(void);
derived f;
int main()
{
	cout<<&f<<endl;
	cout<<&f.a<<endl;
	cout<<&f.b<<endl;
	cout<<&f.c<<endl;
	((Fun)(*(int*)*(int*)(&f)))();
	((Fun)*((int*)*(int*)(&f)+1))(); 
	((Fun)*((int*)*(int*)(&f)+2))(); 	
	((Fun)*((int*)*(int*)(&f.a+1)))(); 
	((Fun)*((int*)*(int*)(&f.a+1)+1))(); 
	base1 * p=&f;
	base2 * p2=&f;
	p->f4();
	p2->f4();
	return 0;
}
