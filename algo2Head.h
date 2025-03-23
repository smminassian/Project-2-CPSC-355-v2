#ifndef ALGO2HEAD_H
#define ALGO2HEAD_H

#include <iostream>
#include <map>



class VibeCheck{
    public:
        map<int, int> myHand;
        VibeCheck();
        void groupIt(map<int, int> myHand, int GroupSize);
        void printMyHand();

};



#endif