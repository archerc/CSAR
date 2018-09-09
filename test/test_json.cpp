#include <iostream>
#include <iomanip>
#include "json.hpp"

using json = nlohmann::json;

int main(int argc, char const *argv[])
{
	json j;
	j << std::cin;
	std::cout << std::setw(4) << j << std::endl;
	return 0;
}
