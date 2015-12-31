#include "allocator.h"
#include "iterators.h"
#include "vector.h"
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
	a1.deallocate(a);//打印

	decltype(a1)::rebind<std::string>::other a2;

	std::string* s = a2.allocate(2); 

	a2.construct(s, "foo");
	a2.construct(s + 1, "bar");

	std::cout << s[0] << ' ' << s[1] << '\n';

	a2.destroy(s);
	a2.destroy(s + 1);
	a2.deallocate(s);
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
	B* b2 = new B(1);
	B* b3;
	b3 = b2;
	std::cout << b2->a << std::endl;
	iterator<B>  b100(b2);
	//b1 = b2;
	std::cout << b2->a << std::endl;
	std::cout << (*b100).a;
	std::cout << "\n\n";
}

void caseC()
{
	std::cout << "caseC():" << std::endl;
	vector<int> c1;
	std::cout << c1.empty() << std::endl;
	vector<int> c2(4);
	c2[1] = 2;
	std::cout << c2[0]<<" "<<c2[1]<<std::endl;
	vector<int> c3(c2);
	std::cout << c3[1] << std::endl;


	vector<int> c4 = c2;
	std::cout << c3[1] << std::endl;
	c1 = c2;
	std::cout << c1[1] << std::endl;
	vector<int> c5(5, 6);
	std::cout << c5[4] << std::endl;
	c2.assign(5, 6);
	vector<int>::iterator it1 = c2.begin();
	
	std::cout << *it1 << std::endl;
	c2.insert(it1, 4);
	std::cout << *it1 << std::endl;
	c2.insert(it1, 4, 5);

	c2.push_back(7);	

	vector<int>::iterator it2 = c2.end();
	std::cout << *(--it2) << std::endl;
	std::cout << c2.front() << std::endl;
	std::cout << c2.back() << std::endl;

	std::cout << c2.pop_back() << std::endl;

	
	std::cout << c2.begin().aspointer() + 10<< " " << c2.end().aspointer() << std::endl;
	std::cout << c2.size()<<std::endl;
	std::cout << "all:";
	int i = 1;
	for (vector<int>::iterator p = c2.begin(); p < c2.end();++i, ++p)
	{
		std::cout << i << ":";
		std::cout << *p <<std::endl;
	}//智能指针未释放
	std::cout <<"\n11:"<< c2[10];//可以访问，释放了内存的吧
	std::cout << std::endl;
	std::cout << c2.size() << std::endl;


	c2.clear();
	std::cout << c2.empty() << std::endl;
	c2.insert(c2.begin(), 4, 5);
	c2.resize(8);
	c2.shrink_to_fit(2);
	std::cout << c2.begin().aspointer() << " " << c2.end().aspointer()<<" "<< c2.capacity() <<" "<< c2.size()<<std::endl;
	
	std::cout << c2[0] << c2[1] << std::endl;
	c2[0] = 2;
	c2[1] = 5;
	std::cout << c2.begin().aspointer()<< " " << c2.end().aspointer() << " " << c2.capacity() << " " << c2.size() << std::endl;
	c2.erase(c2.begin());
	std::cout << c2[0] << std::endl;
}

int main()
{
	caseA();
	caseB();
	caseC();
	std::cout << "aa" << std::endl;
}