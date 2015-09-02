// Author: Tyler Travis
// Email: tyler.travis@aggiemail.usu.edu
// A#: A01519795

class AVL_Node
{
	int data;
	int height;
	AVL_Node* left;
	AVL_Node* right;
	AVL_Node* parent;

	// Constructor for the AVL_Node class
	// This takes the address of the parent node
	// and the left and right nodes if they exist
	AVL_Node (AVL_Node* _parent, AVL_Node* _left = null, AVL_Node* _right = null)
	{
		parent = _parent;
		left = _left;
		right = _right;
	}
};
