#pragma once
#include <iostream>
#include <memory>

class Component
{

public:
	Component() {}
	//virtual void Operaotr() = 0;
	virtual ~Component() {};
	virtual void showDecorator() = 0;
};

class ConcreteComponentA : public Component
{
private:
	int data;
public:
	ConcreteComponentA(int i) : data(i){}
	virtual ~ConcreteComponentA() {}
	virtual void showDecorator() { std::cout << data << std::endl; }
};

class ConcreteComponentB : public Component
{
private:
	int data;
public:
	ConcreteComponentB(int i):data(i) {}
	virtual ~ConcreteComponentB() {}
	virtual void showDecorator() { std::cout << data << std::endl; }
};

class Decorator : public Component
{
protected:
	std::shared_ptr<Component> component;
public:
	Decorator(std::shared_ptr<Component> com) : component(com) { }
	virtual ~Decorator() {};
	virtual void showDecorator() { component->showDecorator(); }
};

class DecoratorA : public Decorator
{
public:
	DecoratorA(std::shared_ptr<Component> com):Decorator(com) {}
	virtual ~DecoratorA() {}
	//virtual void showDecorator() {}
	virtual void showDecorator() { Decorator::showDecorator(); dododo(); }
private:
	void dododo() { std::cout << "DecoratorA" << std::endl; }
};

class DecoratorB : public Decorator
{
public:
	DecoratorB(std::shared_ptr<Component> com) :Decorator(com) {}
	virtual ~DecoratorB() {}
	//virtual void showDecorator() {}
	virtual void showDecorator() { Decorator::showDecorator(); dododo(); }
private:
	void dododo() { std::cout << "DecoratorB" << std::endl; }
};