#include "Fixed.hpp"

int main(void)
{
	Fixed a(42);
	Fixed b(41);

	if (a <= b)
		std::cout << "it worked" << std::endl;
	return (0);
}
