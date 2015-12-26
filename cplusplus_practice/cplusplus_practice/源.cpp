#include "allocator.h"
#include "iterators .h"
#include <iostream>
#include <string>

using namespace ratalsenty;

class A
{
public:
	A() { std::cout << "Con" << std::endl; }
	~A() { std::cout << "dec" << std::endl; }
	int value = 0;
};

void caseA()
{
	std::cout << "caseA():" << std::endl;
	allocator<A> a1;
	A a_2;//打印
	A* a = a1.allocate(10);//使用强制转换，所以不打印

	a1.construct(a, a_2);
	a[9].value = 7;

	std::cout << a[9].value << '\n';
	a1.destroy(a);//打印
	a1.deallocate(a, 10);//打印

	decltype(a1)::rebind<std::string>::other a2;

	std::string* s = a2.allocate(2); 

	a2.construct(s, "foo");
	a2.construct(s + 1, "bar");

	std::cout << s[0] << ' ' << s[1] << '\n';

	a2.destroy(s);
	a2.destroy(s + 1);
	a2.deallocate(s, 2);
	std::cout << "\n\n";
}//a_2delete

class B
{
public:
	int a;
	B(int i) :a(i) {}
	B();
	friend void operator << (std::ostream& out, B& bbbb);
};
void operator << (std::ostream& out, B& bbbb) { out << bbbb.a; }

void caseB()
{
	std::cout << "caseB():" << std::endl;
	iterator<B> b100;
	B* b2 = new B(1);
	B* b3;
	b3 = b2;
	std::cout << b2->a << std::endl;
	b100 = b2;
	//b1 = b2;
	std::cout << b2->a << std::endl;
	std::cout << (*b100).a;
	std::cout << "\n\n";
}

int main()
{
	caseA();
	caseB();
}