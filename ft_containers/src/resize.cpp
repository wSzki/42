#ifdef  VECTOR_HPP



#include "vector.hpp"






namespace ft
{
				void                   vector::resize     (size_type n, value_type val = value_type())
				{
					if (_size >= n)
						while (_size > n)
							pop_back();
					else
					{
						if (n > (_capacity))
						{
							T* tmp  = _array;

							size_type old = _capacity;


							_alloc.allocate(n);
							size_type i = 0;
							size_type counter = 0;
							for (; i < size(); i++, counter++)
								_alloc.construct(_array + counter, tmp[counter]);
							_alloc.deallocate(tmp, old);

						}
						//(n > (_capacity * 2)) ? realloc(n) : realloc(_capacity * 2);
						while (_size > n)
							push_back(val);
					}

				}




}

#endif
