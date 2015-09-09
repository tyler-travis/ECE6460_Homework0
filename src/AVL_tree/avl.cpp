// Author: Tyler Travis
// Email: tyler.travis@aggiemail.usu.edu
// A#: A01519795

#include "avl.h"

AVL::AVL ()
{
	root = nullptr;
}

void AVL::Create_Tree (std::string inputFile)
{
	// Create file input stream
	std::ifstream fileIn(inputFile);	

	// Make sure there is no error in opening the file
	if (!fileIn.is_open())
	{
		std::cout << "Error Opening File" << std::endl;
		return;	
	}
	
	// Temorary variable to read in the data from the file
	int inputData;
	while (fileIn >> inputData)
	{
		// Insert the data into the file
		Insert(inputData);
	}
	// Traverse the newly created tree in post-order
	Traverse(1);
}

void AVL::Insert (int data)
{
	// Create the new node with the correct data
	AVL_Node* node = new AVL_Node(data);

	// If root is the nullptr then set the new node as the root
	if(root == nullptr)
	{
		root = node;
	}
	// Otherwise insert the node into the tree
	else
	{
		Insert (root, node);
	}
}

void AVL::Insert (AVL_Node* curr_node, AVL_Node* node)
{
	// Compare to see if the current node is of greate value or not to the node to insert
	if (curr_node->getData() < node->getData())
	{
		// If the node the right doesn't have anything, insert the new node there
		if (curr_node->getRight() == nullptr)
		{
			curr_node->setRight(node);
			node->setParent(curr_node);
			return;
		}
		// If not, countinue down the tree to the right
		else
		{
			Insert(curr_node->getRight(), node);
		}
	}
	// Same as above but to the left instead
	else if (curr_node->getData() > node->getData())
	{
		if (curr_node->getLeft() == nullptr)
		{
			curr_node->setLeft(node);
			node->setParent(curr_node);
			return;
		}
		else
		{
			Insert(curr_node->getLeft(), node);
		}
	}
	// Check the balance to see if any tree rotations are needed
	//Check_Balance();
}

void AVL::Delete (int data)
{
	AVL_Node* node = Search_Node(data);
	
	if (node == nullptr)
	{
		return;
	}

	// If the node has no children just delete it
	else if (node->getRight() == nullptr && node->getLeft() == nullptr)
	{
		std::cout << "No Children" << std::endl;
		if (node == root)
		{
			root = nullptr;
		}
		if (node->getParent()->getLeft() == node)
		{
			node->getParent()->setLeft(nullptr);
		}
		else
		{
			node->getParent()->setRight(nullptr);
		}
		delete node;
		return;
	}
	
	// If it has one child, swith the child with the parent and delete the parent
	else if (node->getRight() == nullptr)
	{
		std::cout << "One Children" << std::endl;
		if (node == root)
		{
			root = node->getLeft();
		}
		// Check if the node is to the left or right to it's parent
		else if (node->getParent()->getLeft() == node)
		{
			// Switch spots
			node->getParent()->setLeft(node->getLeft());
			node->getLeft()->setParent(node->getParent());
			delete node;
		}
		else
		{
			node->getParent()->setRight(node->getLeft());
			node->getLeft()->setParent(node->getParent());
			delete node;
		}
	}
	else if (node->getLeft() == nullptr)
	{
		std::cout << "One Children" << std::endl;
		if (node == root)
		{
			root = node->getRight();
		}
		else if (node->getParent()->getLeft() == node)
		{
			node->getParent()->setLeft(node->getLeft());
			node->getLeft()->setParent(node->getParent());
			delete node;
		}
		else
		{
			node->getParent()->setRight(node->getRight());
			node->getRight()->setParent(node->getParent());
			delete node;
		}
	}
	// Node to delete has two children
	else
	{
		std::cout << "Two Children" << std::endl;
		Delete(node->getRight(), node);
	}
	//Traverse(1);
}

