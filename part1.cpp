#include "part1.h"
#include <iostream>

Cat::Cat(int startX, int startY) : x(startX), y(startY) {}

void Cat::move() {
    char dir;
    std::cout << "Move (wasd): ";
    std::cin >> dir;
    std::cin.ignore(6, '\n'); // Чтобы ввод был по одному символу
    
    if (dir == 'w') y--;
    else if (dir == 's') y++;
    else if (dir == 'a') x--;
    else if (dir == 'd') x++;

    if (x < 0) x = 0;
    if (x > 4) x = 4;
    if (y < 0) y = 0;
    if (y > 4) y = 4;
}

void Cat::draw() {
    std::cout << "C";
}

int Cat::getX() {
    return x;
}

int Cat::getY() {
    return y;
}
