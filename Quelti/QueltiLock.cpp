/* MAIN */

#define _CLS_ system("cls")

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <Windows.h>

#include "Colors/colors.h"
#include "EncryptionMethod/encryption.h"
#include "GUI.h"
#include "nlohmann/json.hpp"

using std::cout;
using std::cin;
using std::endl;

void jsonConfig(std::vector<std::string>* config);
void exitCode(int code);

int main()
{
	std::vector<std::string> config;
	jsonConfig(&config);

	GUI Gui(config);
	Gui.initializationComponents();

	while (true)
	{
		_CLS_;
		uint8_t uintChooseMain = Gui.mainScreen();
		std::vector<std::string> encryptionAnswerVector;
		std::vector<std::string> decryptionAnswerVector;

		if (uintChooseMain == 1) {
			uint8_t encryptionAnswer = Gui.encryptionScreen1();
			if (encryptionAnswer == 1) {
				encryptionAnswerVector = Gui.encryptionScreen2();
				Gui.EncryptionFinalScreen(encryptionAnswerVector);
				encryptionAnswerVector.clear();
			}
			else if (encryptionAnswer == 2) {
				encryptionAnswerVector = Gui.EncryptionFile2();
				Gui.EncryptionFileFinal(encryptionAnswerVector);
			}
		}
		else if (uintChooseMain == 2) {
			uint8_t decryptionAnswer = Gui.decryptionScreen1();
			if (decryptionAnswer == 1) {
				decryptionAnswerVector = Gui.decryptionScreen2();
				Gui.DecryptionFinalScreen(decryptionAnswerVector);
				decryptionAnswerVector.clear();
			}
			else if (decryptionAnswer == 2) {
				decryptionAnswerVector = Gui.DecryptionFile2();
				Gui.DecryptionFileFinal(decryptionAnswerVector);
			}
		}
	}

	

	return 0;
}

void jsonConfig(std::vector<std::string>* config)
{
	/*
		config:
			0: alphabet		[ ENCRYPTION ]
			1: animations	[ GUI ]
			2: language		[ GUI ]
	*/

	using namespace nlohmann;

	Colors color;
	std::ifstream ifstreamConfig("config.json");
	if (!ifstreamConfig) exitCode(1);

	json configJson = json::parse(ifstreamConfig);

	/* ALPHABET */
	if ((configJson["ALPHABET"]).size() < 3 ) {
		config->push_back(configJson["ALPHABET"]);
	}
	else exitCode(2);

	/* animations */
	if (configJson["animations"] != "true" && configJson["animations"] != "false") exitCode(3);
	else config->push_back(configJson["animations"]);

	/* language */
	if (configJson["language"] != "ru" && configJson["language"] != "en" && configJson["setLocale"] != "uk") exitCode(4);
	else config->push_back(configJson["language"]);

	/* setLocale */
	if (configJson["setLocale"] == "uk")
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		return;
	}

	if (configJson["setLocale"] != "ru" && configJson["setLocale"] != "en" && configJson["setLocale"] == "uk") exitCode(5);
	else {
		std::string cache = configJson["setLocale"];
		setlocale(LC_CTYPE, cache.c_str());
	}
}


void exitCode(int code)
{
	Colors color;

	_CLS_;
	color.set_intensity(true);
	color.set_color(CL_RED);
	cout << "Error! Code ";
	color.set_color(CL_CYAN);
	cout << code << ".";
	color.set_color(CL_RED);
	cout << "\nRead more at ";
	color.set_color(CL_CYAN);
	cout << "https://github.com/BeeFine/QueltiLock" << endl << endl;
	color.clear();
	system("pause");
	exit(code);
}