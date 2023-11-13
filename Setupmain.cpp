//Names: Alexis Martinez, Angie Campos, Daniel Hernandex, John Kim, Neidy Malaga, & Vivian Huynh
//Date: 11/5/2023
//Description: Chapter 10 Assignment - Trees

//Groups
//Option 1 (tree of strings): Daniel
//Option 2 (tree container of integers): Alexis
//Option 3 (animal guessing game): Neidy and Vivian
//main.cpp: Vivian set up the main.cpp
#include <iostream> //For cout
#include <fstream>  //For files
#include <string>

//HEADER FILE
#include "input.h"  //For input validation
#include "binary_tree_node.h"
#include "bTree.h"

using namespace std;

//PROTOTYPES
int menuOption();

//Option 1 - Tree of strings
void option1();
//Option 2 - Tree container of integers
void option2();
//Option 3 - Animal Guessing Game (Vivian)
void option3();
void set_Tree(ifstream&, binary_tree_node<string>*);
void animalGuessedRecursion(binary_tree_node<string>*);
void save_File(ofstream&, binary_tree_node<string>*);

//Precondition : N/A
//Posctondition: Calls option 1, 2, and 3
int main()
{
    do
    {
        system("cls");
        switch (menuOption())
        {
        case 0: exit(0);
        case 1: system("cls"); option1(); break;
        case 2: system("cls"); option2(); break;
        case 3: system("cls"); option3(); break;
        default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
    return 0;
}

//Precondition : Calls from main
//Posctondition: Returns integer choice
int menuOption()
{
    cout << "\n\tCMPR131 Chapter 10: Trees (Final Group 11)";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t\t1> Tree of strings";
    cout << "\n\t\t2> Tree container of integers";
    cout << "\n\t\t3> Animal Guessing Game";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t\t0> Exit";
    cout << "\n\t" << string(100, char(205));

    return inputInteger("\n\t\tOption: ", 0, 3);
}

void option1()
{
    // create root node
    binary_tree_node<string>* root = new binary_tree_node<string>("trunk", nullptr, nullptr);

    cout << "\n\tA> Created root (" << root->getData() << ") with no leaf.\n";
    cout << '\n';

    // print initial tree structure
    print_tree<string>("\t\t", root, false, true, true);

    // grow two branches
    binary_tree_node<string>* branch1 = new binary_tree_node<string>("branch #1", nullptr, nullptr);
    binary_tree_node<string>* branch2 = new binary_tree_node<string>("branch #2", nullptr, nullptr);

    cout << "\n\tB> Root (" << root->getData() << ") grows two branches: " << branch1->getData() << " and " << branch2->getData() << ".\n";
    root->setLeft(branch1);
    cout << "\t\tA branch of (" << root->getLeft()->getData() << ") grows left of the root.\n";
    root->setRight(branch2);
    cout << "\t\tA branch of (" << root->getRight()->getData() << ") grows right of the root.\n";

    // print tree structure after growing branches
    print_tree<string>("\t\t", root, false, true, true);

    // branches grow leaves.
    cout << "\n\tC> Branches grow leaves.";

    /// Creating the initial tree
    binary_tree_node<string>* leaf1 = new binary_tree_node<string>("leaf #1", nullptr, nullptr);
    binary_tree_node<string>* leaf2 = new binary_tree_node<string>("leaf #2", nullptr, nullptr);
    binary_tree_node<string>* leaf3 = new binary_tree_node<string>("leaf #3", nullptr, nullptr);
    binary_tree_node<string>* leaf4 = new binary_tree_node<string>("leaf #4", nullptr, nullptr);


    branch1->setLeft(leaf1);
    branch2->setLeft(leaf2);

    cout << "\n\t\tLeft branch of (branch #1) grows two leaves: leaf #1 and leaf #2.\n\n";
    // print tree structure before deletion
    print_tree<string>("\t\t", root, false, true, true);

    // replace leaf2 with leaf3 in the right branch of branch #2
    branch2->setLeft(leaf3);
    branch2->setRight(leaf4);

    // delete the old leaf2
    delete leaf2;

    cout << "\n\t\tRight branch of (branch #1) grows two leaves: leaf #1 and leaf #2.\n\n";
    // print tree structure after deletion
    print_tree<string>("\t\t", root, false, true, true);


    // left leaf sprouts and yields a fruit
    cout << "\n\tD>. Left leaf sprouts and yields a fruit (apple).\n";

    binary_tree_node<string>* appleNode = new binary_tree_node<string>("apple", nullptr, nullptr);    leaf1->setLeft(appleNode);

    // print tree structure after growing the apple on the left leaf
    print_tree<string>("\t\t", root, false, true, true);

    // right leaf sprouts and yields two fruits
    cout << "\n\tE> Right leaf sprouts and yields two fruits (orange and coconut).\n";

    binary_tree_node<string>* orangeNode = new binary_tree_node<string>("orange", nullptr, nullptr);


    binary_tree_node<string>* coconutNode = new binary_tree_node<string>("coconut", nullptr, nullptr);

    // assuming branch2 is the right branch and leaf3 is the left leaf
    branch2->setLeft(new binary_tree_node<string>("leaf #3", orangeNode, coconutNode));

    // set leaf4 as the right child of branch2
    branch2->setRight(new binary_tree_node<string>("leaf #4", nullptr, nullptr));

    // print tree structure after growing orange and coconut on the right leaf
    print_tree<string>("\t\t", root, false, true, true);


    // delete tree
    cout << "\n\tF> Delete tree.\n";
    delete_tree<string>(root);
}

char option2Menu()
{
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

    return inputChar("\n\t\tOption: ", static_cast<string>("0ABCDEFGH"));
}
void option2()
{
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


/*----------------------------------------------------------------

                    OPTION 3 - ANIMAL TAXONOMY BINARY TREE

----------------------------------------------------------------*/

char menuOption3()
{
    cout << "\n\tWelcome to Animal Guessing Game";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t\tA> Play the game";
    cout << "\n\t\tB> Save the game file";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t\t0> return";
    cout << "\n\t" << string(100, char(205));

    return inputChar("\n\t\tOption: ", static_cast<string>("0AB"));
}

void option3()
{
    string line = ""; //line to store first sentence

    ifstream inputFile("animal.txt"); //open file

    //error checks for failing open, empty file
    if (inputFile.fail())
    {
        cout << "\n\tERROR: File animal.txt cannot be found.\n";
        return;
    }
    if (inputFile.peek() == fstream::traits_type::eof()) {
        cout << "\n\tERROR: File is empty";
        return;
    }

    //get root using first line
    getline(inputFile, line);
    binary_tree_node<string>* root = new binary_tree_node<string>(line.substr(1, line.size() - 2), nullptr, nullptr);
    binary_tree_node<string> animal_tree(*root);

    //sets the file tree
    set_Tree(inputFile, root);
 
    inputFile.close();

    cout << "\n\t3> Animal Guessing Game";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\tA game tree for a simple game of \"animal\" twenty questions would look like:\n";
    cout << "\n\t\t\t\t\t[ Is it a mammal? ]";
    cout << "\n\t\t\t\t\t    /         " << char(92);
    cout << "\n\t\t\t\t\t   /           " << char(92);
    cout << "\n\t\t\t[ Does it have stripes? ]     [ Is it a bird? ]";
    cout << "\n\t\t\t      /       " << char(92) << "                  /       " << char(92);
    cout << "\n\t\t\t     /         " << char(92) << "                /         " << char(92);
    cout << "\n\t\t\t( Zebra )    ( Lion )   [ Does it fly? ]  ( Gila monster )";
    cout << "\n\t\t\t\t\t\t    /       " << char(92);
    cout << "\n\t\t\t\t\t\t   /         " << char(92);
    cout << "\n\t\t\t\t\t   ( Eagle )     ( Penguin )\n";
    cout << "\n\tA learning version of twenty questions: one that not only plays the game, but learns new";
    cout << "\n\tobjects when it loses.\n";

    do
    {
        switch (menuOption3())
        {

        case '0': cout << "\n\tThank you for teaching AI a thing or two.\n"; return;
        case 'A':
        {
            cout << "\n\tThink of an animal and press the RETURN/ENTER key to begin...";
            cin.get(); //for system pause
            animalGuessedRecursion(root);
            system("pause");
            system("cls");
        }break;
        case 'B':
        {
            ofstream outputFile("animal.txt");
            save_File(outputFile, root);
            outputFile.close();
            cout << "\n\tNew data file. animal.txt, has been saved.\n";
        }break;
        default: "\t\tERROR: - Invalid option. Please re-enter"; break;
        }
    } while (true);

    delete_tree(root); //deletes tree 
}

//precondition: A full/complete binary tree set up in a text file (for best organization), the root node
// NOTICE: Be aware of your () leaves as if there are two leaves under a branch, set_Tree will assume 
// those two leaves belong to that branch - [] () ()
// Also if you have one leaf and one branch under a branch, it will automatically assume the branch is also a leaf
// [] () []
//postcondition: sets up the file binary tree
void set_Tree(ifstream& inputFile, binary_tree_node<string>* node) {
    string line;

    //only continues if file has a line, acts as a stop case
    if (getline(inputFile, line)) {

        //puts line into a node
        binary_tree_node<string>* left_node = new binary_tree_node<string>(line.substr(1, line.size() - 2), nullptr, nullptr);

        //if it is a branch, sets as left node first, then recurses to set the 
        //following left branches
        //when it returns it will set up the right branch if available
        if (line[0] == '[') {
            node->setLeft(left_node);
            set_Tree(inputFile, left_node);
            if (getline(inputFile, line)) {
                binary_tree_node<string>* right_node = new binary_tree_node<string>(line.substr(1, line.size() - 2), nullptr, nullptr);
                node->setRight(right_node);

                //if node is a branch, recurses to get leaves 
                if(line[0] == '[')
                  set_Tree(inputFile, right_node);
            }
            return;
        }

        //if leaf will set to a left leaf, if another leaf is there also sets as right leaf
        //if there is a branch instead of a right leaf, skips setting it and returns it to orignial position
        //as it will be returned to be set into right branch 
        if (line[0] == '(') {
            node->setLeft(left_node);

            if (getline(inputFile, line)) {//&& line[0] == '(') {
                binary_tree_node<string>* right_node = new binary_tree_node<string>(line.substr(1, line.size() - 2), nullptr, nullptr);
                node->setRight(right_node);

                //if node is a branch, recurses to get leaves 
                if (line[0] == '[')
                    set_Tree(inputFile, right_node);
            }

        }

    }
}

//precondition: binary tree must have root
//postcondition: traverses through binary tree and adds on or simply stops traversing 
void animalGuessedRecursion(binary_tree_node<string>* node)
{
    //stop case
    //if we are at the last option
    if (node->isLeaf())
    {
        cout << "\n\tMy guess is a " << node->getData();
        //if correct guess, else adds on to binary tree
        if(inputChar(" (Y - yes or N - no) ? ") == 'Y' )
            cout << "\n\tYes, I knew it all along!\n";
        else{
            //gets player animal
            string input = inputString("\n\tI give up. What are you?\n\t", true);

            //gets player question
            cout << "\n\tPlease specify a yes / no question that will distinguish a(n) " << input << " from a(n) " << node->getData() << ".";
            string question = inputString("\n\tEnter your question that ends with a '?': ", true);
            
            string left = "", right = ""; //to find where to place nodes

            //is the animal at right (yes), or left (no)
            cout << "\n\tAs a(n) " << input << ", " << question;
            if (inputChar(" (Y - yes or N - no) ") == 'Y') {
                left = input;
                right = node->getData();
            }
            else {
                right = input;
                left = node->getData();
            }

            //makes node
            binary_tree_node<string>* left_node = new binary_tree_node<string>(left, nullptr, nullptr);
            binary_tree_node<string>* right_node = new binary_tree_node<string>(right, nullptr, nullptr);

            //replaces this node with question, and sets its left and right animal
            node->setData(question); 
            node->setLeft(left_node);
            node->setRight(right_node);
        }
        return; //stops it from going forward
    }


    //ask question
    cout << "\n\t" << node->getData();

    //if yes moves left, if no moves right
    if (inputChar("\n\t(Y-yes or N-no): ") == 'Y') 
        node = node->getLeft();
    else 
        node = node->getRight();

    animalGuessedRecursion(node); //recurses
  
}

//precondition: file to hold in node data, root of binary tree
//postcondition: traverses and saves data into file (traverses left branches, 
//left leaves, and right leaves first)
void save_File(ofstream& outputFile, binary_tree_node<string>* node) {

    //if a leaf, give () in string, else a branch give [] in string
    if (node->isLeaf())
        outputFile << "(" << node->getData() << ")\n";
    else
        outputFile << "[" << node->getData() << "]\n";

    //start at left until it hits NULL (or last left leave)
    // then returns to previous node's right leaf if available
    if (node->getLeft() != NULL) {
        save_File(outputFile, node->getLeft());
        if (node->getRight() != NULL)
            save_File(outputFile, node->getRight());
    }
}
