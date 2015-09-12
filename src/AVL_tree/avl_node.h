// Author: Tyler Travis
// Email: tyler.travis@aggiemail.usu.edu
// A#: A01519795

#ifndef AVL_NODE_H
#define AVL_NODE_H

class AVL_Node
{
private:
	int data;
	int height;
	AVL_Node* left;
	AVL_Node* right;
	AVL_Node* parent;

public:
	// Constructor for the AVL_Node class
	// This takes the address of the parent node
	// and the left and right nodes if they exist
	AVL_Node ();
	AVL_Node (int);
	AVL_Node (AVL_Node*, AVL_Node*, AVL_Node*);
	void setLeft (AVL_Node*);
	void setRight (AVL_Node*);
	void setParent (AVL_Node*);
	void setData (int);
	void setHeight (int);
	int getData ();
	int getHeight ();
	AVL_Node* getRight ();
	AVL_Node* getLeft ();
	AVL_Node* getParent ();
};

#endif
