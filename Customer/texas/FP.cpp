#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<unistd.h>
#include<stdlib.h>

#define keyESC 27
#define keyUp 72 	
#define keyDown 80
#define keyLeft 75
#define keyRight 77
#define keyEnter 13

// Struct
typedef struct item{
	char makan[255];
	int Hmak;
	char minum[255];
	int Hmin;
};

typedef struct Cek{
	char pesan[255];
	int harga;
	int banyak;
};

typedef struct checkOut{
	char pesan[255];
	int harga;
	int banyak;
};

typedef struct func{
	char slot[255];
};
// Prototype Function
	void Hide();
	void splWait();
	void scanmakanan();
	void MakanDis();
	void printmakanan();
	void pilihmakan();
	void confirm();
	void waktu();
	void funcminum();
	void printminum();
	void funcmakanan();
	void pilihminum();
	void fileMeja();
	void legenMeja();
	void menumeja();
	void deletecheck();
	void pilihmenu();
	void gantimeja();
	void MenuTakeAway();
	void writemeja();
	void checkout();
	void mejaawal();
	void History();
	void writepesanan();
	void scanpesanan();
	void writepesanan1();
	void checkoutTake();

// Var Global
	func meja[255]= {0};
	int PosHome;
	int PosMeja;
	int PosMenu;
	char ctr[25] = {0};
	int flag;
	int now = 1;
	int banyak = 0;
	int index;
	int nilai;
	int now2 = 1;
	int sum = 0;
	int countmeja;
	int idxcheckout;
	int awal = 1;
	
// Struct Global
	item sys[255] = {0};
	Cek user[255];
	checkOut final[255];

void home(){
	while(awal != 0){
		countmeja = 0;
		PosHome = 0;
		PosMeja = 0;
		PosMenu = 0;
		sum = 0;
		idxcheckout = 0;			// UNTUK BALIKIN SEMUA NILAI KE AWAL LAGI JIKA SUDAH CHECKOUT ATAU DECLARE NILAI DARI AWAL
		for(int i = 0; i < index + 1; i++){
			user[i].pesan[0] = '\0';
			user[i].harga = 0;
			user[i].banyak = 0;
		}
		index = -1;
		nilai = 0;
		flag = 1;
		--awal;
	}
	
	char opsi[5][25] = {"MAKAN DISINI", "         ", "TAKE AWAY"};
	flag = 1;
	fileMeja();
	for(int i = 0; i < 20; i++){
		if(ctr[i] == 'N'){
			++countmeja;
		}
	}
	while(true){	
		Hide();
		puts("\t _______                              __   ______         _______                         __               ");
		puts("\t|       \\                            |  \\ /      \\       |       \\                       |  \\              ");
		puts("\t| $$$$$$$\\  ______   ________  ______| $$|  $$$$$$\\      | $$$$$$$\\  ______    _______  _| $$_     ______  ");
		puts("\t| $$__| $$ /      \\ |        \\|      \\  $|$$___\\$$       | $$__| $$ /      \\  /       \\|   $$ \\   /      \\ ");
		puts("\t| $$    $$|  $$$$$$\\ \\$$$$$$$$ \\$$$$$$\\   \\$$    \\       | $$    $$|  $$$$$$\\|  $$$$$$$ \\$$$$$$  |  $$$$$$\\");
		puts("\t| $$$$$$$\\| $$    $$  /    $$ /      $$   _\\$$$$$$\\      | $$$$$$$\\| $$    $$ \\$$    \\   | $$ __ | $$  | $$");
		puts("\t| $$  | $$| $$$$$$$$ /  $$$$_|  $$$$$$$  |  \\__| $$      | $$  | $$| $$$$$$$$ _\\$$$$$$\\  | $$|  \\| $$__/ $$");
		puts("\t| $$  | $$ \\$$     \\|  $$    \\\\$$    $$   \\$$    $$      | $$  | $$ \\$$     \\|       $$   \\$$  $$ \\$$    $$");
		puts("\t \\$$   \\$$  \\$$$$$$$ \\$$$$$$$$ \\$$$$$$$    \\$$$$$$        \\$$   \\$$  \\$$$$$$$ \\$$$$$$$     \\$$$$   \\$$$$$$ ");
		printf("\n\t\t\t\t\t    ");
		waktu();
		puts("");
		printf("\t\t\t\t\t%c", 201);
		
		for(int i = 0; i < 29; i++){
			printf("%c", 205);
		}
		printf("%c\n", 187);
		printf("\t\t\t\t\t%c                             %c\n", 186, 186);
		for(int i = 0; i < 3; i++){
			printf("\t\t\t\t\t%c", 186);
			if(PosHome == i){
				printf("  >>");
			}else{
				printf("    ");
			}
			printf("     %s", opsi[i]);
			int len = strlen(opsi[i]);
			for(int j = len; j < 16; j++){
				printf(" ");
			}
			if(PosHome == i){
				printf("<< ");
			}else{
				printf("   ");
			}
			printf(" %c", 186);
			puts("");
		}
		printf("\t\t\t\t\t%c                             %c\n", 186, 186);
		printf("\t\t\t\t\t%c", 200);
		for(int i = 0; i < 29; i++){
			printf("%c", 205);
		}
		printf("%c", 188);
	
		if(kbhit()){
			char button = getch();
			if(PosHome!= 0 && button == keyUp){
				PosHome-=2;
			}else if(PosHome != 2 && button == keyDown){
				PosHome+=2;
			}else if(button == keyEnter){
				system("CLS");
				switch(PosHome){
					case 0:
						if(countmeja < 20){
							MakanDis();
						}else{
							mejaawal();
						}
					break;
					case 2:
						MenuTakeAway();
					break;
				}
				system("CLS");
			}
		}
	}
}

