// Author: Tyler Travis
// Email: tyler.travis@aggiemail.usu.edu
// A#: A01519795

#include "AVL_tree/avl.h"
#include <iostream>
#include <string>

void printMenu();

int main(int argc, char** argv)
{
	int choice;

	AVL tree;

	std::string fileName;
	int inputInteger;

	do
	{
		printMenu();
		std::cin >> choice;


		switch(choice)
		{
			case 1:
				std::cout << "File to read from: ";
				std::cin >> fileName;
				tree.Create_Tree(fileName);
				std::cout << "Create Tree: ";
				tree.Traverse(2);
				break;
			case 2:
				std::cout << "Integer to enter: ";
				std::cin >> inputInteger;
				tree.Insert(inputInteger);
				std::cout << "Inserted: " << inputInteger << std::endl;
				tree.Traverse(2);
				break;
			case 3:
				std::cout << "Integer to delete: ";
				std::cin >> inputInteger;
				tree.Delete(inputInteger);
				std::cout << "Deleted: " << inputInteger << std::endl;
				tree.Traverse(2);
				break;
			case 4:
				std::cout << "Integer to search for: ";
				std::cin >> inputInteger;
				std::cout << "Search: Height of " << inputInteger << " is" << tree.Search(inputInteger) << std::endl;
				break;
			case 5:
				std::cout << "Enter number for traversal\n1. Pre Order\n2. Post Order\n3. In Order\nEnter: ";
				std::cin >> inputInteger;
				std::cout << "Traversal: " << std::endl;
				tree.Traverse(inputInteger);
				break;
			case 6:
				tree.Delete_Tree();
				std::cout << "Delete_Tree: Tree Deleted" << std::endl;
				break;
			case 7:
				tree.Check_Balance();
				break;
			case 8:
				break;
			case 9:
				tree.Pretty_Print();
				break;
			default:
				std::cout << "Wrong response, please re-enter a correct choice.";
		}
	} while(choice != 8);


	return 0;
}

void printMenu()
{
	std::cout << "AVL-Tree Menu" << std::endl;
	std::cout << "1. Create Tree" << std::endl;
	std::cout << "2. Insertion" << std::endl;
	std::cout << "3. Deleteion" << std::endl;
	std::cout << "4. Search" << std::endl;
	std::cout << "5. Traversal" << std::endl;
	std::cout << "6. Delete Tree" << std::endl;
	std::cout << "7. Check Balance" << std::endl;
	std::cout << "8. Exit" << std::endl;
	std::cout << "Enter Choose (1-8): ";
}
