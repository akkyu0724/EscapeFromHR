#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "MacroSet.h"
#include "StructSet.h"
#include "DisplaySystem.h"
#include "BaseSystem.h"
#include "MenuSystem.h"

void SplashScreen(void) {

	short CursorPosition = 0;
	short IsSkipped = 0;
	char UserInput;

	system("mode con:cols=92 lines=24");

	CursorView(False);

	while (True) {

		CurPos(0, 0);

		StringColor(Red);

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

		for (int i = 0; !IsSkipped; ++i) {

			CurPos(2, 10);
			CharBlink('+', i % 2, Red);

			CurPos(86, 12);
			CharBlink('+', i % 2, Red);

			CurPos(4, 14);
			CharBlink('*', i % 2, Red);

			CurPos(84, 14);
			CharBlink('*', i % 2, Red);

			if (i % 2) StringColor(Black);
			else StringColor(White);

			CurPos(30, 20);

			puts("Ⅱ Press Any Key to Start ９");

			if (_kbhit()) {

				IsSkipped = 1;
				char Dummy = _getch();
			}

			Sleep(500);
		}

		StringColor(White);

		for (short i = 0; i < 28; ++i) {

			CurPos(30 + i, 20);
			putchar(' ');
		}

		if (_kbhit()) {

			UserInput = _getch();

			if (UserInput == 13) {

				switch (CursorPosition) {

				case 0:
					return;

				case 1:

					GameInfo();
					break;

				case 2:

					Ranking();
					break;

				case 3:

					Credit();
					break;

				case 4:

					exit(0);
					break;
				}
			}

			if (UserInput == -32) {

				UserInput = _getch();

				switch (UserInput) {

				case UP:

					if (CursorPosition > 0) --CursorPosition;
					break;

				case DOWN:

					if (CursorPosition < 4) ++CursorPosition;
					break;

				default:
					break;
				}
			}
		}

		MainMenu(CursorPosition);

		Sleep(50);
	}
}

