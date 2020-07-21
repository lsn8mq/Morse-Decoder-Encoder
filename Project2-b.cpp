// Project2-b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Morse_Tree.h"
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	string myText;

	
	ifstream MyReadFile("morse.txt");
	Morse_Tree my_tree;
	my_tree.build_tree(MyReadFile);
	/*^The above code reads in the file and passes it to the 
	build tree function in the Morse_Tree class*/

	//my_tree.print_map();
	string word = "hello";
	string coded_word = my_tree.encode(word);

	//cout << "Word: " << word << ", Coded Word: " << coded_word << endl;
	
	
	my_tree.print_tree();
	
	return 0;
}

