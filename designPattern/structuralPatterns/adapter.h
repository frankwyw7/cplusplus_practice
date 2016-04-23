#pragma once
#include <iostream>
#include <memory>

class Target
{
public:
	virtual void request() = 0;
};

class Adaptee
{
	int i;
public:
	Adaptee():i(0) {}
	void specificRequest()
	{
		std::cout << i + 1 << std::endl;
	}
};

class Adapter: public Target, Adaptee
{
public:
	void request()
	{
		specificRequest();
	}
//private:
//	Adaptee a;
};


