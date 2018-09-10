#pragma once

#include "json.hpp"

using json = nlohmann::json;

class Task:public json 
{
public:
	void operator() ();
};

Task&& loadjson(std::string file_path);
