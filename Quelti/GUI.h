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
	GUI(std::vector<std::string> config);

	void initializationComponents();
	void Getline(std::string* strInput);
	uint8_t mainScreen();
	uint8_t encryptionScreen1();
	std::vector<std::string> encryptionScreen2();
	void EncryptionFinalScreen(std::vector<std::string> Answer);

	uint8_t decryptionScreen1();
	std::vector<std::string> decryptionScreen2();
	void DecryptionFinalScreen(std::vector<std::string> Answer);

	std::vector<std::string> EncryptionFile2();
	void EncryptionFileFinal(std::vector<std::string> Answer);

	std::vector<std::string> DecryptionFile2();
	void DecryptionFileFinal(std::vector<std::string> Answer);

private:
	const std::string alphabet;
	const std::string language;
	std::string animation;
};