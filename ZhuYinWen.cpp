// @name	注音文解密器, ZhuYinWen Decoder
// @author	Chester
// @version	3.2
// @description	Convert weird numbers and signs to zhuYin
// @source	https://github.com/ChesterTsai/ZhuYinWen.git
// @lastUpdate	2024.07.07

#include <iostream>
#include <string>
#include <algorithm>
#include <map>


// 轉換成注音
std::string changeToZhuYin(std::string zhuYinWen){

	// 英文及符號所對應的注音
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


	// 替換文字
	int lenOfInput = zhuYinWen.length();
	std::string decodedZhuYin = "";

	for(int i = 0; i < lenOfInput; i++){
		decodedZhuYin += mapForZhuYin[zhuYinWen[i]];
	}

	return decodedZhuYin;
}


// 轉換成拼音
std::string changeToPinYin(std::string zhuYinWen){

	// 定義注音符號對應拼音的 map
	std::map<char, std::string> mapForPinYin = {
		{' ', "-"}, 
		{'1', "b"}, // ㄅ
		{'q', "p"}, // ㄆ
		{'a', "m"}, // ㄇ
		{'z', "f"}, // ㄈ
		{'2', "d"}, // ㄉ
		{'w', "t"}, // ㄊ
		{'s', "n"}, // ㄋ
		{'x', "l"}, // ㄌ
		{'3', "ˇ"}, // ˇ
		{'e', "g"}, // ㄍ
		{'d', "k"}, // ㄎ
		{'c', "h"}, // ㄏ
		{'4', "ˋ"}, // ˋ
		{'r', "j"}, // ㄐ
		{'f', "q"}, // ㄑ
		{'v', "x"}, // ㄒ
		{'5', "zh"}, // ㄓ
		{'t', "ch"}, // ㄔ
		{'g', "sh"}, // ㄕ
		{'b', "r"}, // ㄖ
		{'6', "ˊ"}, // ˊ
		{'y', "z"}, // ㄗ
		{'h', "c"},// ㄘ
		{'n', "s"}, // ㄙ
		{'7', " "}, // ˙
		{'u', "y"}, // 一
		{'j', "w"}, // ㄨ
		{'m', "v"}, // ㄩ
		{'8', "a"}, // ㄚ
		{'i', "o"}, // ㄛ
		{'k', "e"}, // ㄠ
		{',', "e"}, // ㄝ
		{'9', "ai"}, // ㄞ
		{'o', "ei"}, // ㄟ
		{'l', "ao"}, // ㄠ
		{'.', "ou"}, // ㄡ
		{'0', "an"}, // ㄢ
		{'p', "en"}, // ㄣ
		{';', "ang"}, // ㄤ
		{'/', "eng"}, // ㄥ
		{'-', "er"} // ㄦ
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
		{'8', "ua"},	// ㄨㄚ
		{'i', "uo"},	// ㄨㄛ
		{'9', "uai"},	// ㄨㄞ
		{'o', "ui"},	// ㄨㄟ
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
		// 找出聲母
		switch(zhuYinWen[i])
		{
		// 若聲母為"ㄩ"
		case 'm':
			if(i==0 || (zhuYinWen[i-1] == ' ' || zhuYinWen[i-1] == '3' || zhuYinWen[i-1] == '4' || zhuYinWen[i-1] == '6' || zhuYinWen[i-1] == '7')){
				decodedPinYin += mapForPinYin[zhuYinWen[i]];
				break;
			}
			decodedPinYin += mapForM[zhuYinWen[i + 1]];
			i += 1;
			break;
		// 若聲母爲"ㄨ"
		case 'j':
			if(i==0 || (zhuYinWen[i-1] == ' ' || zhuYinWen[i-1] == '3' || zhuYinWen[i-1] == '4' || zhuYinWen[i-1] == '6' || zhuYinWen[i-1] == '7')){
				decodedPinYin += mapForPinYin[zhuYinWen[i]];
				break;
			}
			decodedPinYin += mapForJ[zhuYinWen[i + 1]];
			i += 1;
			break;
		// 若聲母爲"一"
		case 'u':
			if(i==0 || (zhuYinWen[i-1] == ' ' || zhuYinWen[i-1] == '3' || zhuYinWen[i-1] == '4' || zhuYinWen[i-1] == '6' || zhuYinWen[i-1] == '7')){
				decodedPinYin += mapForPinYin[zhuYinWen[i]];
				break;
			}
			decodedPinYin += mapForU[zhuYinWen[i + 1]];
			i += 1;
			break;
		// 其他聲母
		default:
			decodedPinYin += mapForPinYin[zhuYinWen[i]];
			break;
		}
	}

	return decodedPinYin;
}


// 將字串轉換成小寫
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

	std::cout << "拼音：" << changeToPinYin(zhuYinWen) << "\n";

	// Linux也可以用的暫停方法
	std::cout << "Press Enter Key To Continue...";
	std::cin.get();

	return 0;
}
