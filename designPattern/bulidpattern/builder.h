#pragma once
#include <memory>
#include <iostream>


//
//class Product
//{
//public:
//	virtual void dosomething() = 0;
//};
//class ProductA :public Product
//{
//public:
//	virtual void dosomething()
//	{
//		std::cout << "ProductA dosomething" << std::endl;
//	}
//};
//class ProductB :public Product
//{
//public:
//	virtual void dosomething()
//	{
//		std::cout << "ProductB dosomething" << std::endl;
//	}
//};
//
//
//class Builder
//{
//public:
//	virtual std::unique_ptr<Product> build() = 0;
//};
//
//
//
//class Director
//{
//	std::unique_ptr<Builder> builder;
//public:
//	std::unique_ptr<Product> constrcut()
//	{
//		return builder->build();
//	}
//};
//
//
//
//class ConcreteBuilderA
//{
//public:
//	virtual std::unique_ptr<Product> build()
//	{
//		return std::make_unique<ProductA>();
//	}
//};
//
//class ConcreteBuilderB
//{
//public:
//	virtual std::unique_ptr<Product> build()
//	{
//		return std::make_unique<ProductB>();
//	}
//};


class Product
{
	int partA;
	int partB;
	int partC;

public:
	Product(int a, int b, int c) :partA(a), partB(b), partC(c) {}
	Product() = default;
	void setA(int a) { partA = a; }
	void setB(int b) { partB = b; }
	void setC(int c) { partC = c; }

	int getA() { return partA; }
	int getB() { return partB; }
	int getC() { return partC; }
};

class Builder
{
public:
	//Builder() = default;
	virtual void buildA(int a) = 0;
	virtual void buildB(int b) = 0;
	virtual void buildC(int c) = 0;
	virtual void show() = 0;
};

class ConcreteBuilder:public Builder
{
private:
	Product product;
public:
	virtual void buildA(int a)
	{
		product.setA(a);
	}

	virtual void buildB(int b)
	{
		product.setB(b);
	}

	virtual void buildC(int c)
	{
		product.setC(c);
	}
	virtual void show()
	{
		std::cout << product.getA() << " " << product.getB() << " " << product.getC() << std::endl;
	}
};

class Director
{
	std::unique_ptr<Builder> builder;
public:
	void construct(int a, int b, int c)
	{
		builder.reset(new ConcreteBuilder);
		builder->buildA(a);
		builder->buildB(b);
		builder->buildC(c);
	}
	void show()
	{
		builder->show();
	}
};