#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
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

void test_conversion()
{
	// create a JSON value
	json j = R"({"compact": true, "schema": 0})"_json;

	// serialize to CBOR
	std::vector<std::uint8_t> v_cbor = json::to_cbor(j);

	// 0xA2, 0x67, 0x63, 0x6F, 0x6D, 0x70, 0x61, 0x63, 0x74, 0xF5, 0x66, 0x73, 0x63, 0x68, 0x65, 0x6D, 0x61, 0x00

	// roundtrip
	json j_from_cbor = json::from_cbor(v_cbor);

	// serialize to MessagePack
	std::vector<std::uint8_t> v_msgpack = json::to_msgpack(j);

	// 0x82, 0xA7, 0x63, 0x6F, 0x6D, 0x70, 0x61, 0x63, 0x74, 0xC3, 0xA6, 0x73, 0x63, 0x68, 0x65, 0x6D, 0x61, 0x00

	// roundtrip
	json j_from_msgpack = json::from_msgpack(v_msgpack);

	// serialize to UBJSON
	std::vector<std::uint8_t> v_ubjson = json::to_ubjson(j);

	// 0x7B, 0x69, 0x07, 0x63, 0x6F, 0x6D, 0x70, 0x61, 0x63, 0x74, 0x54, 0x69, 0x06, 0x73, 0x63, 0x68, 0x65, 0x6D, 0x61, 0x69, 0x00, 0x7D

	// roundtrip
	json j_from_ubjson = json::from_ubjson(v_ubjson);
	std::ofstream file("output.ubj");
	std::ostream_iterator<std::uint8_t> iterator(file);
	std::copy(v_ubjson.begin(), v_ubjson.end(), iterator);
	std::cout << "output.ubj written" << std::endl;

	std::ifstream infile("output.ubj");
	std::istream_iterator<std::uint8_t> begin(infile), end;
	std::copy(begin, end, v_ubjson.begin());
	std::cout << "output.ubj read: " << std::endl;
	std::cout << json::from_ubjson(v_ubjson) << std::endl;
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
	test_conversion();
	return 0;
}
