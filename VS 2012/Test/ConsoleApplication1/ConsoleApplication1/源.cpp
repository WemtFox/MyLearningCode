#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include <typeinfo>

using namespace std;

using namespace std::placeholders;

void hello(int a, int b,int c){
	cout<<a+b-c;
}

int main()
{
	string word="hello word!!";

	auto test = bind(hello, 5, _2, _1);
	test(9, 8);
	return 0;              

}