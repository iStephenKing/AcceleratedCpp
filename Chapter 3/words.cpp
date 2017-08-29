/*
    From Accellerated C++ by Andrew Koenig and Barbara E. Moo

    Computes a Students Grades based on grades and homework

    Stephen King
    8/07/17
*/

#include <iomanip>
#include <ios>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;
using std::vector;

int main()
{
    // Ask for the Students name
    cout << "Please enter your name: ";
    string name;
    cin >> name;
    cout << "Hello, " + name + "!" << endl;
    
    // Collect some words for funsies
    cout << "Please enter some words followed by EOF: ";
    
    // Variables to read words
    string word;
    vector<string> words;
    
    // Read in any number of words using cin
    while (cin >> word) {
        words.push_back(word);
    }
    
    // For this exercise just iterate through list and count
    // We'll find the results and print, but not store
    typedef vector<string>::size_type vec_sz;
    vec_sz size = words.size();
    
    if (size == 0){
        cout << endl << "Please " "try " "again." << endl;
        return 1;
    }
    
    // First sort the list
    sort(words.begin(), words.end());
    
    // Read through the list and compare each string to the previous one
    string lastword;
    int count = 0;
    
    // We will also keep track of the length of the longest and shorest strings
    int longest = 0;
    int shortest = 9999;  //This should be max int or max string but that's not the point right now
    for (vec_sz i = 0; i < words.size(); ++i) {
        word = words[i];
        if (word == lastword) {
            ++count;
        } else {
            // We have reached a new word, count is the total of previous word
            if (count > 0)
                cout << count << endl;
            cout << word << ": ";
            count = 1;
        }
        lastword = word;
        
        //Track size
        int size = word.size();
        if (size > longest) longest = size;
        if (size < shortest) shortest = size;
    }
    // A bit sloppy, but functional.  Print out the word count for the last word in the list
    cout << count << endl;
    
    cout << "shorstest: " << shortest << endl;
    cout << "longest: "<< longest << endl;
    
    return 0;
}

