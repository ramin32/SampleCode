/**************************************************************
 * mode_finder.c++
 *
 * Finds a mode in a list of integers
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 * ***********************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    vector<int> grades;
    int x;

    //Get the numbers
    while(cin >> x)
        grades.push_back(x);
    //Sort them in increasing order
    sort(grades.begin(),grades.end());

    int mode = grades[0];
    int temp_mode = mode;
    int count = 1;
    int temp_count = count;

    //Count the number of times a number appears consecutively
    //Keep track of the greatest count
    for(int i=1;i<grades.size();i++){
        if(temp_mode != grades[i] || i == grades.size()-1){
            if(temp_count > count){
                count = temp_count;
                mode = temp_mode;
            }
            temp_count =0;
            temp_mode = grades[i];
        }
        temp_count++;
    } 

    cout << mode << " appeared " << count << " times.\n";
}

