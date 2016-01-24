#include "pathfinder.h"
#include <iostream>

//Constructor
Pathfinder::Pathfinder(std::string json_data)
{
	Json::Reader reader;
	//Use the reader to parse the data
	bool parsed = reader.parse(json_data.c_str(), root, false);

	//If parsing fails, report the failure and exit the program
	if (!parsed)
	{
		std::cout << "Parsing failed!" << std::endl;
		exit(1);
	}
}

//Destructor
Pathfinder::~Pathfinder()
{
	
}

/*
Purpose: Given a string to find a path for, get the path
Functionality: It will look into the Pathfinder's hash table for a vector of paths. If it finds nothing it will say so, otherwise it will print each one it finds.
Parameters:
	-string data: input string to find the path for
*/
void Pathfinder::print_path(std::string data)
{
	m_map::const_iterator found = path_table.find(data);
	std::vector<std::string> results;

	//Report if the data is not available in the path table
	if (found == path_table.end())
	{
		std::cout << "Cannot find a path for the value " + data << std::endl;
		return;
	}
	//Otherwise we get the string vector that holds the paths for this value and proceed to print them out
	else
	{
		results = found->second;	//Set the results to the vector that the iterator found
		std::cout << "Found the following results for " << data << ":" << std::endl;
		for (unsigned i = 0; i < results.size(); i++)
		{
			std::cout << results[i] << std::endl;
		}
	}
}


void Pathfinder::generate_path_table()
{
	generate_path_table_helper(root, "");
}

void Pathfinder::generate_path_table_helper(Json::Value object, std::string partial_path)
{
	if (object.isString()) //Only consider pushing the object if it is a string
	{
		auto it = path_table.find(object.asString());
		//If the item doesn't already have a path, we create a table entry for it
		if (it == path_table.end())
		{
			std::vector<std::string> tmp;
			tmp.push_back(object.asString());
		}
		//Otherwise the iterator will point to the vector of paths for this particular item, so we push it back
		else
		{
			it->second.push_back(object.asString());
		}
	}
	//If the object is an array, then we run the function recursively for each of its items
	else if (object.isArray())
	{
		int count = 0;
		for (Json::ValueIterator it = object.begin(); it != object.end(); it++)
		{
			generate_path_table_helper(*it, partial_path + "[" + std::to_string(count) + "]");
			count++;
		}
	}
	//If it's some other object that isn't a string, we run it recursively
	else if (object.size() > 0)
	{
		for (Json::ValueIterator it = object.begin(); it != object.end(); it++)
		{
			generate_path_table_helper(*it, partial_path + "/" + it.key().asString());
		}
	}
}