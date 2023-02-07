#include"Vigenere.h"
#include<string>
#include<iostream>
#include<algorithm>


Vigenere::Vigenere() {} //Vigenere constructor.

Vigenere::~Vigenere() {} //Vigenere destructor.

void Vigenere::setKey(std::string k) { //Function to set the encryption key.
	key = k;
}

std::string Vigenere::getKey() { //Function to return the encryption key.
	return key;
}

std::string Vigenere::toUpperCase(std::string k) { //Function that takes the encyption key and turns it into all upper case characters and then returns it.
	for (int i = 0; i < k.size(); i++) {
		k.at(i) = toupper(k.at(i));
	}
	return k;
}

std::string Vigenere::encrypt(std::string word) //Function that encypts the token passed in from the Message class.
{
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c + key[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
		j = (j + 1) % key.length();
	}
	return output; //returns the output back to Message to be stored in the vector words.
}

std::string Vigenere::decrypt(std::string word) //Function that decrypts the token passed in from the Message class.
{
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c - key[j] + 26) % 26 + 'A';
		j = (j + 1) % key.length();
	}
	return output; //Returns the output back to Message to be stored in the vector words.
}