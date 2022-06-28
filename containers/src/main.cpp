


#include "random_access_iterator.hpp"
#include "vector.hpp"

#include <vector>


typedef ft::vector<int>::iterator  ft_iterator;
typedef std::vector<int>::iterator std_iterator;




int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	ft::vector  <int> ft_vector(5, 42);
	std::vector <int> std_vector(5, 42);

	ft_iterator  ft_it;
	std_iterator std_it;

	ft_it = ft_vector.begin();
	std_it = std_vector.begin();


	std::cout << *ft_it << std::endl;
	std::cout << *std_it << std::endl;


	//std::cout << *ft_vector.end() -1 << std::endl;
	//std::cout << *std_vector.end() - 1 << std::endl;




	//hector.push_back(42);
	//vector.push_back(42);

	//std::cout << *(hector.begin()) << std::endl;



	//iter_end = vec2.end();
	//vec2.end();

	return (0);
}
