#include "bst.h"


//////////////////////////////////////////////////////////////////////////

//This is a constructor and set of methods for a node class. The constructor takes an integer index as an argument and sets the morseChar and morseCode variables to
// the corresponding values in the charTable and morseTable arrays. The setChar() method takes an integer index as an argument and sets the morseChar and morseCode
// variables to the corresponding values in the charTable and morseTable arrays. The getChar() and getMorse() methods return the values of the morseChar and morseCode
// variables respectively. The setLeftN() and setRightN() methods set the leftN and rightN variables to the given node pointer. The getLeftN() and getRightN() methods
// return the values of the leftN and rightN variables respectively.

node::node()
{
	//value = 0;

	rightN = NULL;
	leftN = NULL;
	morseCode.clear();
	morseChar = NULL;
}
node::node(int index)
{
	//pData = new (data);
	//pData->setAge(uAge);
	//pData->setName(uName);
	//value = uValue;

	morseChar = charTable[index];
	morseCode = morseTable[morseChar - 44];
	rightN = NULL;
	leftN = NULL;
}

void node::setChar(int index)
{
	//pData->setAge(uAge);
	//pData->setName(uName);

	morseChar = toupper(charTable[index]);
	morseCode = morseTable[morseChar - 44];
	//morseCode = 0;
}
char node::getChar()
{
	return morseChar;
}
string node::getMorse()
{
	return morseCode;
}

void node::setLeftN(node* newNode)
{
	leftN = newNode;
}
void node::setRightN(node* newNode)
{
	rightN = newNode;
}
node* node::getLeftN()
{
	return leftN;
}
node* node::getRightN()
{
	return rightN;
}




//////////////////////////////////////////////////////////////////////////


//This code is for a binary search tree (BST) class. The bst::bst() function is a constructor for the BST class. It sets the root node of the BST to NULL. The isEmpty
//() function checks if the root node is NULL, and returns true if it is, and false if it is not. The insertNode() function takes a node pointer as an argument and
// inserts it into the BST. It checks if the root node is NULL, and if it is, sets the root node to the new node. If the root node is not NULL, it traverses the tree
// to find the correct position for the new node. It checks for duplicate values and inserts the new node to the left or right of the current node depending on the
// value of the new node. The search() function takes a character as an argument and searches the BST for the corresponding Morse code. It traverses the tree until
// it finds the correct node and returns the Morse code. The getText() function returns the converted text. The setConvert() function takes a string as an argument
// and adds it to the converted text. Finally, the print2D() function prints the BST in a 2D format. It takes a node pointer and an integer as arguments and recursively traverses the tree, 
//printing the nodes in the correct order.

bst::bst()
{
	root = NULL;
}

bool bst::isEmpty()
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void bst::insertNode(node* newNode)
{
	node* temp;
	// is root empty? has tree been created
	if (isEmpty() == true) // if true set root to the newNode
	{
		root = newNode;
	}
	else //if not, traverse through the tree
	{
		temp = root;
		while (temp != NULL)
		{
			//checking for duplicate value
			if (newNode->getChar() != temp->getChar())
			{
				if (newNode->getChar() < temp->getChar()) // is the newNode value less then the current node's value 
				{
					// is the current node's left pointer empty?
					if (temp->getLeftN() == NULL) // if so, set the current node's left pointer to newNode
					{
						temp->setLeftN(newNode);
						break; //if not work make temp = NULL;
					}
					else
					{
						temp = temp->getLeftN(); // traversing to the left
					}
				}
				else // the newNode value is greater than the current node's value
				{
					// is the current node's right pointer empty
					if (temp->getRightN() == NULL) // if so, set the current node's right pointer to newNode
					{
						temp->setRightN(newNode);
						break; //if not work make temp = NULL;
					}
					else
					{
						temp = temp->getRightN(); // traversing to the right
					}
				}
			}
			else
			{
				temp = NULL;
				cout << "Duplicate Value DETECTED, Invalid Input" << endl;
			}
		}
	}


}

void bst::search(char target)
{
	char tempTar = toupper(target);
	node* current = root;
	if (target != ' ')
	{

		while (tempTar != current->getChar())
		{
			if (tempTar < current->getChar())
			{
				current = current->getLeftN();
			}
			else
			{
				current = current->getRightN();
			}
		}

		convertText = convertText + " " + current->getMorse();
		//return current->getMorse();
	}
	else
	{
		convertText = convertText + "   ";
	}

}

string bst::getText()
{
	return convertText;
}

void bst::setConvert(string morse)
{
	convertText = convertText + morse;
}

void bst::print2D(node* r, int space) //credit to a youtuber simple snippets
{
	if (r == NULL) // Base case  1
		return;
	space += SPACE; // Increase distance between levels   2
	print2D(r->getRightN(), space); // Process right child first 3 
	cout << endl;
	for (int i = SPACE; i < space; i++) // 5 
		cout << " "; // 5.1  
	cout << r->getChar() << "\n"; // 6
	print2D(r->getLeftN(), space); // Process left child  7
}


