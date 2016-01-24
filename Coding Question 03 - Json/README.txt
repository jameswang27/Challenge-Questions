This project contains the C++ code for Question 3.

A vital resource for this answer is:
https://github.com/open-source-parsers/jsoncpp

jsoncpp allowed the program to interpret a json file argument properly. 

The principle is to have a hashmap of items to all of the paths that lead to the item, then find a way to traverse a .json
and complete the hashmap. Then, we can simply look up items to get a vector of all of the paths for it.