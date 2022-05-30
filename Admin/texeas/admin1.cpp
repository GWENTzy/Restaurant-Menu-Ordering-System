#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


#define enter 13
#define erase 8

// Protoype
	void scanmeja();
	void mejawrite();
	
// Var Global
	
	char ctr[25] = {0};

int main(){
	
	menu:
	int input;
	puts("");
	puts("    /$$$$$$        /$$$$$$$        /$$      /$$       /$$$$$$       /$$   /$$");
	puts("   /$$__  $$      | $$__  $$      | $$$    /$$$      |_  $$_/      | $$$ | $$");
	puts("  | $$  \\ $$      | $$  \\ $$      | $$$$  /$$$$        | $$        | $$$$| $$");
	puts("  | $$$$$$$$      | $$  | $$      | $$ $$/$$ $$        | $$        | $$ $$ $$");
	puts("  | $$__  $$      | $$  | $$      | $$  $$$| $$        | $$        | $$  $$$$");
	puts("  | $$  | $$      | $$  | $$      | $$\\  $ | $$        | $$        | $$\\  $$$");
	puts("  | $$  | $$      | $$$$$$$/      | $$ \\/  | $$       /$$$$$$      | $$ \\  $$");
	puts("  |__/  |__/      |_______/       |__/     |__/      |______/      |__/  \\__/");
	puts("");
	puts("");
	puts("1. Tambah/edit menu");
	puts("2. History Order & Total Penjualan");
	puts("3. Edit meja");
	puts("0. Log Out\n");
	
	printf(">> ");
  	scanf("%d", &input);
	puts("\n");
	
  	if(input == 1){
  		getchar();
		system("CLS");
		system("main.exe");
		system("CLS");
		goto menu;
		
	  }else if(input == 2){
		getchar();
		system("CLS");
		system("Cek_History.exe");
		getchar();
		system("CLS");
		
	  	
	  }else if(input == 3){
	  	getchar();
		system("CLS");
		system("EditMeja.exe");
		system("CLS");
		goto menu;
		
	  }else if(input == 0){
	  	getchar();
	  	return 0;
	  	
	  }else{
	  	printf("Masukan Angka yang tepat \n");
	  	goto menu;
	  }
	  
	return 0;
}





