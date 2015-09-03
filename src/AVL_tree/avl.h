// Author: Tyler Travis
// Email: tyler.travis@aggiemail.usu.edu
// A#: A01519795

#include "avl_node.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class AVL
{
private:
	AVL_Node* root;
	int height;

	void Tree_Rotation (AVL_Node*);
	void Insert (AVL_Node*, AVL_Node*);

public:
	// Constructor for the AVL tree. This should initialize all the private member variables and set
	// everything to a good state.
	AVL ();

	// Create Tree:
	// This option should create a tree by reading an input file which contains one integer per line that
	// creates the tree. Every time this option is chosen, the existing tree should be deleted with 
	// delete_tree() and a tree with the given input file should be created.
	//
	// TODO: Write function to input the file
	void Create_Tree (std::string);

	// Insert:
	// This option should insert a node in the existing tree. The input integer value should be typed in by
	// the user. If no tree has been created before this option then the entered integer value should be
	// inserted anyway. By using this option multiple times, you should be able to create a tree.
	//
	// TODO: 
	void Insert (int);

	// Delete:
	// This option should delete a node from the existing tree. The input integer value should be typed in
	// by the user. If no tree has been created before this option, the program should print out "Node cannot
	// be deleted. Empty Tree!" If the entered integer valu is not found in the created tree, the program
	// should print out "Node cannot be found. Deletion cannot be performed"
	void Delete (int);

	// Search:
	// This option should search a node in the existing tree. The input integer value should be typed in by
	// the user.
	// Return: the height of the found node. Zero if not found.
	int Search (int);

	// Traverse:
	// Selecting this option should print out the options to choose the type of traversal to be performed:
	//	i. Pre_order
	//	ii. Post_order
	//	iii. In_order
	// The input to choose the type of traversal should be of int value.
	void Traverse ();

	// Delete Tree:
	// choosing this option should delete the whole existing tree. No inputs required.
	void Delete_Tree ();

	// Check Balance:
	// This option should not take any input. It should just check if the balance_factor is 1 or more.
	// If the balance_factor > 1. tree_rotation operations should be performed to balance the tree.
	// This operation should be performed automatically aftrer every create_tree, insertion and deletion
	// operation to check if the tree is an AVL tree (balance_factor = 1) or not.
	void Check_Balance ();
};
