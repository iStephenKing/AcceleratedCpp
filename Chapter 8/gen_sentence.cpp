/*
    gen_sentence.cpp

    From Accelerated C++
    By Koenig and Moo

    Defines main function to generate sentences

    Stephen King
*/

#include "sentence.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main()
{
    srand(time(NULL));
    
    ifstream file;
    file.open("grammer.txt");
    if (file.is_open()) {
        gen_sentence(read_grammer(file), ostream_iterator<string>(cout, " "));
        cout << endl;
                     
        return 0;
    }else
        return -1;
}