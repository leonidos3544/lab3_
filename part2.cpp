#include <iostream>
#include <cstdlib.h>
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
    Cat cat(0, 0);
    Mouse mouse(2, 2);
    const int FIELD_SIZE = 5;
    const int MAX_TURNS = 5;
    
    std::srand(std::time(NULL));
    
    for (int turn = 1; turn <= MAX_TURNS; ++turn) {
        system("clear");
        
        if (cat == mouse) {
            std::cout << "YOU ARE WIN IN TURN " << turn << std::endl;
            return 0;
        }
        
        std::cout << "TURN " << turn << std::endl;
        std::cout << "Catch the mouse in 5 turns!" << std::endl << std::endl;

        for (int y=0; y<FIELD_SIZE; ++y) {
            for (int x=0; x<FIELD_SIZE; ++x) {
                if (cat.getX() == x && cat.getY() == y) {
                    cat.draw();
                } else if (mouse.getX()==x && mouse.getY() == y) {
                    mouse.draw();
                } else {
                    std::cout << ".";
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
        
        cat.move();
        mouse.move();
    }
    
    system("clear");
    std::cout << "You are looose, try again." << std::endl;
    return 0;
}
