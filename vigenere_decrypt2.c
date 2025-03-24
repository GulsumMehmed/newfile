#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXN 1024

char *vigenere_decrypt(char *cipher, char *key)
{
    int text_length = strlen(cipher);
    int key_length = strlen(key);
    char *plaintext = (char *)malloc(sizeof(char) * (text_length + 1));
    memset(plaintext, '\0', sizeof(char) * (text_length + 1));
    for (int i = 0; i < text_length; i++)

    {
        if (isalpha(cipher[i]))
        {

            int shift = tolower(key[i % key_length]) - 'a';
            if (islower(cipher[i]))
            {
                plaintext[i] = (cipher[i] - 'a' - shift + 26) % 26 + 'a';
            }
            else
            {
                plaintext[i] = (cipher[i] - 'A' - shift + 26) % 26 + 'A';
            }
        }
        else
        {
            plaintext[i] = cipher[i];
        }
    }

    plaintext[text_length] = '\0';
    return plaintext;
}




int read_input_file(char* filename, char* text)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("File not found");
        return EXIT_FAILURE;
    }

    if(fgets(text, MAXN, fp) == NULL)
    {
        printf("Error reading from file");
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

void write_text(char* filename, char* text)
{
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "%s", text);
    fclose(fp);
}

char * read_filename_stdin(){
    char * filename = malloc(sizeof(char) * (FILENAME_MAX+1));
    memset(filename, '\0', sizeof(char) * (FILENAME_MAX+1));
    scanf("%s", filename);
    return filename;
}

int main()
{

    char text[MAXN];
    char key[MAXN];

    read_input_file(read_filename_stdin(), text);
    read_input_file(read_filename_stdin(), key);

    
    char * decrypted_text = vigenere_decrypt(text ,key);
    puts(decrypted_text);
    write_text("vigenere_decrypted.txt", decrypted_text);

    free(decrypted_text);

    return EXIT_SUCCESS;

}
