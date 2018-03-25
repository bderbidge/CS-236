//
//  Scanner.hpp
//  CS236Lab1
//
//  Created by Brandon Derbidge on 1/17/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#ifndef Scanner_H
#define Scanner_H

#include "Token.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <ctype.h>
#include "Parser.h"

using namespace std;

class Scanner{
    
protected:
 
    int total_tokens;
    vector<Token> tokenvector;
    ifstream myfile;
    int lineNumber;
    
    
public:
    
    Scanner(string filename){
        
        myfile.open(filename.c_str());
        total_tokens = 0;
        lineNumber = 1;
    }
 
    
    vector<Token> importFile();
    
    void createToken(char my_character, Token::tokenType toktype);
    
    void checkString(char my_character);
    
    void checkColon();
    
    void scanId(char my_character);
    
    void checkComment(char my_character);
    
    void multipleComment(char my_character);
    
    void createStringToken(string characters, int line, Token::tokenType toktype);
};


#endif /* Scanner_hpp */
