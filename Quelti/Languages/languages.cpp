#include "languages.h"

/*

	_MainScreen_					0
	_MainErrorChoose_				10

	_EncryptionScreen1_				20
	_EncryptionScreen2_MESSAGE		30
	_EncryptionScreen2_PASSWORD		31
	_EncryptionScreen2_ALPHABETS	32
	_EncryptionFinalScreen_			40
	
	_DecryptionScreen1_				50

	_DecryptionScreen2_MESSAGE		60
	_DecryptionScreen2_PASSWORD		61
	_DecryptionScreen2_ALPHABETS	62
	_DecryptionFinalScreen_			70

	_EncryptionFile2_CHOOSE_FILE	80
	_EncryptionFile2_PASSWORD		81
	_EncryptionFile2_ALPHABETS		82
	_EncryptionFileFinal_			90

	_DecryptionFile2_CHOOSE_FILE	180
	_DecryptionFile2_PASSWORD		181
	_DecryptionFile2_ALPHABETS		182
	_DecryptionFileFinal_			190

*/

std::string Languages::english(uint8_t textNumber)
{
	switch (textNumber)
	{
	default:	return "Text call error! Code 6\n";
	case 0:		return "Select the appropriate mode of operation:\n\n1. Encryption\n2. Decryption\n\n";
	case 10:	return "Error! Enter a number from the list above.\nPress any key to re-enter.\n";
	case 20:	return "Select the desired option:\n\n1. Encrypting a string\n2. Encrypting a txt file\n\n";
	case 30:	return "Enter message:\n\n";
	case 31:	return "Enter the user's password for encryption:\n\n";
	case 32:	return "Enter the number of alphabets to generate.\nIf you don't know what it is, skip this step by pressing enter, the default value will be selected:\n\n";
	case 40:	return "\rThis is your encrypted message!\nThe number of alphabets when generating: ";
	case 50:	return "Select the desired option:\n\n1. Decrypting a string\n2. Decrypting a txt file\n\n";
	case 60:	return "Enter message:\n\n";
	case 61:	return "Enter the user's password for decryption:\n\n";
	case 62:	return "Enter the number of alphabets to generate.\nIf you don't know what it is, skip this step by pressing enter, the default value will be selected:\n\n";
	case 70:	return "\rThis is your decrypted message!\nThe number of alphabets when generating: ";
	case 80:	return "Enter the path to the file (absolute or relative):\n\n";
	case 81:	return "Enter the user's password for encryption:\n\n";
	case 82:	return "Enter the number of alphabets to generate.\nIf you don't know what it is, skip this step by pressing enter, the default value will be selected:\n\n";
	case 90:	return "Your file has been successfully encrypted!\nThe number of alphabets when generating: ";
	case 180:	return "Enter the path to the file (absolute or relative):\n\n";
	case 181:	return "Enter the user's password for decryption:\n\n";
	case 182:	return "Enter the number of alphabets to generate.\nIf you don't know what it is, skip this step by pressing enter, the default value will be selected:\n\n";
	case 190:	return "Your file has been successfully decrypted!\nThe number of alphabets when generating: ";
	}
}

std::string Languages::russia(uint8_t textNumber)
{
	switch (textNumber)
	{
	default:	return "������ ������ ������! ��� 6\n";
	case 0:		return "�������� ��������������� ����� ������:\n\n1. ����������\n2. ������������\n\n";
	case 10:	return "������! ������� ����� �� ������ ����.\n������� ����� ������� ��� ���������� �����.\n";
	case 20:	return "�������� ������ �����:\n\n1. ���������� ������\n2. ���������� txt-�����.\n\n";
	case 30:	return "������� ���������:\n\n";
	case 31:	return "������� ������ ������������ ��� ����������:\n\n";
	case 32:	return "������� ���������� ��������� ��� ���������:\n���� �� �� ������, ��� ��� �����, ���������� ���� ���, ����� enter, ����� ������� �������� �� ���������:\n\n";
	case 40:	return "\r��� ���� ������������� ���������.\n���������� ��������� ��� ���������: ";
	case 50:	return "�������� ������ �����:\n\n1. ����������� ������\n2. ����������� txt-�����\n\n";
	case 60:	return "������� ���������:\n\n";
	case 61:	return "������� ������ ������������ ��� �����������:\n\n";
	case 62:	return "������� ���������� ��������� ��� ���������:\n���� �� �� ������, ��� ��� �����, ���������� ���� ���, ����� enter, ����� ������� �������� �� ���������:\n\n";
	case 70:	return "\r��� ���� �������������� ���������.\n���������� ��������� ��� ���������: ";
	case 80:	return "������� ���� � ����� (���������� ��� �������������):\n\n";
	case 81:	return "������� ������ ������������ ��� ����������:\n\n";
	case 82:	return "������� ���������� ��������� ��� ���������:\n���� �� �� ������, ��� ��� �����, ���������� ���� ���, ����� ������� Enter, ����� ������� �������� �� ���������:\n\n";
	case 90:	return "��� ���� ������� ����������!\n���������� ��������� ��� ���������: ";
	case 180:	return "������� ���� � ����� (���������� ��� �������������):\n\n";
	case 181:	return "������� ������ ������������ ��� �����������:\n\n";
	case 182:	return "������� ���������� ��������� ��� ���������:\n���� �� �� ������, ��� ��� �����, ���������� ���� ���, ����� ������� Enter, ����� ������� �������� �� ���������:\n\n";
	case 190:	return "��� ���� ������� �����������!\n���������� ��������� ��� ���������: ";
	}
}

Languages::Languages(std::string language)
	: language(language) {}

std::string Languages::getText(uint8_t textNumber)
{
	if (language == "ru")		return russia(textNumber);
	else if (language == "en")	return english(textNumber);
}
