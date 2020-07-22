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
			/*Base case for the recursive function*/
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
			string curr_code = code_map[curr_char];					// simple stores each letter and its corresponding code into the map
			coded_message = coded_message + curr_code + " ";
		}

		return coded_message;
		 
	}
	string decode(string coded_message) {
		/*This method parses through the string of morse code
		and will return its alphanumeric equivalence */
		string decoded_message;

		istringstream message(coded_message);
		do {
			string word;
			message >> word;
			
			char letter= find_letter(root, word);
			/*^calls the function with the tree's root as the starting
			point */
			decoded_message+=letter;

		} while (message);

		
		return decoded_message;
	}
	char find_letter(Morse_Node *& curr_root,string code) {
		/*Recursive function that traverses through the tree by parsing 
		through the morse code values*/
		
		if (code.size() == 0) {
			/*Base case for the recursive call. Since this method
			cuts off the first char of the morse code every time the
			method is called.*/
			char ret = curr_root->letter;
			
			
			return ret;
		}
		char code_segment = code[0];
		
		if (curr_root == NULL) {
			cout << "Invalid code" << endl;
		}
		else {
			if (code_segment == '.') {
				/*Determines if the traversal needs to go left*/
				return find_letter(curr_root->left, code.substr(1));
			}
			if (code_segment == '_') {
				/*Determines if the traversal needs to go right*/
				return find_letter(curr_root->right, code.substr(1));
			}
		}
		
	}

	
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