//edit makanan
#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(){
	makanan:
	puts("");
	puts ("   /$$      /$$        /$$$$$$        /$$   /$$        /$$$$$$        /$$   /$$       /$$");
	puts ("  | $$$    /$$$       /$$__  $$      | $$  /$$/       /$$__  $$      | $$$ | $$      | $$");
	puts ("  | $$$$  /$$$$      | $$  \\ $$      | $$ /$$/       | $$  \\ $$      | $$$$| $$      | $$");
	puts ("  | $$ $$/$$ $$      | $$$$$$$$      | $$$$$/        | $$$$$$$$      | $$ $$ $$      | $$");
	puts ("  | $$  $$$| $$      | $$__  $$      | $$  $$        | $$__  $$      | $$  $$$$      |__/");
	puts ("  | $$\\  $ | $$      | $$  | $$      | $$\\  $$       | $$  | $$      | $$\\  $$$          ");
	puts ("  | $$ \\/  | $$      | $$  | $$      | $$ \\  $$      | $$  | $$      | $$ \\  $$       /$$");
	puts ("  |__/     |__/      |__/  |__/      |__/  \\__/      |__/  |__/      |__/  \\__/      |__/");
	puts ("");
	puts ("");	
		
 	FILE *fp = fopen("../Data/makanan.txt", "r");
	
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
    
    int editMakanan;
    printf ("\nPilih Menu keberapa yang ingin anda edit.\n");
    printf ("Atau tekan 0 untuk keluar.\n");
    scanf ("%d", &editMakanan);
    if (editMakanan==0)
    {
    	printf ("Kembali ke menu sebelumnya . . .\n");
    	getchar();
    	return 0;
	}
    
    printf ("\nAnda akan mengedit\n%d. %s %d\n\n", 
	editMakanan, str[editMakanan-1], harga[editMakanan-1]);
    
    printf ("\nMasukkan data baru: [Nama Makanan][enter][Harga Makanan]\n");
    getchar();
    
    //masukkan data baru
    scanf ("%[^\n] %d", str[editMakanan-1], &harga[editMakanan-1]);
    fclose(fp); //close file read
    
    
    FILE *fp2 = fopen("../Data/makanan.txt", "w"); //write file yang baru 
	for(int k = 0; k < ctr; k++)
	{
       fprintf (fp2, "%s#%d\n", str[k], harga[k]);
    }
    fclose(fp2); //close file write
    
    getchar();
	system("CLS");
    goto makanan;
    
    return 0;
}
