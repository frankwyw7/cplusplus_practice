#pragma once
//auto-iteraor
#include <cstddef>
#include <iostream>


//µü´úÆ÷ÄÚ´æĞ¹Â©
namespace ratalsenty
{
	template <typename T>
	class iterator
	{
	public:
		typedef T			value_type;
		typedef T*			pointer;
		typedef const T*	const_pointer;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef size_t		size_type;
		typedef ptrdiff_t	differnce_type;



		explicit iterator(pointer p0 = nullptr) :p(p0) {  }
		iterator(const iterator & it) { 
			p = it.p; 
		}
		reference operator*() const {  return *p; }
		pointer operator->() const { return p; }
		iterator<value_type>& operator = (const iterator& p0) {
			setp(p0.p);
			return *this;
		}
		iterator<value_type>& operator = (const pointer& p0) {
			setp(p0);
			return *this;
		}


		iterator<value_type>& operator ++ () {
			++p;
			return *this;
		}
		iterator<value_type>& operator -- () {
			--p;
			return *this;
		}
		pointer aspointer() const { return p; }
		//pointer aspointer() { return p; }
		void setp(const pointer& p0) { p = p0; }
		int operator -(iterator<value_type> other) {
			return (p - other.p);
		}
		pointer operator -(int num) {
			return (p - num);
		}
		pointer operator +(int num) {
			return (p + num);
		}

		iterator<value_type>& operator +=(int num) {
			p += num;
			return *this;
		}
		iterator<value_type>& operator -=(int num) {
			p += num;
			return *this;
		}
		bool operator < (iterator p0) {
			return p < p0.aspointer();
		}
		bool operator <= (iterator p0) {
			return ((p < p0.aspointer())&&(p == p0.aspointer()));
		}
		bool operator > (iterator p0) {
			return p > p0.aspointer();
		}
		bool operator >= (iterator p0) {
			return ((p > p0.aspointer()) && (p == p0.aspointer()));
		}
		void setNull() { p = nullptr; }
		friend void operator << (std::ostream&, const iterator<T>);
	
	
		~iterator() {}
	private:
		pointer p;

	};
	
	
	template<typename T>
	void operator << (std::ostream& out, const iterator<T>& a) { out << (*a);}
}