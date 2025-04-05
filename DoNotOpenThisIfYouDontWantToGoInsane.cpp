/*
 * I gonna make this into the most unreadable code of all time
 */
#include "header.h"
std::map<char, std::string> mapForZhuYin = {{' ', " "},{'1', "ㄅ"},{'q', "ㄆ"},{'a', "ㄇ"},{'z', "ㄈ"},{'2', "ㄉ"},{'w', "ㄊ"},{'s', "ㄋ"},{'x', "ㄌ"},{'3', "ˇ"},{'e', "ㄍ"},{'d', "ㄎ"},{'c', "ㄏ"},{'4', "ˋ"},{'r', "ㄐ"},{'f', "ㄑ"},{'v', "ㄒ"},{'5', "ㄓ"},{'t', "ㄔ"},{'g', "ㄕ"},{'b', "ㄖ"},{'6', "ˊ"},{'y', "ㄗ"},{'h', "ㄘ"},{'n', "ㄙ"},{'7', "˙"},{'u', "ㄧ"},{'j', "ㄨ"},{'m', "ㄩ"},{'8', "ㄚ"},{'i', "ㄛ"},{'k', "ㄜ"},{',', "ㄝ"},{'9', "ㄞ"},{'o', "ㄟ"},{'l', "ㄠ"},{'.', "ㄡ"},{'0', "ㄢ"},{'p', "ㄣ"},{';', "ㄤ"},{'/', "ㄥ"},{'-', "ㄦ"}};std::map<char, std::string> mapForPinYin = {{' ', "-"},{'1', "b"},{'q', "p"},{'a', "m"},{'z', "f"},{'2', "d"},{'w', "t"},{'s', "n"},{'x', "l"},{'3', "ˇ"},{'e', "g"},{'d', "k"},{'c', "h"},{'4', "ˋ"},{'r', "j"},{'f', "q"},{'v', "x"},{'5', "zh"},{'t', "ch"},{'g', "sh"},{'b', "r"},{'6', "ˊ"},{'y', "z"},{'h', "c"},{'n', "s"},{'7', " "},{'u', "y"},{'j', "w"},{'m', "v"},{'8', "a"},{'i', "o"},{'k', "e"},{',', "e"},{'9', "ai"},{'o', "ei"},{'l', "ao"},{'.', "ou"},{'0', "an"},{'p', "en"},{';', "ang"},{'/', "eng"},{'-', "er"}};std::map<char, std::string> mapForM = {{' ', "u-"},{'6', "uˊ"},{'3', "uˇ"},{'4', "uˋ"},{',', "ue"},{'0', "uan"},{'p', "un"},{'/', "iong"}};std::map<char, std::string> mapForJ = {{' ', "u-"},{'6', "uˊ"},{'3', "uˇ"},{'4', "uˋ"},{'8', "ua"},{'i', "uo"},{'9', "uai"},{'o', "ui"},{'0', "uan"},{'p', "un"},{';', "uang"},{'/', "ong"}};std::map<char, std::string> mapForU = {{' ', "i-"},{'6', "iˊ"},{'3', "iˇ"},{'4', "iˋ"},{'8', "ia"},{',', "ie"},{'9', "iai"},{'l', "iao"},{'.', "iu"},{'0', "ian"},{'p', "in"},{';', "iang"},{'/', "ing"}};std::string changeToZhuYin(std::string zhuYinWen){int lenOfInput = zhuYinWen.length();std::string decodedZhuYin = "";for(int i = 0; i < lenOfInput; i++) {decodedZhuYin += mapForZhuYin[zhuYinWen[i]];}return decodedZhuYin;}std::string changeToPinYin(std::string zhuYinWen){int lenOfInput = zhuYinWen.length();std::string decodedPinYin = "";for(int i = 0; i < lenOfInput; i++) {bool isUJM = (zhuYinWen[i] == 'u' || zhuYinWen[i] == 'j' || zhuYinWen[i] == 'm');bool isInitial = (i==0 || (zhuYinWen[i-1] == ' ' || zhuYinWen[i-1] == '3' || zhuYinWen[i-1] == '4' || zhuYinWen[i-1] == '6' || zhuYinWen[i-1] == '7'));if(!isUJM) {decodedPinYin += mapForPinYin[zhuYinWen[i]];continue;}if(isUJM && isInitial) {decodedPinYin += mapForPinYin[zhuYinWen[i]];continue;}switch (zhuYinWen[i]) {case 'u':decodedPinYin += mapForU[zhuYinWen[i + 1]];i += 1;break;case 'j':decodedPinYin += mapForJ[zhuYinWen[i + 1]];i += 1;break;case 'm':decodedPinYin += mapForM[zhuYinWen[i + 1]];i += 1;break;}}return decodedPinYin;}void stringToLower(std::string &s){std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {return std::tolower(c);});}int main(){std::string zhuYinWen;while(1) {zhuYinWen = "";std::cout << "輸入注音文(按下CTRL+C暫停)：";std::getline(std::cin >> std::ws, zhuYinWen);stringToLower(zhuYinWen);std::cout << "解譯結果：" << changeToZhuYin(zhuYinWen) << "\n";std::cout << "拼音：" << changeToPinYin(zhuYinWen) << "\n\n";	}return 0;}
