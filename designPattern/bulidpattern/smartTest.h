#pragma once
#include <iostream>
#include <memory>

class A
{
public:
	A() {
		std::cout << "A con" << std::endl;
	}
	virtual void test() { std::cout << "A test" << std::endl; }
	virtual ~A() { std::cout << "A dec" << std::endl; }
};

class B : A
{
public:
	B() { std::cout << "B con" << std::endl; }
	virtual void test() { std::cout << "B test" << std::endl; }
	virtual ~B() { std::cout << "B con" << std::endl; }
};
