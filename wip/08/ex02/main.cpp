/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:15:47 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/17 16:28:08 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// I
void	stack_demo(void)
{
	std::cout << std::endl;
	std::cout << "###########################" << std::endl;
	std::cout << "###   STD::STACK DEMO   ###" << std::endl;
	std::cout << "###########################" << std::endl;

	std::stack<int> stack;

	std::cout << std::endl;
	std::cout << "Pushing 11, 21, 42 to stack" << std::endl;
	stack.push(11);
	stack.push(21);
	stack.push(42);
	std::cout << "Top value  : " << stack.top()  << std::endl;
	std::cout << "Stack size : " << stack.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Popping twice" << std::endl;
	stack.pop();
	stack.pop();
	std::cout << "Top value  : " << stack.top()  << std::endl;
	std::cout << "Stack size : " << stack.size() << std::endl;
}

// II
void	mutant_stack_test(void)
{
	std::cout << std::endl;
	std::cout << "###########################" << std::endl;
	std::cout << "###   MUTANT TEST       ###" << std::endl;
	std::cout << "###########################" << std::endl;

	MutantStack<int> stack;

	std::cout << std::endl;
	std::cout << "Pushing 11, 21, 42 to stack" << std::endl;
	stack.push(11);
	stack.push(21);
	stack.push(42);


	std::cout << std::endl;
	std::cout << "Printing first element of stack's container" << std::endl;
	std::cout << *stack.get_c().begin() << std::endl;

	std::cout << std::endl;
	std::cout << "Printing last element of stack's container" << std::endl;
	std::cout << *stack.get_c().end() << std::endl;

	std::cout << std::endl;
	std::cout << "Top value  : " << stack.top()  << std::endl;
	std::cout << "Stack size : " << stack.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Popping twice" << std::endl;
	stack.pop();
	stack.pop();
	std::cout << "Top value  : " << stack.top()  << std::endl;
	std::cout << "Stack size : " << stack.size() << std::endl;
}

// III
void iterator_test(void)
{
	std::cout << std::endl;
	std::cout << "###########################" << std::endl;
	std::cout << "###   ITERATOR TEST     ###" << std::endl;
	std::cout << "###########################" << std::endl;

	MutantStack<int> stack;

	std::cout << std::endl;
	std::cout << "Pushing 11, 22, 44, 66 to stack" << std::endl;
	stack.push(11);
	stack.push(22);
	stack.push(44);
	stack.push(88);

	std::cout << std::endl;
	std::cout << "Printing content of container with iterators" << std::endl;
	MutantStack<int>::container_type::iterator begin;

	begin = stack.begin();
	while (begin != stack.end())
	{
		std::cout << "Content of iterator : ";
		std::cout << *begin << std::endl;
		begin++;
	}
}

int main(void)
{
	stack_demo();
	mutant_stack_test();
	iterator_test();
	std::cout << std::endl;
}
