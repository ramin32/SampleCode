/*******************************************************
 * add.c++
 *
 * Adds two integers from the command line.
 * 
 * OUTPUT:
 *      [ramin@home c_programs]$ add 100 500
 *      600
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 ******************************************************/ 
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc,char **argv){
    if(argc != 3){
        cerr << "Usage: " << argv[0] << " <num1> <num2>\n";
        exit(1);
    }

    int first,second;
    stringstream(argv[1]) >> first;
    stringstream(argv[2]) >> second;
    cout << first+second << endl;
}

