#pragma once
#include <cstddef>

namespace ratalsenty
{
	template <typename T>
	class allocator
	{
	public:
		typedef T			value_type;
		typedef T*			pointer;
		typedef const T*	const_pointer;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef size_t		size_type;
		typedef ptrdiff_t	differnce_type;

		allocator() = default;
		~allocator() {};
		pointer allocate(size_type size, void* p = 0) 
		{
			T* tmp = static_cast<T*>(::operator new(size * sizeof(T)));//抛出异常未处理
			return tmp;
		}
		void deallocate(pointer buffer, size_type)
		{
			::operator delete(buffer);
		}
		void construct(pointer p, const_reference value)
		{
			new(p) value_type(value);
		}
		void destroy(pointer p)
		{
			p->~T();
		}
		pointer address(reference x)
		{
			return static_cast<pointer>(&x);
		}
		const_pointer const_address(const_reference x)
		{
			return static_cast<const_pointer>(&x);
		}

		template <typename U>
		struct rebind
		{
			typedef allocator<U> other;
		};

	};

}