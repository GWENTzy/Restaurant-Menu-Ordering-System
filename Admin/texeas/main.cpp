//main edit atau tambah menu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main()
{
	awal:
	puts("");
	puts ("   /$$      /$$       /$$$$$$$$       /$$   /$$       /$$   /$$");
	puts ("  | $$$    /$$$      | $$_____/      | $$$ | $$      | $$  | $$");
	puts ("  | $$$$  /$$$$      | $$            | $$$$| $$      | $$  | $$");
	puts ("  | $$ $$/$$ $$      | $$$$$         | $$ $$ $$      | $$  | $$");
	puts ("  | $$  $$$| $$      | $$__/         | $$  $$$$      | $$  | $$");
	puts ("  | $$\\  $ | $$      | $$            | $$\\  $$$      | $$  | $$");
	puts ("  | $$ \\/  | $$      | $$$$$$$$      | $$ \\  $$      |  $$$$$$/");
	puts ("  |__/     |__/      |________/      |__/  \\__/       \\______/ ");
	puts ("");
	puts ("");	
	
	printf ("1. Edit Menu\n");
	printf ("2. Tambah Menu\n");
	printf ("0. Kembali\n\n");
	printf(">> ");
	int menu1;
	
	inputAwal:
	scanf ("%d", &menu1); 		//pilih edit atau tambah
	if (menu1 == 1)
	{
		getchar();
		system("CLS");
		goto editMenu;
	}
	else if (menu1 == 2)
	{
		getchar();
		system("CLS");
		goto tambahMenu;
	}
	else if (menu1 == 0)
	{
		getchar();
		printf ("Keluar dari menu. . .");
		system("CLS");
		goto keluar;
	}
	else
	{
		printf ("Pilih opsi yang tersedia.\n");
		goto inputAwal;
	}
	
	
	editMenu:
	puts("");
	puts ("   /$$$$$$$$       /$$$$$$$        /$$$$$$       /$$$$$$$$");
	puts ("  | $$_____/      | $$__  $$      |_  $$_/      |__  $$__/");
	puts ("  | $$            | $$  \\ $$        | $$           | $$   ");
	puts ("  | $$$$$         | $$  | $$        | $$           | $$   ");
	puts ("  | $$__/         | $$  | $$        | $$           | $$   ");
	puts ("  | $$            | $$  | $$        | $$           | $$   ");
	puts ("  | $$$$$$$$      | $$$$$$$/       /$$$$$$         | $$   ");
	puts ("  |________/      |_______/       |______/         |__/   ");
	puts ("");
	puts ("");
	
	
	char editMenu[3];
	printf ("Pilih data apa yang ingin di-edit:\n");
	printf ("A.  Makanan\n");
	printf ("B.  Minuman\n");
	printf ("C.  Kembali\n\n");
	printf(">>");
	scanf ("%s", editMenu);
	if (!strcmp("A", editMenu) || !strcmp("a", editMenu))
	{
		printf ("Anda akan mengedit menu Makanan.\n");
		printf ("Tekan ENTER untuk melanjutkan.\n");
		getchar();getchar();
		system("CLS");
		system ("editMakanan.exe");
		system("CLS");
		goto editMenu;
	}
	if (!strcmp("B", editMenu) || !strcmp("b", editMenu))
	{
		printf ("Anda akan mengedit menu Minuman.\n");
		printf ("Tekan ENTER untuk melanjutkan.\n");
		getchar();getchar();
		system("CLS");
		system ("editMinuman.exe");
		system("CLS");
		goto editMenu;
	}
	if (!strcmp("c", editMenu) || !strcmp("C", editMenu))
	{
		printf ("\nKembali ke halaman awal . . .\n");
		getchar(); 
		system("CLS");
		goto awal;
	}
	else
	{
		printf ("Pilih opsi yang tersedia.\n");
		getchar(); getchar();
		system("CLS");
		goto editMenu;
	}

	
	tambahMenu:
	puts("");
	puts ("    /$$$$$$        /$$$$$$$        /$$$$$$$ ");
	puts ("   /$$__  $$      | $$__  $$      | $$__  $$");
	puts ("  | $$  \\ $$      | $$  \\ $$      | $$  \\ $$");
	puts ("  | $$$$$$$$      | $$  | $$      | $$  | $$");
	puts ("  | $$__  $$      | $$  | $$      | $$  | $$");
	puts ("  | $$  | $$      | $$  | $$      | $$  | $$");
	puts ("  | $$  | $$      | $$$$$$$/      | $$$$$$$/");
	puts ("  |__/  |__/      |_______/       |_______/ ");
	puts ("");
	puts ("");
	
	char tambahMenu[3];
	printf ("Pilih data apa yang ingin ditambahkan:\n");
	printf ("A.  Makanan\n");
	printf ("B.  Minuman\n");
	printf ("C.  Kembali\n");
	scanf ("%s", tambahMenu);
	if (!strcmp("A", tambahMenu) || !strcmp("a", tambahMenu))
	{
		printf ("Anda akan menambahkan menu Makanan.\n");
		printf ("Tekan ENTER untuk melanjutkan.\n");
		getchar();getchar();
		system("CLS");
		system ("tambahMakanan.exe");
		system("CLS");
		goto editMenu;
	}
	if (!strcmp("B", tambahMenu) || !strcmp("b", tambahMenu))
	{
		printf ("Anda akan menambahkan menu Minuman.\n");
		printf ("Tekan ENTER untuk melanjutkan.\n");
		getchar();getchar();
		system("CLS");
		system ("tambahMinuman.exe");
		system("CLS");
		goto editMenu;
	}
	if (!strcmp("c", tambahMenu) || !strcmp("C", tambahMenu))
	{
		printf ("\nKembali ke halaman awal . . .\n");
		getchar();
		system("CLS");
		goto awal;
	}
	else
	{
		printf ("Pilih opsi yang tersedia.\n");
		getchar(); getchar();
		system("CLS");
		goto editMenu;
	}
	
	keluar:
	return 0;
	
}
