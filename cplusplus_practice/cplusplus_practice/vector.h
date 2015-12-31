#pragma once
#include <cstddef>
#include <iostream>
#include "allocator.h"
#include "iterators.h"

#define		default_min		0
#define		defalut_len		1
#define		default_max		20		


namespace ratalsenty
{
	template<typename T>
	class vector
	{
	public:
		typedef T			 value_type;
		typedef T*			 pointer;
		typedef const T*	 const_pointer;
		typedef T&			 reference;
		typedef const T&	 const_reference;
		typedef size_t		 size_type;
		typedef ptrdiff_t	 differnce_type;
		typedef iterator<T>  iterator;
		typedef allocator<T> allocator;

		vector() :len(default_min), max(default_max) { 
			data = alloc.allocate(max); 
			ibegin = data;
			iend = data + len;
		}
		~vector() { 
			for (; ibegin < iend; ++ibegin) 
				alloc.destroy(ibegin.aspointer()); 
				alloc.deallocate(data.aspointer()); 
		}
		vector(vector<T>& c):len(c.len), max(c.max) { 
			data = alloc.allocate(max); 
			int i = 0;
			for (iterator tmp_it_this = data; i < len; i++, ++tmp_it_this)
			{
				alloc.construct(tmp_it_this.aspointer() , c[i]);
			}
			ibegin = data;
			iend = data + len;
		}
		vector<value_type>& operator = (/*const会报错？使用const函数重载加const_iterator不会报错*/vector<T> & c){
			if (&c == this)
				return *this;
			
			int i = 0;
			for (iterator tmp_it_this = data; i < len; i++, ++tmp_it_this)
			{
				alloc.destroy(tmp_it_this.aspointer());
			}
			len = (c.len);
			max = (c.max);
			i = 0;
			for (iterator tmp_it_this = data; i < len; i++, ++tmp_it_this)
			{
				alloc.construct(tmp_it_this.aspointer(), c[i]);
			}
			ibegin = data;
			iend = data + len;
			return *this;
		}


		vector(vector<T>&&) = default;
		vector<value_type>& operator = (const vector<T> &&) = delete;


		vector(const iterator& b, const iterator& e)  {
			if((len = e - b) < 0) 
				len = -dis;
			max = len * 2;
			data = alloc.allocate(max);
			for (iterator tmp_it_this = data, tmp_it_other = b; tmp_it_other < e; ++tmp_it_other, ++tmp_it_this)
			{
				alloc.construct(tmp_it_this.aspointer(),*tmp_it_other);
			}
			ibegin = data;
			iend = data + len;
		}
		vector(int n) :len(n), max(n * 2) {
			data = alloc.allocate(max);//每次都被析构
			int i = 0;
			for (iterator tmp_it_this = data; i < len; i++, ++tmp_it_this)
			{
				alloc.construct(tmp_it_this.aspointer(), value_type());
			}
			ibegin = data;
			iend = data + len;
		}
		vector(int n, const_reference& t) :len(n), max(n * 2) {
			data = alloc.allocate(max);
			int i = 0;
			for (iterator tmp_it_this = data; i < len; i++, ++tmp_it_this)
			{
				alloc.construct(tmp_it_this.aspointer(), value_type(t));
			}
			ibegin = data;
			iend = data + len;
		}


		//void assign(iterator b, iterator e) {
		//	if ((len = e - b) < 0)
		//		len = -dis;
		//	max = len * 2;
		//	data = alloc.allocate(max);
		//	for (iterator tmp_it_this = data, tmp_it_other = b; tmp_it_other < e; ++tmp_it_other, tmp_it_this++)
		//	{
		//		alloc.construct(tmp_it_this.aspointer(), *tmp_it_other);
		//	}
		//	ibegin = data;
		//	iend = data + len;
		//}
		void assign(int n, value_type t) {
			len = n;
			max = n * 2;
			data = alloc.allocate(max);
			int i = 0;
			for (iterator tmp_it_this = data; i < len; i++, ++tmp_it_this)
			{
				alloc.construct(tmp_it_this.aspointer(), value_type(t));
			}
			ibegin = data;
			iend = data + len;
		}
		//void swap(vector<value_type> c) {
		//	vector<value_type> *tmp = this;
		//	this = &c;
		//	c = tmp;
		//}
		int size() {return len;};
		int max_size() { return (max-len); }
		bool empty() { return (len == 0); };

		void insert(iterator p, value_type t) {
			move_back(p);
			*p = t;
			ibegin = data;
			len++;
			++iend;
		}
		void insert(iterator p, int n, value_type t) {
			move_back(p,n);
			iterator tmp_it_this = p;
			for (int i = 0; i < n;++tmp_it_this, i++)
			{
				*tmp_it_this = t;
			}
			ibegin = data;
			iend += n;
			len += n;
		}
		//void insert(iterator p, iterator b, iterator e) {
		//	if ((n = e - b) < 0)
		//		n = -dis;//
		//	move_back(p, n);
		//	for (iterator tmp_it_this = p, tmp_it_other = b; tmp_it_other < e; ++tmp_it_this, ++tmp_it_other)
		//	{
		//		*tmp_it_this = *tmp_it_other;
		//	}
		//	ibegin = data;
		//	iend += n;
		//	len += n;
		//}

		//void emplace(value_type t);C++11
		//void emplace_back(value_type t);C++11
		void push_back(value_type t) {
			if ((len + 1) > max)
				renew(max * 2);
			alloc.construct(iend.aspointer(), t);
			++iend;
			++len;
		}
		//void emplace_front(value_type t);C++11
		//void push_front(value_type t);Not

