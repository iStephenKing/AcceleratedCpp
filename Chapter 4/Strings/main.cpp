/*

    main.cpp

    Stephen King
    8/14/17
*/

#include "readStrings.h"
#include <iomanip>
#include <ios>

using std::vector; using std::string; using std::cin;
using std::cout; using std::endl; using std::setw;

int main(){
    
    cout << "Enter some text" << endl;
    vector<string> wordList;
    readStrings(cin, wordList);
    
    cout << "Total Number of words Entered = " << wordList.size() << "\n\n";
    
    vector<wordCount> countOfWords;
    parseWordList(wordList, countOfWords);
    int maxWordLength = maxLength(countOfWords);
    
    vector<wordCount>::size_type i;
    for (i = 0; i < countOfWords.size(); ++i)
        cout << setw(maxWordLength + 2) << countOfWords[i].word  + ": "
             << setw(0) << countOfWords[i].count << endl;
    
    return 0;
    
}