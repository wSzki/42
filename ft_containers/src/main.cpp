


#include "random_access_iterator.hpp"
#include "vector.hpp"
#include <cstdio>

#include <vector>

typedef ft::vector<int>::iterator  ft_iterator;
typedef std::vector<int>::iterator std_iterator;



int		vector_test(void)
{
	ft::vector<int> vct(7);

	for (unsigned long int i = 0; i < vct.size(); ++i)
	{
		vct.at(i) = (vct.size() - i) * 3;
		std::cout << "vct.at(): " << vct.at(i) << " | ";
		std::cout << "vct[]: " << vct[i] << std::endl;
	}
	//printSize(vct);

	ft::vector<int> const vct_c(vct);

	std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
	std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

	try {
		vct.at(10) = 42;
	}
	catch (std::out_of_range &e) {
		std::cout << "Catch out_of_range exception!" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Catch exception: " << e.what() << std::endl;
	}
	return (0);
}





int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;



	vector_test();

	int trigger = false;
	if (trigger)
	{
		ft::vector  <int> ft_vector(5, 42);
		std::vector <int > std_vector(5, 42);
		std::cout << "at =========" << ft_vector.at(0)<< std::endl;
		std::cout << "[] =========" << ft_vector[0] << std::endl;


		std::cout << "size " << ft_vector.size() << std::endl;
		ft_vector.pop_back();
		std::cout << "size " << ft_vector.size() << std::endl;
		ft_vector.pop_back();
		std::cout << "size " << ft_vector.size() << std::endl;
		ft_vector.pop_back();
		std::cout << "size " << ft_vector.size() << std::endl;
		ft_vector.pop_back();
		std::cout << "size " << ft_vector.size() << std::endl;
		ft_vector.pop_back();
		std::cout << "size " << ft_vector.size() << std::endl;
		ft_vector.pop_back();
		std::cout << "size " << ft_vector.size() << std::endl;
		ft_vector.pop_back();
		std::cout << "size " << ft_vector.size() << std::endl;
		ft_vector.pop_back();
		std::cout << "size " << ft_vector.size() << std::endl;

		std::cout << "empty? " << ft_vector.empty() << std::endl;


		//getchar();

		ft_iterator  ft_it;
		std_iterator std_it;

		ft_it = ft_vector.begin();
		std_it = std_vector.begin();


		std::cout << *ft_it << std::endl;
		std::cout << *std_it << std::endl;

		if (ft_it == ft_it)
			std::cout<<"ft ok"<<std::endl;
		else
			std::cout<<"ft not ok"<<std::endl;

		if (std_it == std_it)
			std::cout<<"std ok"<<std::endl;
		else
			std::cout<<"std not ok"<<std::endl;





		//std::cout << *ft_vector.end() -1 << std::endl;
		//std::cout << *std_vector.end() - 1 << std::endl;




		//hector.push_back(42);
		//vector.push_back(42);

		//std::cout << *(hector.begin()) << std::endl;



		//iter_end = vec2.end();
		//vec2.end();
	}
	return (0);
}
