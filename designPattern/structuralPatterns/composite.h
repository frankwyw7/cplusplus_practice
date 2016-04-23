#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <string>

class Component
{
public:
	virtual void operation() = 0;
};

class Leaf1 : public Component
{
public:
	virtual void operation()
	{
		std::cout << "leaf1" << std::endl;
	}
};

class Leaf2 :public Component
{
public:
	virtual void operation()
	{
		std::cout << "leaf2" << std::endl;
	}
};

class Composite : public Component
{
public:
	void operation()
	{
		for (auto i : types)
		{
			i.second->operation();
		}
	}
	void add(const std::string& key, std::shared_ptr<Component> value)
	{
		auto i = types.find(key);
		if (i == types.end())
		{
			types.insert(std::make_pair(key, value));
		}
	}
	void remove(const std::string& key)
	{
		types.erase(key);
	}
	std::weak_ptr<Component> get(const std::string& key)
	{
		return std::weak_ptr<Component>(types[key]);
	}
private:
	std::map<std::string, std::shared_ptr<Component>> types;
};