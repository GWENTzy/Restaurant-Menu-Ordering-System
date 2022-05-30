//tambahMinuman
#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
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
    
    fclose(fp); //close file read
    
    printf ("Sudah tersedia %d jenis minuman.\n\n", ctr);
    printf ("Masukkan [Nama Minuman][enter][Harga Minuman] untuk menu ke %d\n", ctr+1);
    scanf ("%[^\n] %d", str[ctr], &harga[ctr]);
    
    printf("Menambahkan menu . . .\n\n");
    getchar();
	system("CLS");
    
    
    FILE *fp2 = fopen("../Data/minuman.txt", "w"); //write file yang baru 
	for(int k = 0; k < ctr+1; k++)
	{
       fprintf (fp2, "%s#%d\n", str[k], harga[k]);
    }
    fclose(fp2); //close file write
    
    //print menu baru
        for(int i = 0; i < ctr+1; i++)
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
    
    exit:
    char exit[3];
    printf ("Apakah Anda Masih ingin Menambahkan Menu? (Y/N)\n");
    scanf ("%s", exit);
    if (!strcmp("Y", exit) || !strcmp("y", exit))
    {
    	getchar();
		system("CLS");
    	goto minuman;
	}
	if (!strcmp("N", exit) || !strcmp("n", exit))
    {
    	printf ("Kembali ke menu sebelumnya . . .\n");
    	getchar();
    	return 0;
	}
	else
	{
		printf ("Pilih opsi yang tersedia, (Y/N)");
	}
    
    return 0;
}
