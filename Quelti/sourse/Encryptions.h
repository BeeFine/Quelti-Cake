#pragma once
#include "numsEncryption.h"

numsEncryption nums;
std::string GLOBAL_SHUFFLE = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=[]{}|;':,./<>?`\"\\~ ";
const std::string GLOBAL_ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=[]{}|;':,./<>?`\"\\~ ";

void chooseMethod(bool loop);

class Encryptions
{
private:
    void encryptionMethod(std::string input, std::vector<int> chooseM, std::string password)
    {
        std::ofstream key("KEYS\\" + FILE_DIRECTORY + "\\key.qlt");
        std::ofstream message("KEYS\\" + FILE_DIRECTORY + "\\message.qlt");

        int offset;
        int numAlph;

        for (char x : input)
        {
            offset = rand() % chooseM[0] + chooseM[1];
            numAlph = rand() % (chooseM[2] + 1);
            key << nums.intEncryption(numAlph, password) << " " << nums.intEncryption(offset, password) << " ";

            for (int i = 0; i < offset; i++)
            {
                char b = rand() % 95 + 32;
                message << b;
            }

            std::string stringKeys = forKeys(numAlph);
            char encrSymbol = stringKeys[GLOBAL_ALPHABET.find(x)];

            message << encrSymbol;
            std::cout << encrSymbol;

        }

        offset = rand() % chooseM[0] + chooseM[1];
        for (int i = 0; i < offset; i++)
        {
            message << char(rand() % 95 + 32);
        }

        key << " [/*/*/*/]";
        message << " [/*/*/*/]";
        message.close();
        key.close();
    }

    void chooseFile()
    {
        system("cls");
        std::cout << "Choose file:\n\n";
        system("dir KEYS /B /W > decache.sys");
        std::ifstream decache("decache.sys");
        std::vector<std::string> listFiles;

        while (!decache.eof())
        {
            std::string cache;
            getline(decache, cache);
            if (cache == "") {
                break;
            }
            listFiles.push_back(cache);
        }
        decache.close();
        system("del decache.sys");

        int i = 1;
        for (std::string file : listFiles)
        {
            std::cout << i << ". " << listFiles[i - 1] << std::endl;
            i++;
        }
        if (listFiles.empty()) {
            std::cout << "\nFolder empty!\n";
            system("pause");
            chooseMethod(true);
        }

        std::string input;

        std::cout << "\n";
        getline(std::cin, input);

        if (isnum(input)) {
            while (true) {
                if (stoi(input) > listFiles.size() && stoi(input) <= 0) {
                    text.getLanguage(SETTINGS[0], 2);
                }
                else break;
            }
        }

        FILE_DIRECTORY = listFiles[stoi(input) - 1];
        system("cls");
    }

    std::vector<int> choose(std::string Num)
    {
        switch (Num[1]) {
        case '1':
            return { 1, 0, 512 };
            break;

        case '2':
            return { 31, 20, 2048 };
            break;

        case '3':
            return { 41, 60, 8192 };
            break;
        }
    }

    bool isnum(std::string& line)
    {
        auto end = line.end();
        auto i = line.begin();
        if (i == end) return false;
        bool exp = false;
        bool dot = false;
        if (*i >= '0' && *i <= '9')
        {
            i++;
            for (; i != end; i++)
            {
                if (*i >= '0' && *i <= '9') continue;
                else if (*i == 'E' && exp == false)
                {
                    i++;
                    if (i == end) return false;
                }
                else if (*i == '.' && i != line.begin() && dot == false)
                {
                    dot = true;
                    continue;
                }
                else return false;
            }
        }
        else return false;
        return true;
    }

    std::vector<std::string> getFile(int iLoop)
    {
        std::string fileName;
        if (iLoop == 0) {
            fileName = "KEYS\\" + FILE_DIRECTORY + "\\key.qlt";
        }
        else {
            fileName = "KEYS\\" + FILE_DIRECTORY + "\\message.qlt";
        }
        iLoop++;
        std::vector<std::string> vsFile;
        std::ifstream file(fileName);
        std::string cacheFile;
        int i = 0;
        while (std::getline(file, cacheFile))
        {
            if (fileName == ("KEYS\\" + FILE_DIRECTORY + "\\key.qlt")) {
                if (cacheFile.find(" [/*/*/*/]") != std::string::npos) {
                    vsFile.push_back(std::string(cacheFile));
                    cacheFile.pop_back();
                    return vsFile;
                }
            }
            else {
                if (cacheFile.find(" [/*/*/*/]") != std::string::npos) {
                    vsFile.push_back(std::string(cacheFile));
                    for (int i = 0; i < 10; i++)
                    {
                        cacheFile.pop_back();
                    } 
                    return vsFile;
                }
            }
            vsFile.push_back(std::string(cacheFile));
            i++;

        }
        file.close();
    }

