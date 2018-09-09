#include <iostream>
#include <fstream>
#include <iomanip>
#include "json.hpp"

using json = nlohmann::json;

void test_construct()
{
	// create an empty structure (null)
	json j;

	// add a number that is stored as double (note the implicit conversion of j to an object)
	j["pi"] = 3.141;

	// add a Boolean that is stored as bool
	j["happy"] = true;

	// add a string that is stored as std::string
	j["name"] = "Niels";

	// add another null object by passing nullptr
	j["nothing"] = nullptr;

	// add an object inside the object
	j["answer"]["everything"] = 42;

	// add an array that is stored as std::vector (using an initializer list)
	j["list"] = { 1, 0, 2 };

	// add another object (using an initializer list of pairs)
	j["object"] = { {"currency", "USD"}, {"value", 42.99} };

	// instead, you could also write (which looks very similar to the JSON above)
	json j2 = {
		{"pi", 3.141},
		{"happy", true},
		{"name", "Niels"},
		{"nothing", nullptr},
		{"answer", {
			{"everything", 42}
		}},
		{"list", {1, 0, 2}},
		{"object", {
			{"currency", "USD"},
			{"value", 42.99}
		}}
	};	

	std::ofstream file("file.json");
	file << j2.dump(4) << std::endl;
}

void test_serialize()
{
	// store a string in a JSON value
	json j_string = "this is a string";

	// retrieve the string value (implicit JSON to std::string conversion)
	std::string cpp_string = j_string;
	// retrieve the string value (explicit JSON to std::string conversion)
	auto cpp_string2 = j_string.get<std::string>();

	// retrieve the serialized value (explicit JSON serialization)
	std::string serialized_string = j_string.dump();

	// output of original string
	std::cout << cpp_string << " == " << cpp_string2 << " == " << j_string.get<std::string>() << '\n';
	// output of serialized value
	std::cout << j_string << " == " << serialized_string << std::endl;
}

void test_io()
{
	// read a JSON file
	std::ifstream i("file.json");
	json j;
	i >> j;

	// write prettified JSON to another file
	std::string filename = "复制.json";
	std::ofstream(filename) << std::setw(4) << j << std::endl;
}

int main(int argc, char const *argv[])
{
	test_construct();
	test_serialize();
	test_io();
	return 0;
}
