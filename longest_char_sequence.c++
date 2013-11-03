/*******************************************************
 * longest_char_sequence.c++
 *
 * Determines the longest char sequence of an input string.
 * 
 * OUTPUT:
 *   [ramin@archlinux cpp]$ ./longest_char_sequence  abbcccccdde
 *   Max sequence: c
 *
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 ******************************************************/ 

#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    if(argc != 2)
        std::cerr << "Usage: " << argv[0] << " <char_sequence> \n";
    
    int size = strlen(argv[1]);

    char currentChar = argv[1][0];
    char currentCharSize = 1;
    int maxCharSize = currentCharSize;
    char maxChar = currentChar;
    for(int i = 1; i <= size; i++)
    {
        char ch = argv[1][i];
        if(ch != currentChar)
        {
            if(currentCharSize > maxCharSize)
            {
                maxChar = currentChar;
                maxCharSize = currentCharSize;
            }
            currentChar = ch;
            currentCharSize = 1;
        }
        else
            currentCharSize++;
    }

    std::cout << "Max sequence: " << maxChar << std::endl;
}

