#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include <algo2Head.h>

using namespace std;

int main()
{
    VibeCheck myVibe;
    vector<int> myVector;

    int size = 0;
    cout << "What size do you want array to be?" << endl;
    cin >> size;
    cout << "Enter numbers into the array: " << endl;
    int input = 0;

    for (int ix = 0; ix < size; ix++)
    {
        cin >> input;
        myVector.push_back(input);
    }

    stable_sort(myVector.begin(), myVector.end());


    for (int jx = 0; jx < myVector.size(); jx++){
        myVibe.myHand[jx] = myVector[jx];
    }

    
    int groupSize = 0;
    cout << "Now enter the group size that u want: " << endl;
    cin >> groupSize;
    myVibe.groupIt(myVibe.myHand, groupSize);

    cout << "Enter numbers into the array: " << endl;
}
