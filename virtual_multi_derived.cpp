/*************************************************************************
    > File Name: vtest.cpp
    > Author: xtestw
    > Mail: xuwei8091@163.com 
    > Created Time: 2015年04月11日 星期六 10时59分49秒
 ************************************************************************/

#include<iostream>
using namespace std;
class base{
	public:
		int a;
		virtual void f(){cout<<"f"<<endl;};
};

class base1  :public virtual base{
	public:
		int b;
		virtual void f1(){cout<<"f1"<<endl;};
};

class base2:public virtual base{
	public:
		int c;
		virtual void f2(){cout<<"f2"<<endl;};
};

class derived:public base1,public base2{
	public :
		int d;
		virtual void f3(){cout<<"f3"<<endl;}
};
derived f;
typedef void(*fun)(void);
int main(){
	cout<<&f<<endl;
	cout<<&(f.b)<<endl;
	cout<<&(f.c)<<endl;
	cout<<&(f.d)<<endl;
	cout<<&(f.a)<<endl;
    ((fun)*(int*)*(int *)(&f))(); 
    ((fun)*((int*)*(int *)(&f)+1))(); 
    //((fun)*((int*)*(int *)(&f)+2))(); 
    ((fun)*((int*)*(int *)(&f.b+1)))(); 
    //((fun)*((int*)*(int *)(&f.b+1)+1))(); 
    ((fun)*((int*)*(int *)(&f.d+1)))(); 
    //((fun)*((int*)*(int *)(&f.d+1)+1))(); 
	return 0;
}
