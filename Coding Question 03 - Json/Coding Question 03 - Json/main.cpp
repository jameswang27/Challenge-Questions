#include "json/json.h"	//For json
#include <iostream>		//For cout
#include <fstream>		//For file streaming
#include "pathfinder.h"	//The code

using namespace std;

//Test by running the program with 1 argument: the json file
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "Usage: " << argv[0] << " filename.json" << endl;
		exit(1);
	}
	//cout << argv[0] << endl;
	//cout << argv[1] << endl;
	// Try to read the whole contents of the file into a string
	ifstream input_file(argv[1]);
	stringstream buffer;
	buffer << input_file.rdbuf();
	string contents(buffer.str());
	//Display the contents of the .json file we are testing
	cout << contents << endl;
	// now the contents of the file is in `contents`

	Pathfinder my_instance(contents);
	my_instance.generate_path_table();

	my_instance.print_path("item2");
	my_instance.print_path("item1");
	my_instance.print_path("something not there");

	return(0);
}
