#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <string>

class Flyweight
{
public:
	virtual void operation() = 0;
};

class FlyweightA : public Flyweight
{
public:
	virtual void operation()
	{
		std::cout << "FlyweightA" << std::endl;
	}
};

class FlyweightB : public Flyweight
{
public:
	virtual void operation()
	{
		std::cout << "FlyweightB" << std::endl;
	}
};

class FlyweightFactory
{
private:
	std::map<std::string, std::shared_ptr<Flyweight>> data;
public:
	FlyweightFactory() {}
	FlyweightFactory(std::string a, std::shared_ptr<Flyweight> b) { data.insert(std::make_pair(a, b)); }

	void addFlyweight(std::string a, std::shared_ptr<Flyweight> b) { data.insert(std::make_pair(a, b)); }
	std::weak_ptr<Flyweight> getFlyweight(std::string key) { return data[key]; }

	void printAll()
	{
		for (auto i : data)
		{
			std::cout << i.first << " ";
			(i.second)->operation();
			std::cout << std::endl;

		}
	}

};