#include <iostream>
#include <boost/program_options.hpp>
#include "json.h"

namespace po = boost::program_options;

int main(int argc, char const *argv[])
{
	po::options_description desc("语法: csar <input-file> [options]");
	desc.add_options()
		("help,h", "produce help messages")
		("input-file", po::value< std::string >(), "input file path")
		("output-file", po::value< std::string >(), "output file path")
		;
	po::positional_options_description p;
	p.add("input-file", -1);

	po::variables_map vm;
	po::store(po::command_line_parser(argc, argv).
		options(desc).positional(p).run(), vm);
	po::notify(vm);

	if (vm.count("help")) {
		std::cout << desc << std::endl;
	}

	if (vm.count("input-file"))
	{
		auto infile = vm["input-file"].as<std::string>();
	 	std::cout << "Read from file: " << infile << std::endl;
	 	auto task = loadjson(infile);
	 	task();
	} 
	else
	{
		std::cout << desc << std::endl;
	}
	return 0;
}