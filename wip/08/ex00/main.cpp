/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:10:00 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/15 18:02:02 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./easyfindT.hpp"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	//std::vector<int>  array_i = {0, 9, 5, 6}; // cannot init like this (C++98)
	//std::vector<char> array_c = {'a', 'b', 'c'};

	std::vector<int>  array_i;

	array_i.push_back(0);
	array_i.push_back(9);
	array_i.push_back(5);
	array_i.push_back(6);

	std::vector<char>  array_c;

	array_c.push_back('a');
	array_c.push_back('b');
	array_c.push_back('c');

	std::cout << std::endl;
	std::cout << "Iterating thru a container of ints" << std::endl;
	for (std::vector<int>::iterator i = array_i.begin(); i != array_i.end(); i++)
		std::cout << *i << std::endl;

	std::cout << std::endl;
	std::cout << "Iterating thru a container of ints" << std::endl;
	for (std::vector<char>::iterator i = array_c.begin(); i != array_c.end(); i++)
		std::cout << *i << std::endl;

	std::cout << std::endl;
	std::cout << "Searching 0, 9, 5, 6, then 7 which does not exist in the container" << std::endl;
	try
	{
		std::cout << easyfind(array_i, 0) << " is the found number" <<  std::endl;
		std::cout << easyfind(array_i, 9) << " is the found number" <<  std::endl;
		std::cout << easyfind(array_i, 5) << " is the found number" <<  std::endl;
		std::cout << easyfind(array_i, 6) << " is the found number" <<  std::endl;
		std::cout << easyfind(array_i, 7) << " is the found number" <<  std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Number not found" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Searching Invalid number" << std::endl;
	try
	{
		std::cout << easyfind(array_i, -2345) << " is the found number" <<  std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Number not found" << std::endl;
	}
	std::cout << std::endl;
}
