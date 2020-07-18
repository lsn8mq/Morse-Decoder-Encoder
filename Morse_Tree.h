#pragma once
#include "Morse_node.h"
#include <sstream>
#include <string>
#include <map>
using namespace std;

class Morse_Tree {
private:
	Morse_Node* root;
	map<char, string> code_map;

public:


	void insert(Morse_Node* curr_root, char letter, string code) { 
		/*This method will be called recursively as the current_root is 
		updated everytime the Node to be inserted is pushed down
		the height of the Tree*/
		{
			if (curr_root == nullptr) {
			Morse_Node *letter = new Morse_Node(C, Str);
			newNode = letter;
		}

		else {
			if ((C < newNode->getChar())) {
				insert((newNode)->getLeft(), C, Str);
			}
		else if(C > newNode->getChar()){
			insert((newNode)->getRight(), C, Str);
	}
			
			
			
	void insert(char letter, string code) 
	{ // This is the wrapper insert method
    		insert(pHead, newC, newStr);
	}

	void print()
	{
    		print(pHead);
	}
			
			
	void build_tree(istream& read_in) {
		
		string line;
		while (read_in >> line) {
			
			char letter = line[0]; 
			string code = line.substr(1);
		//^We should try to include some error checking for these


		//	insert(letter, code);

			/*This can be where the insert wrapper can be called
			I have not encountered any errors when reading the file so i
			can HOPE that there should not be any issues when passing the 
			letter and the code to the insert function*/
			code_map[letter] = code;
			//cout << letter << " " << code << endl;
		}

	}
	string encode(string message) {
		/*This function should be pretty simple. 
		All it does is go through char by char through the message and 
		look up each char in the code_map and return a string where
		each char has been replaced by its code equivalent*/
		 
	}
	void decode(string coded_message) {
		/*This will definitely be the more complicated one, but i think
		between the slides, googling, and stack overflow, it should be 
		fairly straight up*/
	}

	/*I was thinking that maybe we would like to include a delete method
	and a function to print the tree so we can test it properly before we start 
	trying to play around with the decoding*/

	void print_map() {
		/*This function is only for testing to make sure that the map was
		properly constructed from the contents of the file*/
		for (map<char, string>::iterator it = code_map.begin(); it != code_map.end(); ++it) {
			cout << "letter: " << it->first << " code: " << it->second << endl;
		}
	}

};
