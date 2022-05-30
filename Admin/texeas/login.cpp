#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>


#define enter 13
#define erase 8

int main () {
	login:
	puts("");
	puts("   $$$$$$\\        $$\\               $$\\                 $$\\       $$$$$$\\   $$$$$$\\  $$$$$$\\ $$\\   $$\\  ");
	puts("  $$  __$$\\       $$ |              \\__|                $$ |     $$  __$$\\ $$  __$$\\ \\_$$  _|$$$\\  $$ |");
	puts("  $$ /  $$ | $$$$$$$ |$$$$$$\$$$$\\   $$\\ $$$$$$$\\        $$ |     $$ /  $$ |$$ /  \\__|  $$ |  $$$$\\ $$ |");
	puts("  $$$$$$$$ |$$  __$$ |$$  _$$  _$$\\ $$ |$$  __$$\\       $$ |     $$ |  $$ |$$ |$$$$\\   $$ |  $$  $$\$$ |");
	puts("  $$  __$$ |$$ /  $$ |$$ / $$ / $$ |$$ |$$ |  $$ |      $$ |     $$ |  $$ |$$ |\\_$$ |  $$ |  $$ \\$$$$ |");
	puts("  $$ |  $$ |$$ |  $$ |$$ | $$ | $$ |$$ |$$ |  $$ |      $$ |     $$ |  $$ |$$ |  $$ |  $$ |  $$ |\\$$$ |");
	puts("  $$ |  $$ |\$$$$$$$  |$$ | $$ | $$ |$$ |$$ |  $$ |      $$$$$$$$\  $$$$$$  |\\$$$$$$  |$$$$$$\  $$ | \\$$ |");
	puts("  \\__|  \\__| \\_______|\\__| \\__| \\__|\\__|\\__|  \\__|      \\________|\\______/  \\______/ \\______|\\__|  \\__|");
	puts("");
	puts("");
	
	FILE *fileproc = fopen("../Data/userPass.txt", "r");
	char userOutput[255], passOutput[255];
	fscanf(fileproc, "%s %s", userOutput, passOutput);
	char userInput[255], passInput[255];
	int j = 0;
	printf("  username: ");
	scanf("%s", userInput);

	if (!strcmp("keluar", userInput) || !strcmp("exit", userInput))
	{
		puts ("\n\n  Menutup aplikasi admin . . .");
		return 0;
	}
	
	printf("  password: ");
	while(true) {
		if(kbhit()) {
			char button = getch();
			if(button != enter && button != erase) {
				passInput[j] = button;
				++j;
				passInput[j] = '\0';
				printf("*");
			} else if(button == erase) {
				if(j > 0) {
					passInput[--j] = '\0';
					printf("\b");
					printf(" ");
					printf("\b");
				} 
			}else if(button == enter) {
					break;
			}
		}
	}
	if (strcmp(userInput, userOutput) == 0 && strcmp(passInput, passOutput) == 0) 
	{
		printf("\n");
		printf("\n  Login berhasil\n");
		printf("\n  SELAMAT DATANG YANG MULIA KAISAR MEOWMERE\n");
		printf("\n  tekan enter untuk ke menu admin...\n");
		getchar();
		getchar();
		system("CLS");
		system("admin1.exe");
		system("CLS");
		goto login;
	} 
	else 
	{
		printf("\nLogin gagal, periksa kembali\n");
		getchar();
		getchar();
		system("CLS");
		goto login;
	}
	
	fclose(fileproc);
	
	return 0;
}
