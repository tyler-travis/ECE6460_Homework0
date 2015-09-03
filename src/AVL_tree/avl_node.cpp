#include "avl_node.h"

AVL_Node::AVL_Node()
{
	parent = NULL;
	left = NULL;
	right = NULL;
}

AVL_Node::AVL_Node (AVL_Node* _parent, AVL_Node* _left = NULL, AVL_Node* _right = NULL)
{
	parent = _parent;
	left = _left;
	right = _right;
}

void AVL_Node::setLeft (AVL_Node* _left)
{
	left = _left;
}

void AVL_Node::setRight (AVL_Node* _right)
{
	right = _right;
}

void AVL_Node::setData (int _data)
{
	data = _data;
}

void AVL_Node::setHeight (int _height)
{
	height = _height;
}
