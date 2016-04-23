#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <string>

class Fruit
{
public:
	static std::weak_ptr<Fruit> getFruit(const std::string& type);
	static void printCurrentTypes();
private:
	static std::map<std::string, std::shared_ptr<Fruit> > types;
	std::string type;
	Fruit(const std::string& t) :type(t) {}
};

std::map<std::string, std::shared_ptr<Fruit> > Fruit::types;

std::weak_ptr<Fruit> Fruit::getFruit(const std::string& type)
{
	auto it = types.find(type);
	std::weak_ptr<Fruit> result;
	if (it == types.end())
	{
		Fruit* ggg = new Fruit(type);
		std::shared_ptr<Fruit> ff(ggg);
		types[type] = ff;
		result = ff;
	}
	else
	{
		result = it->second;
	}
	return result;

}

void Fruit::printCurrentTypes()
{
	if (!types.empty())
	{
		std::cout << "Number of instances made = " << types.size() << std::endl;
		for (auto it : types)
		{
			std::cout << it.first << " " << it.second << std::endl;
		}
	}
}