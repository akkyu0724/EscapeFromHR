#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

#define PowerHeight 3
#define FactoryHeight 3
#define ResidenceHeight 3

void SplashScreen(void);
void StoryDescriptor(void);

void PAC(void);
void CurPos(short x, short y);
void K_Putchar(char toPrint[], short index);

void TypeAnimation(char toPrint[]);
void DialogDisplay(char toPrint[]);

void UserInfo(void);
void CityInfo(void);

void GameInitialize(void);
void BuildingHeight(void);
void AvailableBuilding(int AvailPower, int AvailFactory, int AvailResidence);

void UserPrint(short UserPosition);

typedef struct {

	char UserName[21];
	char CityName[21];
}User;

typedef struct {

	int PowerLeft;
	int FactoryLeft;
	int ResidenceLeft;
}Buildings;

int main(void) {

	Buildings B = { .PowerLeft = 4,.FactoryLeft = 4,.ResidenceLeft = 4 };

	short UserPosition;

	SplashScreen();
	
	StoryDescriptor();

	UserInfo();
	CityInfo();

	GameInitialize();

	AvailableBuilding(B.PowerLeft, B.FactoryLeft, B.ResidenceLeft);


	return 0;
}

void SplashScreen(void) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

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

	CurPos(30, 17);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	puts("Ⅱ Press Any Key to Start ９");

	char Dummy = _getch();

	for (int i = 0; i < 5; ++i) {
		
		CurPos(30, 17);

		if (i % 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		puts("Ⅱ 煎註醞... 晦棻溥輿撮蹂 ９ ");

		Sleep(250);
	}


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

	puts("\n");
	puts("Ⅱ Press Any Key ９");
	char Dummy = _getch();
}

void CurPos(short x, short y) {

	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void K_Putchar(char toPrint[], short index) {

	putchar(toPrint[index]);
	if (toPrint[index + 1]) putchar(toPrint[index + 1]);
}

void TypeAnimation(char toPrint[]) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void DialogDisplay(char toPrint[]) {

	system("cls");

	printf("旨");

	for (short i = 0; toPrint[i]; ++i) printf("收");

	printf("收旬\n早\n曲");

	for (short i = 0; toPrint[i]; ++i) printf("收");

	printf("收旭");

	CurPos(2, 1);
	TypeAnimation(toPrint);
	printf("早");

	CurPos(0, 2);

	PAC();
}

void UserInfo(void) {

	User U;

	system("cls");

	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早 渡褐曖 檜葷擎? (譆渠 и旋 10濠, 艙僥 20濠) 早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

	CurPos(47, 1);

	gets_s(U.UserName, sizeof(U.UserName));

	CurPos(1, 3);

	printf("SYSTEM : %s 餌滄婦椒, 殮溘ж褐 檜葷檜 蜃蝗棲梱? (Y/N)", U.UserName);

	char UserInput = _getch();

	if (UserInput == 'Y' || UserInput == 'y') return;

	UserInfo();
}
void CityInfo(void) {

	User U;

	system("cls");

	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早 寞橫й 紫衛曖 檜葷擎? (譆渠 и旋 10濠, 艙僥 20濠) 早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

	CurPos(54, 1);

	gets_s(U.CityName, sizeof(U.CityName));

	CurPos(1, 3);

	printf("SYSTEM : 餌滄婦椒, 殮溘ж褐 紫衛曖 檜葷檜 %s 殮棲梱? (Y/N)", U.CityName);

	char UserInput = _getch();

	if (UserInput == 'Y' || UserInput == 'y') return;

	CityInfo();
}

void GameInitialize(void) {

	system("cls");

	CurPos(1, 0);
	printf("旨收收收收收收收有收收收收收收收有收收收收收收收收收收收收收收收收收有收收收收收收收收收旬"); CurPos(1, 1);
	printf("早 嫦瞪模早 堪檜 0早 勒撲 陛棟 熱 : 0早 勒撲 : e早"); CurPos(1, 2);
	printf("曳收收收收收收收朱收收收收收收收朱收收收收收收收收收收收收收收收收收朱收收收收收收收收收朽"); CurPos(1, 3);
	printf("早 奢  濰早 堪檜 0早 勒撲 陛棟 熱 : 0早 勒撲 : t早"); CurPos(1, 4);
	printf("曳收收收收收收收朱收收收收收收收朱收收收收收收收收收收收收收收收收收朱收收收收收收收收收朽"); CurPos(1, 5);
	printf("早 輿剪雖早 堪檜 0早 勒撲 陛棟 熱 : 0早 勒撲 : m早"); CurPos(1, 6);
	printf("曲收收收收收收收朴收收收收收收收朴收收收收收收收收收收收收收收收收收朴收收收收收收收收收旭"); CurPos(1, 7);
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬"); CurPos(1, 8);
	printf("早                                           早"); CurPos(1, 9);
	printf("早                                           早"); CurPos(1, 10);
	printf("早                                           早"); CurPos(1, 11);
	printf("早                                           早"); CurPos(1, 12);
	printf("早           鼠樹陛 菟橫陛朝 奢除            早"); CurPos(1, 13);
	printf("早                                           早"); CurPos(1, 14);
	printf("早                                           早"); CurPos(1, 15);
	printf("早                                           早"); CurPos(1, 16);
	printf("早                                           早"); CurPos(1, 17);
	printf("早                                           早"); CurPos(1, 18);
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭"); CurPos(1, 19);
	printf("旨收收收收收收收有收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收旬"); CurPos(1, 20);
	printf("早 檜  翕早 豭薹 : a 螃艇薹 : d早 啪歜 謙猿 : x早"); CurPos(1, 21);
	printf("曲收收收收收收收朴收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收旭"); CurPos(50, 0);

	printf("旨收收收收收收收收收收收收收旬"); CurPos(50, 1);
	for (short i = 2; i < 22; ++i) {
		printf("早 aaaaaaaaaaaa早"); CurPos(50, i);
	}
	printf("曲收收收收收收收收收收收收收旭");

	BuildingHeight();
}

void BuildingHeight(void) {

	CurPos(16, 1);
	printf("%d", PowerHeight); CurPos(16, 3);
	printf("%d", FactoryHeight); CurPos(16, 5);
	printf("%d", ResidenceHeight);
}

void AvailableBuilding(int AvailPower, int AvailFactory, int AvailResidence) {

	CurPos(34, 1);
	printf("%d", AvailPower); CurPos(34, 3);
	printf("%d", AvailFactory); CurPos(34, 5);
	printf("%d", AvailResidence); CurPos(0, 23);
}