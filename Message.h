#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Vigenere.h"

//Constains a vector of words that have been encrypted or decrypted and the logic 
//for calling the functions in the Vigenere class to encrypt/decrypt.
class Message { //Class that contains the encrypted/decrypted words inside a vector. Contains a Vigenere object to help store the encryption key. Contains functions to create
				//Files for output, output the vector to the screen, and help encrypt/decrypt tokens.
	public:
		//Constructor
		Message(std::string k);

		//Functions to encrypt/decrypt
		void encryptWord(char* token);
		void decryptWord(char* token);

		//Function to create a new file for output.
		void makeFile();

		//Function to print the vector words to the screen.
		void showWords();

		//destructor
		~Message(); 
	private:
		//Stores the encrypted/decrypted words.
		std::vector<std::string> words;
		
		//Vigenere object to help store the encyption key.
		Vigenere v;

};