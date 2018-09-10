#include <iostream>
#include <exception>
#include <boost/program_options/cmdline.hpp>

struct NotImplementedError: public std::exception
{
};

int main(int argc, char const *argv[])
{
	std::cout << "Hello world!" << std::endl;
	return 0;
}