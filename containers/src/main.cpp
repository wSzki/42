


#include "random_access_iterator.hpp"
#include "vector.hpp"

#include <vector>

using namespace ft;


int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	ft::vector  <int> vec(2, 4);
	ft::vector  <int> vec2;
	//iterator it;
	ft::vector<int>::iterator it2;

	typedef ft::vector<int>::iterator i;

	i iter;
	i iter_end;


	//hector.push_back(42);
	//vector.push_back(42);

	//std::cout << *(hector.begin()) << std::endl;


	it2  =  vec2.begin();
	iter  =  vec2.begin();
	//iter_end = vec2.end();
	//vec2.end();

	return (0);
}
