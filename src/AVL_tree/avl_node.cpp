// Author: Tyler Travis
// Email: tyler.travis@aggiemail.usu.edu
// A#: A01519795

#include "avl_node.h"

AVL_Node::AVL_Node()
{
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}

AVL_Node::AVL_Node (AVL_Node* _parent, AVL_Node* _left = nullptr, AVL_Node* _right = nullptr)
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

void AVL_Node::setParent (AVL_Node* _parent)
{
	parent = _parent;
}

void AVL_Node::setData (int _data)
{
	data = _data;
}

void AVL_Node::setHeight (int _height)
{
	height = _height;
}

int AVL_Node::getData ();
{
	return data;
}

int AVL_Node::getHeight ();
{
	return height;
}

AVL_Node* AVL_Node::getRight ();
{
	return right;
}

AVL_Node* AVL_Node::getLeft ();
{
	return left;
}
