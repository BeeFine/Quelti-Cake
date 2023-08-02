#define _CLS_ system("cls")

#include "hash-library-master/sha3.h"
#include "encryption.h"
#include "Colors/colors.h"

using std::cout;
using std::cin;
using std::endl;

bool loop;
std::string generated;
uint32_t line1 = 1;

void wait(int num)
{
	Colors color;
	while (loop)
	{
		color.clear();
		cout << "\rAlphabets generated ";
		color.set_color(CL_CYAN);
		cout << generated << " / " << num;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

void wait1(int num)
{
	Colors color;
	color.clear();
	while (loop)
	{
		cout << "\rDecryption: ";
		color.set_color(CL_CYAN);
		cout << line1 << " / " << num;
		color.clear();
		cout << " lines";
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

Encryption::Encryption(std::string alphabet)
	: GLOBAL_ALPHABET(alphabet) {}

void Encryption::EncryptionMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets)
{
	SHA3 sha3;
	Colors color;

	std::vector<uint64_t> sortkeys;
	std::vector<uint64_t> keys;
	std::vector<std::string> alphabets;

	std::string password = vectorAnswers[0]; // User's password
	std::string numsAlphabets = vectorAnswers[1]; // Number of alphabets
	std::string message = vectorAnswers[2]; // User's message

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
		uint64_t randomNum = random() % atoi(numsAlphabets.c_str());
		keys.push_back(randomNum);
	}

	sortkeys = keys;
	std::sort(sortkeys.begin(), sortkeys.end());

	// Alphabets generation
	std::string shuffle = GLOBAL_ALPHABET;
	{
		int i2 = 0;
		for (int i = 0; i < stoi(numsAlphabets); i++)
		{
			std::shuffle(shuffle.begin(), shuffle.end(), random);
			generated = std::to_string(i);
			if (i2 == sortkeys.size()) break;
			if (i == sortkeys[i2]) {
				alphabets.push_back(shuffle);
				alphabets.push_back(std::to_string(sortkeys[i2]));
				i2++;
			}
		}
	}
	loop = false;
	Wait.join();
	_CLS_;

	// Encryption
	uint32_t i = 0;
	for (char x : message)
	{
		uint64_t key = keys[i];
		std::string alphabet;
		for (int i = 0; i < alphabets.size(); i++)
		{
			if (alphabets[i] == std::to_string(key)) {
				alphabet = alphabets[i - 1];
			}
		}
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

void Encryption::DecryptionMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets)
{
	SHA3 sha3;
	Colors color;

	std::vector<uint64_t> sortkeys;
	std::vector<uint64_t> keys;
	std::vector<std::string> alphabets;

	std::string password = vectorAnswers[0]; // User's password
	std::string numsAlphabets = vectorAnswers[1]; // Number of alphabets
	std::string message = vectorAnswers[2]; // User's message

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
		uint64_t randomNum = random() % atoi(numsAlphabets.c_str());
		keys.push_back(randomNum);
	}

	sortkeys = keys;
	std::sort(sortkeys.begin(), sortkeys.end());

	// Alphabets generation
	std::string shuffle = GLOBAL_ALPHABET;
	{
		int i2 = 0;
		for (int i = 0; i < stoi(numsAlphabets); i++)
		{
			std::shuffle(shuffle.begin(), shuffle.end(), random);
			generated = std::to_string(i);
			if (i2 == sortkeys.size()) break;
			if (i == sortkeys[i2]) {
				alphabets.push_back(shuffle);
				alphabets.push_back(std::to_string(sortkeys[i2]));
				i2++;
			}
		}
	}
	loop = false;
	Wait.join();
	_CLS_;

	// Encryption
	uint32_t i = 0;
	for (char x : message)
	{
		uint64_t key = keys[i];
		std::string alphabet;
		for (int i1 = 0; i1 < alphabets.size(); i1++)
		{
			if (alphabets[i1] == std::to_string(key)) {
				alphabet = alphabets[i1 - 1];
			}
		}
		cout << GLOBAL_ALPHABET[alphabet.find(x)];
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

void Encryption::EncryptionFileMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets)
{
	SHA3 sha3;
	Colors color;

	std::ifstream input(vectorAnswers[0], std::ios::in/*, std::ios_base::binary*/);
	std::ofstream output(vectorAnswers[0] + ".qltp", std::ios::out/*, std::ios_base::binary*/);

	std::vector<uint64_t> sortkeys;
	std::vector<uint64_t> keys;
	std::vector<std::string> alphabets;
	std::vector<std::string> lines;

	std::string password = vectorAnswers[1]; // User's password
	std::string numsAlphabets = vectorAnswers[2]; // Number of alphabets

	std::string sizeLines;
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

	// GetLine
	while (true)
	{
		std::string cache;
		getline(input, cache);
		if (cache == "" && input.eof()) break;
		lines.push_back(cache);
	}

	// Size
	for (std::string word : lines)
	{
		sizeLines = std::to_string(atoi(sizeLines.c_str()) + word.size());
	}

	// Keys generation
	for (int i = 0; i < atoi(sizeLines.c_str()); i++)
	{
		uint64_t randomNum = random() % atoi(numsAlphabets.c_str());
		keys.push_back(randomNum);
	}

	sortkeys = keys;
	std::sort(sortkeys.begin(), sortkeys.end());

	// Alphabets generation
	std::string shuffle = GLOBAL_ALPHABET;
	{
		int i2 = 0;
		for (int i = 0; i < stoi(numsAlphabets); i++)
		{
			std::shuffle(shuffle.begin(), shuffle.end(), random);
			generated = std::to_string(i);
			if (i2 == sortkeys.size()) break;
			if (i == sortkeys[i2] || i - 1 == sortkeys[i2]) {
				alphabets.push_back(shuffle);
				alphabets.push_back(std::to_string(sortkeys[i2]));
				i2++;
			}
		}
	}
	loop = false;
	Wait.join();
	_CLS_;

	// Encryption
	uint32_t i = 0;
	for (std::string line : lines)
	{
		for (char x : line)
		{
			if (x == '\t') {
				output << "\t";
				continue;
			}
			uint64_t key = keys[i];
			std::string alphabet;
			for (int i = 0; i < alphabets.size(); i++)
			{
				if (alphabets[i + 1] == std::to_string(key)) {
					alphabet = alphabets[i];
					break;
				}
			}
			output << alphabet[GLOBAL_ALPHABET.find(x)];
			i++;
		}
		output << endl;
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

void Encryption::DecryptionFileMethod(std::vector<std::string> vectorAnswers, std::string* numAlphabets)
{
	SHA3 sha3;
	Colors color;

	std::ifstream input(vectorAnswers[0], std::ios::in/*, std::ios_base::binary*/);

	std::vector<uint64_t> sortkeys;
	std::vector<uint64_t> keys;
	std::vector<std::string> alphabets;
	std::vector<std::string> lines;

	std::string password = vectorAnswers[1]; // User's password
	std::string numsAlphabets = vectorAnswers[2]; // Number of alphabets

	std::string sizeLines;
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

	// GetLine
	while (true)
	{
		std::string cache;
		getline(input, cache);
		if (cache == "" && input.eof()) break;
		lines.push_back(cache);
	}

	// Size
	for (std::string word : lines)
	{
		sizeLines = std::to_string(atoi(sizeLines.c_str()) + word.size());
	}

	// Keys generation
	for (int i = 0; i < atoi(sizeLines.c_str()); i++)
	{
		uint64_t randomNum = random() % atoi(numsAlphabets.c_str());
		keys.push_back(randomNum);
	}

	sortkeys = keys;
	std::sort(sortkeys.begin(), sortkeys.end());

	// Alphabets generation
	std::string shuffle = GLOBAL_ALPHABET;
	{
		int i2 = 0;
		for (int i = 0; i < stoi(numsAlphabets); i++)
		{
			std::shuffle(shuffle.begin(), shuffle.end(), random);
			generated = std::to_string(i);
			if (i2 == sortkeys.size()) break;
			if (i == sortkeys[i2] || i - 1 == sortkeys[i2]) {
				alphabets.push_back(shuffle);
				alphabets.push_back(std::to_string(sortkeys[i2]));
				i2++;
			}
		}
	}
	loop = false;
	Wait.join();
	_CLS_;

	// Create output vector
	std::vector<char> output;

	loop = true;
	std::thread wait2(wait1, lines.size());

	// Decryption
	uint32_t i = 0;
	for (std::string line : lines)
	{
		for (char x : line)
		{
			if (x == '\t') {
				output.push_back('\t');
				continue;
			}
			uint64_t key = keys[i];
			std::string alphabet;
			for (int i = 0; i < alphabets.size(); i++)
			{
				if (alphabets[i + 1] == std::to_string(key)) {
					alphabet = alphabets[i];
					break;
				}
			}
			output.push_back(GLOBAL_ALPHABET[alphabet.find(x)]);
			i++;
		}
		output.push_back('\n');
		line1++;
	}
	*numAlphabets = numsAlphabets;
	loop = false;
	wait2.join();
	_CLS_;

	color.set_intensity(true);
	color.set_color(CL_GREEN);
	cout << "\n\nCleaning RAM...";
	color.set_intensity(false);
	color.clear();
	alphabets.clear();
	keys.clear();

	_CLS_;

	color.set_color(CL_CYAN);
	cout << "\n---------------------------------------------\n\n";
	color.clear();

	for (char x : output)
	{
		cout << x;
	}

	color.set_color(CL_CYAN);
	cout << "\n---------------------------------------------\n\n";
	color.clear();
}