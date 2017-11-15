#ifndef XREF_H
#define XREF_H
/*
    xref.h defines the xref function
    
    Takes in access to an input stream and returns a map of strings to a vector of where
    that string appeared in the input stream.
*/

#include "split.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>


// For Exercise 8-5
// I was lost for what it means to have an output iterator for map
// This code was referenced from example code by the Author
template <class OutIterator>
OutIterator xref(std::istream& in, void find_words(const std::string&, std::back_insert_iterator<std::vector<std::string> >),
                 OutIterator d)
{
    std::string line;
    int line_number = 0;
    std::map< std::string, std::vector<int> > ret;
    
    // Read the next line from input stream
    while (getline(in, line)) {
        ++line_number;
        std::vector<std::string> words;
        find_words(line,std::back_inserter(words));
        
        for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++it) {
            word = *it;
            if (ret[word].empty() || ret[word].back() != line_number)
                ret[word].push_back(line_number);
        }
    }
    //Write the results to the output operator
    copy(ret.begin(), ret.end(), d);
    
    return d;
}

//  This function is what I was missing to translate a map output iterator to ostream
//  The author (and code below) uses a custom class which hasn't been introduced in
//  The book yet, so how was this actually supposed to be done?  Was asking for this
//  from a map just an editorial mistake originally?
template <class T, class charT = char, class traits = std::char_traits<CharT> >
class c_ostream_iterator:
    public std::iterator<std::output_iterator_tag, void, void, void, void>
{
    std::basic_ostream<charT, traits>* out_stream;
    cosnt charT* out_stream;
    const CharT* delim;
    
public:
    typedef charT char_type;
    typedef traits traits_type;
    typedef std::basic_ostream<charT, traits> ostream_type;
    my_ostream_iterator(ostream_type& s) : out_stream(&s), delim(0) {}
    my_ostream_iterator(ostream_type& s, const charT* delimiter)
    : out_stream(&s), delim(delimiter) { }
    my_ostream_iterator(const my_ostream_iterator<T, charT, traits>& x)
    : out_stream(x.out_stream), delim(x.delim) {}
    ~my_ostream_iterator() {}
    
    // print pair<string, vector<int>> to std out
    my_ostream_iterator<T, charT, traits>& operator=(const T& value) {
        *out_stream << value.first << ": ";
        for (int i = 0; i != value.second.size(); ++i)
            *out_stream << value.second[i] << delim;
        *out_stream << std::endl;
        return *this;
    }
    
    my_ostream_iterator<T, charT, traits>& operator*() { return *this; }
    my_ostream_iterator<T, charT, traits>& operator++() { return *this; }
    my_ostream_iterator<T, charT, traits>& operator++(int) { return *this; }
};



bool compare_wordcount(std::pair<std::string, int> left, std::pair<std::string, int> right);
std::string::size_type max_key_length(std::map<std::string, std::vector<int> > m);


#endif
