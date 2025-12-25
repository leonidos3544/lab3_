#ifndef PART1_H
#define PART1_H

#include <iostream>

class Animal {
public:
    virtual void move() = 0;
    virtual void draw() = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    
    bool operator==(Animal& other) {
        return (getX() == other.getX()) && (getY() == other.getY());
    }
};

class Cat : public Animal {
private:
    int x, y;
    
public:
    Cat(int startX, int startY);
    void move() override;
    void draw() override;
    int getX() override;
    int getY() override;
};

#endif // PART1_H