    std::string forKeys(int key)
    {
        std::string Output;
        std::ifstream file("KEYS\\" + FILE_DIRECTORY + "\\keys.qlt");
        char cache[97];
        int i = 0;
        int o = 0;
        while (!file.eof())
        {
            file.getline(cache, 97);

            if (i == key)
            {
                Output = std::string(cache);
                break;
            }
            i++;

        }
        file.close();
        return Output;
    }

    bool testFiles()
    {
        std::ifstream testFile1("KEYS\\" + FILE_DIRECTORY + "\\message.qlt");
        std::ifstream testFile2("KEYS\\" + FILE_DIRECTORY + "\\keys.qlt");
        std::ifstream testFile3("KEYS\\" + FILE_DIRECTORY + "\\key.qlt");
        if (testFile1) {
            if (testFile2) {
                if (testFile3) {
                    return true;
                }
                else { return false; }
            }
            else { return false; }
        }
        else { return false; }
    }

public:
    void fileEncryption(std::string chooseInput)
    {
        while (true)
        {
            system("cls");
            int iInput;
            std::vector<int> forEncryption;
            color.clear();
            iInput = stoi(chooseInput);

            if (isnum(chooseInput) == false) {
                std::cout << "\nIt isn't num!\n";
            }
            else {
                std::string password;
                std::cout << "Enter password for encryption.\n";
                std::cout << "[ USER ] --> ";
                getline(std::cin, password);
                system("cls");
                forEncryption = choose(chooseInput);

                std::string text = "FileForEncryption\\";
                std::string input2;
                std::vector<std::string> filesForEncryption;
                LPCSTR lpcstrText = text.c_str();
                CreateDirectory(lpcstrText, NULL);

                system("dir FileForEncryption /B /W > cache2.txt");
                std::cout << "Choose file for encryption\n";
                std::ifstream file("cache2.txt");
                if (file) {
                    std::string cache;
                    int i = 1;
                    while (!file.eof())
                    {
                        getline(file, cache);
                        filesForEncryption.push_back(cache);
                        std::cout << i << ". " << cache << std::endl;
                    }
                    file.close();
                    system("del cache2.txt");
                    getline(std::cin, input2);
                    if (atoi(input2.c_str()) != 0) {
                        std::ifstream fileEncr(filesForEncryption[atoi(input2.c_str())-1]);
                        if (fileEncr) {
                            /*#################################*/

                            FILE_DIRECTORY = filesForEncryption[atoi(input2.c_str())-1];
                            while (!fileEncr.eof())
                            {
                                std::string cache;
                                getline(fileEncr, cache);
                                encryptionMethod(cache, forEncryption, password);
                            }

                            /*#################################*/
                        }
                        else {
                            std::cout << "\nError!\n";
                        }
                    }
                    else {
                        std::cout << "\nIncorrect number\n";
                    }
                }
                else {
                    std::cout << "\nError!\n";
                }
            }
        }
    }

    std::string GUIDcreate()
    {
        CoInitialize(NULL);
        GUID guid;
        CoCreateGuid(&guid);
        OLECHAR* bstrGuid;
        StringFromCLSID(guid, &bstrGuid);
        std::wstring ws(bstrGuid);
        std::string str(ws.begin(), ws.end());
        CoTaskMemFree(bstrGuid);
        CoUninitialize();
        return str;
    }

