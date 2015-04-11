/*************************************************************************
    > File Name: vtest2.cpp
    > Author: xtestw
    > Mail: xuwei8091@163.com 
    > Created Time: 2015年04月11日 星期六 11时39分20秒
 ************************************************************************/

#include<iostream>
using namespace std;
class base{
	public:
		int a;
		virtual void f(){cout<<"f"<<endl;}
};

class derived:public base{
	public:
		int b;
		virtual void f1(){cout<<"f2"<<endl;}
};
typedef void(*Fun)(void);
int main(){
	int a;
	derived f;
	derived f2;
	cout<<&a<<endl;
	cout<<&f<<endl;
	((Fun)*(int*)*(int*)(&f))();
	((Fun)*((int*)*(int*)(&f)+1))();
	return 0;
}
