// Author: Tyler Travis
// Email: tyler.travis@aggiemail.usu.edu
// A#: A01519795

#include "AVL_tree/avl.h"
#include <iostream>

int main(int argc, char** argv)
{
	AVL tree, tree1;
	
	std::string fileName = "input.txt";

	tree1.Create_Tree(fileName);

	std::cout << "Inserting" << std::endl;
	tree.Insert(4);
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(2);
	tree.Insert(1);
	tree.Insert(7);
	tree.Insert(9);
	tree.Insert(8);
	tree.Insert(6);

	tree.Traverse(2);

	std::cout << "Deleting 1" << std::endl;
	tree.Delete(1);

	tree.Traverse(2);

	//std::cout << "Deleting 2" << std::endl;
	//tree.Delete(2);

	//tree.Traverse(2);

	std::cout << "Deleting 3" << std::endl;
	tree.Delete(3);

	tree.Traverse(2);

	std::cout << "Deleting 4" << std::endl;
	tree.Delete(4);
	
	tree.Traverse(2);


	std::cout << "Finding 6" << std::endl;
	std::cout << "6 found at " << tree.Search(6) << " height" << std::endl;

	return 0;
}
