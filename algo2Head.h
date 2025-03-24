#ifndef ALGO2HEAD_H
#define ALGO2HEAD_H

#include <iostream>
#include <map>
#include <vector>



class VibeCheck{
    public:
        std::map<int, bool> boolMap;   //I declare a int and boolean map. You will see why in groupItAndPrintIt function
        std::vector<int> myHand;        //here is my vector of integers
        VibeCheck();
        void groupItAndPrintIt(std::vector<int> myHand, int GroupSize); //This function groups numbers and prints them
        int AmountOfGroups();  //This is to check if I got the right amount of Groups
        
};



#endif