#pragma once
#include <iostream>
#include <memory>

class abstractItem
{
public:
	virtual std::unique_ptr<abstractItem> clone() const = 0;
	virtual void test() { std::cout << "abstract" << std::endl; }
};

class Door : public abstractItem
{
private:
	int door;
public:
	Door(int i) :door(i) {}
	Door(const Door& a) { door = a.door; }
	Door& operator = (const Door& other) { door = other.door; return *this; };
	virtual std::unique_ptr<abstractItem> clone() const
	{
		return std::make_unique<Door>((*this));
	}
};
class Wall :public abstractItem
{
private:
	int wall;
public:
	Wall(int i) :wall(i) {}
	Wall(const Wall& a) { wall = a.wall; }
	Wall& operator = (const Wall& other) { wall = other.wall; return *this; }
	virtual std::unique_ptr<abstractItem> clone() const
	{
		return std::make_unique<Wall>((*this));
	}
};
class Room :public abstractItem
{
private:
	int room;
public:
	Room(int i) :room(i) {}
	Room(const Room& other) { room = other.room; }
	Room& operator = (const Room& other) { room = other.room; return *this; }
	virtual void test() { std::cout << "room" << room << std::endl; }
	virtual std::unique_ptr<abstractItem> clone() const
	{
		return std::make_unique<Room>(*this);
	}
};

class AbstractFactory
{
public:
	virtual std::unique_ptr<abstractItem> makedoor()const = 0;
	virtual std::unique_ptr<abstractItem> makewall()const = 0;
	virtual std::unique_ptr<abstractItem> makeroom()const = 0;
};

class FactoryA:public AbstractFactory
{
public:
	FactoryA()
	{
		door = std::make_unique<Door>(1);
		wall = std::make_unique<Wall>(2);
		room = std::make_unique<Room>(3);
	}
	virtual std::unique_ptr<abstractItem> makedoor() const
	{
		return door->clone();
	}

	virtual std::unique_ptr<abstractItem> makewall() const
	{
		return wall->clone();
	}

	virtual std::unique_ptr<abstractItem> makeroom() const
	{
		return room->clone();
	}

private:
	std::unique_ptr<Door> door;
	std::unique_ptr<Wall> wall;
	std::unique_ptr<Room> room;
};
