#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
 
int write_file(char* filename, char* buf, int size)
{
    FILE* fp;
    int write_len = 0;

    if ((fp = fopen(filename, "wb")) == NULL)
    {
        printf("파일 오픈 에러'%s'\n", filename);
        return -1;
    }
 
    if ((write_len = fwrite(buf, sizeof(char), size, fp)) < size)
    {
        fclose(fp);
        printf("쓰기 에러 '%s' '%d(%d)'\n", filename, size, write_len);
    }
 
    fclose(fp);
 
    return 0;
}
 
int read_file(char* filename, char *buf, int size)
{
    FILE* fp;
    int read_len = 0;
 
    if ((fp = fopen(filename, "rb")) == NULL)
{
        printf("파일 오픈 에러 '%s'\n", filename);
        return -1;
    }
    read_len = fread(buf, sizeof(char), size, fp);
 
    fclose(fp);
 
    return 0;
 
}
 
int main()
{
    char filename[256] = "test.docx";
    //char write_data[20] = { 0xFF, 0xFD, 0xFC, 0xFB, 0xFA, };
    char read_data[20] = { 0x00, };
    int i =0;
 
        read_file(filename, read_data, 1024*1024);
        for (i = 0; i < 1024*1024; i++)
            printf("0x%X ", (unsigned char)read_data[i]);
    return 0;
}