void AVL::Delete (AVL_Node* node, AVL_Node* node_to_delete)
{
	std::cout << "Node: " << node->getData() << std::endl;
	// Found the smallest value to the right of the node to delete
	if (node->getLeft() == nullptr)
	{
		// Check to see if the parent of the node is the one to delete
		if (node->getParent() == node_to_delete)
		{
			// Check to see if we need to replace root
			if (node_to_delete == root)
			{
				root = node;
			}
			// Set the correct left value
			node->setLeft(node_to_delete->getLeft());
			

			// Check to see if the left node is null or not
			if(node->getLeft() != nullptr)
			{
				// Set the correct parent
				node->getLeft()->setParent(node);
			}
		}
		else
		{
			// Check to see if the node to move has a child to the right
			if (node->getRight() != nullptr)
			{
				// Set the left subtree for the parent as the right subtree to the node to move
				node->getParent()->setLeft(node->getRight());
				node->getRight()->setParent(node->getParent());
			}
			else
			{
				// Remove node from the tree
				node->getParent()->setLeft(nullptr);
			}
			// Figure out what to set the parent as.
			if (node_to_delete == root)
			{
				root = node;
			}
			else
			{
				node->setParent(node_to_delete->getParent());
			}
			
			// Reattach the left and right subtrees
			node->setLeft(node_to_delete->getLeft());
			node->setRight(node_to_delete->getRight());
			if (node->getLeft() != nullptr)
			{
				node->getLeft()->setParent(node);
			}
			if (node->getRight() != nullptr)
			{
				node->getRight()->setParent(node);
			}
		}


		delete node_to_delete;
		return;
	}
	// Keep looking
	else
	{
		return Delete(node->getLeft(), node_to_delete);
	}
}

void AVL::Delete_Tree ()
{
	Delete_Tree(root);
}

void AVL::Delete_Tree (AVL_Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	Delete_Tree(node->getLeft());
	Delete_Tree(node->getRight());
	delete node;
}

AVL_Node* AVL::Search_Node (int data)
{
	return Search_Node(root, data);
}

AVL_Node* AVL::Search_Node (AVL_Node* node, int data)
{
	if (node->getData() == data)
	{
		return node;
	}

	else if(node->getLeft() != nullptr && node->getData() > data)
	{
		return Search_Node(node->getLeft(), data);
	}

	else if(node->getRight() != nullptr && node->getData() > data)
	{
		return Search_Node(node->getRight(), data);
	}
	else
	{
		return nullptr;
	}
}

int AVL::Search (int data)
{
	return Search(root, data);
}

int AVL::Search (AVL_Node* node, int data)
{
	if (node->getData() == data)
	{
		return node->getHeight();
	}
	else if (node->getData() > data)
	{
		return Search(node->getLeft(), data);
	}
	else
	{
		return Search(node->getRight(), data);
	}

}

void AVL::Traverse (int type)
{
	switch(type)
	{
		// Pre-order
		// 1. Display the data part of root element (or current element)
		// 2. Traverse the left subtree by recursively calling the pre-order function
		// 3. Traverse the right subtree by recursively calling the pre-order fuction
		case 1:
			Traverse (root, 1);
			break;
		// In-order (symmetric)
		// 1. Traverse the left subtree by recursively calling the in-order function
		// 2. Display the data part of root element (or current element)
		// 3. Traverse the right subtree by recursively calling the in-order function
		case 2:
			Traverse (root, 2);
			break;
		// Post-order
		// 1. Traverse the left subtree by recursively calling the post-order function
		// 2. Traverse the right subtree by recursively calling the post-order function
		// 3. Display the data part of root element (or current element)
		case 3:
			Traverse (root, 3);
			break;
		default:

			std::cout << "Error, " << type << " is not a valid number to choose from" << std::endl;
	}
}

