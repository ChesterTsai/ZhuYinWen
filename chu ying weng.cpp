#include <iostream>
#include <string>

// �`����ѱK��

std::string changeToChuYing(std::string chuYingWeng){
	std::string x = " 1qaz2wsx3edc4rfv5tgb6yhn7ujm8ik,9ol.0p;/-";
	std::string y[] = {" ", "�t", "�u", "�v", "�w", "�x", "�y", "�z", "�{", "��", "�|", "�}", "�~", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��"};
		
	int lenOfInput = chuYingWeng.length();
	int lenOfDecoder = x.length();
	std::string decodedChuYing = "";
	
	for(int i = 0; i < lenOfInput; i++){
		for(int j = 0; j < lenOfDecoder; j++){
			if(chuYingWeng[i] == x[j]){
				decodedChuYing = decodedChuYing + y[j];
			}
		}
	}
	
	return decodedChuYing;
}

std::string changeToPingYin(std::string chuYingWeng){
	std::string x = " 1qaz2wsx3edc4rfv5tgb6yhn7ujm8ik,9ol.0p;/-";
	std::string y[] = {" ", "b", "p", "m", "f", "d", "t", "n", "l", " ", "g", "k", "h", " ", "j", "q", "x", "zh", "ch", "sh", "r", " ", "z", "c", "s", " ", "yi", "wu", "vu", "a", "o", "e", "e", "ai", "ei", "ao", "ou", "an", "in", "ang", "eng", "er"};
	
	int lenOfInput = chuYingWeng.length();
	int lenOfDecoder = x.length();
	std::string pinYing = "";
	
	for(int i = 0; i < lenOfInput; i++){
		for(int j = 0; j < lenOfDecoder; j++){
			if(chuYingWeng[i] == x[j]){
				pinYing = pinYing + y[j];
			}
		}
	}
	return pinYing;
}

int main(){
	std::string chuYingWeng = "";
	std::cout << "��J�`����G";
	std::getline(std::cin, chuYingWeng);
	
	std::cout << "��Ķ���G�G" << changeToChuYing(chuYingWeng) << "\n";
	
	//std::cout << "�����G" << changeToPingYin(chuYingWeng) << "\n";
	
	system("pause");
	
	return 0;
}
