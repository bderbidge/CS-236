//
//  Token.hpp
//  CS236Lab1
//
//  Created by Brandon Derbidge on 1/17/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#ifndef Token_H
#define Token_H

#include <iostream>
#include <map>
#include <stdio.h>
#include <sstream>
#include <cctype>
#include <string>


using namespace std;

class Token
{
public:
    
    enum tokenType { COMMA, PERIOD, Q_MARK, LEFT_PARAN, RIGHT_PARAN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, WHITESPACE, UNDEFINED, EOFTOK };

    Token( string val, int line, tokenType tok);
   
    string getValue();
    
    int getLine();
    
    string getToken();
    
    void toString();
    
    tokenType getType();
    
    
private:
    string value;
    int lineNumber;
    tokenType kind;
    
    
};
#endif /* Token_hpp */
