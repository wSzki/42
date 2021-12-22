



#include <iostream>
#include <string>
#include <stdio.h>
#include <aio.h>
#include <vector>

int main(void)
{
	int a(42);
	int b = 42;

	printf("%s%d\n", "a : ", a);
	printf("%s%d\n", "b : ", b);



	typedef std::vector<int>	vector_t;

	int start = 0;
	int end   = 0;

	vector_t iterations(0, 10);

	//////////////////////////////
	std::vector<int> vector_a;
	vector_a = {1, 2, 3};
	std::cout << "vector a: ";
	for (int i : vector_a)
		std::cout << i << " ";
	///////////////////////////////
	std::vector<int> vector_b(5, 0);
	// ==
	std::vector<int> vector_c = {0, 0, 0, 0, 0};

	vector_b.push_back(1);

	std::cout <<std::endl << "Num at position 2 in vector a : " << vector_a[2] << std::endl;
	//std::cout <<std::endl << "Num at position 10 in vector a (error with array[n]) : " << vector_a[10] << std::endl;
	//std::cout <<std::endl << "Num at position 10 in vector a (error with .at(n)) : " << vector_a.at(10) << std::endl;

	std::cout << "vector b: ";
	for (int i : vector_b)
		std::cout << i << " ";
	std::cout << "vector c: ";
	for (int i : vector_c)
		std::cout << i << " ";


	int d[] = {1, 2, 3, 4};
	typedef std::vector<int> vector_d;

	vector_d dop(d, d);
	std::cout << "vector d: ";
	for (int i : dop)
		std::cout << i << " ";






}
