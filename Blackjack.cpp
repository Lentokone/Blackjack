// Blackjack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//! Ei varmaan tarvi selitt‰‰

// ! perkele
// Todo Luokat
// ! Ajattelin card, deck, ehk‰ game, character, player, dealer

//
#include <iostream>
#include <stdio.h>
#include "Player.h"

using namespace std;

class Vector
{
private:
    double x0;
    double y0;
    double x1;
    double y1;

public:
    
    Vector()
    {
        alustaVektori();
    }
    
    Vector(double x0, double y0, double x1, double y1)
    {
        this->x0 = x0;
        this->x1 = x1;
        this->y0 = y0;
        this->y1 = y1;
    }

    Vector(Vector& v)
    {
        this->x0 = v.x0;
        this->y0 = v.y0;
        this->x1 = v.x1;
        this->y1 = v.y1;
    }

    void tulosta()
    {
        cout << "Testaus" << endl;
    }

    void tulostaVektori()
    {
        cout << "start:" << x0 << "," << y0 << " end:" << x1 << "," << y1 << endl;
    }

    void alustaVektori()
    {
        x0 = 0;
        y0 = 0;
        x1 = 0;
        y1 = 0;
    }

    void aseta(double x0, double y0, double x1, double y1)
    {
        this->x0 = x0;
        this->x1 = x1;
        this->y0 = y0;
        this->y1 = y1;
    }
};

int main()
{
    Vector v1;


    v1.tulosta();

    v1.alustaVektori();
    v1.tulostaVektori();

    v1.aseta(2, 5, 1, 5);
    v1.tulostaVektori();

    Vector v2(1, 2, 3, 4);
    v2.tulostaVektori();

    Player bob;
    bob.UURR();
    bob.kortit();
}