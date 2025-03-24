#include <iostream>
#include <vector>

#include "algo2Head.h"

using namespace std;

VibeCheck::VibeCheck()
{
    this->boolMap = map<int, bool>();     //I initliaze my map to be empty
    this->myHand = vector<int>();         //I also intialize my vector to be empty.
}

void VibeCheck::groupItAndPrintIt(vector<int> myHand, int GroupSize)
{
    vector<int> temp; //So this is the array I will use to form my groups
    int count = 0;

    for (int ix = 0; ix < myHand.size(); ix++)  // I loop through the my main vector
    {

        if (temp.size() == GroupSize)   // if I have a group that equals group size, I print it out here and then clear temp to prep for next group
        {
            for (int jx = 0; jx < temp.size(); jx++)
            {
                cout << temp[jx];
                cout << " , ";
            }
            cout << endl;
            count++; //This is how i count how many groups i have and I check it with the amount of groups i should have below
            temp.clear();
            continue; //I continue to the next iteration 
        }

        if (myHand[ix + 1] - myHand[ix] == 1)  //So if the next element and current element are in order
        {
            if (boolMap[myHand[ix]] == false && boolMap[myHand[ix + 1]] == false) //I do this at the start cus i know the first two elements will have false as their visited status
            {
                temp.push_back(myHand[ix]); //I push the first element
                temp.push_back(myHand[ix + 1]); // then the next 
                boolMap[myHand[ix]] = true; // i switch both to true cus i visited them
                boolMap[myHand[ix + 1]] = true;
                continue; // i move on to next iteration
            }
            else if (myHand[ix - 1] == myHand[ix] && temp.size() != GroupSize && myHand[ix + 1] - myHand[ix] == 1)
            {
                // I am checking, was the last element a duplicate? If it was then what I can do is I can push the current element and the next element into a array.
                //I did this because I was having trouble getting duplicate numbers into seperate groups.
                temp.push_back(myHand[ix]);
                temp.push_back(myHand[ix + 1]);
                boolMap[myHand[ix + 1]] = true; // I dont turn ix to true cus i already know its true cus of when i had false false

                continue;
            }
            else if (boolMap[myHand[ix]] == true && boolMap[myHand[ix + 1]] == false) 
            {
                //So for this if statement, if the current element has been visted and the next one has not been visted, push the next one because the current one is already in temp.
                temp.push_back(myHand[ix + 1]);
                boolMap[myHand[ix + 1]] = true;

                continue;
            }
        }
        else if (boolMap[myHand[ix]] == true && boolMap[myHand[ix + 1]] == true)
        {

            if (ix + 2 < myHand.size()) //I do ix+2 cus i want to skip over the duplicate. So if i have 1 2 2 3 3 and Im processing index 1 and 2, 
                                        //i will jump from index 1 to 3 to get 3 so I can make the group 1, 2, 3
            {
                if (myHand[ix + 2] - myHand[ix] == 1)
                {
                    //so if the difference between ix+2 and ix is 1, then I push ix+2 to temp and mark it as true
                    temp.push_back(myHand[ix + 2]);
                    boolMap[myHand[ix + 2]] = true;

                    continue;
                }
            }
        }
        else if (myHand[ix + 1] - myHand[ix] != 1)
        {
            continue;  //If the difference is not 1, then I move on to the next iteration
        }
    }
    int expectedAmountOfGroups = AmountOfGroups();  //I let the value returned from Amount of Groups be a new int
    if (count == expectedAmountOfGroups){
        cout << "true" << endl; // I correctly got number of groups
    }
    else{
        cout << "false" << endl; // I did not correctly get number of groups
    }
}


int VibeCheck::AmountOfGroups()
{
    int consecutiveCount = 0;
    for(int ix = 0; ix < myHand.size(); ix++){
        if(myHand[ix+1] - myHand[ix] == 1){  //I count the number of values in my vector that have a difference of 1
            consecutiveCount++;
        }
    }
    return consecutiveCount;
}