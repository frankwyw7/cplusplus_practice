#pragma once
#include <cstddef>
#include <iostream>
#include "allocator.h"
#include "iterators.h"

namespace ratalsenty
{
	template<typename T>
	class list
	{
	private:
		struct node;

	public:
		typedef T			 value_type;
		typedef T*			 pointer;
		typedef const T*	 const_pointer;
		typedef T&			 reference;
		typedef const T&	 const_reference;
		typedef size_t		 size_type;
		typedef ptrdiff_t	 differnce_type;
		typedef iterator<node>  Nodeiterator;
		typedef iterator<T>  iterator;
		typedef allocator<T> allocator;

		list():len(0) {
			_begin = new node();
		};
		list(int n) :len(n) {
			_begin =new node();
			Nodeiterator tmp(new node());
			Nodeiterator next_;
			_begin->setNext(tmp);
			tmp->setPre(_begin);
			for (int i = 1; i < n; i++)
			{
				next_ = new node();
				tmp->setNext(next_);
				next_->setPre(tmp);
				
				tmp = next_;
			}
			tmp->setNext(_begin);
			_begin->setPre(tmp);
		}

		list(int n, const_reference value) :len(n) {
			_begin =new node();
			Nodeiterator tmp(new node(value));
			Nodeiterator next_;
			_begin->setNext(tmp);
			tmp->setPre(_begin);
			for (int i = 1; i < n; i++)
			{
				next_= (new node(value));
				tmp->setNext(next_);
				next_->setPre(tmp);

				tmp = next_;
			}
			tmp->setNext(_begin);
			_begin->setPre(tmp);
		}

		//vector(const iterator& b, const iterator& e);

		~list()
		{
						
		}

		void splice();
		
		void remove();
		void remove_if();
		void unique();
		void merge();
		void sort();
		void reverse();

		void push_front();
		void pop_front();
		void emplace_fornt();

		void assign();
		void fornt();
		void resize();
		void back();
		void push_back();
		void pop_back();
		void emplace_back();

		void begin();
		void end();
		//void operator =();
		//void operator ==();
		//void operator !=();
		//void operator <();
		//void operator >();
		//void operator <=();
		//void operator >=();

		void insert();
		void erase();
		void emplace();

	private:
		struct node
		{
			allocator alloc;

			Nodeiterator pre;
			Nodeiterator next;
			iterator data;
		public:
			node(const_reference& value = value_type(), Nodeiterator pre = Nodeiterator(), Nodeiterator next = Nodeiterator())
			{
				data = alloc.allocate(1);
				alloc.construct(data.aspointer(), value);
			}
			~node()
			{
				alloc.destroy(data.aspointer());
				alloc.deallocate(data.aspointer());
			}
			void setPre(Nodeiterator p) { pre = p; }
			void setNext(Nodeiterator p) { next = p; }
		};


		int len;
		Nodeiterator _begin;
	};
}