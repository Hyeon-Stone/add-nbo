#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <stdlib.h>

void usage() {

    printf("syntax:  add-nbo <file1> <file2>\n");
    printf("sample:  add-nbo a.bin c.bin\n");
}
uint32_t nbo(char *file){
    FILE *fp = fopen(file, "rb");
    uint32_t input;
    size_t result;

    if (fp == NULL) {
        fprintf(stderr, "File Ptr allocation error");
        exit(-1);
    }

    result = fread(&input, 1, sizeof(input), fp);
    if(result != sizeof(input)){
        fprintf(stderr, "Error read Input file");
        exit(-1);
    }
    fclose(fp);
    return ntohl(input);
}

int main(int argc, char **argv){
    if(argc != 3){
        usage();
        exit(-1);
    }
    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);

    uint32_t result1 = nbo(argv[1]);
    uint32_t result2 = nbo(argv[2]);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",result1,result1,result2,result2,result1+result2,result1+result2);

}
