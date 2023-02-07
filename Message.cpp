#include"Message.h"
#include<string>
#include<iostream>
#include<fstream>

Message::Message(std::string k) {
	k = v.toUpperCase(k); //Sets k equal to the return value of the toUpperCase function using the Vigenere object v.
	v.setKey(k); //Passes k to the setKey function using the Vigenere object v.
}

Message::~Message() { //Destructor that deletes that values of the vector words.
	words.clear();
}

void Message::encryptWord(char *token) { //Function that takes the token, casts it into a string, encrypts using the encrypt function, then adds the encrypted word to the vector words.
	std::string s;
 	s.push_back(*token); //Sets the token to a string value.
	s = v.encrypt(token); //Sets s equal to the encrypted token.
	words.push_back(s); //Adds the encrypted token (s) to the vector words.
}

void Message::decryptWord(char* token) { //Fucntion that takes the token, casts it into a string, decrypts using the decrypt function, then adds the decrypted word to the vector words.
	std::string s;
	s.push_back(*token); //Sets the token to a string value.
	s = v.decrypt(token); //Sets s equal to the decrypted token.
	words.push_back(s); //Adds the decrypted token (s) to the vector words.
}

void Message::makeFile() { //Function to create a new file and output the decrypted/encrypted contents to it. 
	std::ofstream file_;
	std::string newFile;
	std::cout << "Please enter the name of the new file to create: ";
	getline(std::cin, newFile); //User inputs the name of the new file.
	std::cout << std::endl;
	file_.open(newFile); //ofstream opens the new file.

	for (int i = 0; i < words.size(); i++) //Loop that outputs the vector words to the new file.
		file_ << words.at(i) << ' ';

	file_.close(); //Once the file contains the contents of the vecotor the file is closed.
}

void Message::showWords() { //Function that outputs the encrypted/decrypted words to the screen.
	for (int i = 0; i < words.size(); i++) { //Loop that outputs the vector words to the screen.
		std::cout << words.at(i) << ' ';
	}
	std::cout << std::endl << std::endl;
}