void pilihmenu(){
	writemeja();
	char opsimenu[10][15] = {"Makanan", "       ", "Minuman", "       ", "Check Out"};
	flag = 0;
	while(true){
		Hide();
		puts("");
		puts("");
		puts("");
		puts("");
		printf("\t\t\t\t  ");
		waktu();
		printf("\t\t\t\t%c", 201);
		for(int i = 0; i < 25; i++){
			printf("%c", 205);
		}
		printf("%c\n", 187);
		printf("\t\t\t\t%c                         %c\n", 186, 186);
		for(int j = 0; j < 5; j++){
			printf("\t\t\t\t");
			printf("%c", 186);
			if(PosMenu == j){
				printf("    >>");
			}else{
				printf("      ");
			}
			
			printf("   %s", opsimenu[j]);
			int len = strlen(opsimenu[j]);
			for(int k = len; k < 10; k++){
				printf(" ");
			}
			if(PosMenu == j){
				printf("<<    ");
			}else{
				printf("      ");
			}
			printf("%c", 186);
			printf("\n");
		}
		printf("\t\t\t\t%c                         %c\n", 186, 186);
		printf("\t\t\t\t%c", 200);
		for(int i = 0; i < 25; i++){
			printf("%c", 205);
		}
		printf("%c\n", 188);
		gantimeja();
		if(kbhit()){
			char button = getch();
			if(PosMenu != 0 && button == keyUp){
				PosMenu -= 2;
			}else if(PosMenu != 4 && button == keyDown){
				PosMenu += 2;
			}else if(button == keyESC){
				system("CLS");
				ctr[PosMeja] = 'A';
				writemeja();
				break;
			}else if(button == keyEnter){
				system("CLS");
				switch(PosMenu){
					case 0:
						funcmakanan();
					break;
					case 2:
						funcminum();
					break;
					case 4:
						checkout();
					break;
				}
			}
		}
	}
}