void PAC(void) {

	for (int i = 0;; ++i) {

		if (i % 2) StringColor(Black);
		else StringColor(White);

		CurPos(22, 20);
		puts("Ⅱ Press Any Key ９");

		if (_kbhit())break;

		Sleep(500);
	}

	Beep((DWORD)_C, 100);

	StringColor(White);

	char Dummy = _getch();
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

	PAC();
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

void GameSetup(void) {

	char UserInput;

	system("cls");

	CurPos(16, 10); puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
	CurPos(16, 11); puts("早 掏濰 �飛� 綠徽擊 餌辨ж衛啊蝗棲梱? (衙辦 掏濰!) [Y/N]早");
	CurPos(16, 12); puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

	while (True) {

		UserInput = _getch();

		Beep((DWORD)_C, 100);

		if (UserInput == 'Y' || UserInput == 'y') {

			system("mode con:cols=67 lines=24");
			break;
		}
		else if (UserInput == 'N' || UserInput == 'n') break;
	}

	system("cls");

	puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
	puts("早 蝶饜葬蒂 衛羶ж衛啊蝗棲梱? [Y/N]早");
	puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

	while (True) {

		UserInput = _getch();

		Beep((DWORD)_C, 100);

		if (UserInput == 'Y' || UserInput == 'y') {

			StoryDescriptor();
			break;
		}
		else if (UserInput == 'N' || UserInput == 'n') break;
	}
}

void UserInfo(char UserName[]) {

	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	char CharBuffer;
	char UserInput;
	char StringBuffer[11] = { 0 };

	int Index = 0;

	system("cls");

	CursorView(True);

	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收旬\n");
	printf("早 渡褐曖 檜葷擎? (譆渠 艙僥 10濠, 奢寥 碳陛)早           早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收旭\n");

	CurPos(46, 1);

	while (True) {

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

		CursorView(0);
		CurPos(1, 3);
		printf("陴擎 旋濠 熱 : %-24d", 56 - curInfo.dwCursorPosition.X);

		CurPos(curInfo.dwCursorPosition.X, 1);
		CursorView(True);

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

				strcpy_s(UserName, 11, StringBuffer);
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

	printf("SYSTEM : %s 餌滄婦椒, 殮溘ж褐 檜葷檜 蜃蝗棲梱? [Y/N]", UserName);

	while (True) {

		UserInput = _getch();

		Beep((DWORD)_C, 100);

		if (UserInput == 'Y' || UserInput == 'y') {

			return;
		}
		else if (UserInput == 'N' || UserInput == 'n') break;
	}

	UserInfo(UserName);
}

void CityInfo(char CityName[]) {

	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	char CharBuffer;
	char UserInput;
	char StringBuffer[11] = { 0 };

	int Index = 0;

	system("cls");

	CursorView(True);

	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收旬\n");
	printf("早 寞橫й 紫衛曖 檜葷擎? (譆渠 艙僥 10濠, 奢寥 碳陛)早           早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收旭\n");

	CurPos(53, 1);

	while (True) {

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

		CursorView(0);
		CurPos(1, 3);
		printf("陴擎 旋濠 熱 : %-29d", 63 - curInfo.dwCursorPosition.X);

		CurPos(curInfo.dwCursorPosition.X, 1);
		CursorView(True);

		CharBuffer = _getche();
		if (CharBuffer > 32) StringBuffer[Index] = CharBuffer;
		++Index;

		if (curInfo.dwCursorPosition.X == 62 || CharBuffer == 13) {

			if (StringBuffer[0] == 0) {

				CurPos(1, 3);
				printf("SYSTEM : 紫衛 檜葷擎 奩萄衛 殮溘п撿 м棲棻.");

				CurPos(curInfo.dwCursorPosition.X, 1);
				Index = 0;

				Sleep(500);
			}
			else {

				strcpy_s(CityName, 11, StringBuffer);
				break;
			}
		}

		else if (CharBuffer == 8 && curInfo.dwCursorPosition.X > 53) {

			Index -= 2;
			if (Index > -1) StringBuffer[Index] = 0;
			putchar(' ');
			CurPos(curInfo.dwCursorPosition.X - 1, 1);
		}
		else if (CharBuffer == 8 && curInfo.dwCursorPosition.X == 53) {

			Index = 0;
			CurPos(curInfo.dwCursorPosition.X, 1);
		}

		Sleep(50);
	}

	CursorView(0);

	CurPos(1, 3);

	printf("SYSTEM : 餌滄婦椒, 殮溘ж褐 紫衛曖 檜葷檜 %s 殮棲梱? [Y/N]", CityName);

	while (True) {

		UserInput = _getch();

		Beep((DWORD)_C, 100);

		if (UserInput == 'Y' || UserInput == 'y') {

			return;
		}
		else if (UserInput == 'N' || UserInput == 'n') break;
	}

	CityInfo(CityName);
}

void UserPrint(short UserPosition) {

	StringColor(Cyan);

	for (short i = 0; i < 12; ++i) {

		CurPos(CityLeft + i, 22);

		if (i == UserPosition) putchar('*');
		else putchar(' ');
	}

	StringColor(White);

	CurPos(0, 23);
}

void BuildingHeight(void) {


	CurPos(16, 1); printf("%d", PowerHeight);
	CurPos(16, 3); printf("%d", FactoryHeight);
	CurPos(16, 5); printf("%d", ResidenceHeight);

	CurPos(0, 23);
}

void AvailableBuilding(Buildings Buil) {



	if (!Buil.PowerLeft) StringColor(Red);
	CurPos(34, 1); printf("%d", Buil.PowerLeft);
	if (!Buil.PowerLeft) StringColor(White);

	if (!Buil.FactoryLeft) StringColor(Red);
	CurPos(34, 3); printf("%d", Buil.FactoryLeft);
	if (!Buil.FactoryLeft) StringColor(White);

	if (!Buil.ResidenceLeft) StringColor(Red);
	CurPos(34, 5); printf("%d", Buil.ResidenceLeft);
	if (!Buil.ResidenceLeft) StringColor(White);

	CurPos(0, 23);
}

void ResourceDisplayer(City City) {


	CurPos(19, 1);

	printf("%-16d", City.Res.EnergyState);

	CurPos(37, 1);

	if (City.OccupyState[City.UserPosition] == Power) {

		StringColor(Green);
		printf("儅 骯 醞");
	}
	else {

		StringColor(Red);
		printf("渠 晦 醞");
	}

	StringColor(White);

	CurPos(19, 3);

	printf("%-16d", City.Res.TechnologyState);

	CurPos(37, 3);

	if (City.OccupyState[City.UserPosition] == Factory) {

		StringColor(Green);
		printf("儅 骯 醞");
	}
	else {

		StringColor(Red);
		printf("渠 晦 醞");
	}

	StringColor(White);

	CurPos(19, 5);

	printf("%-16d", City.Res.CapitalState);

	CurPos(37, 5);

	if (City.OccupyState[City.UserPosition] == Residence) {

		StringColor(Green);
		printf("儅 骯 醞");
	}
	else {

		StringColor(Red);
		printf("渠 晦 醞"); CurPos(19, 3);
	}

	StringColor(White);

	CurPos(0, 23);
}

void UserInfoDisplayer(City CityStr) {

	CurPos(10, 17); printf("%-10s", CityStr.Usr.CityName);
	CurPos(33, 17); printf("%-10s", CityStr.Usr.UserName);
	CurPos(10, 19); printf("%d", CityStr.Score);
}

void GameInitialize(short GamePhase) {

	if (GamePhase == BuildingPhase) {

		system("cls");

		CursorView(False);

		CurPos(1, 0); printf("旨收收收收收收收有收收收收收收收有收收收收收收收收收收收收收收收收收有收收收收收收收收收旬");
		CurPos(1, 1); printf("早 "); StringColor(Yellow);
		printf("嫦瞪模"); StringColor(White);
		printf("早 堪檜 0早 勒撲 陛棟 熱 : 0早 勒撲 : e早");
		CurPos(1, 2); printf("曳收收收收收收收朱收收收收收收收朱收收收收收收收收收收收收收收收收收朱收收收收收收收收收朽");
		CurPos(1, 3); printf("早 "); StringColor(Red);
		printf("奢  濰"); StringColor(White);
		printf("早 堪檜 0早 勒撲 陛棟 熱 : 0早 勒撲 : t早");
		CurPos(1, 4); printf("曳收收收收收收收朱收收收收收收收朱收收收收收收收收收收收收收收收收收朱收收收收收收收收收朽");
		CurPos(1, 5); printf("早 "); StringColor(Green);
		printf("輿剪雖"); StringColor(White);
		printf("早 堪檜 0早 勒撲 陛棟 熱 : 0早 勒撲 : m早");
		CurPos(1, 6); printf("曲收收收收收收收朴收收收收收收收朴收收收收收收收收收收收收收收收收收朴收收收收收收收收收旭");
		CurPos(1, 7); printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
		CurPos(1, 8); printf("早 SYSTEM :                                  早");
		CurPos(1, 9); printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
		CurPos(1, 10); printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
		CurPos(1, 11); printf("早                                           早");
		CurPos(1, 12); printf("早         <褐殮 餌滄婦擊 嬪и 詭賅>         早");
		CurPos(1, 13); printf("早                                           早");
		CurPos(1, 14); printf("早           鏃歜擊 �紊腎炡� 餌滄婦          早");
		CurPos(1, 15); printf("早  嬪 詭景蒂 霤堅ж罹 紫衛 勒撲擊 霞чж啪  早");
		CurPos(1, 16); printf("早     陝 勒僭擎 堅嶸曖 濠錳擊 儅骯и棻啻    早");
		CurPos(1, 17); printf("早        檜�� 儅骯 欽啗縑憮朝 и 廓縑       早");
		CurPos(1, 18); printf("早      и 謙盟曖 濠錳虜 儅骯檜 陛棟ж啻     早");
		CurPos(1, 19); printf("早      斜楝棲 ⑷貲ж啪 勒撲擊 霞чж啪      早");
		CurPos(1, 20); printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
		CurPos(1, 21); printf("旨收收收收收收收有收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收旬");
		CurPos(1, 22); printf("早 檜  翕早 豭薹 : a 螃艇薹 : d早 啪歜 謙猿 : x早");
		CurPos(1, 23); printf("曲收收收收收收收朴收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收旭");

		BuildingHeight();

		CurPos(50, 0); printf("旨收收收收收收收收收收收收收旬");
		for (short i = 1; i < 21; ++i) {
			CurPos(50, i);
			printf("早             早");
		}
		CurPos(50, 21); printf("曳收收收收收收收收收收收收收朽");
		CurPos(50, 22); printf("早             早");
		CurPos(50, 23); printf("曲收收收收收收收收收收收收收旭");

		UserPrint(0);

		CurPos(0, 23);
	}
	else if (GamePhase == ProductionPhase) {

		CurPos(1, 0); printf("旨收收收收收收收有收收收收收收收有收收收收收收收收收收收收收收收收收有收收收收收收收收收旬");
		CurPos(1, 1); printf("早 "); StringColor(Yellow);
		printf("嫦瞪模"); StringColor(White);
		printf("早 "); StringColor(D_Yellow);
		printf("縑傘雖"); StringColor(White);
		printf("早 EEEEEEEEEEEEEE16早 螃 盟 歜早");
		CurPos(1, 2); printf("曳收收收收收收收朱收收收收收收收朱收收收收收收收收收收收收收收收收收朱收收收收收收收收收朽");
		CurPos(1, 3); printf("早 "); StringColor(Red);
		printf("奢  濰"); StringColor(White);
		printf("早 "); StringColor(D_Red);
		printf("晦  獎"); StringColor(White);
		printf("早 EEEEEEEEEEEEEE16早 螃 盟 歜早");
		CurPos(1, 4); printf("曳收收收收收收收朱收收收收收收收朱收收收收收收收收收收收收收收收收收朱收收收收收收收收收朽");
		CurPos(1, 5); printf("早 "); StringColor(Green);
		printf("輿剪雖"); StringColor(White);
		printf("早 "); StringColor(D_Green);
		printf("濠  獄"); StringColor(White);
		printf("早 EEEEEEEEEEEEEE16早 螃 盟 歜早");
		CurPos(1, 6); printf("曲收收收收收收收朴收收收收收收收朴收收收收收收收收收收收收收收收收收朴收收收收收收收收收旭");
		CurPos(1, 10); printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
		CurPos(1, 11); printf("早                                           早");
		CurPos(1, 12); printf("早         <褐殮 餌滄婦擊 嬪и 詭賅>         早");
		CurPos(1, 13); printf("早                                           早");
		CurPos(1, 14); printf("早    寞旎 勒撲檜 諫猿腑棻朝 模衝擊 菟歷啻   早");
		CurPos(1, 15); printf("早           濠啻陛 謝辦煎 遺霜檜賊          早");
		CurPos(1, 16); printf("早          紫雜и 掘羲曖 勒僭煎睡攪         早");
		CurPos(1, 17); printf("早        堅嶸и 濠錳擊 �僱磈� 熱 氈啻       早");
		CurPos(1, 18); printf("早     в蹂и 濠錳擊 �螃窕�戲煎 賅嬴爾啪     早");
		CurPos(1, 19); printf("早        ж萄溯檣檜 橡葆 陴雖 彊懊啻...     早");
		CurPos(1, 20); printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

		CurPos(0, 23);
	}
	else if (GamePhase == HardrainPhase) {

		FILE* RankingData;
		
		char FileLocation[] = "c:\\ProgramData\\AKKYU\\EscapeHR\\ranking.aku";
		char FileLineBuffer[50];
		char* FileSliceBuffer;
		char* FileSliceLeft = NULL;
		char ScoreString[16];
		char ParityChar;

		CurPos(1, 10); printf("旨收收收收收收有收收收收收收收收收收有收收收收收收收收收收收有收收收收收有收收收收收收收旬");
		CurPos(1, 11); printf("早 ");
		StringColor(Cyan); printf("LASER"); StringColor(White);
		printf("早 ");
		StringColor(D_Yellow); printf("10 縑傘雖"); StringColor(White);
		printf("早 и 還 奢問早 嫦餌早  Space早");
		CurPos(1, 12); printf("曳收收收收收收朱收收收收收收收收收收朱收收收收收收收收收收收朱收收收收收朱收收收收收收收朽");
		CurPos(1, 13); printf("早 ");
		StringColor(Yellow); printf("PULSE"); StringColor(White);
		printf("早 ");
		StringColor(D_Green); printf("35 濠  獄"); StringColor(White);
		printf("早 陛梱遴 3偃早 嫦餌早    p  早");
		CurPos(1, 14); printf("曳收收收收收收朱收收收收收收收收收收朱收收收收收收收收收收收朱收收收收收朱收收收收收收收朽");
		CurPos(1, 15); printf("早 熱 葬早 15 晦  獎早 и 類 熱葬早 熱葬早    f  早");
		CurPos(1, 16); printf("曳收收收收收收朱收收收收收收收收收收朴收收收有收收收收收收收朱收收收收收朴收收收收收收收朽");
		CurPos(1, 17); printf("早 紫 衛早 0000000000   早 餌滄婦早 0000000000  早");
		CurPos(1, 18); printf("曳收收收收收收朱收收收收收收收收收收收收收有朴收收收收收收收朴有收收收收收收收收收收收收朽");
		CurPos(1, 19); printf("早 薄 熱早             早 譆堅薄熱早            早");
		CurPos(1, 20); printf("曲收收收收收收朴收收收收收收收收收收收收收朴收收收收收收收收收朴收收收收收收收收收收收收旭");

		fopen_s(&RankingData, FileLocation, "r");

		if (RankingData == NULL) {
			CurPos(34, 19); printf("0");
		}
		else {

			memset(FileLineBuffer, 0, sizeof(FileLineBuffer));

			fgets(FileLineBuffer, sizeof(FileLineBuffer), RankingData);

			FileSliceBuffer = strtok_s(FileLineBuffer, ":", &FileSliceLeft);

			FileSliceBuffer = strtok_s(NULL, ":", &FileSliceLeft);

			FileSliceBuffer = strtok_s(NULL, ":", &FileSliceLeft);

			strcpy_s(ScoreString, sizeof(ScoreString), FileSliceBuffer);

			FileSliceBuffer = strtok_s(NULL, ":", &FileSliceLeft);

			ParityChar = *FileSliceBuffer;

			if (ParityMaker(atoi(ScoreString)) != ParityChar) {

				system("cls");

				CurPos(23, 1); printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
				CurPos(23, 2); printf("早       盪濰 等檜攪陛 槳鼻腎歷蝗棲棻...    早");
				CurPos(23, 3); printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
				CurPos(23, 4); printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
				CurPos(23, 5); printf("早    嬴鼠 酈釭 揚楝憮 蟾晦�� �� 鬼薯謙猿   早");
				CurPos(23, 6); printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

				fclose(RankingData);

				char Dummy = getchar();

				int RmResult = remove(FileLocation);

				if (RmResult == -1) {

					system("cls");

					printf("憲 熱 橈朝 螃盟 嫦儅!\n嬴鼠 酈釭 揚楝 啪歜擊 鬼薯 謙猿м棲棻...");

					char Dummy = _getch();

					exit(-1);
				}

				exit(-1);
			}

			CurPos(34, 19); printf("%d", atoi(ScoreString));
			fclose(RankingData);
		}
	}
}

void SystemMessage(short MessageType) {

	CurPos(12, 8);

	for (short i = 0; i < 33; ++i) putchar(' ');

	CurPos(12, 8);

	switch (MessageType) {

	case BuildingPhase:

		printf("勒僭 勒撲擊 霞чп輿撮蹂.");
		break;

	case EnterProductionPhase:

		for (int i = 0; i < 4; ++i) {

			CurPos(12, 8);

			for (short i = 0; i < 33; ++i) putchar(' ');

			CurPos(12, 8);

			StringColor(Cyan);

			if (i % 2) printf("儅骯 欽啗縑 霞殮м棲棻.");
			else printf("Please Wait...");

			Sleep(500);
		}

		StringColor(White);
		break;

	case ProductionPhase:

		printf("濠錳 儅骯擊 霞чп輿撮蹂.");
		break;

	case AlreadyOccupied:

		StringColor(Red);
		printf("檜嘐 勒僭擊 雖橫霞 奢除殮棲棻.");
		StringColor(White);
		break;

	case NotingLeft:

		StringColor(Red);
		printf("陴擎 勒僭檜 橈蝗棲棻.");
		StringColor(White);
		break;

	case Confirm:

		StringColor(Green);
		printf("勒撲ж衛溥賊 и 廓 渦 揚楝輿撮蹂.");
		StringColor(White);
		break;

	case Canceled:

		StringColor(Red);
		printf("鏃模腎歷蝗棲棻.");
		StringColor(White);
		break;

	default:

		StringColor(Red);
		printf("Error, Someting Went Wrong");
		StringColor(White);
		break;
	}

	CurPos(0, 23);
}

void HardrainAlert(short Timer) {

	CurPos(12, 8);

	for (short i = 0; i < 33; ++i) putchar(' ');

	CurPos(12, 8);

	StringColor(Red);

	if (Timer > 0)
		printf("HardRain 梱雖 %2d蟾 陴懊蝗棲棻.", Timer / 2);
	else
		printf("Hard Rain Impact");

	StringColor(White);

	CurPos(0, 23);
}