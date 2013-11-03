/*******************************************************
 * perms.c++
 *
 * Returns a permutation of the first command line argument.
 * Uses boost shared_ptr and the STL.
 * 
 * OUTPUT:
 *      [ramin@home cpp]$ ./perms abc
 *      abc
 *      bac
 *      bca
 *      acb
 *      cab
 *      cba
 *      
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 ******************************************************/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/tr1/memory.hpp>

using std::vector;
using std::string;
using std::cout;
using std::cerr;
using std::tr1::shared_ptr;


typedef shared_ptr<vector<string> > string_vector;

string_vector perms(string input);
void println(string s) {cout << s << std::endl;}
string_vector insert_everywhere(string input, char ch);


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <sequence>\n";
        abort();
    }

    string input(argv[1]);
    string_vector result = perms(input);
    for_each(result->begin(), result->end(), println);
}


string_vector perms(string input)
{

    string_vector result(new vector<string>());
    if(input.size() == 1)
    {
        result->push_back(input);
        return result;
    }

    char head = input[0];
    string tail = input.substr(1,input.size()-1);

    string_vector tail_perms = perms(tail);
    vector<string>::iterator it = tail_perms->begin();
    while(it != tail_perms->end())
    {
        string_vector char_inserted_string_vector = insert_everywhere(*it,head);
        result->insert(result->end(), char_inserted_string_vector->begin(), char_inserted_string_vector->end());
        it++;
    }
    return result;
}

string_vector insert_everywhere(string input, char ch)
{
    string_vector result( new vector<string>(input.size() + 1, input));
    for(int i = 0; i <= input.size(); i++)
        result->at(i).insert(i,sizeof(char), ch);
    return result;
}
