#pragma once

#include <iostream>
#include <memory>

//
//class AbstractProduct;
//class ProductA;
//class ProductB;


class AbstractProduct
{
public:
	virtual void dosometing() = 0;
};

class ProductA :public AbstractProduct
{
public:
	virtual void dosometing()
	{
		std::cout << "productA" << std::endl;
	}
};

class ProductB :public AbstractProduct
{
public:
	virtual void dosometing()
	{
		std::cout << "productB" << std::endl;
	}
};



class AbstractFactory
{
public:
	virtual std::unique_ptr<AbstractProduct> creatProduct() = 0;
};

class FactoryA :public AbstractFactory
{
public:
	virtual std::unique_ptr<AbstractProduct> creatProduct()
	{
		return std::make_unique<ProductA>();
	}
};

class FactoryB :public AbstractFactory
{
public:
	virtual std::unique_ptr<AbstractProduct> creatProduct()
	{
		return std::make_unique<ProductB>();
	}
};
