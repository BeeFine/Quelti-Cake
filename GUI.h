/* GUI class */

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdint.h>
#include <thread>

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

private:
	 void wait();
};

class Encryption
{
public:
	void EncryptionMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets);
	void DecryptionMethod(std::vector<std::string> vectorAnswers);

private:
	const std::string GLOBAL_ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=[]{}|;':,./<>?`\"\\~ ";
};