void MakanDis(){
	while(true){
		Hide();
		menumeja();
		legenMeja();
		
		if(kbhit()){
			char button = getch();
			if(PosMeja != 0 && button == keyUp && PosMeja!= 1 && PosMeja != 2 && PosMeja != 3 && PosMeja != 4){
				PosMeja -= 5;
			}else if(PosMeja != 15 && button == keyDown && PosMeja != 16 && PosMeja != 17 && PosMeja != 18 && PosMeja != 19){
				PosMeja += 5;
			}else if(PosMeja != 0 && button == keyLeft && PosMeja != 5 && PosMeja != 10 && PosMeja != 15){
				PosMeja -= 1;
			}else if(PosMeja != 19 && button == keyRight && PosMeja != 9 && PosMeja != 14 && PosMeja != 4){
				PosMeja += 1;
			}else if(button == keyESC){
				break;
			}else if(button == keyEnter){
				if(ctr[PosMeja] == 'N'){
					system("CLS");
					menumeja();
                    printf("\n\t\t\t Maaf meja sedang digunakan. Silakan pilih meja lain.\n");
                    getch();
                    system("CLS");
					continue;
                }
				ctr[PosMeja] = 'N';
				system("CLS");
				if(flag == 1){
					splWait();
					pilihmenu();
				}else{
					pilihmenu();
				}
				system("CLS");
			}
		}
	}
}

// MAIN

int main(){
	system("CLS");
	do{
		home();
	}while(true);
}

// FUNCTION

void waktu(){
	time_t w;
	time(&w);
	printf("%s", ctime(&w));
}

void Hide(){
	printf("\e[?25l");
	COORD Curp;
	Curp.X = 0;
	Curp.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Curp);
}

void splWait(){
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	puts("");
	printf("\t\t\t\t Mohon tunggu sebentar, sedang menyiapkan meja ");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	system("CLS");
}

void scanmakanan(){
	int ctr1 = 0;
	FILE *fp = fopen("../Data/makanan.txt", "r");
	
	while(fscanf(fp, "%[^#]#%d\n", &sys[ctr1].makan, &sys[ctr1].Hmak) != EOF){
	    ctr1++;
	}
	
	fclose(fp);
}

void printmakanan(){
	puts("");
	printf(" ===============================================\n");
	printf(" No.\t    Nama makanan\t\tHarga\n");
	printf(" ===============================================\n");
	scanmakanan();
	for(int i = (now - 1) * 20;i < now * 20; i++){
	    if(sys[i].makan != NULL){
			printf(" %d.  \t%s", i+1, sys[i].makan);
		    int len = strlen(sys[i].makan);
		    for(int j = len; j < 30; j++){
				printf(" ");
			}
			if(sys[i].Hmak != NULL){
				printf("Rp. %d", sys[i].Hmak);
			}else{
				printf("               ");
			}
			puts("");
		}
	}
	printf(" ===============================================\n");
	
}

void funcmakanan(){
	while(true){
		Hide();
		printmakanan();
		printf(" <<                [%02d - %d]                  >>\n", (now - 1) * 20 + 1, now * 20);
		puts("");
		printf("    [Buy/\"B\"]    [Return/\"ESC\"]    [Check/\"C\"]\n");
	    if(kbhit()){
			char button = getch();
			if(now != 1 && button == keyLeft){
				now -= 1;
			}else if(button == keyRight){
				now += 1;
			}else if(button == keyESC){
				system("CLS");
				break;
			}else if(button == 'b' || button == 'B'){
				++index;
				system("CLS");	
				pilihmakan();
			}else if(button == 'c' || button == 'C'){
				confirm();
			}
		}
	}
}

void pilihmakan(){
	char ans;
	int nomor, porsi;
	while(true){
		nilai = 1;
		Hide();
		printmakanan();
		printf("\n Makanan nomor berapa? _\b");
		scanf("%d", &nomor);
		strcpy(user[index].pesan, sys[nomor - 1].makan);
		getchar();
		printf(" Pesan Berapa? _\b");
		scanf("%d", &porsi);
		user[index].banyak = porsi;
		user[index].harga = sys[nomor - 1].Hmak * porsi;
		sum += user[index].harga;
		getchar();
		system("CLS");
		
		printmakanan();
		printf("\n Ada tambahan? _ (Y/N)\b\b\b\b\b\b\b");
		scanf("%c", &ans);
		getchar();
		system("CLS");
		if(ans == 'y' || ans == 'Y'){
			++index;
			continue;			
		}else if(ans == 'n' || ans == 'N'){
			break;
		}else{
			printmakanan();
			++index;
			printf("\n Pilih dengan Benar!\n");
			printf(" Tekan Enter untuk lanjut\n");
			getchar();
		}
		system("CLS");
	}
	writepesanan();
}

