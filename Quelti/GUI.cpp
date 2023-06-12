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

#include "GUI.h"
#include "hash-library-master/sha3.h"

using std::cout;
using std::cin;
using std::endl;

Colors color;
bool loop;
std::vector<std::string> alphabets;

/* PUBLIC */

void GUI::initializationComponents()
{
	system("color 7");
	setlocale(LC_ALL, "en");
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

void wait(int num)
{
	while (loop)
	{
		color.clear();
		cout << "\rAlphabets generated ";
		color.set_color(CL_CYAN);
		cout << alphabets.size() << " / " << num;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void GUI::waitTime(uint32_t time)
{
	
}

uint8_t GUI::mainScreen(bool animation)
{
	Languages lang;

	while (true)
	{
		/* DRAWING */

		system("cls");
		if (animation) {
			for (char x : lang.getText(_MainScreen_))
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(20));
				cout << x;
			}
		}
		else { cout << lang.getText(_MainScreen_); }

		animation = false;

		GUI Gui;
		std::string strInputMain;
		Gui.Getline(&strInputMain);

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
		Languages lang;
		cout << lang.getText(_EncryptionScreen1_);

		GUI Gui;
		std::string strInputEncryption1;
		Gui.Getline(&strInputEncryption1);

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
	Languages lang;
	GUI Gui;
	std::string message;

	cout << lang.getText(_EncryptionScreen2_MESSAGE);
	Gui.Getline(&message);

	std::vector<std::string> Array;

	_CLS_;
	cout << lang.getText(_EncryptionScreen2_PASSWORD);

	std::string strPassword;
	std::string strAlphabets;
	Gui.Getline(&strPassword);

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

	Gui.Getline(&strAlphabets);

	Array.push_back(strPassword);
	Array.push_back(strAlphabets);
	Array.push_back(message);

	return Array;
}

void GUI::EncryptionFinalScreen(std::vector<std::string> Answer)
{
	_CLS_;
	Encryption encryption;
	Languages lang;
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

// Encryption function

void Encryption::EncryptionMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets)
{
	SHA3 sha3;

	std::vector<std::string> keys;

	std::string password		=	vectorAnswers[0]; // User's password
	std::string numsAlphabets	=	vectorAnswers[1]; // Number of alphabets
	std::string message			=	vectorAnswers[2]; // User's message

	std::string strSeed; // Int Seed
	std::string strHash = sha3(password); // SHA3 Hash

	if (atoi(numsAlphabets.c_str()) == 0) numsAlphabets = "2048"; // Default value

	// Converting hash
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890";

	for (char x : strHash)
	{
		auto intCache = alphabet.find(x);
		intCache += 10;
		strSeed += std::to_string(intCache);
	}


	// Converting seed
	strSeed += numsAlphabets;

	// Random
	std::mt19937 random((atoi(strSeed.c_str())));

	// Animation
	color.clear();
	loop = true;
	std::thread Wait(wait, stoi(numsAlphabets));

	// Keys generation
	for (int i = 0; i < message.size(); i++)
	{
		std::string randomNum = std::to_string(random() % atoi(numsAlphabets.c_str()));
		keys.push_back(randomNum);
	}

	// Alphabets generation
	std::string shuffle = GLOBAL_ALPHABET;
	for (int i = 0; i < stoi(numsAlphabets); i++)
	{
		std::shuffle(shuffle.begin(), shuffle.end(), random);
		alphabets.push_back(shuffle);
	}
	loop = false;
	Wait.join();
	_CLS_;
	
	// Encryption
	uint32_t i = 0;
	for (char x : message)
	{
		std::string key = keys[i];
		std::string alphabet = alphabets[atoi(key.c_str())];

		cout << alphabet[GLOBAL_ALPHABET.find(x)];
		i++;
	}
	*numAlphabets = numsAlphabets;

	color.set_intensity(true);
	color.set_color(CL_GREEN);
	cout << "\n\nCleaning RAM...";
	color.set_intensity(false);
	color.clear();
	alphabets.clear();
	keys.clear();
}

void Encryption::DecryptionMethod(std::vector<std::string> vectorAnswers)
{

}
