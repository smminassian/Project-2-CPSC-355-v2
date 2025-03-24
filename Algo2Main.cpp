#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "algo2Head.h"

using namespace std;

int main()
{
    VibeCheck myVibe; //I create a instance of mu class
    int size = 0;
    cout << "What size do you want array to be?" << endl;
    cin >> size;
    cout << "Enter numbers into the array: " << endl;
    int input = 0;

    for (int ix = 0; ix < size; ix++)
    {
        cin >> input;
        myVibe.myHand.push_back(input); // I push the user input into my vector
    }
    stable_sort(myVibe.myHand.begin(), myVibe.myHand.end()); // I sort my vector in increasing order.
    

    for(int kx = 0; kx < myVibe.myHand.size(); kx++){
        myVibe.boolMap.insert({myVibe.myHand[kx], false});  // I insert the values of myHand as a key into bool map and their values are all set to false
    }



    int groupSize = 0;
    cout << "Now enter the group size that u want: " << endl;
    cin >> groupSize;
    myVibe.groupItAndPrintIt(myVibe.myHand, groupSize); 

    return 0;
}
