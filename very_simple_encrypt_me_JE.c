#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encrypt_password(char *password, int *matrix, int matrix_length)
{
    static char encrypted_password[16];
    for (int i = 0; i < strlen(password); i++)
    {
        int ascii = (int)password[i];
        int index = i % matrix_length;
        int encoded_ascii = ascii ^ matrix[index];
        encrypted_password[i] = (char)(encoded_ascii % 256);
    }
    encrypted_password[15] = '\0';
    return encrypted_password;
}
char *encrypt_password2(char *password, int matrix[3][3])
{
    static char encoded_password[16];
    for (int i = 0; i < strlen(password); i++)
    {
        int ascii = (int)password[i];
        int row = i % 3;
        int encoded_ascii = 0;
        for (int j = 0; j < 3; j++)
        {
            encoded_ascii += ascii ^ matrix[row][j];
        }
        encoded_password[i] = (char)(encoded_ascii % 256);
    }
    encoded_password[15] = '\0';
    return encoded_password;
}


int main(int argc, char *argv[])
{
    // char password[] = "bridgerton";
    int matrix1[6] = {1, 2, 2, 1, 1, 2};
    int matrix2[3][3] = {{1, 2, 3}, 
                        {2, 3, 1}, 
                        {3, 1, 2}};
    // char *encrypted_password = encrypt_password2(argv[1], matrix2);
    char *encrypted_password = encrypt_password(argv[1], matrix1, 6);
    printf("Encrypted password: %s\n", encrypted_password);
    return 0;
}