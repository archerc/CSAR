#include "json.h"
#include <fstream>
#include <exception>
#include <iostream>

struct NotImplementedError: public std::exception
{
};

void Task::operator() ()
{
	std::cout << "Running Task" << std::endl;
	throw NotImplementedError();
}

Task&& loadjson(std::string file_path)
{
	std::ifstream file(file_path);
	Task s;
	file >> *static_cast<json*>(&s);
	return std::move(s);
}