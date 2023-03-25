#pragma once

#include <iostream>
#define SPACE 10
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using std::cout; // we can now use cout without explicitly writing std::cout
using std::cin;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::toupper;
using std::getline;

class node
{
public:

	node();


	node(int index);
	void setChar(int index);
	char getChar();
	string getMorse();

	void setLeftN(node* newNode);
	void setRightN(node* newNode);
	node* getLeftN();
	node* getRightN();




private:

	node* leftN;
	node* rightN;

	string morseCode;
	char morseChar;

	char charTable[38] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4',
		'5', '6', '7', '8', '9', ',', '.', '?' };

	string morseTable[47] = {
	"--..--", // , 44 0
	"NULL",   //   45 1
	".-.-.-", // . 46 2
	"NULL",   //   47 3
	"-----",  // 0 48 4
	".----",  // 1 49 5
	"..---",  // 2 50 6
	"...--",  // 3 51 7
	"....-",  // 4 52 8
	".....",  // 5 53 9
	"-....",  // 6 54 10
	"--...",  // 7 55 11
	"---..",  // 8 56 12
	"----.",  // 9 57 13
	"NULL",   //   58 14
	"NULL",   //   59 15
	"NULL",   //   60 16
	"NULL",   //   61 17
	"NULL",   //   62 18
	"..--..", // ? 63 19
	"NULL",   //   64 20   
	".-",     // A 65 21
	"-...",   // B 66 22
	"-.-.",   // C 67 23
	"-..",    // D 68 24
	".",      // E 69 25
	"..-.",   // F 70 26
	"--.",    // G 71 27
	"....",   // H 72 28
	"..",     // I 73 29
	".---",   // J 74 30
	"-.-",    // K 75 31
	".-..",   // L 76 32
	"--",     // M 77 33
	"-.",     // N 78 34
	"---",    // O 79 35
	".--.",   // P 80 36
	"--.-",   // Q 81 37
	".-.",    // R 82 38
	"...",    // S 83 39
	"-",      // T 84 40
	"..-",    // U 85 41
	"...-",   // V 86 42
	".--",    // W 87 43
	"-..-",   // X 88 44
	"-.--",   // Y 89 45
	"--.."    // Z 90 46
	};

};

class bst
{
public:

	bst();

	bool isEmpty();

	void insertNode(node* newNode);

	void search(char target);

	void setConvert(string morse);

	string getText();

	void print2D(node* r, int space);

	node* getRoot()
	{
		return root;
	}
private:
	node* root;

	string convertText;
};