		reference back() { return *(iend - 1); };
		reference front() {	return *ibegin;	}
		reference operator [](int n) { return *(ibegin + n); }
		//const_reference operator [](int n) const{ return *(ibegin + n); }
		reference at(int n) {
			try {
				value_type tmp_value = *(ibegin + n);
			}				
			catch(std::exception){
				std::cerr << "out of range" << endl;
			}
			return tmp_value;
		}//越界抛异常

		value_type pop_back() {
			iterator tmp_it =( --iend);
			value_type tmp_value = value_type(*tmp_it);
			alloc.destroy(tmp_it.aspointer());
			len--;
			return tmp_value;			
		}
		//void pop_front();

		void clear() { 
			for (; ibegin < iend; ++ibegin)
				alloc.destroy(ibegin.aspointer()); 
			len = 0; 
			ibegin = data; 
			iend = ibegin;
		}
		void erase(iterator p) {
			move_advance(p,iterator(p+1));
			--iend;
			--len;
		}
		/*void erase(iterator b, iterator e) {
			move_advance(b, ++e);
			--iend;
			--len;
		}*/
		void resize(int n) {
			if (n <= len)
			{
				/*iterator tmp_it_this = ibegin + n;
				while (tmp_it_this < iend)
					alloc.deallocate(tmp_it_this);
				len = n;*/
				resmallnew(n);
			}
			else if(n > max)
			{
				renew(n * 2);
				int i = 0;
				for (iterator tmp_it_this = iend; i < n; i++, ++tmp_it_this)
				{
					alloc.construct(tmp_it_this.aspointer()+i, value_type());
				}

				iend += n - len;
			}
			else
			{
				int i = 0;
				for (iterator tmp_it_this = iend; i < n; i++, ++tmp_it_this)
				{
					alloc.construct(tmp_it_this.aspointer()+i, value_type(1));
				}

				iend += n - len;
			}
			
		}
		void resize(int n, value_type t) {
			if (n <= len)
			{
				resmallnew(n);
				/*iterator tmp_it_this = ibegin + n;
				while (tmp_it_this < iend)
					alloc.deallocate(tmp_it_this);
				len = n;*/
			}
			else if (n > max)
			{
				renew(n * 2);
				int i = 0;
				int num = n - len;
				for (iterator tmp_it_this = iend; i < num; i++, ++tmp_it_this)
				{
					alloc.construct(tmp_it_this.aspointer() + i, value_type(t));
				}
			}
			else
			{
				int i = 0;
				int num = n - len;
				for (iterator tmp_it_this = iend; i < num; i++, ++tmp_it_this)
				{
					alloc.construct(tmp_it_this.aspointer() + i, value_type(t));
				}
			}
		}

		void shrink_to_fit(int n) {
			resmallnew(n);
		}
		int capacity() { return max; }
		void reserve(int n) {
			renew(n+max);
		}

		iterator begin() { return ibegin; }
		iterator end() { return iend; }
		
	private:
		void move_back(iterator p ,int n = 1){
			if(n + len > max) 
				renew((n + len) * 2);
			//for construct
			int i = n;
			iterator tmp_it_base;
			for (tmp_it_base = iend + n - 1; tmp_it_base > p; i--, --tmp_it_base)
			{
				alloc.construct(tmp_it_base.aspointer(), *(tmp_it_base - n));
			}
			for (; i > 0; i--,--tmp_it_base)
			{
				alloc.construct(tmp_it_base.aspointer(), *(tmp_it_base - n));
			}

			/*alloc.construct(iend.aspointer(), *(iend - n));
			int i = n - 1;
			for (iterator tmp_it = iend; tmp_it >= p;n-- )
			{
				alloc.construct(iend.aspointer(), *(iend - n));
				*tmp_it = *(--tmp_it);
			}*/
		}

		void move_advance(iterator p, iterator start)
		{
			for (iterator tmp_it_start = start; tmp_it_start < iend; ++tmp_it_start, ++p)
			{
				*p = *tmp_it_start;
			}
			for (; p < iend; ++p)
			{
				alloc.destroy(p.aspointer());
			}
		}

		void renew(int n)
		{
			iterator tmp_data;
			tmp_data = alloc.allocate(n);
			for (iterator tmp_it = tmp_data, tmp_it_this = ibegin; tmp_it_this < iend; ++tmp_it,++tmp_it_this)
			{
				alloc.construct(tmp_it.aspointer(), *tmp_it_this);
			}
			for (iterator tmp_it_this = ibegin; tmp_it_this < iend; ++tmp_it_this)
			{
				alloc.destroy(tmp_it_this.aspointer());
			}
			alloc.deallocate(data.aspointer());

			data = tmp_data;
			max = n;
			ibegin = data;
			iend = data + len;
		}

		void resmallnew(int n)
		{
			iterator tmp_data;
			tmp_data = alloc.allocate(n);
			int i = 0;
			for (iterator p = tmp_data; i < n;i++, ++ibegin)
			{
				alloc.construct(p.aspointer() + i, *ibegin);
			}
			alloc.deallocate(data.aspointer());

			data = tmp_data;
			len = max = n;
			ibegin = data;
			iend = data + len;
		}
		int max;
		int len;
		allocator alloc;
		iterator data;
		iterator ibegin;
		iterator iend;	
	};
}