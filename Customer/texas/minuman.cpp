#include <stdio.h>

int main(){
	minuman:
    FILE *fp = fopen("../Data/minuman.txt", "r");

    char str[40][100];
    int harga[40];
    int ctr =0;

    while(fscanf(fp, "%[^#]#%d\n", str[ctr], &harga[ctr]) != EOF){
        ctr++;
    }
    
    for(int i=0;i<ctr;i++){
        printf("%d. %s", i+1, str[i]);
        printf("%d\n", harga[i]);
    }
    
    fclose(fp);
    return 0;
}
