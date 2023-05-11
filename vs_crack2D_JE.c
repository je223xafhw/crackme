// #include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password: "bridgerton"

int check(char *user_input)
{
    static const char pwd_encrypted[] = "$T=2/1TbGH";
    int matrix[3][3] = {{1, 2, 3}, 
                        {2, 3, 1}, 
                        {3, 1, 2}};
    char *encoded_password = calloc(strlen(user_input) + 1, sizeof(char));
    for (int i = 0; i < strlen(user_input); i++)
    {
        int ascii = (int)user_input[i];
        int row = i % 3;
        int encoded_ascii = 0;
        for (int j = 0; j < 3; j++)
        {
            encoded_ascii += ascii ^ matrix[row][j];
        }
        encoded_password[i] = (char)(encoded_ascii % 256);
    }
    int result = !strcmp(encoded_password, pwd_encrypted);
    free(encoded_password);
    return result;
}

int main(int argc, char *argv[]){

  if ((argc == 2) && check(argv[1])) {
    printf("Congratulations, password check successful!\n");
    return (0);
  }
  else {
    printf("Password check failed!\n");
    return (-1);
  }
}