/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:02:47 by wszurkow          #+#    #+#             */
/*   Updated: 2022/02/07 17:10:55 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "colors.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	srand(time(0));

	Data data;
	Data *processed_data;

	data.value_a       = rand() % 100;
	data.value_b       = rand() % 100;
	data.value_c       = rand() % 100;
	data.str           = "test";


	std::cout << GREEN << "\n########### Original structure" << std::endl;
	std::cout << _R << std::endl;
	std::cout << "data.value a : " << data.value_a << std::endl;
	std::cout << "data.value b : " << data.value_b << std::endl;
	std::cout << "data.value c : " << data.value_c << std::endl;
	std::cout << "data.string  : " << data.str     << std::endl;
	uintptr_t raw = serialize(&data);

	std::cout << ORANGE << "\n########### Serializing &data to uintptr_t" << std::endl;
	std::cout << _R << std::endl;
	std::cout << "Raw value of &data  : " << raw << std::endl;

	std::cout << ORANGE << "\n########### Creating empty Data *processed_data pointer" << std::endl;
	std::cout << _R << std::endl;
	processed_data = NULL;
	std::cout << "Adress of processed_data : " << processed_data << std::endl;

	std::cout << RED << "\n########### Logging content of processed_data after deserialization" << std::endl;
	std::cout << _R << std::endl;
	processed_data = deserialize(raw);

	std::cout << "processed_data.value_a : " << processed_data->value_a << std::endl;
	std::cout << "processed_data.value_b : " << processed_data->value_b << std::endl;
	std::cout << "processed_data.value_c : " << processed_data->value_c << std::endl;
	std::cout << "processed_data.string  : " << processed_data->str     << std::endl;

	std::cout << CYAN << "\n########### Comparing original and deserialized adress " << std::endl;
	std::cout << _R << std::endl;
	std::cout << "Adress of data           : " << &data           << std::endl;
	std::cout << "Adress of processed_data : " << processed_data  << std::endl;


	return (0);
}
