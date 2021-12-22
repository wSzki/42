



#include <iostream>
//#include <chrono>
#include <ctime>


void prepend_zero_if_needed_then_print(int value)
{
	if (value < 10)
		std::cout << 0;
	std::cout << value;
}

void	print_timestamp(void)
{
	std::time_t	now;
	struct tm	timestruct;

	now = time(0);
	timestruct = *localtime(&now);
	std::cout << "[";
	prepend_zero_if_needed_then_print(timestruct.tm_year + 1900);
	prepend_zero_if_needed_then_print(timestruct.tm_mon);
	prepend_zero_if_needed_then_print(timestruct.tm_mday);
	std::cout << "_";
	prepend_zero_if_needed_then_print(timestruct.tm_hour);
	prepend_zero_if_needed_then_print(timestruct.tm_min);
	prepend_zero_if_needed_then_print(timestruct.tm_sec);
	std::cout << "]";
}