void confirm(){
	int nomor;
	system("CLS");
	while(true){
		Hide();
		puts("");
		puts("\t$$$$$$$\\  $$\\                           $$\\       ");
		puts("\t$$  __$$\\ $$ |                          $$ |      ");
		puts("\t$$ /  \__| $$$$$$$\\  $$$$$$$\\   $$$$$$$$\\$$ | $$\\ ");
		puts("\t$$ |      $$  __$$\\ $$  __$$\\ $$  _____|$$ | $$ |");
		puts("\t$$ |      $$ |  $$ |$$$$$$$$ |$$ /      $$$$$$  / ");
		puts("\t$$ |  $$\\ $$ |  $$ |$$   ____|$$ |      $$  _$$<  ");
		puts("\t\\$$$$$$  |$$ |  $$ |\\$$$$$$$\\ \\$$$$$$$\\ $$ | \\$$\\ ");
		puts("\t \\______/ \\__|  \\__| \\_______| \\_______| \__|  \\__|");
 		puts("");
 		printf(" ===========================================================\n");
		printf(" No.\t  Nama makanan\t\tJumlah\t\t   Harga\n");
		printf(" ===========================================================\n");
		scanpesanan();
		if(nilai == 1){
			for(int i = 0; i < index + 1; i++){
				printf(" %d. \t%s", i + 1, user[i].pesan);
				int len = strlen(user[i].pesan);
				for(int j = len; j < 26; j++){
					printf(" ");
				}
				printf("%d\t\t Rp. %d\n", user[i].banyak, user[i].harga);
			}
			for(int j = index + 1; j < 10; j++){
				puts("");
			}
			printf("\t\t\t\t            Total Rp. %d\n", sum);
			printf("\n [Hapus\"X\"]\t\t\t\t      [Return\"ESC\"]\n");
			if(kbhit()){
				char button = getch();
				if(button == 'x' || button == 'X'){
					if(index == 0){
						nilai = 2;
						deletecheck();
						writepesanan1();
						system("CLS");	
					}else {
						deletecheck();
						writepesanan1();
						system("CLS");	
					}
				}else if(button == keyESC){
					system("CLS");
					break;
				}
			}
		}else if(nilai == 2){
			printf("\n \tPesanan anda kosong silahkan kembali ke menu\n\n");
			printf(" \t\t Tekan apapun untuk lanjut\n");
			getch();
			system("CLS");
			break;
		}
		else{
			printf("\n \t\tAnda belum memesan apa - apa\n\n");
			printf(" \t\t Tekan apapun untuk lanjut\n");
			getch();
			system("CLS");
			break;
		}
	}
}

void scanminum(){
	FILE *fp = fopen("../Data/minuman.txt","r");
	int ctr2 = 0;
	while(fscanf(fp,"%[^#]#%d\n", &sys[ctr2].minum, &sys[ctr2].Hmin) != EOF){
		++ctr2;
	}
	fclose(fp);
}

void printminum(){
	puts("");
	printf(" ===============================================\n");
	printf(" No.\t    Nama minuman\t\tHarga\n");
	printf(" ===============================================\n");
	scanminum();
	for(int i = (now2 - 1) * 20; i < now2 * 20; i++){
		printf(" %d.  \t%s", i+1, sys[i].minum);
		int len = strlen(sys[i].minum);
		for(int j = len; j < 30; j++){
			printf(" ");
		}if(sys[i].Hmin != NULL){
			printf("Rp. %d", sys[i].Hmin);
		}else{
			printf("               ");
		}
		puts("");
	}
}

void funcminum(){
	while(true){
		Hide();
		printminum();
		printf(" <<                [%02d - %d]                  >>\n", (now2 - 1) * 20 + 1, now2 * 20);
		puts("");
		printf("    [Buy/\"B\"]    [Return/\"ESC\"]    [Check/\"C\"]\n");
	    if(kbhit()){
			char button = getch();
			if(now2 != 1 && button == keyLeft){
				now2 -= 1;
			}else if(button == keyRight){
				now2 += 1;
			}else if(button == keyESC){
				system("CLS");
				break;
			}else if(button == 'b' || button == 'B'){
				++index;
				system("CLS");	
				pilihminum();
			}else if(button == 'c' || button == 'C'){
				confirm();
			}
		}
	}
}

