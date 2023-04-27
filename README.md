## Setup

#### Tests on "test" build target

#### App on "programmet-debug.exe" build target

## App

Main menu with three options (Shapes, Calculator or Game).

Shapes: enter a shape (TEXT! not a number), and both the area and perimeter is calculated. These shapes are available to choose from: Rectangle, Parallelogram, Triangle, and Circle.

```
Enter shape (rectangle, parallelogram, triangle, circle): rectangle
length: 4
width: 5
Area: 20.00
Perimeter: 18.00
```

Handle invalid input (e.g. numbers instead of text, or negative numbers). The program should not crash, but instead print an error message and allow the user to try again.

Input Shape error handling:
```
Enter shape (rectangle, parallelogram, triangle, circle): rec
Invalid shape
Enter shape (rectangle, parallelogram, triangle, circle): -1
Invalid shape
Enter shape (rectangle, parallelogram, triangle, circle): 1
Invalid shape
Enter shape (rectangle, parallelogram, triangle, circle): rectangle
length:
```

Input Shape error handling:
```

```

Calculator: Enter two numbers and then select which operator to use: +, -, \*, /, and % (modulus). Returns
the value.

```
num1: 5
num2: 7
Enter operator (+-*/%): *
5.00 * 7.00 = 35.00
```

Handle invalid input (e.g. numbers instead of text, or negative numbers). The program should not crash, but instead print an error message and allow the user to try again.
```
Enter shape (rectangle, parallelogram, triangle, circle): rec
Invalid shape
Enter shape (rectangle, parallelogram, triangle, circle): -1
Invalid shape
Enter shape (rectangle, parallelogram, triangle, circle): 1
Invalid shape
Enter shape (rectangle, parallelogram, triangle, circle): rectangle
length:
```

Game: play Rock, Paper, Scissors against the computer. The result (win or loss), date of the game, and the average number of times you have won against the computer (at that point) is saved in a file.
Example data:

```
Enter your choice (Stones, Scissors, or Bag): 3
Computer wins!
Your average win rate is 48.15% (13/28).

-- Game history --
Tie			2023-04-26 15:41:57	48.00%
User		2023-04-26 15:41:58	50.00%
Computer	2023-04-26 15:41:58	48.15%
```

## Source code

Makefile & 13 files in total

- (6 c files): main.c shapes.c shapesfunc.c calculator.c game.c input.c
- (4 h files): shapes.h calculator.h game.h input.h
- 3 Test cases: TestCalc.cpp TestGame.cpp TestShapes.cpp
- - TestShapes (rectangle, triangle, circle, parallelogram)
- - TestCalc (add, subtract, multiply, divide)
- - TestGame (rock, paper, scissors)

## Test

All tests in the program utilize the Google Test framework and follow the Arrange-Act-Assert pattern. Each test focuses on a specific part of the functionality. Depending on the source code, tests either verify a certain status or a returned value. When testing shapes, the status can be one of three values: OK, InvalidShape, or InvalidInput. When testing the calculator, the test checks whether the returned value matches the expected value. // mingw32-make test //

```
gcc -Wall -Werror -g   -c -o calculator.o calculator.c
gcc -Wall -Werror -g   -c -o game.o game.c
g++ -o check.exe input.o TestShapes.o calculator.o shapesfunc.o game.o TestCalc.o TestGame.o -Wall -Werror -g -I gtest C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a
./check.exe
Running main() from C:/M/mingw-w64-gtest/src/googletest-release-1.12.1/googletest/src/gtest_main.cc
[==========] Running 27 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 9 tests from GameTest
[ RUN      ] GameTest.TestStonesVsScissors
[       OK ] GameTest.TestStonesVsScissors (0 ms)
[----------] 10 tests from CalcTest
[ RUN      ] CalcTest.AddTwoNumbersCorrectly
[       OK ] CalcTest.AddTwoNumbersCorrectly (0 ms)
[----------] 8 tests from ShapesTest
[ RUN      ] ShapesTest.WhenCreateRectangleIsOK
[       OK ] ShapesTest.WhenCreateRectangleIsOK (0 ms)
[ RUN      ] ShapesTest.WhenCreateParallelogramLengthIsZero
[       OK ] ShapesTest.WhenCreateParallelogramLengthIsZero (0 ms)
[----------] 8 tests from ShapesTest (31 ms total)

[----------] Global test environment tear-down
[==========] 27 tests from 3 test suites ran. (110 ms total)
[  PASSED  ] 27 tests.
```
