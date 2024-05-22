#include <iostream>
#include <string>
#include <algorithm>

// 注音文解密器

std::string wordReplace(char sameWordA, char sameWordB, std::string replaceWithThisWord, std::string replaceResult){
	if(sameWordA == sameWordB){
		replaceResult = replaceResult + replaceWithThisWord;
	}
	return replaceResult;
}

std::string changeToChuYing(std::string chuYingWeng){
	std::string x = " 1qaz2wsx3edc4rfv5tgb6yhn7ujm8ik,9ol.0p;/-";
	std::string y[] = {" ", "ㄅ", "ㄆ", "ㄇ", "ㄈ", "ㄉ", "ㄊ", "ㄋ", "ㄌ", "ˇ", "ㄍ", "ㄎ", "ㄏ", "ˋ", "ㄐ", "ㄑ", "ㄒ", "ㄓ", "ㄔ", "ㄕ", "ㄖ", "ˊ", "ㄗ", "ㄘ", "ㄙ", "˙", "ㄧ", "ㄨ", "ㄩ", "ㄚ", "ㄛ", "ㄜ", "ㄝ", "ㄞ", "ㄟ", "ㄠ", "ㄡ", "ㄢ", "ㄣ", "ㄤ", "ㄥ", "ㄦ"};

	int lenOfInput = chuYingWeng.length();
	int lenOfDecoder = x.length();
	std::string decodedChuYing = "";

	for(int i = 0; i < lenOfInput; i++){
		for(int j = 0; j < lenOfDecoder; j++){
			decodedChuYing = wordReplace(chuYingWeng[i], x[j], y[j], decodedChuYing);
		}
	}

	return decodedChuYing;
}


// std::string changeToPingYin(std::string chuYingWeng){
// 	std::string x = " 1qaz2wsx3edc4rfv5tgb6yhn7ujm8ik,9ol.0p;/-";
// 	std::string y[] = {" ", "b", "p", "m", "f", "d", "t", "n", "l", " ", "g", "k", "h", " ", "j", "q", "x", "zh", "ch", "sh", "r", " ", "z", "c", "s", " ", "yi", "wu", "vu", "a", "o", "e", "e", "ai", "ei", "ao", "ou", "an", "in", "ang", "eng", "er"};

// 	int lenOfInput = chuYingWeng.length();
// 	int lenOfDecoder = x.length();
// 	std::string pinYing = "";

// 	for(int i = 0; i < lenOfInput; i++){
// 		for(int j = 0; j < lenOfDecoder; j++){
// 			pinYing = wordReplace(chuYingWeng[i], x[j], y[j], pinYing);
// 		}
// 	}
// 	return pinYing;
// }

void stolower(std::string &s){
	std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
		return std::tolower(c);
	});
}

int main(){
	std::string chuYingWeng = "";
	std::cout << "輸入注音文：";
	std::getline(std::cin, chuYingWeng);

	stolower(chuYingWeng);

	std::cout << "解譯結果：" << changeToChuYing(chuYingWeng) << "\n";

	// std::cout << "拼音" << changeToPingYin(chuYingWeng) << "\n";

	std::cout << "Press Enter Key To Continue...";
	std::cin.get();

	return 0;
}
