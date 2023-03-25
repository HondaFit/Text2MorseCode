#include "bst.h"


int main()
{
	int option;
	char dummy;

	bst tree;
	node* newNode;
	int opiton;
	char val;

	string userText;
	string text;
	int count = 0;

	do
	{

		cout << "1. Load Morse Code" << endl;
		cout << "2. Translate" << endl;
		cout << "3. Print BST Value (Debugging) - Credit to Simple Snippets " << endl;
		cout << "4. Clear" << endl;
		cout << "0. Exit Program" << endl;

		cin >> option;

		switch (option)
		{
		case 0:
			break;
		case 1:
			cout << "\nLoad MorseCode Table" << endl;
			for (int i = 0; i < 37; i++)
			{
				newNode = new(node); //make another array that contains letter
				newNode->setChar(i);
				tree.insertNode(newNode);
			}
			break;
		case 2:
			cout << "\nTranslate" << endl;
			cout << "\n Type in something to translate: ";

			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, userText);
			while (userText[count] != NULL)
			{
				tree.search(userText[count]);
				count++;
			}
			cout << "Morse Code: " << tree.getText() << endl;
			count = 0;

			break;
		case 3:
			cout << "\nPrint Tree (credit to simple snippet)" << endl;
			tree.print2D(tree.getRoot(), 5);
			break;
		case 4:
			cout << "\nClear Screen" << endl;
			system("cls");
			break;
		}

		/*cout << "Press any key to continue" << endl;
		cin >> dummy;
		system("cls");*/

	} while (option != 0);
}