void pilihminum(){
	char ans;
	int nomor, porsi;
	while(true){
		nilai = 1;
		Hide();
		printminum();
		printf("\n Makanan nomor berapa? _\b");
		scanf("%d", &nomor);
		strcpy(user[index].pesan, sys[nomor - 1].minum);
		getchar();
		printf(" Pesan Berapa? _\b");
		scanf("%d", &porsi);
		user[index].banyak = porsi;
		user[index].harga = sys[nomor - 1].Hmin * porsi;
		sum += user[index].harga;
		getchar();
		system("CLS");
		
		printminum();
		printf("\n Ada tambahan? _ (Y/N)\b\b\b\b\b\b\b");
		scanf("%c", &ans);
		getchar();
		system("CLS");
		if(ans == 'y' || ans == 'Y'){
			++index;
			continue;			
		}else if(ans == 'n' || ans == 'N'){
			break;
		}else{
			printminum();
			++index;
			printf("\n Pilih dengan Benar!\n");
			printf(" Tekan Enter untuk lanjut\n");
			getchar();
		}
		system("CLS");
	}
	writepesanan();
}

void fileMeja(){
	FILE *fp = fopen("../Data/meja.txt", "r");
	
	int count = 0;
	
	while(fscanf(fp, "%c\n", &ctr[count]) != EOF){
		++count;
	}
	fclose(fp);
}

void legenMeja(){
	puts("\t\t \[A] = \"Available\"");
	puts("\t\t \[N] = \"Not Available\"");
	puts("\t\t Press ESC to Return");
}

void menumeja(){
	puts("");
	puts("\t\t /$$$$$$$  /$$ /$$ /$$ /$$             /$$      /$$                       ");
	puts("\t\t| $$__  $$|__/| $$|__/| $$            | $$$    /$$$                        ");
	puts("\t\t| $$  \\ $$ /$$| $$ /$$| $$$$$$$       | $$$$  /$$$$  /$$$$$$  /$$  /$$$$$$ ");
	puts("\t\t| $$$$$$$/| $$| $$| $$| $$__  $$      | $$ $$/$$ $$ /$$__  $$|__/ |____ $$");
	puts("\t\t| $$____/ | $$| $$| $$| $$  \\ $$      | $$  $$$| $$|$$$$$$$$ /$$| /$$$$$$$");
	puts("\t\t| $$      | $$| $$| $$| $$  | $$      | $$ \\ $ | $$|$$_____/| $$|/$$__  $$");
	puts("\t\t| $$      | $$| $$| $$| $$  | $$      | $$  \\/ | $$|$$$$$$$| |$$|| $$$$$$$");
	puts("\t\t|__/      |__/|__/|__/|__/  |__/      |__/     |___/\\_______/|$$|\\______/");
	puts("\t\t	                                               /$$  | $$|       ");
	puts("\t\t	                                               |  $$$$$$/        ");
	puts("\t\t                                                        \\______/           ");
	puts("");
	printf("\t\t\t\t\t\t\t     ");
	waktu();
	puts("\t\t ====================================================================");
	puts("");
	puts("");
	fileMeja();
	for(int i = 0; i < 20; i++){
		if(i == 0 || i == 5 || i == 10 || i == 15){
			printf("\t\t      ");
 		}if(i < 10){
			printf("%d. \[%c]  ", i + 1, ctr[i]);
		}else{
			printf("%d. \[%c] ", i + 1, ctr[i]);
		}if(PosMeja == i){
			printf("<<   ");
		}else{
			printf("     ");
		}if(i == 4 || i == 9 || i == 14 || i == 19){
			printf("\n\n");
		}	
	}
	puts("");
	puts("\t\t ====================================================================");
}

