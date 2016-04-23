#pragma once
#include <iostream>
#include <memory>
#include <map>

class multion
{
private:
	static std::map<std::string, multion> instances;
	multion() {}
public:
	static multion* getmultion(const std::string& key)
	{
		auto it = instances.find(key);
		if (it == instances.end())
		{
			
		}
	}
};