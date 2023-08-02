#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdint.h>
#include <thread>
#include <fstream>
#include <windows.h>

class Encryption
{
public:
	Encryption(std::string alphabet);

	void EncryptionMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets);
	void DecryptionMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets);
	void EncryptionFileMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets);
	void DecryptionFileMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets);

private:
	const std::string GLOBAL_ALPHABET;
};