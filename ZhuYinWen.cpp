/**
 * @name	注音文解密器, ZhuYinWen Decoder
 * @author	Chester
 * @version	3.3
 * @description	Convert weird numbers and signs to zhuYin
 * @source	https://github.com/ChesterTsai/ZhuYinWen
 * @lastUpdate	2024.09.26
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

/**
 * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
 * │Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐
 * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
 * │~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │N L│ / │ * │ - │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
 * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
 * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
 * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │     │ 1 │ 2 │ 3 │   │
 * ├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E││
 * │ Ctrl│    │Alt │         Space         │ Alt│    │    │Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │←─┘│
 * └─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
 *
 *              ,----------------,              ,---------,
 *         ,-----------------------,          ,"        ,"|
 *       ,"                      ,"|        ,"        ,"  |
 *      +-----------------------+  |      ,"        ,"    |
 *      |  .-----------------.  |  |     +---------+      |
 *      |  |                 |  |  |     | -==----'|      |
 *      |  |  I LOVE DOS!    |  |  |     |         |      |
 *      |  |  Bad command or |  |  |/----|`---=    |      |
 *      |  |  C:\>_          |  |  |   ,/|==== ooo |      ;
 *      |  |                 |  |  |  // |(((( [33]|    ,"
 *      |  `-----------------'  |," .;'| |((((     |  ,"
 *      +-----------------------+  ;;  | |         |,"
 *         /_)______________(_/  //'   | +---------+
 *    ___________________________/___  `,
 *   /  oooooooooooooooo  .o.  oooo /,   \,"-----------
 *  / ==ooooooooooooooo==.o.  ooo= //   ,`\--{)B     ,"
 * /_==__==========__==_ooo__ooo=_/'   /___________,"
 *
 *
 *                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
 *             __.'              ~.   .~              `.__
 *           .'//                  \./                  \\`.
 *         .'//                     |                     \\`.
 *       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \\`.
 *     .'//.-"                 `-.  |  .-'                 "-.\\`.
 *   .'//______.============-..   \ | /   ..-============.______\\`.
 * .'______________________________\|/______________________________`.
 *
 *
 *
 *
 *
 *
 * 「鍵盤、電腦、書」
 *
 * 作者：進軍的王小二
 * 鏈接：https://juejin.cn/post/6905998341889490958
 * 來源：稀土掘金
 * 著作權歸作者所有。商業轉載請聯系作者獲得授權，非商業轉載請注明出處。
 */


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

// 一般情況下的拼音對照表
std::map<char, std::string> mapForPinYin = {
	{' ', "-"},
	{'1', "b"},	// ㄅ
	{'q', "p"},	// ㄆ
	{'a', "m"},	// ㄇ
	{'z', "f"},	// ㄈ
	{'2', "d"},	// ㄉ
	{'w', "t"},	// ㄊ
	{'s', "n"},	// ㄋ
	{'x', "l"},	// ㄌ
	{'3', "ˇ"},	// ˇ
	{'e', "g"},	// ㄍ
	{'d', "k"},	// ㄎ
	{'c', "h"},	// ㄏ
	{'4', "ˋ"},	// ˋ
	{'r', "j"},	// ㄐ
	{'f', "q"},	// ㄑ
	{'v', "x"},	// ㄒ
	{'5', "zh"},	// ㄓ
	{'t', "ch"},	// ㄔ
	{'g', "sh"},	// ㄕ
	{'b', "r"},	// ㄖ
	{'6', "ˊ"},	// ˊ
	{'y', "z"},	// ㄗ
	{'h', "c"},	// ㄘ
	{'n', "s"},	// ㄙ
	{'7', " "},	// ˙
	{'u', "y"},	// 一
	{'j', "w"},	// ㄨ
	{'m', "v"},	// ㄩ
	{'8', "a"},	// ㄚ
	{'i', "o"},	// ㄛ
	{'k', "e"},	// ㄠ
	{',', "e"},	// ㄝ
	{'9', "ai"},	// ㄞ
	{'o', "ei"},	// ㄟ
	{'l', "ao"},	// ㄠ
	{'.', "ou"},	// ㄡ
	{'0', "an"},	// ㄢ
	{'p', "en"},	// ㄣ
	{';', "ang"},	// ㄤ
	{'/', "eng"},	// ㄥ
	{'-', "er"}	// ㄦ
};

// 聲母爲"ㄩ"時的對照表
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

// 聲母爲"ㄨ"時的對照表
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

/**
 * 偷偷放一個艾莉同學內褲圖，看看會不會有人發現
 * https://i.imgur.com/BWw0Kjl.png
 */

// 聲母爲"ㄧ"時的對照表
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


std::string changeToZhuYin(std::string zhuYinWen)
{
	int lenOfInput = zhuYinWen.length();
	std::string decodedZhuYin = "";

	for(int i = 0; i < lenOfInput; i++) {
		decodedZhuYin += mapForZhuYin[zhuYinWen[i]];
	}

	return decodedZhuYin;
}


std::string changeToPinYin(std::string zhuYinWen)
{
	int lenOfInput = zhuYinWen.length();
	std::string decodedPinYin = "";

	for(int i = 0; i < lenOfInput; i++) {

		/**
		 * 判斷輸入的注音符號是否爲ㄧㄨㄩ,
		 * 輸出True則輸入爲ㄧㄨㄩ;
		 * False則爲其他注音符號
		 */
		bool isUJM = (zhuYinWen[i] == 'u' || zhuYinWen[i] == 'j' || zhuYinWen[i] == 'm');

		/**
		 * 判斷ㄧㄨㄩ是放在介音還是聲母的位置,
		 * 輸出True則ㄧㄨㄩ放在聲母位置;
		 * False則ㄧㄨㄩ放在介音位置
		 */
		bool isInitial = (i==0 || (zhuYinWen[i-1] == ' ' || zhuYinWen[i-1] == '3' || zhuYinWen[i-1] == '4' || zhuYinWen[i-1] == '6' || zhuYinWen[i-1] == '7'));

		if(!isUJM) {
			decodedPinYin += mapForPinYin[zhuYinWen[i]];
			continue;
		}
		if(isUJM && isInitial) {
			decodedPinYin += mapForPinYin[zhuYinWen[i]];
			continue;
		}

		switch (zhuYinWen[i]) {
		// 若介音爲"ㄧ"
		case 'u':
			decodedPinYin += mapForU[zhuYinWen[i + 1]];
			i += 1;
			break;
		// 若介音爲"ㄨ"
		case 'j':
			decodedPinYin += mapForJ[zhuYinWen[i + 1]];
			i += 1;
			break;
		// 若介音爲"ㄩ"
		case 'm':
			decodedPinYin += mapForM[zhuYinWen[i + 1]];
			i += 1;
			break;
		}
	}

	return decodedPinYin;
}


void stringToLower(std::string &s)
{
	std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
		return std::tolower(c);
	});
}


int main()
{
	std::string zhuYinWen;

	while(1) {
		zhuYinWen = "";

		std::cout << "輸入注音文(按下CTRL+C暫停)：";
		std::getline(std::cin >> std::ws, zhuYinWen);

		stringToLower(zhuYinWen);

		std::cout << "解譯結果：" << changeToZhuYin(zhuYinWen) << "\n";

		std::cout << "拼音：" << changeToPinYin(zhuYinWen) << "\n\n";	
	}

	return 0;
}
