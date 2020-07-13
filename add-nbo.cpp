#include<stdio.h>
#include<stdint.h>
#include<netinet/in.h>

int main(int argc, char *argv[]){
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");

    uint32_t int_1, int_2;
    fread(&int_1, sizeof(uint32_t), 1, fp1);
    fread(&int_2, sizeof(uint32_t), 1, fp2);
    int_1 = ntohl(int_1);
    int_2 = ntohl(int_2);

    printf("0x%x + 0x%x = 0x%x", int_1, int_2, int_1 + int_2);

    fclose(fp1);
    fclose(fp2);
}

/*
int main(void){
    FILE *fp1, *fp2;
    fp1 = fopen("unit32_1.bin", "wb");
    fp2 = fopen("unit32_2.bin", "wb");

    uint32_t int_1, int_2;
    int_1 = 0x1234abcd;
    int_2 = 0x12345678;

    printf("0x%x 0x%x\n", int_1, int_2);

    int_1 = htonl(int_1);
    int_2 = htonl(int_2);

    printf("0x%x 0x%x", int_1, int_2);

    fwrite(&int_1, sizeof(uint32_t), 1, fp1);
    fwrite(&int_2, sizeof(uint32_t), 1, fp2);
    fclose(fp1);
    fclose(fp2);
}
*/
