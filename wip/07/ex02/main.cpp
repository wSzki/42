/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:03:04 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/10 20:59:12 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ArrayT.hpp"
#include "colors.hpp"
#include <cstdio>

static void next(void)
{
	std::cout << _R << "\nPRESS ENTER TO CONTINUE" << std::endl;
	getchar();
	_CLEAR;
}

static void example(void)
{
	_CLEAR;
	std::cout << "####################\n";
	std::cout << "### SUBJECT TEST ###\n";
	std::cout << "####################\n\n";
	std::cout << CYAN <<
		"int   * a = new int (42)\n"
		"char  * b = new char('Z')\n\n"
		"int   * c = new int [3] = {1, 2, 3}\n"
		"char  * c = new char[3] = \"hello\""
		<< std::endl;
	std::cout << _R << std::endl;

	int  *integer         = new int (42);
	char *character       = new char('Z');
	int  *integer_array   = new int[3];
	char *character_array = new char[5];

	integer_array[0] = 1;
	integer_array[1] = 2;
	integer_array[2] = 3;

	character_array[0] = 'h';
	character_array[1] = 'e';
	character_array[2] = 'l';
	character_array[3] = 'l';
	character_array[4] = 'o';

	std::cout << GREEN << "int:      " << *integer   << std::endl;
	std::cout << GREEN << "char:     " << *character << std::endl;

	std::cout << YELLOW << "int arr:  " << integer_array[0] << std::endl;
	std::cout << YELLOW << "int arr:  " << integer_array[1] << std::endl;
	std::cout << YELLOW << "int arr:  " << integer_array[2] << std::endl;

	std::cout << RED << "char arr: " << character_array[0] << std::endl;
	std::cout << RED << "char arr: " << character_array[1] << std::endl;
	std::cout << RED << "char arr: " << character_array[2] << std::endl;
	std::cout << RED << "char arr: " << character_array[3] << std::endl;
	std::cout << RED << "char arr: " << character_array[4] << std::endl;

	delete integer;
	delete [] integer_array; // try to remove []
	delete character;
	delete [] character_array; // try to remove []
}

static void basic_test(void)
{
	std::cout << "####################\n";
	std::cout << "## BASIC TEST    ###\n";
	std::cout << "####################\n\n";
	float f;
	Array<int>    array_int  (5);
	Array<char>   array_char (5);
	Array<float>  array_float(5);
	std::cout << std::endl;

	std::cout << "int   array size : " << array_int.size()   << std::endl;
	std::cout << "char  array size : " << array_char.size()  << std::endl;
	std::cout << "float array size : " << array_float.size() << std::endl;

	for (int i = 0; i < 5; i++)
	{
		f = (rand() % 93) + 33;
		array_int   [i] = f;
		array_char  [i] = f;
		array_float [i] = f + 0.5;
		std::cout << CYAN   << "int   value:        " << array_int  [i] << std::endl;
		std::cout << PURPLE << "float value + 0.5:  " << array_float[i] << std::endl;
		std::cout << ORANGE << "char  value:        " << array_char [i] << std::endl;
		std::cout << std::endl;
	}
}

static void index_test(void)
{
	std::cout << "####################\n";
	std::cout << "## INDEX TEST    ###\n";
	std::cout << "####################\n\n";

	int f;
	Array<int>    array_int  (5);

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		f = rand() % 20 - 10;
		std::cout << "Wanted index value : " << f << std::endl;
		try
		{
			array_int[i] = 42;
			std::cout << GREEN << "[OK]" << _R << " Wanted value : " << array_int[f] << _R << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "[ERROR] "<< _R << e.what();
			std::cout << ": Index out of bounds" << std::endl;
		}
		std::cout << std::endl;
	}
}

static void copy_test()
{
	std::cout << "####################\n";
	std::cout << "## COPY TEST     ###\n";
	std::cout << "####################\n\n";

	int f;
	Array<int>    array_int (5);
	Array<int>    array_int_copy_assignment;

	for (int i = 0; i < 5; i++)
	{
		f = (rand() % 100);
		array_int[i] = f;
	}

	Array<int>    array_int_copy(array_int);

	array_int_copy_assignment = array_int;

	std::cout << YELLOW << "\n******** BEFORE MODIFICATION ********" << std::endl;

	std::cout << BLUE << "####### COPY" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array_int_copy[i] << std::endl;

	std::cout << LIGHT_GRAY << "####### ASSIGNMENT (=) COPY" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array_int_copy_assignment[i] << std::endl;

	std::cout << PURPLE << "####### ORIGINAL" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array_int[i] << std::endl;

	for (int i = 0; i < 5; i++)
	{
		f = (rand() % 100);
		array_int_copy[i] = f;
	}
	for (int i = 0; i < 5; i++)
	{
		f = (rand() % 100);
		array_int_copy_assignment[i] = f;
	}

	std::cout << YELLOW << "\n******** AFTER MODIFICATION ********" << std::endl;

	std::cout << BLUE << "####### COPY" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array_int_copy[i] << std::endl;

	std::cout << LIGHT_GRAY << "####### ASSIGNMENT (=) COPY" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array_int_copy_assignment[i] << std::endl;

	std::cout << PURPLE << "####### ORIGINAL" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array_int[i] << std::endl;

	std::cout << std::endl;
}

int main (void)
{
	srand      (time (0));

	example    (); next ();
	basic_test (); next ();
	index_test (); next ();
	copy_test  ();

	return (0);
}
