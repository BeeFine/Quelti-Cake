#pragma once
#include "colors.h"

class Texts
{
public:
	std::string TEXT1;
	std::string TEXT2;

	void getLanguage(std::string lang, int iText)
	{
		if (lang == "ru") {
			TEXT1 = "Выберите нужный режим работы:\n\n0. Выход\n1. Шифрование\n2. Расшифровка\n";
			TEXT2 = "Ошибка! Введите число из списка ниже.\nНажмите на любую клавишу для повторного ввода.\n";
			ruText(iText);
		}

		if (lang == "en") {
			TEXT1 = "Select the appropriate mode of operation:\n\n0. Exit\n1. Encryption\n2. Decryption\n";
			TEXT2 = "Error! Enter a number from the list above.\nPress any key to re-enter.\n";
			enText(iText);
		}

		if (lang != "ru" && lang != "en") {
			std::cout << "\nError";
		}
	}

private:
	void enText(int Num)
	{
		switch (Num) {
		case 0:
			break;

		case 2:
			std::cout << "Error! Enter a number from the list above.\nPress any key to re-enter.\n";
			break;

		case 3:
			std::cout << "There are no files to decrypt the message. Encrypt the message first.\n\n";
			break;

		case 4:
			std::cout << "       < 1/2 >\n";
			color.set_color(CL_CYAN);
			std::cout << "\nSelect the desired option:\n\n";
			color.set_color(CL_WHITE);
			std::cout << "1. Encrypting a string\n2. Encrypting a txt file [!NOT WORK!]\n\n";
			break;

		case 5:
			std::cout << "       < 2/2 >\n";
			color.set_color(CL_CYAN);
			std::cout << "\nSelect the encryption level:\n\n";
			color.set_color(CL_WHITE);
			break;

		case 6:
			std::cout << "1. Easy encryption\n";
			color.set_color(CL_GREEN);
			std::cout << "   No phantom symbols, 512 keys are generated.\n\n";
			color.set_color(CL_WHITE);

			std::cout << "2. Medium encryption\n";
			color.set_color(CL_YELLOW);
			std::cout << "   More than 20 phantom characters, 2048 keys are generated.\n\n";
			color.set_color(CL_WHITE);

			std::cout << "3. Hard encryption\n";
			color.set_intensity(true);
			color.set_color(CL_RED);
			std::cout << "   More than 60 phantom characters, 8192 keys are generated.\n\n";
			color.clear();
			color.set_color(CL_WHITE);

			std::cout << "4. Extreme encryption [!NOT WORK!]\n";
			color.set_color(CL_RED);
			std::cout << "   The most reliable method of encryption.\n   Can only be decrypted on the computer on which it was encrypted.\n\n";
			color.set_color(CL_WHITE);
			break;

		case 7:
			color.set_color(CL_WHITE);
			std::cout << "Enter the user password for encryption.\n\n";
			color.clear();
			break;

		case 8:
			color.set_intensity(true);
			color.set_color(CL_RED);
			std::cout << "\nThe password must be longer than 6 characters.\n\n";
			color.clear();
			break;
		}
	}

	void ruText(int Num)
	{
		switch (Num) {
		case 1:
			std::cout << "Выберите нужный режим работы:\n\n0. Выход\n1. Шифрование\n2. Расшифровка\n3. Показать GUID\n";
			break;

		case 2:
			std::cout << "Ошибка! Введите число из списка ниже.\nНажмите на любую клавишу для повторного ввода.\n";
			break;

		case 3:
			std::cout << "Нет файлов для расшифровки сообщения. Сначала зашифруйте сообщение.\n\n";
			break;

		case 4:
			std::cout << "       < 1/2 >\n";
			color.set_color(CL_CYAN);
			std::cout << "\nВыберете нужный режим:\n\n";
			color.set_color(CL_WHITE);
			std::cout << "1. Шифрование строки\n2. Шифрование txt файла [!NOT WORK!]\n\n";
			break;

		case 5:
			std::cout << "       < 2/2 >\n";
			color.set_color(CL_CYAN);
			std::cout << "\nВыберете нужный режим шифрования:\n\n";
			color.set_color(CL_WHITE);
			break;

		case 6:
			std::cout << "1. Простое шифрование\n";
			color.set_color(CL_GREEN);
			std::cout << "   Нет фантомных символов, генерируется 512 ключей.\n\n";
			color.set_color(CL_WHITE);

			std::cout << "2. Среднее шифрование\n";
			color.set_color(CL_YELLOW);
			std::cout << "   Больше 20 фантомных символов, генерируется 2048 ключей.\n\n";
			color.set_color(CL_WHITE);

			std::cout << "3. Сильное шифрование\n";
			color.set_intensity(true);
			color.set_color(CL_RED);
			std::cout << "   Больше 60 фантомных символов, генерируется 8192 ключей.\n\n";
			color.clear();
			color.set_color(CL_WHITE);

			std::cout << "4. Extreme шифрование [!NOT WORK!]\n";
			color.set_color(CL_RED);
			std::cout << "   Самый надежный метод шифрования.\nМожет быть расшифрован только на компьютере, на котором он был зашифрован.\n\n";
			color.set_color(CL_WHITE);
			break;

		case 7:
			color.set_color(CL_WHITE);
			std::cout << "Введите пользовательский пароль для шифрования.\n\n";
			color.clear();
			break;

		case 8:
			color.set_intensity(true);
			color.set_color(CL_RED);
			std::cout << "\nПароль должен быть длиннее 6 символов.\n\n";
			color.clear();
			break;
		}
	}
};