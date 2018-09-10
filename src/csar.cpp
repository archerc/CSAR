#include <iostream>
#include <exception>
#include <boost/program_options.hpp>

struct NotImplementedError: public std::exception
{
};

namespace po = boost::program_options;

int main(int argc, char const *argv[])
{
	po::options_description desc("Arguments: ");
	desc.add_options()
		("help", "produce help messages")
		("input-file", po::value< std::string >(), "input file path")
		("output", po::value< std::string >(), "output file path")
		;
	po::positional_options_description p;
	p.add("input-file", -1);

	po::variables_map vm;
	po::store(po::command_line_parser(argc, argv).
		options(desc).positional(p).run(), vm);
	po::notify(vm);

	if (vm.count("help")) {
		std::cout << "Usage: options_description [options]\n";
		std::cout << desc << std::endl;
		return 0;
	}
	if (vm.count("output"))
	{
	 	// std::cout << desc["output"].as<std::string>() << std::endl;
	} 
	return 0;
}