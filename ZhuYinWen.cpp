// @name	注音文解密器, ZhuYinWen Decoder
// @author	Chester
// @version	2.4
// @description	Convert weird numbers and signs to zhuYin
// @source	https://github.com/ChesterTsai/ZhuYinWen.git

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

std::string changeToZhuYin(std::string zhuYinWen){
	std::map<char, std::string> map1 = {
		{' ', " "},
		{'1', "ㄅ"},
		{'q', "ㄆ"},
		{'a', "ㄇ"},
		{'z', "ㄈ"},
		{'2', "ㄉ"},
		{'w', "ㄊ"},
		{'s', "ㄋ"},
		{'x', "ㄌ"},
		{'3', "ˇ"},
		{'e', "ㄍ"},
		{'d', "ㄎ"},
		{'c', "ㄏ"},
		{'4', "ˋ"},
		{'r', "ㄐ"},
		{'f', "ㄑ"},
		{'v', "ㄒ"},
		{'5', "ㄓ"},
		{'t', "ㄔ"},
		{'g', "ㄕ"},
		{'b', "ㄖ"},
		{'6', "ˊ"},
		{'y', "ㄗ"},
		{'h', "ㄘ"},
		{'n', "ㄙ"},
		{'7', "˙"},
		{'u', "ㄧ"},
		{'j', "ㄨ"},
		{'m', "ㄩ"},
		{'8', "ㄚ"},
		{'i', "ㄛ"},
		{'k', "ㄜ"},
		{',', "ㄝ"},
		{'9', "ㄞ"},
		{'o', "ㄟ"},
		{'l', "ㄠ"},
		{'.', "ㄡ"},
		{'0', "ㄢ"},
		{'p', "ㄣ"},
		{';', "ㄤ"},
		{'/', "ㄥ"},
		{'-', "ㄦ"}
	};

	int lenOfInput = zhuYinWen.length();
	std::string decodedZhuYin = "";

	for(int i = 0; i < lenOfInput; i++){
		decodedZhuYin += map1[zhuYinWen[i]];
	}

	return decodedZhuYin;
}

// std::string changeToPinYin(std::string zhuYinWen){
// 	std::string x = " 1qaz2wsx3edc4rfv5tgb6yhn7ujm8ik,9ol.0p;/-";
// 	std::string y[] = {" ", "b", "p", "m", "f", "d", "t", "n", "l", " ", "g", "k", "h", " ", "j", "q", "x", "zh", "ch", "sh", "r", " ", "z", "c", "s", " ", "yi", "wu", "vu", "a", "o", "e", "e", "ai", "ei", "ao", "ou", "an", "in", "ang", "eng", "er"};

// 	int lenOfInput = zhuYinWen.length();
// 	int lenOfDecoder = x.length();
// 	std::string pinYin = "";

// 	for(int i = 0; i < lenOfInput; i++){
// 		for(int j = 0; j < lenOfDecoder; j++){
// 			pinYin = wordReplace(zhuYinWen[i], x[j], y[j], pinYin);
// 		}
// 	}
// 	return pinYin;
// }

void stolower(std::string &s){
	std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
		return std::tolower(c);
	});
}

int main(){
	std::string zhuYinWen = "";
	std::cout << "輸入注音文：";
	std::getline(std::cin >> std::ws, zhuYinWen);

	stolower(zhuYinWen);

	std::cout << "解譯結果：" << changeToZhuYin(zhuYinWen) << "\n";

	// std::cout << "拼音" << changeToPinYin(zhuYinWen) << "\n";

	std::cout << "Press Enter Key To Continue...";
	std::cin.get();

	return 0;
}
