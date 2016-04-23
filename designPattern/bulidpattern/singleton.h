#pragma once
#include <iostream>
#include <memory>

class singleton1
{
public:
	static singleton1* instance()
	{
		if (_instance == 0)
			_instance = new singleton1;
		return _instance;
	}
	void dosomethin()
	{
		std::cout << "singleton" << std::endl;
	}
protected:
	singleton1() = default;
private:
	static singleton1* _instance;
};

singleton1* singleton1::_instance = 0;