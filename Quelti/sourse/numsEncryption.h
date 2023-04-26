#pragma once

class numsEncryption
{
private:
    int charToInt(char x) // Вспомогательная функция
    {
        int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
        return arr[x - '0'];
    }

public:
    std::string intEncryption(int Num, std::string Password)
    {
        std::string sNum = std::to_string(Num);
        std::string ret;
        int i = 0;
        for (char x : sNum)
        {
            int c = charToInt(x);
            c += int(Password[int(Password[i]) % Password.size()]) + int(Password[i]);
            std::string cache = std::to_string(c);
            ret += cache[cache.size() - 1];
            i++;
        }
        return ret;
    }

    int intDecryption(std::string Num, std::string Password)
    {
        std::string ret;
        std::string ret2;
        int i = 0;
        for (char x : Num)
        {
            int c = charToInt(x);
            c -= int(Password[int(Password[i]) % Password.size()]) + int(Password[i]);
            std::string cache = std::to_string(c);
            ret = cache[cache.size() - 1];
            ret = std::to_string(10 - stoi(ret));
            ret2 += ret[ret.size() - 1];
            i++;
        }
        return stoi(ret2);
    }
};