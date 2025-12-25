#include <iostream>
#include <cstdlib>
#include<memory>
#include <ctime>//rand
#include "part1.h"

class Mouse : public Animal {
private:
    int x, y;
    
public:
    Mouse(int startX, int startY);
    void move() override;
    void draw() override;
    int getX() override;
    int getY() override;
};

Mouse::Mouse(int startX, int startY) : x(startX), y(startY) {}

void Mouse::move() {
    int dir = std::rand() % 4;
    if (dir == 0)--y;
    else if (dir == 1) y++;
    else if (dir == 2) x--;
    else if (dir == 3) x++;
    
    if (x < 0) x = 0;
    if (x > 4) x = 4;
    if (y < 0) y = 0;
    if (y > 4) y = 4;
}

void Mouse::draw() {
    std::cout << "M";
}

int Mouse::getX() {
    return x;
}

int Mouse::getY() {
    return y;
}

int main() {
    auto ptrc = std::make_shared<Cat>(0,0);
    auto ptrm = std::make_shared<Mouse>(2,2);
    const int FIELD_SIZE = 5;
    const int MAX_TURNS = 5;
    
    std::srand(std::time(NULL));
    
    for (int turn = 1; turn <= MAX_TURNS; ++turn) {
        system("clear");
        
        if (ptrc->getX() == ptrm->getX() && ptrc->getY() == ptrm->getY()){
            std::cout << "YOU ARE WIN IN TURN " << turn << std::endl;
            return 0;
        }
        
        std::cout << "TURN " << turn << std::endl;
        std::cout << "Catch the mouse in 5 turns!" << std::endl << std::endl;

        for (int y=0; y<FIELD_SIZE; ++y) {
            for (int x=0; x<FIELD_SIZE; ++x) {
                if (ptrc->getX() == x && ptrc->getY() == y) {
                    ptrc->draw();
                } else if (ptrm->getX()==x && ptrm->getY() == y) {
                    ptrm->draw();
                } else {
                    std::cout << ".";
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
        
        ptrc->move();
        ptrm->move();
    }
    
    system("clear");
    std::cout << "You are looose, try again." << std::endl;
    return 0;
}
    
    system("clear");
    std::cout << "You are looose, try again." << std::endl;
    return 0;
}
