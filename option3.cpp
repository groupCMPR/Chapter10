//Names: Alexis Martinez, Angie Campos, Daniel Hernandex, John Kim, Neidy Malaga, & Vivian Huynh
//Date: 11/5/2023
//Description: Chapter 10 Assignment - Trees

#include <iostream> //For cout
#include <fstream>  //For files

//HEADER FILE
#include "input.h"  //For input validation
using namespace std;

//PROTOTYPES
int menuOption();

//Option 1 - Tree of strings
void option1();
//Option 2 - Tree container of integers
void option2();
//Option 3 - Animal Guessing Game (Vivian)
void option3();
bool animalGuessedRecursion(char choice, string fileInput);

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

void menuOption1()
{
    cout << "\n\tA> Created root (trunk) with no leaf.\n";
    cout << "\n\t\t\ttrunk\n";
    cout << "\n\tB> Root (trunk) grows two branches: branch #1 and branch #2.";
    cout << "\n\t\tA branch of (branch #1) grows left of the root.";
    cout << "\n\t\tA branch of (branch #2) grows right of the root.\n";
    cout << "\n\t\t\ttrunk";
    cout << "\n\t\t\t" << char(195) << string(3, char(196)) << " branch #1";
    cout << "\n\t\t\t" << char(192) << string(3, char(196)) << " branch #2";
    cout << '\n';
    cout << "\n\tC> Branches grows leaves.\n";
    cout << "\n\t\tLeft branch of (branch #1) grows two leaves: leaf #1 and leaf #2.\n";
    cout << "\n\t\t\ttrunk";
    cout << "\n\t\t\t" << char(195) << string(3, char(196)) << " branch #1";
    cout << "\n\t\t\t" << char(179) << "   " << char(195) << string(3, char(196)) << " leaf #1";
    cout << "\n\t\t\t" << char(192) << string(3, char(196)) << " branch #2";
    cout << "\n\t\t\t    " << char(192) << string(3, char(196)) << " leaf #2";
    cout << '\n';
    cout << "\n\t\tRight branch of (branch #2) grows two leaves: leaf #3 and leaf #4.";
    cout << "\n\t\t\ttrunk";
    cout << "\n\t\t\t" << char(195) << string(3, char(196)) << " branch #1";
    cout << "\n\t\t\t" << char(179) << "   " << char(195) << string(3, char(196)) << " leaf #1";
    cout << "\n\t\t\t" << char(192) << string(3, char(196)) << " branch #2";
    cout << "\n\t\t\t    " << char(195) << string(3, char(196)) << " leaf #3";
    cout << "\n\t\t\t    " << char(192) << string(3, char(196)) << " leaf #4";
    cout << '\n';
    cout << "\n\tD> Left leaf sprouts and yields a fruit (apple).\n";
    cout << "\n\t\t\ttrunk";
    cout << "\n\t\t\t" << char(195) << string(3, char(196)) << " branch #1";
    cout << "\n\t\t\t" << char(179) << "   " << char(195) << string(3, char(196)) << " leaf #1";
    cout << "\n\t\t\t" << char(179) << "   " << char(179) << "   " << char(195) << string(3, char(196)) << " apple";
    cout << "\n\t\t\t" << char(192) << string(3, char(196)) << " branch #2";
    cout << "\n\t\t\t    " << char(195) << string(3, char(196)) << " leaf #3";
    cout << "\n\t\t\t    " << char(192) << string(3, char(196)) << " leaf #4";
    cout << '\n';
    cout << "\n\tE> Right leaf sprouts and yields two fruits (orange and coconut).\n";
    cout << "\n\t\t\ttrunk";
    cout << "\n\t\t\t" << char(195) << string(3, char(196)) << " branch #1";
    cout << "\n\t\t\t" << char(179) << "   " << char(195) << string(3, char(196)) << " leaf #1";
    cout << "\n\t\t\t" << char(179) << "   " << char(179) << "   " << char(195) << string(3, char(196)) << " apple";
    cout << "\n\t\t\t" << char(192) << string(3, char(196)) << " branch #2";
    cout << "\n\t\t\t    " << char(195) << string(3, char(196)) << " leaf #3";
    cout << "\n\t\t\t    " << char(179) << "   " << char(195) << string(3, char(196)) << " orange";
    cout << "\n\t\t\t    " << char(179) << "   " << char(192) << string(3, char(196)) << " coconut";
    cout << "\n\t\t\t    " << char(192) << string(3, char(196)) << " leaf #4";
    cout << '\n';
    cout << "\n\tF> Delete tree.\n";
    cout << "\n\t\tDeleting: apple";
    cout << "\n\t\tDeleting: leaf #1";
    cout << "\n\t\tDeleting: branch #1";
    cout << "\n\t\tDeleting: orange";
    cout << "\n\t\tDeleting: coconut";
    cout << "\n\t\tDeleting: leaf #3";
    cout << "\n\t\tDeleting: leaf #4";
    cout << "\n\t\tDeleting: branch #2";
    cout << "\n\t\tDeleting: trunk";
    cout << '\n';
}
void option1()
{
    cout << "\n\t1> Tree of strings";
	cout << "\n\t" << string(100, char(205));
    menuOption1();
}

