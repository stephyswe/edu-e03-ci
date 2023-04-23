#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculator.h"
#include "shapes.h"

int characterCheck() {
    char input[100];

    while (1) {
        printf("Enter a string starting with 'A' or 'B': ");
        scanf("%s", input);

        if (strlen(input) > 0 && (input[0] == 'A' || input[0] == 'B')) {
            printf("You entered: %s\n", input);
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}

int mainmenu() {
    while (1) {
        printf("1. Shapes\n2. Calculator\n3. Exit\nChoice: ");
        int sel;
        scanf(" %d", &sel);
        if (sel >= 1 || sel <= 3) return sel;
    }
}

int main() {
    while (1) {
        int sel = mainmenu();
        if (sel == 3) break;
        if (sel == 1)
            shapesMenu();
        else if (sel == 2)
            calculatorMenu();
    }
    return 0;
}
