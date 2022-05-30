#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
	meja:
	puts("");
	puts ("   /$$      /$$       /$$$$$$$$          /$$$$$        /$$$$$$        /$$");
	puts ("  | $$$    /$$$      | $$_____/         |__  $$       /$$__  $$      | $$");
	puts ("  | $$$$  /$$$$      | $$                  | $$      | $$  \\ $$      | $$");
	puts ("  | $$ $$/$$ $$      | $$$$$               | $$      | $$$$$$$$      | $$");
	puts ("  | $$  $$$| $$      | $$__/          /$$  | $$      | $$__  $$      |__/");
	puts ("  | $$\\  $ | $$      | $$            | $$  | $$      | $$  | $$          ");
	puts ("  | $$ \\/  | $$      | $$$$$$$$      |  $$$$$$/      | $$  | $$       /$$");
	puts ("  |__/     |__/      |________/       \\______/       |__/  |__/      |__/");
	puts ("");
	puts ("");	
	
 	FILE *fp = fopen("../Data/meja.txt", "r");
	
    char str[40][100];
    int meja[20];
    int ctr = 0;
    int num;

    for(int i = 0; i < 20; i++){
    	fscanf(fp, "%c\n", &meja[i]);
	}
    
    fclose(fp); //close file read
    
    printf ("Masukkan nomor meja _\b");
    scanf ("%d", &num);
    
    
    FILE *fp2 = fopen("../Data/meja.txt", "w"); //write file yang baru 
	for(int k = 0; k < 20; k++)
	{
       fprintf (fp2, "%c\n", meja[k]);
    }
    fclose(fp2); //close file write
    
    //print menu baru
    
    printf("Meja nomor %d telah diganti\n\n", num);
    
    exit:
    char exit[3];
    printf ("Apakah Anda Masih ingin mengganti status meja? (Y/N)\n");
    scanf ("%s", exit);
    if (!strcmp("Y", exit) || !strcmp("y", exit))
    {
    	getchar();
		system("CLS");
    	goto meja;
	}
	else if (!strcmp("N", exit) || !strcmp("n", exit))
    {
    	printf ("Kembali ke menu sebelumnya . . .\n");
    	getchar();
	}
	else
	{
		printf ("Pilih opsi yang tersedia, (Y/N)");
	}
}
