#include "BinaryTree.h"

extern BinaryTree *treeDisplay;
extern BinaryTree *treeSound;
extern BinaryTree *treeGeneral;

// Contructor to init Tree
BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	destroy_tree();
}

/*
* Function to detroy tree
*/
void BinaryTree::destroy_tree(Node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

/*
* Function to detroy tree
*/
void BinaryTree::destroy_tree()
{
	destroy_tree(root);
}

/*
* The function to insert new node into binary tree
*/
void BinaryTree::insert(Setting *data)
{

	// If root is NULL, then create data for root
	if (root == NULL)
	{
		root = new Node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{ // Create data for child
		insert(root, data);
	}
}

/*
* The function to insert new node into binary tree
*/
void BinaryTree::insert(Node *node, Setting *data)
{

	// If personal key of data is smaller than personal key of node
	// Go to left node
	if (data->getPersonalKey() < node->data->getPersonalKey())
	{

		// If node left is NULL then create data
		if (node->left == NULL)
		{
			node->left = new Node;
			node->left->data = data;
			node->left->left = NULL;
			node->left->right = NULL;
		}
		else
		{ // If not, go to next left node
			insert(node->left, data);
		}
	}
	else
	{ // If personal key of data is greater than personal key of node => Go to right node

		// If node right is NULL then create data
		if (node->right == NULL)
		{
			node->right = new Node;
			node->right->data = data;
			node->right->left = NULL;
			node->right->right = NULL;
		}
		else
		{ // If not, go to next right node
			insert(node->right, data);
		}
	}
}

/*
* The function to search node by personal key
*/
Node *BinaryTree::searchByPersonalKey(Node *node, string personalKey)
{
	// If node is not NULL
	if (node != NULL)
	{
		// If personal key is equal with personal key of node
		if (personalKey == node->data->getPersonalKey())
		{
			return node;
		}
		// If personal key is smaller than personal key of node => go to next left node
		if (personalKey < node->data->getPersonalKey())
		{
			return searchByPersonalKey(node->left, personalKey);
		}
		// If personal key is greater than or equal with personal key of node => go to next right node
		else
		{
			return searchByPersonalKey(node->right, personalKey);
		}
	}
	else
	{ // If tree is NULL then return NULL
		return NULL;
	}
}

/*
* The function to search node by personal key
*/
Node *BinaryTree::searchByPersonalKey(string personalKey)
{
	return searchByPersonalKey(root, personalKey);
}

/*
* The function to search node by owner name
*/
void BinaryTree::searchByName(string name)
{
	count = 0;				  //kiem tra xem co tim thay name trong tree k, neu tim thay thi count > 0
	searchByName(name, root); //thuc hien tim kim dua vao name va in ra luon
	if (count == 0)			  // If is not found
	{
		cout << "NOT FOUND!!! \n"
			 << endl;
	}
}

/*
* The function to search node by owner name
*/
void BinaryTree::searchByName(string name, Node *node)
{

	// if node not NULL
	if (node != NULL)
	{

		// Go to left node to search data
		searchByName(name, node->left);
		// ss owner name voi owner name cua node trong cay
		int res = name.compare(node->data->getCarName());

		Node *resultDisplay;
		Node *resultSound;
		Node *resultGeneral;
		// neu name dang tim duoc tim thay trong cay thi in ra
		if (res == 0)
		{
			cout << setw(10) << left << ++count << setw(30) << left << "Owner name" << setw(35) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(25) << left << "Remind Service (km)" << endl;
			cout << setw(10) << left << ""
				 << setw(30) << left << node->data->getCarName()
				 << setw(35) << left << node->data->getEmail()
				 << setw(20) << left << node->data->getPersonalKey()
				 << setw(20) << left << node->data->getODO()
				 << setw(25) << left << node->data->getServiceRemind() << endl;

			//dua vao ten da tim thay thi lay mscn cua no di tim trong tree display, sound, general
			resultDisplay = treeDisplay->searchByPersonalKey(node->data->getPersonalKey());
			resultSound = treeSound->searchByPersonalKey(node->data->getPersonalKey());
			resultGeneral = treeGeneral->searchByPersonalKey(node->data->getPersonalKey());

			//chuyen node qua kieu du lieu dispay, sound, general de in ra thong tin cua tung loai
			Display *dpl_result = dynamic_cast<Display *>(resultDisplay->data);
			Sound *s_result = dynamic_cast<Sound *>(resultSound->data);
			General *g_result = dynamic_cast<General *>(resultGeneral->data);

			//in data cua Display
			cout << setw(20) << left << "Display:" << setw(15) << "Light level" << setw(20) << "Screen Light level" << setw(15) << "Taplo Light" << endl;
			cout << setw(20) << left << ""
				 << setw(15) << dpl_result->get_light_level()
				 << setw(20) << dpl_result->get_screen_light_level()
				 << setw(15) << dpl_result->get_taplo_light_level() << endl;

			//in data cua Sound
			cout << setw(20) << left << "Sound:" << setw(10) << left << "Media" << setw(10) << left << "Call" << setw(15) << left << "Navigation" << setw(10) << left << "Notify" << endl;
			cout << setw(20) << left << ""
				 << setw(10) << s_result->get_media_level()
				 << setw(10) << s_result->get_call_level()
				 << setw(15) << s_result->get_navi_level()
				 << setw(10) << s_result->get_notification_level() << endl;

			//in data cua General
			cout << setw(20) << "General:" << setw(20) << "Timezone" << setw(50) << "Language" << endl;
			cout << setw(20) << left << ""
				 << setw(20) << "GMT" + g_result->get_timeZone()
				 << setw(50) << g_result->get_language() << endl;
			cout << endl
				 << endl;
		}

		// Go to right node to search data
		searchByName(name, node->right);
	}
}

/*
* The function use inorder traversal to print data out MSCN
*/
void BinaryTree::printTree(Node *node, int type)
{
	// check if node is not NULL
	if (node != NULL)
	{
		// go to left node
		printTree(node->left, type);

		// Check type to print the corect type out
		// if type is display
		switch (type)
		{
		case 1: // The case type is Display
			// print value
			// cast is executed at runtime, not compile time.
			if (dynamic_cast<Display *>(node->data) != NULL)
			{
				dynamic_cast<Display *>(node->data)->xuatThongTin();
			}
			break;

		case 2: // The case type is Display
			// print value
			if (dynamic_cast<Sound *>(node->data) != NULL)
			{
				dynamic_cast<Sound *>(node->data)->xuatThongTin();
			}
			break;

		case 3: // The case type is Display
			// print value
			if (dynamic_cast<General *>(node->data) != NULL)
			{
				dynamic_cast<General *>(node->data)->xuatThongTin();
			}
			break;
		}

		// go to right node
		printTree(node->right, type);
	}
}

/*
* The function print data in tree
*/
void BinaryTree::printTree(int type)
{
	printTree(root, type);
}

/*
* The function to get all data of Display and return to vector
*/
void BinaryTree::getAllDisplay(Node *node, vector<Display *> *v_display)
{
	// if node is not NULL
	if (node != NULL)
	{
		// go to left node
		getAllDisplay(node->left, v_display);
		// push to vector
		v_display->push_back(dynamic_cast<Display *>(node->data));
		// go to right node
		getAllDisplay(node->right, v_display);
	}
}

/*
* The function to get all data of Display and return to vector
*/
vector<Display *> *BinaryTree::getAllDisplay(vector<Display *> *v_display)
{
	getAllDisplay(root, v_display);
	return v_display;
}

/*
* The function to get all data of Sound and return to vector
*/
void BinaryTree::getAllSound(Node *node, vector<Sound *> *v_sound)
{
	// if node is not NULL
	if (node != NULL)
	{
		// go to left node
		getAllSound(node->left, v_sound);
		// push to vector
		v_sound->push_back(dynamic_cast<Sound *>(node->data));
		// go to right node
		getAllSound(node->right, v_sound);
	}
}

/*
* The function to get all data of Sound and return to vector
*/
vector<Sound *> *BinaryTree::getAllSound(vector<Sound *> *v_sound)
{
	getAllSound(root, v_sound);
	return v_sound;
}

/*
* The function to get all data of General and return to vector
*/
void BinaryTree::getAllGeneral(Node *node, vector<General *> *v_general)
{
	// if node is not NULL
	if (node != NULL)
	{
		// go to left node
		getAllGeneral(node->left, v_general);
		// push to vector
		v_general->push_back(dynamic_cast<General *>(node->data));
		// go to right node
		getAllGeneral(node->right, v_general);
	}
}

/*
* The function to get all data of General and return to vector
*/
vector<General *> *BinaryTree::getAllGeneral(vector<General *> *v_general)
{
	getAllGeneral(root, v_general);
	return v_general;
}