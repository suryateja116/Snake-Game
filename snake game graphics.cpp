#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameover;
const int width = 20;
const int height = 20;
int x, y, foodX, foodY, score;
int tailX[100], tailY[100];
int Tail;
int dir;
int speedDelay = 100; // default speed (ms between frames)

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Setup() {
    gameover = false;
    dir = 0; // STOP
    x = width / 2;
    y = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
    Tail = 0;
    hideCursor();
}

void Draw() {
    gotoxy(0, 0);
    setColor(1);
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#";
            if (i == y && j == x) {
                setColor(2); cout << "@"; // Snake head
            } else if (i == foodY && j == foodX) {
                setColor(4); cout << "*"; // Food
            } else {
                bool printTail = false;
                for (int k = 0; k < Tail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        setColor(10 + k % 7);
                        cout << "O";
                        printTail = true;
                        break;
                    }
                }
                if (!printTail) {
                    setColor(8);
                    cout << " ";
                }
            }
            if (j == width - 1) { setColor(1); cout << "#"; }
        }
        cout << endl;
    }

    setColor(1);
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    setColor(7);
    cout << "Score: " << score << "\tSpeed: ";
    if (speedDelay > 100) cout << "Easy";
    else if (speedDelay > 70) cout << "Medium";
    else if (speedDelay > 40) cout << "Hard";
    else cout << "Extreme";
    cout << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': if (dir != 2) dir = 1; break;
            case 'd': if (dir != 1) dir = 2; break;
            case 'w': if (dir != 4) dir = 3; break;
            case 's': if (dir != 3) dir = 4; break;
            case 'x': gameover = true; break;
        }
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < Tail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case 1: x--; break;
        case 2: x++; break;
        case 3: y--; break;
        case 4: y++; break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < Tail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameover = true;
    }

    if (x == foodX && y == foodY) {
        score += 10;
        foodX = rand() % width;
        foodY = rand() % height;
        Tail++;
    }
}

void Instructions() {
    system("cls");
    setColor(14);
    cout << "========== INSTRUCTIONS ==========\n";
    setColor(7);
    cout << "Use W, A, S, D to move the snake.\n";
    cout << "Eat * to grow and score points.\n";
    cout << "Press X anytime to exit the game.\n";
    cout << "Avoid running into yourself!\n";
    cout << "\nPress any key to go back...";
    _getch();
}

void SelectSpeed() {
    system("cls");
    setColor(11);
    cout << "========== SELECT GAME SPEED ==========\n\n";
    setColor(7);
    cout << "1. Easy (Slow)\n";
    cout << "2. Medium (Normal)\n";
    cout << "3. Hard (Fast)\n";
    cout << "4. Extreme (Very Fast)\n\n";
    cout << "Choose your difficulty: ";
    char choice = _getch();
    switch (choice) {
        case '1': speedDelay = 120; break;
        case '2': speedDelay = 80; break;
        case '3': speedDelay = 50; break;
        case '4': speedDelay = 30; break;
        default: speedDelay = 80; break;
    }
}

void Menu() {
    char choice;
    do {
        system("cls");
        setColor(11);
        cout << "========== SNAKE GAME ==========\n\n";
        setColor(7);
        cout << "1. Play Game\n";
        cout << "2. Instructions\n";
        cout << "3. Exit\n\n";
        cout << "Select an option: ";
        choice = _getch();
        switch (choice) {
            case '1':
                SelectSpeed();
                Setup();
                while (!gameover) {
                    Draw();
                    Input();
                    Logic();
                    Sleep(speedDelay);
                }
                system("cls");
                setColor(12);
                cout << "\n\n\tGAME OVER!\n";
                setColor(7);
                cout << "\tYour Score: " << score << "\n";
                cout << "\n\tPress any key to return to menu...";
                _getch();
                break;
            case '2':
                Instructions();
                break;
            case '3':
                setColor(10);
                cout << "\nExiting game... Goodbye!\n";
                Sleep(800);
                break;
            default:
                cout << "\nInvalid option! Try again.\n";
                Sleep(700);
        }
    } while (choice != '3');
}

int main() {
    Menu();
    return 0;
}

