#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define CAPTCHA_LENGTH 6
#define MAX_ATTEMPTS 3

// Generate random captcha
void generateCaptcha(char *captcha) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charsetSize = sizeof(charset) - 1;

    for (int i = 0; i < CAPTCHA_LENGTH; i++) {
        int index = rand() % charsetSize;
        captcha[i] = charset[index];
    }
    captcha[CAPTCHA_LENGTH] = '\0';
}

// Display distorted captcha
void displayCaptcha(char *captcha) {
    printf("\n=== CAPTCHA ===\n\n");

    for (int i = 0; i < CAPTCHA_LENGTH; i++) {
        printf("%c ", captcha[i]);   // space distortion
        if (rand() % 2) printf(" "); // random extra space
    }

    printf("\n\n==============\n");
}

int main() {
    srand(time(NULL));

    char captcha[CAPTCHA_LENGTH + 1];
    char input[100];

    generateCaptcha(captcha);

    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        displayCaptcha(captcha);

        printf("Enter CAPTCHA: ");
        scanf("%s", input);

        if (strcmp(captcha, input) == 0) {
            printf("Access Granted!\n");
            return 0;
        } else {
            printf("Incorrect CAPTCHA!\n");
            attempts++;
        }
    }

    printf("Too many failed attempts. Access Denied.\n");
    return 0;
}
