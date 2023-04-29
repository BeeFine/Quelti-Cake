/////////////////
//  MAIN FILE  //
/////////////////

#include "Quelti.h"
using std::cout;

bool bChoose = false;

void start();
void chooseMethod(bool loop);
void generateSrand();
void readSettings();

int main()   // MAIN
{
    readSettings();
    text.getLanguage(SETTINGS[0], 0);
    start();
    chooseMethod(bChoose);
}

void start()   // Стартовые настройки приложения
{
    generateSrand();
    if (SETTINGS[3] == "false") {
        system("title Project Phantom");
    }
    if (SETTINGS[3] == "true") {
        std::string title = "title " + std::to_string(rand());
        system(title.c_str());
    }
    if (SETTINGS[0] != "ru" && SETTINGS[0] != "en") {
        std::cout << "Settings error!";
        system("pause");
        exit(1);
    }

    setlocale(LC_ALL, SETTINGS[1].c_str());
    system("color f");
}

void chooseMethod(bool loop)           // Выбор шифрования или расшифровки, bool loop принимает true если функция вызывается больше 1го раза, иначе false.
{                                      // Значение нужно для настройки анимации.
    system("cls");
    color.set_color(CL_WHITE);
    std::string userInput;

    if (SETTINGS[2] == "true") {
        if (!loop)  // Если loop == false то выводим анимацию
        {
            for (char s : text.TEXT1) {
                std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 25 + 15));
                std::cout << s;
            }
        }
        else { cout << text.TEXT1; }
    }
    if (SETTINGS[2] == "false") {
        cout << text.TEXT1;
    }

    bChoose = true;
    color.set_color(CL_CYAN);
    std::cout << "\n[ USER ] --> ";
    std::getline(std::cin, userInput);
    color.set_color(CL_WHITE);

    if (userInput[0] == '0') {
        exit(0);
    }
    if (userInput[0] == '1') {
        std::string answer;
        std::cout << std::endl;
        system("cls");
        text.getLanguage(SETTINGS[0], 4);

        color.set_color(CL_CYAN);
        std::cout << "[ USER ] --> ";
        std::getline(std::cin, userInput);
        color.set_color(CL_WHITE);
        answer += userInput[0];

        system("cls");
        text.getLanguage(SETTINGS[0], 5);

        text.getLanguage(SETTINGS[0], 6);

        color.set_color(CL_CYAN);
        std::cout << "[ USER ] --> ";
        std::getline(std::cin, userInput);
        color.set_color(CL_WHITE);
        answer += userInput[0];

        if(answer[0] == '1') encr.encryption(GLOBAL_ALPHABET, answer);
        if (answer[0] == '2') encr.fileEncryption(answer);
        chooseMethod(true);
    }
    if (userInput[0] == '2') {
        std::cout << std::endl;

        encr.decryption(GLOBAL_ALPHABET);
        chooseMethod(true);

    }
    else {
        color.set_intensity(true);
        color.set_color(CL_RED);
        std::cout << std::endl;
        for (char c : text.TEXT2) {
            std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 30 + 20));
            std::cout << c;
        }
        system("pause > \"%temp%\\cache.txt\"");
        color.clear();
        chooseMethod(true);
    }

}

void generateSrand()
{
    std::string GUID = encr.GUIDcreate();
    std::string USER_ID_STRING;
    for (int x = 1; x < (GUID.size() - 2); x++)
    {
        int cache = GUID[x];
        USER_ID_STRING += std::to_string(cache);
    }
    srand(time(0) * atoi(USER_ID_STRING.c_str()));
}

void readSettings()
{
    nlohmann::json Json;
    std::ifstream fileJson("config.json");
    fileJson >> Json;
    fileJson.close();

    SETTINGS.push_back(Json["language"]);
    SETTINGS.push_back(Json["setLocale"]);
    SETTINGS.push_back(Json["animations"]);
    SETTINGS.push_back(Json["randomTitle"]);

    if (Json["defaultConfig"][0]["enabled"] == "true") {
        SETTINGS.push_back(Json["defaultConfig"][1]["page_1"]);
        SETTINGS.push_back(Json["defaultConfig"][1]["page_2"]);

        if (Json["defaultConfig"][1]["page_1"] == "not_assigned" || Json["defaultConfig"][1]["page_2"] == "not_assigned") {
            std::cout << "\nError\n";
        }
    }
}