void deletecheck(){
	int num;
	printf("\n Nomor berapa yang ingin anda Hapus? _\b");
	scanf("%d", &num);
	
	strcpy(user[num-1].pesan, "#"); 
	sum -= user[num - 1].harga;
}

void gantimeja(){
	puts("");
	printf("\t\t\t         Press ESC to \"Ganti Meja\"");
}

void MenuTakeAway(){
	char opsimenu[10][15] = {"Makanan", "       ", "Minuman", "       ", "Check Out"};
	flag = 0;
	while(true){
		Hide();
		puts("");
		puts("");
		puts("");
		puts("");
		printf("\t\t\t\t  ");
		waktu();
		printf("\t\t\t\t%c", 201);
		for(int i = 0; i < 25; i++){
			printf("%c", 205);
		}
		printf("%c\n", 187);
		printf("\t\t\t\t%c                         %c\n", 186, 186);
		for(int j = 0; j < 5; j++){
			printf("\t\t\t\t");
			printf("%c", 186);
			if(PosMenu == j){
				printf("    >>");
			}else{
				printf("      ");
			}
			
			printf("   %s", opsimenu[j]);
			int len = strlen(opsimenu[j]);
			for(int k = len; k < 10; k++){
				printf(" ");
			}
			if(PosMenu == j){
				printf("<<    ");
			}else{
				printf("      ");
			}
			printf("%c", 186);
			printf("\n");
		}
		printf("\t\t\t\t%c                         %c\n", 186, 186);
		printf("\t\t\t\t%c", 200);
		for(int i = 0; i < 25; i++){
			printf("%c", 205);
		}
		printf("%c\n", 188);
		if(kbhit()){
			char button = getch();
			if(PosMenu != 0 && button == keyUp){
				PosMenu -= 2;
			}else if(PosMenu != 4 && button == keyDown){
				PosMenu += 2;
			}else if(button == keyESC){
				system("CLS");
				ctr[PosMeja] = 'A';
				break;
			}else if(button == keyEnter){
				system("CLS");
				switch(PosMenu){
					case 0:
						funcmakanan();
					break;
					case 2:
						funcminum();
					break;
					case 4:
						checkoutTake();
					break;
				}
			}
		}
	}
}

void checkout(){
	system("CLS");
	while(true){
		Hide(); 	
		puts("");
		puts("\t$$$$$$$\\  $$\\                           $$\\          /$$$$$$              /$$    ");
		puts("\t$$  __$$\\ $$ |                          $$ |         /$$$$$$              /$$    ");
		puts("\t$$ /  \__| $$$$$$$\\  $$$$$$$\\   $$$$$$$$\\$$ | $$\\   | $$  \\ $$ /$$   /$$ /$$$$$$  ");
		puts("\t$$ |      $$  __$$\\ $$  __$$\\ $$  _____|$$ | $$ |  | $$  | $$| $$  | $$|_  $$_/  ");
		puts("\t$$ |      $$ |  $$ |$$$$$$$$ |$$ /      $$$$$$  /  | $$  | $$| $$  | $$  | $$    ");
		puts("\t$$ |  $$\\ $$ |  $$ |$$   ____|$$ |      $$  _$$<   | $$  | $$| $$  | $$  | $$ /$$");
		puts("\t\\$$$$$$  |$$ |  $$ |\\$$$$$$$\\ \\$$$$$$$\\ $$ | \\$$\\  |  $$$$$$/|  $$$$$$/  |  $$$$/");
		puts("\t \\______/ \\__|  \\__| \\_______| \\_______| \__|  \\__|  \\______/  \\______/    \\___/ ");
 		puts("");
 		printf("\t ======================================================================\n");
		printf("\t No.\t  Nama makanan\t\tJumlah\t\t   Harga | Meja No. %d\n", PosMeja + 1);
		printf("\t ======================================================================\n");
		
		if(index >= 0 && nilai == 1){
			for(int i = 0; i < index + 1; i++){
				printf("\t %d. \t%s", i + 1, user[i].pesan);
				int len = strlen(user[i].pesan);
				for(int j = len; j < 26; j++){
					printf(" ");
				}
				printf("%d\t\        Rp. %d\n", user[i].banyak, user[i].harga);
			}
			for(int j = index + 1; j < 11; j++){
				puts("");
			}
			printf("\t\t\t             Total Rp. %d\n", sum);
			printf("\n\t\t\t             [Lanjut\"ENTER\"]\n");
			getchar();
			if(getchar()){
				History();
				awal = 1;
				system("CLS");
				puts("");
				puts("");
				puts("");
				puts("");
				puts("");
				puts("");
				puts("");
				puts("");
				puts("");
				puts("");
				puts("");
				printf("\t\t\t Terima Kasih Sudah Datang, dan selamat Menikmati\n");
				sleep(3);
				home();
			}
		}else{
			puts("");
			puts("");
			printf("\t\t  Anda belum memesan apa - apa, tekan apapun untuk kembali\n");
			getch();
			system("CLS");
			break;
		}
	}
}


