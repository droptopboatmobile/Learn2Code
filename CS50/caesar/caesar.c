#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char rotate(char c, int n);
bool only_digits(string chars);

int main(int argc, string argv[]) {

    // checks if there are two command arguments e.g "./caesar 45, if not print usage instructions
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
            return 1;
    }

    // checks if command argument is digits, if not prints usage instructions
    bool valid_key = only_digits(argv[1]);
    if (valid_key == false) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert key string to int
    int key = atoi(argv[1]);

    // get user plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // for each increment of string plaintext
    for(int i = 0, n = strlen(plaintext); i < n; i++) {

        // rotate function each letter of plaintext key number of times
        char cipher_char = rotate(plaintext[i], key);
        printf("%c", cipher_char);
    }

    printf("\n");
    return 0;
}

// checks if the key is not digits
bool only_digits(string chars) {
    for (int i = 0, n = strlen(chars); i < n; i++) {
        if (!isdigit(chars[i])) {
            return false;
        }
    }
    return true;
}

// rotate function, bringing in a character and an integer which we will later use when calling the function
char rotate(char c, int n) {

    // declaring an int that will be assigned the value of c - 'A' or 'a' respectively.
    int c1;

    if (isalpha(c)) {
        if (isupper(c)) {
            c1 = c - 'A';
        } else {
            c1 = c - 'a';
        }

    // caesar cipher formula
    int ci = (c1 + n) % 26;
        if (isupper(c)) {
            return ci + 'A';
        } else {
            return ci + 'a';
        }
    }
    return c;
}

