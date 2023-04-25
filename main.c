#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculator.h"
#include "shapes.h"

#include "game.h"

int mainmenu() {
    while (1) {
        printf("1. Shapes\n2. Calculator\n3. Game\n4. Exit\nChoice: ");
        int sel;
        scanf(" %d", &sel);
        if (sel >= 1 || sel <= 4) return sel;
    }
}

int main() {
    while (1) {
        int sel = mainmenu();
        if (sel == 4) break;
        if (sel == 1)
            shapesMenu();
        else if (sel == 2)
            calculatorMenu();
        else if (sel == 3)
            return game();
    }
    return 0;
}
