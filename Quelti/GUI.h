/* GUI class */

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdint.h>
#include <thread>
#include <fstream>
#include <windows.h>

#include "Languages/languages.h"
#include "Colors/colors.h"

class GUI
{
public:
	 void initializationComponents();
	 void Getline(std::string* strInput);
	 void waitTime(uint32_t time);
	 uint8_t mainScreen(bool animation);
	 uint8_t encryptionScreen1();
	 std::vector<std::string> encryptionScreen2();
	 void EncryptionFinalScreen(std::vector<std::string> Answer);

	 uint8_t decryptionScreen1();
	 std::vector<std::string> decryptionScreen2();
	 void DecryptionFinalScreen(std::vector<std::string> Answer);

	 std::vector<std::string> EncryptionFile2();
	 void EncryptionFileFinal(std::vector<std::string> Answer);
};

class Encryption
{	
public:
	void EncryptionMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets);
	void DecryptionMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets);
	void EncryptionFileMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets);
	void DecryptionFileMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets);

private:
	const std::string GLOBAL_ALPHABET = "!\"#$%&\'()*+,-./123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя ";
};