    void encryption(std::string GLOBAL_ALPHABET, std::string answer)    // Шифрование сообщения
    {
        std::vector<int> chooseM = choose(answer);
        system("cls");
        std::cout << "Enter the name of the directory where the message files will be stored.\n\n";
        color.set_color(CL_CYAN);
        std::cout << "[ USER ] --> ";
        std::getline(std::cin, FILE_DIRECTORY);

        std::string sKeys = "KEYS\\";
        LPCSTR lpswstrKeys = sKeys.c_str();
        CreateDirectory(lpswstrKeys, NULL);

        std::string kFILE_DIRECTORY = "KEYS\\" + FILE_DIRECTORY;
        LPCSTR lpswstrDIRECTORY = kFILE_DIRECTORY.c_str();
        CreateDirectory(lpswstrDIRECTORY, NULL);
        color.clear();
        system("cls");
        std::cout << "File path: ";
        color.set_color(CL_GREEN);
        std::cout << "KEYS\\" << FILE_DIRECTORY << "\\message.qlt\n\n\n";
        color.clear();

        std::ofstream keys("KEYS\\" + FILE_DIRECTORY + "\\keys.qlt");
        for (int i = 0; i <= chooseM[2]; i++)
        {
            std::random_shuffle(GLOBAL_SHUFFLE.begin(), GLOBAL_SHUFFLE.end());
            keys << GLOBAL_SHUFFLE << std::endl;
        }
        std::string input;
        std::string password;
        char cacheKeys[400];
        int randomNum;
        int b = 0;
        int i = 0;
        int c = 0;
        char Symbol;

        while (true)
        {
            color.set_color(CL_WHITE);
            std::cout << "Enter the user password for encryption.\n\n";
            color.set_color(CL_CYAN);
            std::cout << "[ USER ] --> ";
            std::getline(std::cin, password);

            if (password.size() <= 6) {
                color.set_intensity(true);
                color.set_color(CL_RED);
                std::cout << "\nThe password must be longer than 6 characters.\n\n";
                color.clear();
                system("pause > \"%temp%\\cache.txt\"");
                system("del \"%temp%\\cache.txt\"");
                system("cls");
            }
            else {
                break;
            }
        }

        keys.close();
        std::cout << std::endl << std::endl;
        color.set_color(CL_WHITE);
        std::cout << "Enter message that you want to encrypt.\n\n";
        color.set_color(CL_CYAN);
        std::cout << "[ USER ] --> ";
        std::getline(std::cin, input);
        color.clear();
        std::cout << std::endl << std::endl;
        color.set_intensity(true);
        color.set_color(CL_GREEN);

        encryptionMethod(input, chooseM, password);

        color.clear();
        std::cout << std::endl << "    " << char(24) << "\n   This string is not the final encrypted message!";
        system("pause > \"%temp%\\cache.txt\"");
        system("del %temp%\\cache.txt");
    }

    void decryption(std::string GLOBAL_ALPHABET)
    {
        chooseFile();

        std::string password;
        color.set_color(CL_WHITE);
        std::cout << "Enter the user password for decryption.\n\n";
        color.set_color(CL_CYAN);
        std::cout << "[ USER ] --> ";
        std::getline(std::cin, password);
        std::cout << std::endl;

        std::vector<std::string> INTs;
        std::string word;

        std::vector<std::string> key = getFile(0);
        std::vector<std::string> message = getFile(1);

        for (std::string words : key)
        {
            for (char cache : words)
            {
                if (cache == ' ') {
                    INTs.push_back(word); 
                    word = "";
                }
                else { word += cache; }
            }
            INTs.push_back(word);
        }
        key.clear();

        INTs.pop_back();
        std::cout << std::endl;
        color.set_intensity(true);
        color.set_color(CL_GREEN);

        int i = 0;
        int o = 0;
        int o1 = 1;

        int offset = nums.intDecryption(INTs[o1], password); //dir "C:\Users\beefi\source\repos\Project Phantom\Project Phantom\KEYS" /B /W

        for (std::string Stroka : message)
        {
            for (char x : Stroka)
            {
                if (i == offset) {
                    int nom = nums.intDecryption(INTs[o], password);
                    std::string alph = forKeys(nom);
                    int a = alph.find(x);
                    if (a < 0) break;
                    std::cout << GLOBAL_ALPHABET[a];
                    o += 2;
                    o1 += 2;
                    if (o1 >= INTs.size()) {
                        break;
                    }
                    offset = nums.intDecryption(INTs[o1], password);
                    i = -1;
                }
                i++;
            }

        }
        key.clear();
        message.clear();
        system("pause > \"%temp%\\cache.txt\"");
        system("del %temp%\\cache.txt");
    }
};