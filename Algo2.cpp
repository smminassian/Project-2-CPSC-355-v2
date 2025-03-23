#include <iostream>
#include <vector>

#include <algo2Head.h>

using namespace std;

VibeCheck::VibeCheck()
{
    this->myHand = map<int, int>();
}


void VibeCheck::groupIt(map<int, int>, int GroupSize)
{
    vector<int> temp;
    for (int ix = 0; ix < myHand.size(); ix++)
    {
        if (myHand.empty() == true)
        {
            break;
        }
        else if(myHand[ix + 1] - myHand[ix] == 1){
            temp.push_back(myHand[ix]);
            temp.push_back(myHand[ix+1]);
            myHand[ix]--;
            myHand[ix+1]--;
        }
        }
        
        
    }



