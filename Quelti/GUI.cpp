#define _CLS_ system("cls")

#define _MainScreen_					0
#define _MainErrorChoose_				10

#define _EncryptionScreen1_				20
#define _EncryptionScreen2_MESSAGE		30
#define _EncryptionScreen2_PASSWORD		31
#define _EncryptionScreen2_ALPHABETS	32
#define _EncryptionFinalScreen_			40

#define _DecryptionScreen1_				50
#define _DecryptionScreen2_MESSAGE		60
#define _DecryptionScreen2_PASSWORD		61
#define _DecryptionScreen2_ALPHABETS	62
#define _DecryptionFinalScreen_			70

#define _EncryptionFile2_CHOOSE_FILE	80
#define _EncryptionFile2_PASSWORD		81
#define _EncryptionFile2_ALPHABETS		82
#define _EncryptionFileFinal_			90

#define _DecryptionFile2_CHOOSE_FILE	180
#define _DecryptionFile2_PASSWORD		181
#define _DecryptionFile2_ALPHABETS		182
#define _DecryptionFileFinal_			190

#include "EncryptionMethod/encryption.h"
#include "GUI.h"

using std::cout;
using std::cin;
using std::endl;

Colors color;

/* PUBLIC */

GUI::GUI(std::vector<std::string> config)
	: alphabet(config[0]), animation(config[1]), language(config[2]) {}

void GUI::initializationComponents()
{
	system("color 7");
	system("title QueltiLock");
}

void GUI::Getline(std::string* strInput)
{
	color.set_color(CL_CYAN);
	cout << "[ USER ] --> ";
	color.clear();
	getline(cin, *strInput);
	cout << endl;
}

uint8_t GUI::mainScreen()
{
	Languages lang(language);

	while (true)
	{
		/* DRAWING */

		system("cls");
		if (animation == "true") {
			for (char x : lang.getText(_MainScreen_))
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(20));
				cout << x;
			}
		}
		else { cout << lang.getText(_MainScreen_); }

		animation = "false";

		std::string strInputMain;
		Getline(&strInputMain);

		/* ANALYSIS */

		if (atoi(strInputMain.c_str()) == 0 || atoi(strInputMain.c_str()) > 2) {		// Checking whether a string is a number
			color.set_intensity(true);
			color.set_color(CL_RED);
			for (char x : lang.getText(_MainErrorChoose_))
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(20));
				cout << x;
			}
			color.set_intensity(false);
			color.clear();
			system("pause > pause.txt");
			system("del pause.txt");
			continue;
		}

		return stoi(strInputMain);
	}
}

uint8_t GUI::encryptionScreen1()
{
	/* DRAWING */

	while (true)
	{
		_CLS_;
		Languages lang(language);
		cout << lang.getText(_EncryptionScreen1_);

		std::string strInputEncryption1;
		Getline(&strInputEncryption1);

		/* ANALYSIS */

		if (atoi(strInputEncryption1.c_str()) == 0 || atoi(strInputEncryption1.c_str()) > 2) {
			color.set_intensity(true);
			color.set_color(CL_RED);
			for (char x : lang.getText(_MainErrorChoose_))
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(20));
				cout << x;
			}
			color.set_intensity(false);
			color.clear();
			system("pause > pause.txt");
			system("del pause.txt");
			continue;
		}

		return stoi(strInputEncryption1);
	}
}
std::vector<std::string> GUI::encryptionScreen2()
{
	_CLS_;
	Languages lang(language);
	std::string message;

	cout << lang.getText(_EncryptionScreen2_MESSAGE);
	Getline(&message);

	std::vector<std::string> Array;

	_CLS_;
	cout << lang.getText(_EncryptionScreen2_PASSWORD);

	std::string strPassword;
	std::string strAlphabets;
	Getline(&strPassword);

	_CLS_;
	cout << lang.getText(_EncryptionScreen2_PASSWORD);
	color.set_color(CL_CYAN);
	cout << "[ USER ] --> ";
	color.clear();

	for (uint16_t i = 0; i < strPassword.size(); i++)
	{
		cout << "*";
	}

	cout << "\n\n\n";
	cout << lang.getText(_EncryptionScreen2_ALPHABETS); // Input numbers of alphabets

	Getline(&strAlphabets);

	Array.push_back(strPassword);
	Array.push_back(strAlphabets);
	Array.push_back(message);

	return Array;
}

void GUI::EncryptionFinalScreen(std::vector<std::string> Answer)
{
	_CLS_;
	Languages lang(language);
	Encryption encryption(alphabet);
	color.set_color(CL_CYAN);

	encryption.EncryptionMethod(Answer, &Answer[1]);

	color.set_intensity(true);
	color.set_color(CL_GREEN);
	cout << lang.getText(_EncryptionFinalScreen_);
	color.set_color(CL_CYAN);
	cout << Answer[1];
	color.clear();
	cout << "\n\n\n\n";
	system("pause");
}


uint8_t GUI::decryptionScreen1()
{
	/* DRAWING */

	while (true)
	{
		_CLS_;
		Languages lang(language);
		cout << lang.getText(_DecryptionScreen1_);

		std::string strInputDecryption1;
		Getline(&strInputDecryption1);

		/* ANALYSIS */

		if (atoi(strInputDecryption1.c_str()) == 0 || atoi(strInputDecryption1.c_str()) > 2) {
			color.set_intensity(true);
			color.set_color(CL_RED);
			for (char x : lang.getText(_MainErrorChoose_))
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(20));
				cout << x;
			}
			color.set_intensity(false);
			color.clear();
			system("pause > pause.txt");
			system("del pause.txt");
			continue;
		}

		return stoi(strInputDecryption1);
	}
}