char menuOption2()
{
    cout << "\n\t2> bTree container";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t\tA> Insert a node/leaf";
    cout << "\n\t\tB> Count of Nodes/leaves";
    cout << "\n\t\tC> Search a node/leaf";
    cout << "\n\t\tD> Pre-order traversal";
    cout << "\n\t\tE> In-order traversal";
    cout << "\n\t\tF> Post-order traveral";
    cout << "\n\t\tG> Delete the entire tree";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t\t0> return";
    cout << "\n\t" << string(100, char(205));

    return inputChar("\n\t\tOption: ", static_cast<string>("0ABCDEFG"));
}
void option2()
{
    do
    {
        system("cls");
        switch (menuOption2())
        {
        case '0': return;
        case 'A': break;
        case 'B': break;
        case 'C': break;
        case 'D': break;
        case 'E': break;
        case 'F': break;
        case 'G': break;
        default: "\t\tERROR: - Invalid option. Please re-enter"; break;
        }
    } while (true);
}


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
    char choice = 'N';
    string animal = "";
    string animalQuestion = "";
    string vowelsString = "aeiouAEIOU";
    bool vowels = false;
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("animal.txt");

    if (inputFile.fail())
    {
        cout << "\n\tERROR: File animal.txt cannot be found.\n";
        return;
    }

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
            system("cls");
            cout << "\n\tThink of an animal and press the RETURN/ENTER key to begin...";
            cin.clear();
            cin.ignore(999, '\n');

            if (animalGuessedRecursion == 0) //True
            {
                cout << "\n\tYes, I knew it all along!\n";
                system("cls");
                break;
            }
            else //Enter question
            {
                cout << "\n\tI give up. What are you?";
                animal = inputString("\n\t", true);

                cout << "\n\tPlease specify a yes/no question that will distinguish a " << animal << " from a lion.";

                cout << "\n\tEnter your question in this format: (Does it have " << string(5, char(95)) << "?: ";
                animalQuestion = inputString("\n\t", true);

                for (int i = 0; i < vowelsString.size(); i++)
                {
                    if (animal[0] == vowelsString[i])
                    {
                        vowels = true;
                        break;
                    }
                }

                if (vowels == true)
                {
                    cout << "\n\tAs an " << animal << ": " << animalQuestion << " (Y-yes or N-no) ";
                }
                else
                {
                    cout << "\n\tAs a " << animal << ": " << animalQuestion << " (Y-yes or N-no) ";
                }
            }

            system("cls");
        }break;
        case 'B':
        {
            cout << "\n\tNew data file. animal.txt, has been saved.\n";
        }break;
        default: "\t\tERROR: - Invalid option. Please re-enter"; break;
        }
        
    /*Think of an animal and press the RETURN/ENTER key to begin...


                Is it a mammal? (Y-yes or N-no) y

                Does it have stripes? (Y-yes or N-no) n

                Does it have a pouch? (Y-yes or N-no) n

                My guess is a lion (Y-yes or N-no)? n

                ///

                Yes, I knew it all along!

                ///

                I give up. What are you?
                dolphin

                Please specify a yes/no question that will distinguish a dolphin from a lion.

                Enter your question that ends with a '?':
                Does it have flippers?
                As a dolphin, does it Does it have flippers? (Y-yes or N-no)

                New data file. animal.txt, has been saved.
    */
    } while (true);
}

bool animalGuessedRecursion(char choice, string fileInput)
{
    if (!fileInput.empty())
    {
        choice = inputChar("\n\tIs it a mammal? (Y-yes or N-no) ", static_cast<string>("YN"));
        return true;
    }
}
