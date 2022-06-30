








#include <cctype>
#include <cstddef>
#include <iostream>
#include <iterator>


int main ()
{
	std::allocator<int> alloc;



	int * arr = alloc.allocate(1);
	alloc.construct(arr, 42);


	std::cout<<*arr<<std::endl;


	alloc.destroy(arr);
	alloc.deallocate(arr, 1);





}
