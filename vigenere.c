/*=============================================================================

|   Assignment:  pa01 - Encrypting a plaintext file using the Vigenere cipher|
|       Author:  Benjamin Osante
|     Language:  c
|   To Compile:  gcc -o pa01 vigenere.c  on windows ( gcc vigenere.c )
|   To Execute:  ./vigenere kX.txt pX.txt
|         Note:  All input files are simple 8 bit ASCII input
|        Class:  CIS3360 - Security in Computing - Summer 2021
|   Instructor:  McAlpin
|     Due Date:  June 27 2021

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main(int argc,char* argv[])
{
    FILE *key_file,*plaintext_file;
    char key[512];
    char plain_text[512];
    int ch;


    key_file = fopen(argv[1], "r");

    if (key_file == NULL)
    {
        printf("No File \n");
        exit(0);
    }

    int i=0;
    int k=0;
    int j;

    ch = fgetc(key_file);
    printf("Key:\n");


    while (ch != feof(key_file))
    {
        printf ("%c", ch);

        if(i>512) break;
       i++;

        if(ch>='a'&&ch<='z') key[k++]=toupper(ch);
        if(ch>='A'&&ch<='Z')key[k++]=ch;
        ch = fgetc(key_file);

    }
    key[k]='\0';
    printf("\n");
    fclose(key_file);


    plaintext_file = fopen(argv[2], "r");
    if (plaintext_file == NULL)
    {
        printf("No File \n");
        exit(0);
    }

    k=0;
    i=1;
    ch = fgetc(plaintext_file);

    printf("Plain Text:\n");
    while (ch != feof(plaintext_file))
    {
        printf ("%c", ch);

       if(i>512)   break;
        i++;

        if(ch>='a'&&ch<='z') plain_text[k++]=toupper(ch);
        if(ch>='A'&&ch<='Z') plain_text[k++]=ch;
        ch = fgetc(plaintext_file);
    }
    printf("\n");
    plain_text[k]='\0';

    fclose(plaintext_file);


    int msg_len = strlen(plain_text);
    int key_len = strlen(key);
    char newkey[msg_len];
    char ct[msg_len];


    for(i=msg_len;i<key_len;i++)
    {
        plain_text[i]='X';
        plain_text[i]='\0';
        msg_len=strlen(plain_text);
    }


    for(i=0;i<msg_len;++i)

    ct[i]=( (plain_text[i]+key[i])%26)+'A';
    ct[i]='\0';
    printf("Cipher text:\n");




    for(i=0;i<strlen(ct);i++)
    {
        if(i%80==0)
        printf("\n");
        printf("%c",tolower(ct[i]));
     }

    printf("\n");

}


/*  I Benjamin Osante (be940343) affirm that this program is| entirely my own work and that I have neither developed my code together with| any another person, nor copied any code from any other person, nor permitted| my code to be copied  or otherwise used by any other person, nor have I| copied, modified, or otherwise used programs created by others. I acknowledge| that any violation of the above terms will be treated as academic dishonesty.+=============================================================================*/


