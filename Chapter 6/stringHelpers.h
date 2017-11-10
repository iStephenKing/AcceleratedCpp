#ifndef string_helpers_h
#define string_helpers_h
/*
    main.cpp

    main function for playing with Strings as a container

    Stephen King
    8/21/17
*/

#include <vector>
#include <string>


std::vector<std::string> split(const std::string& s);
std::string::size_type width(const std::vector<std::string>& vec);
std::vector<std::string> frame(const std::vector<std::string>& vec);
std::vector<std::string> frame(const std::vector<std::string>& vec, std::string::size_type frameWidth);
std::vector<std::string> vcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom);
std::vector<std::string> hcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom);


#endif