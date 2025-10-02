#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Ousama" ,1);
		for (size_t i = 0; i < 149; i++)
		{
			std::cout << a << std::endl;
			a.decrement_grade();
		}
		std::cout << a << std::endl;
		a.decrement_grade();
	}
	catch (std::exception& e)
	{
		std::cout << "throw: " << e.what() << std::endl;
	}
	return 0;
}
