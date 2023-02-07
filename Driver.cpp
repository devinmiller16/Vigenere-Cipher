//<Programming Assignment 4> -- Encrypts and decrypts text files using the Vigenere cypher.
//CSIS 112-<D01>
//<Citations if necessary> -- 
//Example code used from C++ Programming Assignment Instructions by Terri Sipantzi.
//strtok_s function help from https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l?redirectedfrom=MSDN&view=msvc-160
//Char conversion help from https://stackoverflow.com/questions/17201590/c-convert-from-1-char-to-string
//Conversion to upper case help from http://www.cplusplus.com/reference/cctype/toupper/
//More strtok_s help from https://en.cppreference.com/w/c/string/byte/strtok

#include<iostream>
#include"Message.h"
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<iomanip>

using namespace std;

int displayMenu();
void encryptDecrypt(string, int, string);
string key();


int main() {

	cout << "Devin Miller - Programming Assignment 5" << endl << endl;
	
	bool go = true;
	string fileName;
	string encryptionKey;

	//Unless go is false this loop will always execute. 
	while (go) {
		
		int selection = displayMenu(); //Invokes the display menu function and sets the return value equal to selection.
		
		//If selection equals 1, 2, or 3 the following will occur otherwise the input is invalid. 
		if (selection == 1) { //If the user selects 1.
			cout << "Enter the name of the file to encrypt: ";
			getline(cin, fileName);
			cout << endl;

			encryptionKey = key(); //Sets the encryption key equal to the return value of the function key.
			encryptDecrypt(fileName, selection, encryptionKey); //Passes the file, selection, and encryption key to be encrypted or decrypted.
		}
		else if (selection == 2) { //If the user selects 2.
			cout << "Enter the name of the file to decrypt: "; 
			getline(cin, fileName);
			cout << endl;

			encryptionKey = key(); //Sets the encryption key equal to the return value of the function key.
			encryptDecrypt(fileName, selection, encryptionKey); //Passes the file, selection, and encryption key to be encrypted or decrypted. 
		}
		else if (selection == 3) { //If the user selects 3.
			go = false; //Go is set equal to false to ensure that the menu no longer displays.
			cout << "Exiting Program...." << endl << endl; 
			system("pause"); //Program pauses and then ends.
			return 0;
		}
		else
			cout << "Invalid input! Please try again." << endl << endl; //If the user enters anything other than 1, 2, or 3.
	}
 }

string key() { //Function that asks for the encryption key.
	string encryptionKey;

	cout << "Enter an encryption/decryption key: ";
	getline(cin, encryptionKey);
	cout << endl;

	//Error checking loop that executes if the encryption key contains no date or contains numbers.
	while (cin.fail() || encryptionKey.size() == 0 || string::npos != encryptionKey.find_first_of("0123456789")) {
		if (encryptionKey.size() == 0) { //If the encryption key contains no data.
			cout << "ERROR! The encryption/decryption key must include data." << endl;
			cout << "Please try again: ";
		}
		else if (string::npos != encryptionKey.find_first_of("0123456789")) { //If the encryption key contains numbers.
			cout << "ERROR! Encryption/decryption key must not include numbers." << endl;
			cout << "Please try agian: ";
		}
		cin.clear(); //Clears the stream and gets a new input. 
		getline(cin, encryptionKey);
	}
	return encryptionKey;
}

 void encryptDecrypt(string fileName, int selection, string encryptionKey) {

	 char file[1000];
	 std::fill(std::begin(file), std::end(file), '\0'); //Sets each value in the file to the NULL character.

	 int i = 0, num_characters = 0;

	 ifstream inFile;
	 inFile.open(fileName); //Opens the file
	 Message message(encryptionKey); //Passes the encryption key to the Message class which then gets sent to the Vigenere class.

	 if (!inFile.is_open()) { //If the file doesnt open or doesnt exist the program ends.
		 cout << "ERROR! failed to open file. " << endl;
		 cout << "Exiting program...." << endl << endl;
		 system("pause");
		 exit(0); //Allows the program to end within a void function.
	 }
	 while (!inFile.eof()) //While there is still data in the file.
	 {
		 inFile.get(file[i]); //Fills the array with the data from the file.
		 i++;
		 num_characters++;
	 }
	 //Tokenization of the array.
	 const char *delim = " ";
	 char *next_token;
	 printf("Parsing the input string '%s'\n", file);
	 char *token = strtok_s(file, delim, &next_token);
	 while (token) { //While token is not NULL.
		 if (selection == 1) { //If the users selection was 1 the token is sent for encryption.
			 message.encryptWord(token); //Encrypt function
		 }
		 else if (selection == 2) { //If the users selection was 2 the token is sent for decryption.
			 message.decryptWord(token); //Decrypt function
		 }
		 token = strtok_s(NULL, delim, &next_token); 
	 }
	 if (selection == 1) { //Output statements if selection was 1.
		 cout << endl << "A new file will be created that contains the encrypted message." << endl << endl;
		 message.makeFile(); //Function that makes a new file for output.

		 cout << "The new file contains the following encrypted message: " << endl << endl;
	 }
	 else if (selection == 2) { //Output statements if selection was 2.
		 cout << endl << "A new file will be created that contains the decrypted message." << endl << endl;
		 message.makeFile(); //Function that makes a new file for output.

		 cout << "The new file contains the following decrypted message: " << endl << endl;
	 }
	 message.showWords(); //Function to print words to the screen.
	 message.~Message(); //Message destructor.
	 std::fill(std::begin(file), std::end(file), '\0'); //Fills file with NULL values again.
	 i = 0; //Resets counters.
	 num_characters = 0;
 }

int displayMenu() { //Function that displays a main menu with cout statements.
	int s;
	cout << setw(50) << "Vigener Cypher" << endl << endl;
	cout << setw(48) << "Main Menu" << endl << endl;
	cout << setw(50) << "[1] - Encrypt File" << endl;
	cout << setw(50) << "[2] - Decrypt File" << endl;
	cout << setw(42) << "[3] - Quit" << endl;
	cout << endl << endl;
	cout << setw(5) << "Selection: ";
	cin >> s; //Gets the users selection.
	cin.ignore(); //Ignores the newline character. 
	cout << endl;

	return s; //Returns the users selection.
}