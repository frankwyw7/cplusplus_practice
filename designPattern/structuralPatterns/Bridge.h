#pragma once

#include <iostream>
#include <memory>

class Implementor
{
public:
	virtual void implmention() = 0;
};
class Abstraction
{
public:
	virtual void operation() = 0;
	Abstraction(std::unique_ptr<Implementor> a) :impl(std::move(a)) {}
protected:
	std::unique_ptr<Implementor> impl;
};

class ConcreteImplementor : public Implementor
{
public:
	void implmention()
	{
		std::cout << "is doing something" << std::endl;
	}
};

class RefinedAbstraction : public Abstraction
{
public:
	RefinedAbstraction(std::unique_ptr<Implementor> a) :Abstraction(std::move(a)) { }
	void operation()
	{
		std::cout << "RefinedAbstraction" << std::endl;
		impl->implmention();
	}
};