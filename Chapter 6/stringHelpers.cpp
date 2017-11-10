/*
    main.cpp

    main function for playing with Strings as a container

    Stephen King
    8/21/17
*/

#include "stringhelpers.h"

#include <cctype>

using namespace std;

vector<string> split(const string& s);
string::size_type width(const vector<string>& vec);
vector<string> frame(const vector<string>& vec);
vector<string> frame(const vector<string>& vec, string::size_type frameWidth);
vector<string> vcat(const vector<string>& top, const vector<string>& bottom);
vector<string> hcat(const vector<string>& top, const vector<string>& bottom);
/*
int main () {
    
    string s;
 
    while (getline(cin,s)) {
        vector<string> vec = split(s);
        
        for (vector<string>::size_type i = 0; i != vec.size(); ++i)
            cout << vec[i] << endl;
    }
 
    vector<string> vec;
    while (getline(cin, s))
        vec.push_back(s);
    
    vector<string> framedStrings = frame(vec);
    
    for (vector<string>::size_type i  = 0; i != framedStrings.size(); ++i)
        cout << framedStrings[i] << endl;
    
    cout << endl << "Vcat" << endl;
    vector<string> vertical = vcat(vec, framedStrings);
    for (vector<string>::size_type i = 0; i != vertical.size(); ++i)
        cout << vertical[i] << endl;
    
    cout << endl << "Hcat" << endl;
    vector<string> horizontal = hcat(vec, framedStrings);
    for (vector<string>::size_type i = 0; i != horizontal.size(); ++i)
        cout << horizontal[i] << endl;
    
    return 0;
    
    
}
*/

vector<string> split(const string& s)
{
    vector<string> words;
    typedef string::size_type string_size;
    
    string_size i = 0;
    while (i != s.size()){
        
        // ignore whitespace
        while (i != s.size() && isspace(s[i]))
            ++i;
        
        // find the end of the next word
        string_size j = i;
        while (j != s.size() && !isspace(s[j]))
            ++j;
        
        // Check that we found some characters
        if (j > i){
            words.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return words;
}

string::size_type width(const vector<string>& vec)
{
    string::size_type width = 0;
    for (vector<string>::size_type i = 0; i != vec.size(); ++i)
        width = max(width, vec[i].size());
    return width;
}

vector<string> frame(const vector<string>& vec) {
    return frame(vec, 1);
}

// Frame with iterators
vector<string> frame(const vector<string>& vec, string::size_type frameWidth){
    vector<string> frame;
    string::size_type maxLength = width(vec);
    string border = string(maxLength + 2 + 2 * frameWidth, '*');
    frame.push_back(border);
    
    string space1 = string(frameWidth, ' ');
    for (vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
        string space2 = string(frameWidth + maxLength - iter->size(), ' ');
        frame.push_back("*" + space1 + *iter + space2 + "*");
    }
    frame.push_back(border);
    return frame;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    vector<string> ret  = top;
    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
        ret.push_back(*it);
    // ret.insert(top.end(), bottom.begin(), bottom.end());
    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;
    string::size_type leftWidth = width(left) + 1;
    vector<string>::const_iterator i = left.begin(), j = right.begin();
    
    while (i != left.end() || j != right.end())
    {
        string s;
        if (i != left.end())
            s = *i++;
        
        s += string(leftWidth - s.size(), ' ');
        if (j != right.end())
            s += *j++;
        ret.push_back(s);
    }
    return ret;
    
}
