//
//  HelloWorld.cpp
//  
//
//  Created by Stephen King on 9/10/14.
//
//

#include "HelloWorld.h"

int main()
{
    //std::cout<<"Hello, World!"<<std::endl;
    
    //Ask for a persons name
    std::cout << "Please enter your first name: ";
    
    //read the name
    std::string name;  //define name
    std::cin >> name;  //read stadard input to name;
    
    //Write greeting to user
    std::cout << "Hello, " << name << "!" << std::endl;
    
    return 0;
}
