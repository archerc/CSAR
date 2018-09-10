#include <iostream>
#include <exception>
#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/options_description.hpp>

struct NotImplementedError: public std::exception
{
};


int main(int argc, char const *argv[])
{
	using options_description = boost::program_options::options_description;
	// options_description desc("Allowed options:");
	std::cout << "Hello world!" << std::endl;
	return 0;
}