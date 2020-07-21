#pragma once
#include "Morse_node.h"
#include <sstream>
#include <string>
#include <map>
using namespace std;

class Morse_Tree {
private:
	Morse_Node *root;
	map<char, string> code_map;
	

public:
	
	Morse_Tree(){

		root = NULL;


	}

	void insert(Morse_Node* &curr_root, char letter, string code) { 
		/*This method will be called recursively as the current_root is 
		updated everytime the Node to be inserted is pushed down
		the height of the Tree*/
		
		
		char code_segment = code[0];
		
		if (curr_root == NULL) {
			curr_root = new Morse_Node();
			
		}
		
		if (code.size() == 0) {
			curr_root->letter = letter;
		}
		else {
			if (code_segment == '.') {
				insert(curr_root->left, letter, code.substr(1));

			}
			if (code_segment == '_') {
				insert(curr_root->right, letter, code.substr(1));

			}
		}


	}
	void build_tree(istream& read_in) {
		
		
		string line;
		while (read_in >> line) {
			
			char letter = line[0]; 
			string code = line.substr(1);
		//^We should try to include some error checking for these


			insert(root,letter, code);
			
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

		string coded_message;

		string::iterator it;
		for (it = message.begin(); it != message.end(); it++) {
			char curr_char = *it;
			string curr_code = code_map[curr_char];
			coded_message = coded_message + curr_code + " ";
		}

		return coded_message;
		 
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

	void print_tree() {
		print_tree(root);
	}

	void print_tree(Morse_Node *& curr_root) {  //prints the tree using preorder traversal
		if (curr_root == NULL) {
			return;
		}
		
		print_tree(curr_root->left);
		
		cout << curr_root->to_string();
		
		print_tree(curr_root->right);


	}

};