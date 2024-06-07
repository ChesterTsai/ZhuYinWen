// @name	注音文解密器, ZhuYinWen Decoder
// @author	Chester
// @version	3.0
// @description	Convert weird numbers and signs to zhuYin
// @source	https://github.com/ChesterTsai/ZhuYinWen.git

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

std::string changeToZhuYin(std::string zhuYinWen){
	std::map<char, std::string> mapForZhuYin = {
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
		decodedZhuYin += mapForZhuYin[zhuYinWen[i]];
	}

	return decodedZhuYin;
}


// I started to hate myself after doing this part
// why do I even do this shit
std::string changeToPinYin(std::string zhuYinWen){
	std::map<char, std::string> mapForPinYin = {
		{' ', "-"},
		{'1', "b"},
		{'q', "p"},
		{'a', "m"},
		{'z', "f"},
		{'2', "d"},
		{'w', "t"},
		{'s', "n"},
		{'x', "l"},
		{'3', "ˇ"},
		{'e', "g"},
		{'d', "k"},
		{'c', "h"},
		{'4', "ˋ"},
		{'r', "j"},
		{'f', "q"},
		{'v', "x"},
		{'5', "zh"},
		{'t', "ch"},
		{'g', "sh"},
		{'b', "r"},
		{'6', "ˊ"},
		{'y', "z"},
		{'h', "c"},
		{'n', "s"},
		{'7', " "},
		{'8', "a"},
		{'i', "o"},
		{'k', "e"},
		{',', "e"},
		{'9', "ai"},
		{'o', "ei"},
		{'l', "ao"},
		{'.', "ou"},
		{'0', "an"},
		{'p', "en"},
		{';', "ang"},
		{'/', "eng"},
		{'-', "er"}
	};

	// 聲母爲"ㄩ"時的map
	std::map<char, std::string> mapForM = {
		{' ', "u-"},
		{'6', "uˊ"},
		{'3', "uˇ"},
		{'4', "uˋ"},
		{',', "ue"},	// ㄩㄝ
		{'0', "uan"},	// ㄩㄢ
		{'p', "un"},	// ㄩㄣ
		{'/', "iong"}	// ㄩㄥ
	};

	// 聲母爲"ㄨ"時的map
	std::map<char, std::string> mapForJ = {
		{' ', "u-"},
		{'6', "uˊ"},
		{'3', "uˇ"},
		{'4', "uˋ"},
		{'8', "ue"},	// ㄨㄚ
		{'i', "uan"},	// ㄨㄛ
		{'9', "un"},	// ㄨㄞ
		{'o', "iong"},	// ㄨㄟ
		{'0', "uan"},	// ㄨㄢ
		{'p', "un"},	// ㄨㄣ
		{';', "uang"},	// ㄨㄤ
		{'/', "ong"}	// ㄨㄥ
	};

	// 聲母爲"ㄧ"時的map
	std::map<char, std::string> mapForU = {
		{' ', "i-"},
		{'6', "iˊ"},
		{'3', "iˇ"},
		{'4', "iˋ"},
		{'8', "ia"},	// 一ㄚ
		{',', "ie"},	// 一ㄝ
		{'9', "iai"},	// 一ㄞ
		{'l', "iao"},	// 一ㄠ
		{'.', "iu"},	// 一ㄡ
		{'0', "ian"},	// 一ㄢ
		{'p', "in"},	// 一ㄣ
		{';', "iang"},	// 一ㄤ
		{'/', "ing"}	// 一ㄥ
	};

	int lenOfInput = zhuYinWen.length();
	std::string decodedPinYin = "";

	for(int i = 0; i < lenOfInput; i++){
		// 若聲母為"ㄧ"
		if(zhuYinWen[i] == 'u'){
			decodedPinYin += mapForU[zhuYinWen[i + 1]];
			i += 1;
		}
		// 若聲母爲"ㄨ"
		else if(zhuYinWen[i] == 'j'){
			decodedPinYin += mapForJ[zhuYinWen[i + 1]];
			i += 1;
		}
		//若聲母爲"ㄩ"
		else if(zhuYinWen[i] == 'm'){
			decodedPinYin += mapForM[zhuYinWen[i + 1]];
			i += 1;
		}
		else{
			decodedPinYin += mapForPinYin[zhuYinWen[i]];
		}
	}

	return decodedPinYin;
}

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

	std::cout << "拼音" << changeToPinYin(zhuYinWen) << "\n";

	std::cout << "Press Enter Key To Continue...";
	std::cin.get();

	return 0;
}
