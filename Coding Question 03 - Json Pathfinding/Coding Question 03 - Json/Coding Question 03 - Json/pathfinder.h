#pragma once

#include <unordered_map>	//For hash tables
#include <string>
#include <vector>
#include "json/json.h"

typedef std::unordered_map<std::string, std::vector<std::string>> m_map;

class Pathfinder
{
public:
	Json::Value root;		//stores the json object
	m_map path_table;		//Holds the path hash

	Pathfinder(std::string json_data);	//Constructor
	~Pathfinder();						//Destructor
	void print_path(std::string data);
	void generate_path_table();
private:
	void generate_path_table_helper(Json::Value object, std::string partial_path);
};