void writemeja(){
	FILE *fp = fopen("../Data/meja.txt", "w");
	
	for(int i = 0; i < 20; i++){
		fprintf(fp, "%c\n", ctr[i]);
	}
	
	fclose(fp);
}

void mejaawal(){
	char opsi[5][25] = {"MAKAN DISINI", "         ", "TAKE AWAY"};
	while(true){	
		Hide();
		puts("\t _______                              __   ______         _______                         __               ");
		puts("\t|       \\                            |  \\ /      \\       |       \\                       |  \\              ");
		puts("\t| $$$$$$$\\  ______   ________  ______| $$|  $$$$$$\\      | $$$$$$$\\  ______    _______  _| $$_     ______  ");
		puts("\t| $$__| $$ /      \\ |        \\|      \\  $|$$___\\$$       | $$__| $$ /      \\  /       \\|   $$ \\   /      \\ ");
		puts("\t| $$    $$|  $$$$$$\\ \\$$$$$$$$ \\$$$$$$\\   \\$$    \\       | $$    $$|  $$$$$$\\|  $$$$$$$ \\$$$$$$  |  $$$$$$\\");
		puts("\t| $$$$$$$\\| $$    $$  /    $$ /      $$   _\\$$$$$$\\      | $$$$$$$\\| $$    $$ \\$$    \\   | $$ __ | $$  | $$");
		puts("\t| $$  | $$| $$$$$$$$ /  $$$$_|  $$$$$$$  |  \\__| $$      | $$  | $$| $$$$$$$$ _\\$$$$$$\\  | $$|  \\| $$__/ $$");
		puts("\t| $$  | $$ \\$$     \\|  $$    \\\\$$    $$   \\$$    $$      | $$  | $$ \\$$     \\|       $$   \\$$  $$ \\$$    $$");
		puts("\t \\$$   \\$$  \\$$$$$$$ \\$$$$$$$$ \\$$$$$$$    \\$$$$$$        \\$$   \\$$  \\$$$$$$$ \\$$$$$$$     \\$$$$   \\$$$$$$ ");
		printf("\n\t\t\t\t\t    ");
		waktu();
		puts("");
		printf("\t\t\t\t\t%c", 201);
		
		for(int i = 0; i < 29; i++){
			printf("%c", 205);
		}
		printf("%c\n", 187);
		printf("\t\t\t\t\t%c                             %c\n", 186, 186);
		for(int i = 0; i < 3; i++){
			printf("\t\t\t\t\t%c", 186);
			if(PosHome == i){
				printf("  >>");
			}else{
				printf("    ");
			}
			printf("     %s", opsi[i]);
			int len = strlen(opsi[i]);
			for(int j = len; j < 16; j++){
				printf(" ");
			}
			if(PosHome == i){
				printf("<< ");
			}else{
				printf("   ");
			}
			printf(" %c", 186);
			puts("");
		}
		printf("\t\t\t\t\t%c                             %c\n", 186, 186);
		printf("\t\t\t\t\t%c", 200);
		for(int i = 0; i < 29; i++){
			printf("%c", 205);
		}
		printf("%c", 188);
		
		printf("\n\n\t\t Maaf meja sudah penuh, disarankan untuk menunggu atau memilih layanan Take Away");
	
		getch();
		
		break;
	}

}