void AVL::Traverse (AVL_Node* node, int type)
{
	// If the current node is the nullptr then return back up the recursion hole
	if(node == nullptr)
	{
		return;
	}
	switch(type)
	{
		// Pre-order
		// 1. Display the data part of root element (or current element)
		// 2. Traverse the left subtree by recursively calling the pre-order function
		// 3. Traverse the right subtree by recursively calling the pre-order fuction
		case 1:
			std::cout << node->getData() << std::endl;
			Traverse (node->getLeft(), 1);
			Traverse (node->getRight(), 1);
			break;
		// In-order (symmetric)
		// 1. Traverse the left subtree by recursively calling the in-order function
		// 2. Display the data part of root element (or current element)
		// 3. Traverse the right subtree by recursively calling the in-order function
		case 2:
			Traverse (node->getLeft(), 2);
			std::cout << node->getData() << std::endl;
			Traverse (node->getRight(), 2);
			break;
		// Post-order
		// 1. Traverse the left subtree by recursively calling the post-order function
		// 2. Traverse the right subtree by recursively calling the post-order function
		// 3. Display the data part of root element (or current element)
		case 3:
			Traverse (node->getLeft(), 3);
			Traverse (node->getRight(), 3);
			std::cout << node->getData() << std::endl;
			break;
	}
	return;
}

void AVL::Check_Balance ()
{
	Check_Heights (root, 0);
}

int AVL::Check_Heights (AVL_Node* node, int height)
{
	if (node == nullptr)
	{
		return height;
	}
	height++;
	int right = Check_Heights(node->getRight(), height);
	int left = Check_Heights(node->getLeft(), height);
	int balance = left - right;
	node->setHeight(balance);
	if (abs(balance) > 1)
	{
		// Imbalance is on left side if postive
		if (balance > 0)
		{
			// Imbalance is on left->left
			if (node->getLeft()->getHeight() > 0)
			{
				Left_Left_Tree_Rotation(node);	
			}
			// Imbalance is on left->right
			else
			{
				Left_Right_Tree_Rotation(node);	
			}

		}
		// Imbalance is on right side if negative
		else
		{
			// Imbalance is on right->left
			if (node->getRight()->getHeight() > 0)
			{
				Right_Left_Tree_Rotation(node);	
			}
			// Imbalance is on right->right
			else
			{
				Right_Right_Tree_Rotation(node);	
			}
		}
	}
	return 0;
}


void AVL::Right_Right_Tree_Rotation (AVL_Node* node)
{
	AVL_Node* right_subtree = node->getRight();
	AVL_Node* right_right_subtree = node->getRight()->getRight();

	// Correctly set parent for right subtree
	if (node == root)
	{
		root = right_subtree;
	}
	else
	{
		right_subtree->setParent(node->getParent());
	}

	// Correctly set left side of rotation
	right_subtree->setLeft(node);
	node->setParent(right_subtree);

	node->setRight(right_right_subtree);

	right_right_subtree->setParent(node);
}

void AVL::Right_Left_Tree_Rotation (AVL_Node* node)
{
	AVL_Node* right_subtree = node->getRight();
	AVL_Node* right_left_subtree = node->getRight()->getLeft();

	// Correctly set paret for right left subtree
	if (node == root)
	{
		root = right_left_subtree;
	}
	else
	{
		right_left_subtree->setParent(node->getParent());
	}
	
}

void AVL::Left_Left_Tree_Rotation (AVL_Node* node)
{
	AVL_Node* left_subtree = node->getLeft();
	AVL_Node* left_left_subtree = node->getLeft()->getLeft();

	// Correctly set parent for right subtree
	if (node == root)
	{
		root = left_subtree;
	}
	else
	{
		left_subtree->setParent(node->getParent());
	}

	// Correctly set left side of rotation
	left_subtree->setRight(node);
	node->setParent(left_subtree);

	node->setLeft(left_left_subtree);

	left_left_subtree->setParent(node);
}

void AVL::Left_Right_Tree_Rotation (AVL_Node* node)
{

}
