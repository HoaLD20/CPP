#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "Setting.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"


// Create a struct Node
struct Node {
	Setting* data;
	Node* left;
	Node* right;
};

class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();
	void destroy_tree();
	void destroy_tree(Node* node);

	// Functions to insert
	void insert(Setting* data);
	void insert(Node* node, Setting* data);

	// Functions to search
	Node* searchByPersonalKey(string personalKey);
	Node* searchByPersonalKey(Node* data, string personalKey);
	void searchByName(string name);
	void searchByName(string name, Node* node);

	// Function to print out data
	void printTree(int type);
	void printTree(Node* node, int type);

	// Function to get all data of Display, Sound and General
	vector<Display*>* getAllDisplay(vector<Display*>* v_display);
	void getAllDisplay(Node* node, vector<Display*>* v_display);

	vector<Sound*>* getAllSound(vector<Sound*>* v_sound);
	void getAllSound(Node* node, vector<Sound*>* v_sound);

	vector<General*>* getAllGeneral(vector<General*>* v_general);
	void getAllGeneral(Node* node, vector<General*>* v_general);
private:
	Node* root;
	int count = 0;
};

#endif /* BINARYTREE_H_ */