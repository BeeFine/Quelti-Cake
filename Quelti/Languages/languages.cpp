#include "languages.h"

std::string Languages::english(uint8_t textNumber)
{
	switch (textNumber)
	{
	default:		return "Text call error! Code 6\n";
	case 0:			return "Select the appropriate mode of operation:\n\n1. Encryption\n2. Decryption\n\n";
	case 10:		return "Error! Enter a number from the list above.\nPress any key to re-enter.\n";
	case 20:		return "Select the desired option:\n\n1. Encrypting a string\n2. Encrypting a txt file [!NOT WORK!]\n\n";
	case 30:		return "Enter message:\n\n";
	case 31:		return "Enter the user's password for encryption:\n\n";
	case 32:		return "Enter the number of alphabets to generate.\nIf you don't know what it is, skip this step by pressing enter, the default value will be selected:\n\n";
	case 40:		return "\rThis is your encrypted message!\nThe number of alphabets when generating: ";
	case 50:		return "Select the desired option:\n\n1. Decrypting a string\n2. Decrypting a txt file [!NOT WORK!]\n\n";
	case 60:		return "Enter message:\n\n";
	case 61:		return "Enter the user's password for decryption:\n\n";
	case 62:		return "Enter the number of alphabets to generate.\nIf you don't know what it is, skip this step by pressing enter, the default value will be selected:\n\n";
	case 70:		return "\rThis is your decrypted message!\nThe number of alphabets when generating: ";
	case 80:		return "Enter the path to the file (absolute or relative):\n\n";
	case 81:		return "Enter the user's password for encryption:\n\n";
	case 82:		return "Enter the number of alphabets to generate.\nIf you don't know what it is, skip this step by pressing enter, the default value will be selected:\n\n";
	case 90:		return "Your file has been successfully encrypted!";
	}
}

std::string Languages::getText(uint8_t textNumber)
{
	return Languages::english(textNumber);
}
