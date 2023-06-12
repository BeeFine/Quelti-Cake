// QueltiLock.cpp: определяет точку входа для приложения.


#define _CLS_ system("cls")

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdint.h>

#include "Colors/colors.h"
#include "GUI.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	GUI Gui;
	Encryption encryption;
	Gui.initializationComponents();
	uint8_t uintChooseMain = Gui.mainScreen(true);
	std::vector<std::string> encryptionAnswerVector;

	if (uintChooseMain == 1) {
		uint8_t encryptionAnswer = Gui.encryptionScreen1();
		if (encryptionAnswer == 1) {
			encryptionAnswerVector = Gui.encryptionScreen2();
			Gui.EncryptionFinalScreen(encryptionAnswerVector);
		}
		else if (encryptionAnswer == 2) {

		}
	}
	else if (uintChooseMain == 2) {

	}


	return 0;
}