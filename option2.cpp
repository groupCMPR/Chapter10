#include <iostream>
#include "input.h"
#include "bTree.h"

using namespace std;

int mainMenu();

void option2();

int main() {
	
	do {
		system("cls");
		switch (mainMenu()) {
		case 0: return EXIT_SUCCESS;
		case 2: option2(); break;

		default: "\n\t\tERROR - INVALID CHOICE"; break;
		}
		cout << "\n\n\t";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

int mainMenu() {
	cout << "\n\tCMPR131 Chapter 10: Trees";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Tree of strings";
	cout << "\n\t\t2> Tree container of integers";
	cout << "\n\t\t3> Animal Guessing Game";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(196));

	return inputInteger("\n\t\tOption: ", 0, 3);
}

char option2Menu() {
	cout << "\n\t2> bTree container";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\tA> Insert a node/leaf";
	cout << "\n\t\tB> Remove a node/leaf";
	cout << "\n\t\tC> Count of Nodes/leaves";
	cout << "\n\t\tD> Search a node/leaf";
	cout << "\n\t\tE> Pre-order traversal";
	cout << "\n\t\tF> In-order traversal";
	cout << "\n\t\tG> Post-order traveral";
	cout << "\n\t\tH> Delete the entire tree";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(100, char(205));

	return inputChar("\n\t\tOption: ", static_cast<string>("ABCDEFGH0"));
}

void option2() {
	
	bTree<int> tree;
	int number;
	int remove;
	int search;
	do {
		system("cls");
		switch (option2Menu()) {
		case '0': return;
		case 'A': 
			number = inputInteger("\n\t\tEnter an integer: ");
			tree.insert(number);
			break;
		case 'B':
			if (tree.isEmpty()) {
				cout << "\n\t\tERROR - bTree is empty";
				break;
			}
			remove = inputInteger("\n\t\tEnter a node/leaf to remove: ");
			if (tree.find(remove)) {
				cout << "\n\t\t" << remove << " has been removed from bTree.";
				tree.remove(remove);
			}
			else cout << "\n\t\t" << remove << " cannot be found.";
			break;
		case 'C': 
			cout << "\n\t\tCount of Nodes = " << tree.count();
			break;
		case 'D': 
			if (tree.isEmpty()) {
				cout << "\n\t\tERROR - bTree is empty";
				break;
			}

			search = inputInteger("\n\t\tEnter an integer key to search: ");

			if (tree.find(search)) {
				cout << "\n\t\t" << search << " is found.";
			}
			else {
				cout << "\n\t\t" << search << " cannot be found.";
			}

			break;
		case 'E': 
			if (tree.isEmpty()) {
				cout << "\n\t\tERROR - bTree is empty";
				break;
			}

			cout << "\n\t\tPre-order traversal of bTree with " << tree.count() << " nodes:\n";
			tree.preOrder();
			break;
		case 'F': 
			if (tree.isEmpty()) {
				cout << "\n\t\tERROR - bTree is empty";
				break;
			}

			cout << "\n\t\tIn-order traveral of bTree with " << tree.count() << " nodes:\n";
			tree.inOrder();
			break;
		case 'G':
			if (tree.isEmpty()) {
				cout << "\n\t\tERROR - bTree is empty";
				break;
			}

			cout << "\n\t\tPost-order traveral of bTree with " << tree.count() << " nodes:\n";
			tree.postOrder();
			break;
		case 'H':
			if (tree.isEmpty()) {
				cout << "\n\t\tERROR - bTree is empty";
				break;
			}
			cout << "\n\t\tAll " << tree.count() << " nodes/leaves have been destroyed.";
			tree.deleteTree();
			break;
		}
		cout << "\n\n\t";
		system("pause");
	} while (true);


	
}


