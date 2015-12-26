#pragma once
#include <cstddef>
#include <iostream>

namespace ratalsenty
{
	template<typename T>
	class vector
	{
	public:
		typedef T			value_type;
		typedef T*			pointer;
		typedef const T*	const_pointer;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef size_t		size_type;
		typedef ptrdiff_t	differnce_type;

		vector() {}
		~vector() {}
		vector(vector c) {}
		vector(iterator b, iterator e) {}
		vector(int n) {}
		vector(int n, value_type t) {}
		void operator = () {}
		void assign(iterator b, iterator e) {}
		void assign(int n, value_type t) {}
		void swap();
		int size();
		int max_size();
		bool empty();

		void insert(iterator p, value_type t);
		void insert(iterator p, int, value_type t);
		void insert(iterator p, iterator b, iterator e);
		void emplace(value_type t);

		void emplace_back(value_type t);
		void push_back(value_type t);
		void emplace_front(value_type t);
		void push_front(value_type t);

		reference back();
		reference front();
		reference operator [](int n) {}
		reference at(int n) {}//Խ�����쳣

		void pop_back();
		void pop_front();

		void clear();
		void erase(iterator p) {};
		void erase(iterator b, iterator e) {};

		void resize(int n) {};
		void resize(int n, value_type t) {}

		void shrink_to_fit() {}
		int capacity() {}
		void reserve(int n) {}


		void begin();
		void end();
	};
}