std::vector<std::string> GUI::decryptionScreen2()
{
	_CLS_;
	Languages lang(language);
	std::string message;

	cout << lang.getText(_DecryptionScreen2_MESSAGE);
	Getline(&message);

	std::vector<std::string> Array;

	_CLS_;
	cout << lang.getText(_DecryptionScreen2_PASSWORD);

	std::string strPassword;
	std::string strAlphabets;
	Getline(&strPassword);

	_CLS_;
	cout << lang.getText(_DecryptionScreen2_PASSWORD);
	color.set_color(CL_CYAN);
	cout << "[ USER ] --> ";
	color.clear();

	for (uint16_t i = 0; i < strPassword.size(); i++)
	{
		cout << "*";
	}

	cout << "\n\n\n";
	cout << lang.getText(_DecryptionScreen2_ALPHABETS); // Input numbers of alphabets

	Getline(&strAlphabets);

	Array.push_back(strPassword);
	Array.push_back(strAlphabets);
	Array.push_back(message);

	return Array;
}

void GUI::DecryptionFinalScreen(std::vector<std::string> Answer)
{
	_CLS_;
	Languages lang(language);
	Encryption encryption(alphabet);
	color.set_color(CL_CYAN);

	encryption.DecryptionMethod(Answer, &Answer[1]);

	color.set_intensity(true);
	color.set_color(CL_GREEN);
	cout << lang.getText(_DecryptionFinalScreen_);
	color.set_color(CL_CYAN);
	cout << Answer[1];
	color.clear();
	cout << "\n\n\n\n";
	system("pause");
}

std::vector<std::string> GUI::EncryptionFile2()
{
	Languages lang(language);
	std::vector<std::string> parametrs;
	std::string path;

	while (true)
	{
		_CLS_;
		cout << lang.getText(_EncryptionFile2_CHOOSE_FILE);
		Getline(&path);

		std::ifstream file(path);
		if (file) {
			file.close();
			break;
		}
		else {
			file.close();
			continue;
		}
	}

	_CLS_;
	cout << lang.getText(_EncryptionFile2_PASSWORD);

	std::string strPassword;
	std::string strAlphabets;
	Getline(&strPassword);

	_CLS_;
	cout << lang.getText(_EncryptionFile2_PASSWORD);
	color.set_color(CL_CYAN);
	cout << "[ USER ] --> ";
	color.clear();

	for (uint16_t i = 0; i < strPassword.size(); i++)
	{
		cout << "*";
	}

	cout << "\n\n\n";
	cout << lang.getText(_EncryptionScreen2_ALPHABETS); // Input numbers of alphabets

	Getline(&strAlphabets);

	parametrs.push_back(path);
	parametrs.push_back(strPassword);
	parametrs.push_back(strAlphabets);

	return parametrs;
}

void GUI::EncryptionFileFinal(std::vector<std::string> Answer)
{
	_CLS_;
	Languages lang(language);
	Encryption encryption(alphabet);
	color.set_color(CL_CYAN);

	encryption.EncryptionFileMethod(Answer, &Answer[1]);

	_CLS_;

	color.set_intensity(true);
	color.set_color(CL_GREEN);
	cout << lang.getText(_EncryptionFileFinal_);
	color.set_color(CL_CYAN);
	cout << Answer[1];
	color.clear();
	cout << "\n\n\n\n";
	system("pause");
}

std::vector<std::string> GUI::DecryptionFile2()
{
	Languages lang(language);
	std::vector<std::string> parametrs;
	std::string path;

	while (true)
	{
		_CLS_;
		cout << lang.getText(_DecryptionFile2_CHOOSE_FILE);
		Getline(&path);

		std::ifstream file(path);
		if (file) {
			file.close();
			break;
		}
		else {
			file.close();
			continue;
		}
	}

	_CLS_;
	cout << lang.getText(_DecryptionFile2_PASSWORD);

	std::string strPassword;
	std::string strAlphabets;
	Getline(&strPassword);

	_CLS_;
	cout << lang.getText(_DecryptionFile2_PASSWORD);
	color.set_color(CL_CYAN);
	cout << "[ USER ] --> ";
	color.clear();

	for (uint16_t i = 0; i < strPassword.size(); i++)
	{
		cout << "*";
	}

	cout << "\n\n\n";
	cout << lang.getText(_DecryptionScreen2_ALPHABETS); // Input numbers of alphabets

	Getline(&strAlphabets);

	parametrs.push_back(path);
	parametrs.push_back(strPassword);
	parametrs.push_back(strAlphabets);

	return parametrs;
}

void GUI::DecryptionFileFinal(std::vector<std::string> Answer)
{
	_CLS_;
	Languages lang(language);
	Encryption encryption(alphabet);
	color.set_color(CL_CYAN);

	encryption.DecryptionFileMethod(Answer, &Answer[1]);

	//_CLS_;

	color.set_intensity(true);
	color.set_color(CL_GREEN);
	cout << lang.getText(_DecryptionFileFinal_);
	color.set_color(CL_CYAN);
	cout << Answer[1];
	color.clear();
	cout << "\n\n\n\n";
	system("pause");
}
