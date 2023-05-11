#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(char *user_input)
{
    static const char pwd_encrypted[] = "cpkefgsvmo"; // replace with the actual encrypted password
    int matrix[6] = {1, 2, 2, 1, 1, 2};
    // char *encoded_password = calloc(strlen(pwd_encrypted) + 1, sizeof(char));
    // char *encoded_password = calloc(strlen(pwd_encrypted) + 1, sizeof(char));
    char encoded_password[31];
    for (int i = 0; i < strlen(pwd_encrypted); i++){
        int decoded_ascii = (int)pwd_encrypted[i] ^ matrix[i % 6];
        encoded_password[i] = (char)(decoded_ascii % 256);
    }
    int res = !strcmp(encoded_password, user_input);
    // free(encoded_password);
    return res;
}

int main(int argc, char *argv[])
{
    printf("%s\n", (argc == 2 && check(argv[1])) ? "Congratulations, password check successful!" : "Password check failed!");
    return 0;
}