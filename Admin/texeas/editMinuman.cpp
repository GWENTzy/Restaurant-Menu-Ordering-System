//edit minuman
#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(){
	minuman:
	puts("");	
	puts ("   /$$      /$$       /$$$$$$       /$$   /$$       /$$   /$$       /$$      /$$       /$$");
	puts ("  | $$$    /$$$      |_  $$_/      | $$$ | $$      | $$  | $$      | $$$    /$$$      | $$");
	puts ("  | $$$$  /$$$$        | $$        | $$$$| $$      | $$  | $$      | $$$$  /$$$$      | $$");
	puts ("  | $$ $$/$$ $$        | $$        | $$ $$ $$      | $$  | $$      | $$ $$/$$ $$      | $$");
	puts ("  | $$  $$$| $$        | $$        | $$  $$$$      | $$  | $$      | $$  $$$| $$      |__/");
	puts ("  | $$\\  $ | $$        | $$        | $$\\  $$$      | $$  | $$      | $$\\  $ | $$          ");
	puts ("  | $$ \\/  | $$       /$$$$$$      | $$ \\  $$      |  $$$$$$/      | $$ \\/  | $$       /$$");
	puts ("  |__/     |__/      |______/      |__/  \\__/       \\______/       |__/     |__/      |__/");
	puts ("");
	puts ("");
	
    FILE *fp = fopen("../Data/minuman.txt", "r");
	
	char str[40][100];
    int harga[40];
    int ctr = 0;
	
    while(fscanf(fp, "%[^#]#%d\n", str[ctr], &harga[ctr]) != EOF)
	{
        ctr++;
    }
    
    for(int i = 0; i < ctr; i++)
	{
		if (i<9)
		{
		printf(" %d. %s", i+1, str[i]);
		}
		else
		{
        printf("%d. %s", i+1, str[i]);
    	}
        int len = strlen(str[i]);
        for (int j = 0; j < 30-len; j++)
        {
        	printf(" ");
		}
        printf("%d\n", harga[i]);
    }
    
    int editMinuman;
    printf ("\nPilih Menu keberapa yang ingin anda edit.\n");
    printf ("Atau tekan 0 untuk keluar.\n");
    scanf ("%d", &editMinuman);
    if (editMinuman==0)
    {
    	printf ("Kembali ke menu sebelumnya . . .\n");
    	getchar();
    	return 0;
	}
    
    printf ("\nAnda akan mengedit\n%d. %s %d\n\n", 
	editMinuman, str[editMinuman-1], harga[editMinuman-1]);
    
    printf ("\nMasukkan data baru: [Nama Minuman][enter][Harga Minuman]\n");
    getchar();
    
	//masukkan data baru
    scanf ("%[^\n] %d", str[editMinuman-1], &harga[editMinuman-1]);
    fclose(fp); //close file read
    
    
    FILE *fp2 = fopen("../Data/minuman.txt", "w"); //write file yang baru 
	for(int k = 0; k < ctr; k++)
	{
       fprintf (fp2, "%s#%d\n", str[k], harga[k]);
    }
    fclose(fp2); //close file write
    
    getchar();
	system("CLS");
    goto minuman;
    return 0;
}
