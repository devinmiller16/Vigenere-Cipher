#pragma once //Constains the encryption key and the logic for encrypting and 
//decrypting individual words.
#include<string>

class Vigenere {
public:
	//Constructor
	Vigenere();

	//Function that sets the string key.
	void setKey(std::string k);

	//Function that returns the string key.
	std::string getKey();

	//Function that returns the upper case version of the string k.
	std::string toUpperCase(std::string k);

	//Functions that encrypt/decrypt the token passed in from Message.
	std::string encrypt(std::string word);
	std::string decrypt(std::string word);

	//Destructor
	~Vigenere();
private:
	//String that contains the encryption key.
	std::string key;
};