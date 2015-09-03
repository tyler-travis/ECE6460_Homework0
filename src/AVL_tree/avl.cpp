// Author: Tyler Travis
// Email: tyler.travis@aggiemail.usu.edu
// A#: A01519795

#include "avl.h"

AVL::AVL ()
{
	root = nullptr;
	height = 0;
}

void AVL::Create_Tree (std::string inputFile)
{
	std::ifstream fileIn(inputFile);	
	if (!fileIn.is_open())
	{
		std::cout << "Error Opening File" << std::endl;
		return;	
	}
	int inputData;
	while (fileIn >> inputData)
	{
		Insert(inputData);
	}
	Traverse(1);
}

void AVL::Insert (int data)
{
	AVL_Node* node();
	node.setData(data);

	if(height == 0)
	{
		node.setHeight(1);
		root = node;
		height = 1;
	}
	else
	{
		Insert (root, node);
	}
}

void AVL::Insert (AVL_Node* curr_node, AVL_Node* node)
{
	if (curr_node->getData() > node->getData())
	{
		if (curr_node->getRight() == nullptr)
		{
			curr_node->setRight(node);
			node->setParent(curr_node);
			node->setHeight(curr_node->getHeight() + 1);
			return;
		}
		else
		{
			Insert(curr_node->getRight(), node);
		}
	}
	else if (curr_node->getData() < node->getData())
	{
		if (curr_node->getLeft() == nullptr)
		{
			curr_node->setLeft(node);
			node->setParent(curr_node);
			node->setHeight(curr_node->getHeight() + 1);
			return;
		}
		else
		{
			Insert(curr_node->getLeft(), node);
		}
	}
}

void AVL::Delte (int data)
{

}

int AVL::Search (int data)
{

}

void AVL::Traverse (int type)
{

}

void AVL::Tree_Rotation (AVL_Node* node)
{

}
