#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Morse_Node {

public:
	char letter;

	Morse_Node* left;
	Morse_Node* right;
	Morse_Node() {

	}
	Morse_Node(const Morse_Node& other) {
		letter = other.letter;
		left = other.left;
		right = other.right;
	}
	Morse_Node(char new_letter) {
		letter = new_letter;
		left = NULL;
		right = NULL;
		
	}
	const string to_string() const { //to string method for testing the tree
		ostringstream buffer;
		buffer  << letter;
		return buffer.str();
	}
	/*This is pretty simple for a Node of a binary tree. I really dont
	think that we will need to change this too much*/
};