#include <stdio.h>

#include "calculator.h"
#include "shapes.h"

int mainmenu() {
    while (1) {
        printf("1. Shapes\n2.Calculator\n3.Exit");
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