void History(){
	FILE *fp = fopen("../Data/History.txt", "a");
	
	time_t w;
	time(&w);
	
	fprintf(fp, "%s#%d\n", ctime(&w), sum);
	
	fclose(fp);
}

void writepesanan(){
	FILE *fp = fopen("../Data/Temp.txt", "w");
	int count = 0;
	for(int i = 0; i < index + 1; i++){
		fprintf(fp, "%s@%d|%d\n", user[i].pesan, user[i].banyak, user[i].harga);
	}
	
	fclose(fp);
}

void writepesanan1(){
	FILE *fp = fopen("../Data/Temp.txt", "w");
	int count = 0;
	for(int i = 0; i < index + 1; i++){
		if(user[i].pesan[0] != '#' && user[i].harga != 0){
			fprintf(fp, "%s@%d|%d\n", user[i].pesan, user[i].banyak, user[i].harga);
		}else{
			continue;
		}
	}
	--index;
	fclose(fp);
}

void scanpesanan(){
	FILE *fp = fopen("../Data/Temp.txt", "r");
	int count = 0;
	while(fscanf(fp, "%[^@]@%d|%d\n", &user[count].pesan, &user[count].banyak, &user[count].harga) != EOF){
		++count;
	}
	fclose(fp);
}

void checkoutTake(){
	system("CLS");
	while(true){
		Hide(); 	
		puts("");
		puts("\t$$$$$$$\\  $$\\                           $$\\          /$$$$$$              /$$    ");
		puts("\t$$  __$$\\ $$ |                          $$ |         /$$$$$$              /$$    ");
		puts("\t$$ /  \__| $$$$$$$\\  $$$$$$$\\   $$$$$$$$\\$$ | $$\\   | $$  \\ $$ /$$   /$$ /$$$$$$  ");
		puts("\t$$ |      $$  __$$\\ $$  __$$\\ $$  _____|$$ | $$ |  | $$  | $$| $$  | $$|_  $$_/  ");
		puts("\t$$ |      $$ |  $$ |$$$$$$$$ |$$ /      $$$$$$  /  | $$  | $$| $$  | $$  | $$    ");
		puts("\t$$ |  $$\\ $$ |  $$ |$$   ____|$$ |      $$  _$$<   | $$  | $$| $$  | $$  | $$ /$$");
		puts("\t\\$$$$$$  |$$ |  $$ |\\$$$$$$$\\ \\$$$$$$$\\ $$ | \\$$\\  |  $$$$$$/|  $$$$$$/  |  $$$$/");
		puts("\t \\______/ \\__|  \\__| \\_______| \\_______| \__|  \\__|  \\______/  \\______/    \\___/ ");
 		puts("");
 		printf("\t =========================================================================\n");
		printf("\t No.\t  Nama makanan\t\tJumlah\t\t   Harga  |  TAKE AWAY: %c%d \n", rand()%26 + 'A', rand()%1000);
		printf("\t =========================================================================\n");
		
		if(index >= 0 && nilai == 1){
			for(int i = 0; i < index + 1; i++){
				printf("\t %d. \t%s", i + 1, user[i].pesan);
				int len = strlen(user[i].pesan);
				for(int j = len; j < 26; j++){
					printf(" ");
				}
				printf("%d\t         Rp. %d\n", user[i].banyak, user[i].harga);
			}
			for(int j = index + 1; j < 11; j++){
				puts("");
			}
			printf("\t\t\t             Total Rp. %d\n", sum);
			printf("\n\t\t\t             [Lanjut\"ENTER\"]\n");
			getchar();
			if(getchar()){
				History();
				awal = 1;
				system("CLS");
				puts("");
				puts("");
				puts("");
				puts("");
				puts("");
				puts("");
				puts("");
				puts("");
				printf("\t\t\t Terima Kasih Sudah Datang, dan selamat Menikmati\n");
				sleep(3);
				home();
			}
		}else{
			puts("");
			puts("");
			printf("\t\t  Anda belum memesan apa - apa, tekan apapun untuk kembali\n");
			getch();
			system("CLS");
			break;
		}
	}
}
