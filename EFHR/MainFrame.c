/*
2021 Yonsei Computer Programming Project (prof. Hyo Sang Lim)
[Game - Hard Rain Impact]

All code written by Sungha Choi

All rights reserved...
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

#define PowerHeight 4
#define FactoryHeight 3
#define ResidenceHeight 2

#define DialogLength 63

enum { 

	Black, 
	D_Blue, 
	D_Green, 
	D_Cyan, 
	D_Red, 
	D_Violet, 
	D_Yellow, 
	Gray, 
	D_Gray, 
	Blue, 
	Green, 
	Cyan, 
	Red, 
	Violet, 
	Yellow, 
	White 
};

struct User {

	char UserName[11];
	char CityName[11];
}U;

typedef struct {

	int PowerLeft;
	int FactoryLeft;
	int ResidenceLeft;
}Buildings;

typedef struct {

	int PowerHealth;
	int FactoryHealth;
	int ResidenceHealth;
}Health;

void SplashScreen(void);
void CharBlink(char toBlink, short show, short color);

void GameSetup(void);
 
void StoryDescriptor(void);

void PAC(void);
void CurPos(short x, short y);
void CursorView(short show);
void K_Putchar(char toPrint[], short index);

void TypeAnimation(char toPrint[]);
void DialogDisplay(char toPrint[]);

void UserInfo(void);
void CityInfo(void);

void GameInitialize(void);
void BuildingHeight(void);
void AvailableBuilding(int AvailPower, int AvailFactory, int AvailResidence);
void SystemMessage(short MessageType);

void UserPrint(short UserPosition);

void MakePower(short UserPosition);
void MakeFactory(short UserPosition);
void MakeResidence(short UserPosition);

int main(void) {

	Buildings B = { .PowerLeft = 4,.FactoryLeft = 4,.ResidenceLeft = 4 };

	short OccupyState[12] = { 0 };
	
	short GameState = 0;
	short UserPosition = 0;
	short IsBuildingError = 0;
	char UserInput;

	system("title Hard Rain Impact v1.0");

	SplashScreen();
	
	GameSetup();

	UserInfo();
	CityInfo();

	GameInitialize();

	AvailableBuilding(B.PowerLeft, B.FactoryLeft, B.ResidenceLeft);
	SystemMessage(GameState);

	while (1) {

		IsBuildingError = 0;

		UserPrint(UserPosition);

		UserInput = _getch();

		if (UserInput == 'x') break;

		else if (UserInput == 'a') --UserPosition;
		else if (UserInput == 'd') ++UserPosition;

		else if (!GameState && UserInput == 'e') {

			if (OccupyState[UserPosition]) {

				SystemMessage(-1);
				IsBuildingError = 1;
			}
			else if (!B.PowerLeft) {

				SystemMessage(-2);
				IsBuildingError = 1;
			}

			if (!IsBuildingError) {

				MakePower(UserPosition);
				++OccupyState[UserPosition];
				--B.PowerLeft;
			}
		}
		else if (!GameState && UserInput == 't') {

			if (OccupyState[UserPosition]) {

				SystemMessage(-1);
				IsBuildingError = 1;
			}
			else if (!B.FactoryLeft) {

				SystemMessage(-2);
				IsBuildingError = 1;
			}

			if (!IsBuildingError) {

				MakeFactory(UserPosition);
				++OccupyState[UserPosition];
				--B.FactoryLeft;
			}
		}
		else if (!GameState && UserInput == 'm') {

			if (OccupyState[UserPosition]) {

				SystemMessage(-1);
				IsBuildingError = 1;
			}
			else if (!B.ResidenceLeft) {

				SystemMessage(-2);
				IsBuildingError = 1;
			}

			if (!IsBuildingError) {

				MakeResidence(UserPosition);
				++OccupyState[UserPosition];
				--B.ResidenceLeft;
			}
		}

		AvailableBuilding(B.PowerLeft, B.FactoryLeft, B.ResidenceLeft);

		if (!GameState && !B.PowerLeft && !B.FactoryLeft && !B.ResidenceLeft) ++GameState;
		if (!IsBuildingError) SystemMessage(GameState);

		if (UserPosition < 0) UserPosition = 0;
		else if (UserPosition > 11) UserPosition = 11;
	}

	DialogDisplay("啪歜擊 謙猿м棲棻... 釭醞縑 棻衛 瞄啊蝗棲棻 餌滄婦椒.");

	return 0;
}

void SplashScreen(void) {

	CursorView(0);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Red);

	putchar('\n');
	puts(":::    :::     :::     :::::::::  :::::::::   :::::::::      :::     ::::::::::: ::::    :::");
	puts(":+:    :+:   :+: :+:   :+:    :+: :+:    :+:  :+:    :+:   :+: :+:       :+:     :+:+:   :+:");
	puts("+:+    +:+  +:+   +:+  +:+    +:+ +:+    +:+  +:+    +:+  +:+   +:+      +:+     :+:+:+  +:+");
	puts("+#++:++#++ +#++:++#++: +#++:++#:  +#+    +:+  +#++:++#:  +#++:++#++:     +#+     +#+ +:+ +#+");
	puts("+#+    +#+ +#+     +#+ +#+    +#+ +#+    +#+  +#+    +#+ +#+     +#+     +#+     +#+  +#+#+#");
	puts("#+#    #+# #+#     #+# #+#    #+# #+#    #+#  #+#    #+# #+#     #+#     #+#     #+#   #+#+#");
	puts("###    ### ###     ### ###    ### #########   ###    ### ###     ### ########### ###    ####");
	putchar('\n');
	puts("          ::::::::::: ::::    ::::  :::::::::      :::      ::::::::  :::::::::::");
	puts("              :+:     +:+:+: :+:+:+ :+:    :+:   :+: :+:   :+:    :+:     :+:    ");
	puts("              +:+     +:+ +:+:+ +:+ +:+    +:+  +:+   +:+  +:+            +:+    ");
	puts("              +#+     +#+  +:+  +#+ +#++:++#+  +#++:++#++: +#+            +#+    ");
	puts("              +#+     +#+       +#+ +#+        +#+     +#+ +#+            +#+    ");
	puts("              #+#     #+#       #+# #+#        #+#     #+# #+#    #+#     #+#    ");
	puts("          ########### ###       ### ###        ###     ###  ########      ###    ");

	for (int i = 0;; ++i) {

		CurPos(2, 10);
		CharBlink('+', i % 2, Red);

		CurPos(86, 12);
		CharBlink('+', i % 2, Red);

		CurPos(4, 14);
		CharBlink('*', i % 2, Red);

		CurPos(84, 14);
		CharBlink('*', i % 2, Red);

		if (i % 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Black);
		else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);

		CurPos(30, 17);
		puts("Ⅱ Press Any Key to Start ９");

		if (_kbhit())break;

		Sleep(500);
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);

	char Dummy = _getch();
}

void CharBlink(char toBlink, short show, short color) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	if (show) putchar(toBlink);
	else putchar(' ');
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
}

void GameSetup(void) {

	char UserInput;

	system("cls");

	puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
	puts("早 掏濰 �飛� 綠徽擊 餌辨ж衛啊蝗棲梱? (衙辦 掏濰!) [Y/N]早");
	puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

	UserInput = _getch();

	if (UserInput == 'Y' || UserInput == 'y') system("mode con:cols=67 lines=24");

	system("cls");

	puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
	puts("早 蝶饜葬蒂 衛羶ж衛啊蝗棲梱? [Y/N]早");
	puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

	UserInput = _getch();

	if (UserInput == 'Y' || UserInput == 'y') StoryDescriptor();
}

void StoryDescriptor(void) {

	system("cls");

	DialogDisplay("SYSTEM : Incoming Message...");
	DialogDisplay("SYSTEM : 曹晝 詭衛雖殮棲棻.");
	DialogDisplay("薑羹碳貲曖 錳檣 縑檜瞪お(Agent)煎 檣п 殖檜 7褻陝戲煎 薺偃螺棻啻.");
	DialogDisplay("7褻陝曖 殖擎 陝濠曖 醞溘戲煎 и翕寰 捨紫蒂 嶸雖ж艘戲釭,");
	DialogDisplay("埠 憮煎 醱給ж罹 渦 濛擎 褻陝戲煎 釭斯橫雖晦 衛濛ц啻.");
	DialogDisplay("舒粽 夢餌曖 衛嘆溯檜暮縑 曖ж賊 檜楝и 醱給 ⑷鼻擎 晦ж晝熱瞳戲煎 陛樓腆 匙檜貊...");
	DialogDisplay("埠 瞪 雖掘 捨紫陛 殖曖 懍戮 褻陝戲煎 菴竣檜朝 �倣昄� 蝶蘋檜(White Sky) ⑷鼻檜 嫦儅й 匙檜塭 и棻啻.");
	DialogDisplay("衛嘆溯檜暮 唸婁縑憮 渦遵 懍選и 匙擎 �倣昄� 蝶蘋檜 嫦儅 �� 賃 喇 檜頂縑...");
	DialogDisplay("熱 褻 偃縑 殖ж朝 捨紫 鼻曖 殖 懍戮 褻陝菟檜 雖掘 醞溘縑 檜莊溥 翕衛棻嫦瞳戲煎 雖掘煎 踏嬴螳 頂葬朝...");
	DialogDisplay("ж萄溯檣(Hard Rain) ⑷鼻檜 衛濛腎橫 擒 5,000喇 除 雖樓脹棻朝 匙檜啻. ");
	DialogDisplay("辦葬 檣盟朝 謙蜓擊 跡瞪縑 舒堅 氈啻...");
	DialogDisplay("濠啻朝 檜楝и 瞰蜂瞳檣 鼻�窒□� 紫衛蒂 勒撲ж堅 檣盟曖 葆雖虞 �騆謊� 辦輿摹...");
	DialogDisplay("贗塭辦萄嬴觼(Cloud Ark)蒂 勒褻ж罹 嫦餌й 陽 梱雖 髦嬴陴朝 嘐暮擊 雖�秷� 餌滄婦戲煎 歜貲腎歷啻.");
	DialogDisplay("檣盟曖 嘐楚陛 斜渠曖 橫梟縑 殖溥氈啻...");
	DialogDisplay("餌滄婦...");
	DialogDisplay("勒癱蒂 綠啻.");
	DialogDisplay("SYSTEM : 鱔褐檜 謙猿腎歷蝗棲棻.");
}

void PAC(void) {

	for (int i = 0;; ++i) {

		if (i % 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Black);
		else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);

		CurPos(22, 20);
		puts("Ⅱ Press Any Key ９");

		if (_kbhit())break;

		Sleep(500);
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);

	char Dummy = _getch();
}

void CurPos(short x, short y) {

	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorView(short show) {

	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void K_Putchar(char toPrint[], short index) {

	putchar(toPrint[index]);
	if (toPrint[index + 1]) putchar(toPrint[index + 1]);
}

void TypeAnimation(char toPrint[]) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cyan);

	for (short i = 0; toPrint[i]; i += 2) {

		if (toPrint[i] != ' ') {

			K_Putchar(toPrint, i);
			Sleep(25);
		}
		else {

			putchar(' ');
			--i;
		}

		if (!toPrint[i + 1]) break;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
}

void DialogDisplay(char toPrint[]) {

	char LineCutA[DialogLength + 1];
	char LineCutB[DialogLength + 1];

	short Line = 1;
	short StrLen = (short)strlen(toPrint);

	if (StrLen > DialogLength) {

		strncpy_s(LineCutA, sizeof(LineCutA), toPrint, DialogLength);

		for (short i = 0; i < StrLen - DialogLength; ++i) LineCutB[i] = toPrint[i + DialogLength];

		LineCutB[StrLen - DialogLength] = 0;

		++Line;
	}

	system("cls");

	CurPos(0, 0);

	printf("旨");

	if (Line < 2) {

		for (short i = 0; i < DialogLength; ++i) printf("收");

		printf("收旬\n早\n曲");

		for (short i = 0; i < DialogLength; ++i) printf("收");

		printf("收旭");

		CurPos(DialogLength + 2, 1);
		printf("早");

		CurPos(2, 1);
		TypeAnimation(toPrint);
	}
	else {

		for (short i = 0; i < DialogLength; ++i) printf("收");

		printf("收旬\n早\n早\n曲");

		for (short i = 0; i < DialogLength; ++i) printf("收");

		printf("收旭");

		CurPos(DialogLength + 2, 1);
		printf("早");
		CurPos(DialogLength + 2, 2);
		printf("早");

		CurPos(2, 1);
		TypeAnimation(LineCutA);

		CurPos(2, 2);
		TypeAnimation(LineCutB);
	}
	CurPos(0, 2);

	PAC();
}

void UserInfo(void) {

	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	char CharBuffer;
	char UserInput;
	char StringBuffer[11] = { 0 };

	int Index = 0;

	system("cls");

	CursorView(1);

	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收旬\n");
	printf("早 渡褐曖 檜葷擎? (譆渠 艙僥 10濠, 奢寥 碳陛)早           早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收旭\n");

	CurPos(46, 1);

	while (1) {

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

		CursorView(0);
		CurPos(1, 3);
		printf("陴擎 旋濠 熱 : %-24d", 56 - curInfo.dwCursorPosition.X);

		CurPos(curInfo.dwCursorPosition.X, 1);
		CursorView(1);

		CharBuffer = _getche();
		if (CharBuffer > 32) StringBuffer[Index] = CharBuffer;
		++Index;

		if (curInfo.dwCursorPosition.X == 55 || CharBuffer == 13) {

			if (StringBuffer[0] == 0) {

				CurPos(1, 3);
				printf("SYSTEM : 檜葷擎 奩萄衛 殮溘п撿 м棲棻.");

				CurPos(curInfo.dwCursorPosition.X, 1);
				Index = 0;

				Sleep(500);
			}
			else {
			
				strcpy_s(U.UserName, sizeof(U.UserName), StringBuffer);
				break;
			}
		}

		else if (CharBuffer == 8 && curInfo.dwCursorPosition.X > 46) {

			Index -= 2;
			if (Index > -1) StringBuffer[Index] = 0;
			putchar(' ');
			CurPos(curInfo.dwCursorPosition.X - 1, 1);
		}
		else if (CharBuffer == 8 && curInfo.dwCursorPosition.X == 46) {

			Index = 0;
			CurPos(curInfo.dwCursorPosition.X, 1);
		}

		Sleep(50);
	}

	CursorView(0);

	CurPos(1, 3);

	printf("SYSTEM : %s 餌滄婦椒, 殮溘ж褐 檜葷檜 蜃蝗棲梱? [Y/N]", U.UserName);

	UserInput = _getch();

	if (UserInput == 'Y' || UserInput == 'y') return;

	UserInfo();
}

void CityInfo(void) {

	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	char Dummy;
	char UserInput;
	char StringBuffer[11] = { 0 };

	int Index = 0;

	system("cls");

	CursorView(1);

	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收旬\n");
	printf("早 寞橫й 紫衛曖 檜葷擎? (譆渠 艙僥 10濠, 奢寥 碳陛)早           早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收旭\n");

	CurPos(53, 1);

	while (1) {

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

		CursorView(0);
		CurPos(1, 3);
		printf("陴擎 旋濠 熱 : %-29d", 63 - curInfo.dwCursorPosition.X);

		CurPos(curInfo.dwCursorPosition.X, 1);
		CursorView(1);

		Dummy = _getche();
		if (Dummy > 32) StringBuffer[Index] = Dummy;
		++Index;

		if (curInfo.dwCursorPosition.X == 62 || Dummy == 13) {

			if (StringBuffer[0] == 0) {

				CurPos(1, 3);
				printf("SYSTEM : 紫衛 檜葷擎 奩萄衛 殮溘п撿 м棲棻.");

				CurPos(curInfo.dwCursorPosition.X, 1);
				Index = 0;

				Sleep(500);
			}
			else {

				strcpy_s(U.CityName, sizeof(U.CityName), StringBuffer);
				break;
			}
		}

		else if (Dummy == 8 && curInfo.dwCursorPosition.X > 53) {

			Index -= 2;
			if(Index > -1) StringBuffer[Index] = 0;
			putchar(' ');
			CurPos(curInfo.dwCursorPosition.X - 1, 1);
		}
		else if (Dummy == 8 && curInfo.dwCursorPosition.X == 53) {

			Index = 0;
			CurPos(curInfo.dwCursorPosition.X, 1);
		}

		Sleep(50);
	}

	CursorView(0);

	CurPos(1, 3);

	printf("SYSTEM : 餌滄婦椒, 殮溘ж褐 紫衛曖 檜葷檜 %s 殮棲梱? [Y/N]", U.CityName);

	UserInput = _getch();

	if (UserInput == 'Y' || UserInput == 'y') return;

	CityInfo();
}

void GameInitialize(void) {

	system("cls");

	CursorView(0);

	CurPos(1, 0);
	printf("旨收收收收收收收有收收收收收收收有收收收收收收收收收收收收收收收收收有收收收收收收收收收旬"); CurPos(1, 1);
	printf("早 "); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Yellow);
	  printf("嫦瞪模"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
	        printf("早 堪檜 0早 勒撲 陛棟 熱 : 0早 勒撲 : e早"); CurPos(1, 2);
	printf("曳收收收收收收收朱收收收收收收收朱收收收收收收收收收收收收收收收收收朱收收收收收收收收收朽"); CurPos(1, 3);
	printf("早 "); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Red);
	  printf("奢  濰"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
	        printf("早 堪檜 0早 勒撲 陛棟 熱 : 0早 勒撲 : t早"); CurPos(1, 4);
	printf("曳收收收收收收收朱收收收收收收收朱收收收收收收收收收收收收收收收收收朱收收收收收收收收收朽"); CurPos(1, 5);
	printf("早 "); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Green);
	  printf("輿剪雖"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
	        printf("早 堪檜 0早 勒撲 陛棟 熱 : 0早 勒撲 : m早"); CurPos(1, 6);
	printf("曲收收收收收收收朴收收收收收收收朴收收收收收收收收收收收收收收收收收朴收收收收收收收收收旭"); CurPos(1, 7);
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬"); CurPos(1, 8);
	printf("早 SYSTEM :                                  早"); CurPos(1, 9);
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭"); CurPos(1, 10);
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬"); CurPos(1, 11);
	printf("早                                           早"); CurPos(1, 12);
	printf("早                <歜衛 紫遺蜓>              早"); CurPos(1, 13);
	printf("早                                           早"); CurPos(1, 14);
	printf("早  嬪 詭景曖 勒撲酈蒂 援腦賊 勒僭擊 騁朝棻. 早"); CurPos(1, 15);
	printf("早                                           早"); CurPos(1, 16);
	printf("早      ⑷薯 薯濛 欽啗 : 勒僭 勒撲 掘⑷      早"); CurPos(1, 17);
	printf("早                                           早"); CurPos(1, 18);
	printf("早                                           早"); CurPos(1, 19);
	printf("早                                           早"); CurPos(1, 20);
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭"); CurPos(1, 21);
	printf("旨收收收收收收收有收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收旬"); CurPos(1, 22);
	printf("早 檜  翕早 豭薹 : a 螃艇薹 : d早 啪歜 謙猿 : x早"); CurPos(1, 23);
	printf("曲收收收收收收收朴收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收旭"); 

	BuildingHeight();

	CurPos(50, 0);
	printf("旨收收收收收收收收收收收收收旬"); CurPos(50, 1);
	for (short i = 2; i < 22; ++i) {
		printf("早             早"); CurPos(50, i);
	}
	printf("曳收收收收收收收收收收收收收朽"); CurPos(50, 22);
	printf("早             早"); CurPos(50, 23);
	printf("曲收收收收收收收收收收收收收旭");
}

void BuildingHeight(void) {

	CurPos(16, 1);
	printf("%d", PowerHeight); CurPos(16, 3);
	printf("%d", FactoryHeight); CurPos(16, 5);
	printf("%d", ResidenceHeight);
}

void AvailableBuilding(int AvailPower, int AvailFactory, int AvailResidence) {

	CurPos(34, 1);

	if (!AvailPower) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Red);
	printf("%d", AvailPower); CurPos(34, 3);
	if (!AvailPower) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);

	if (!AvailFactory) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Red);
	printf("%d", AvailFactory); CurPos(34, 5);
	if (!AvailFactory) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);

	if (!AvailResidence) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Red);
	printf("%d", AvailResidence);
	if (!AvailResidence) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
}

void SystemMessage(short MessageType) {

	CurPos(12, 8);
	for (short i = 0; i < 33; ++i)putchar(' ');

	CurPos(12, 8);

	switch (MessageType) {
	
	case 0:

		printf("勒僭 勒撲擊 霞чп輿撮蹂.");
		break;

	case 1:

		printf("%s 紫衛蒂 寞橫ж塭!", U.CityName);
		break;

	case -1:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Red);
		printf("檜嘐 勒僭擊 雖橫霞 奢除殮棲棻.");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
		break;

	case -2:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Red);
		printf("陴擎 勒僭檜 橈蝗棲棻.");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
		break;

	default:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Red);
		printf("Error, Someting Went Wrong");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
		break;
	}
}

void UserPrint(short UserPosition) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cyan);

	for (short i = 0; i < 12; ++i) {
		
		CurPos(52 + i, 22);

		if (i == UserPosition) putchar('*');
		else putchar(' ');
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
	CurPos(0, 23);
}

void MakePower(short UserPosition) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Yellow);

	for (short i = 20; i > 20 - PowerHeight; --i) {
	
		CurPos(52 + UserPosition, i);
		putchar('E');
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
	CurPos(0, 23);
}

void MakeFactory(short UserPosition) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Red);

	for (short i = 20; i > 20 - FactoryHeight; --i) {

		CurPos(52 + UserPosition, i);
		putchar('T');
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
	CurPos(0, 23);
}

void MakeResidence(short UserPosition) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Green);

	for (short i = 20; i > 20 - ResidenceHeight; --i) {

		CurPos(52 + UserPosition, i);
		putchar('M');
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), White);
	CurPos(0, 23);
}