#pragma once
//auto-iteraor
#include <cstddef>
#include <iostream>

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
		~iterator() {
			if(p != nullptr)
				delete p;
				p = nullptr;
		}
		reference operator*() const { return *p; }
		pointer operator->() const { return p; }
		iterator<value_type>& operator = (pointer p0) {//必须返回引用
			p = p0;return *this;
		}
		friend void operator << (std::ostream&, const iterator<T>);

	private:
		pointer p;

	};
	
	
	template<typename T>
	void operator << (std::ostream& out, const iterator<T>& a) { out << (*a);}
}