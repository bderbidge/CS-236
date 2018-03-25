//
//  parameter.hpp
//  Lab2
//
//  Created by Brandon Derbidge on 2/8/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#ifndef parameter_H_
#define parameter_H_
#pragma once

#include "Token.h"
#include <string>
using namespace std;


class Parameter{
    
    
private:
    
    string value;
    Token::tokenType type;
    
public:
    
    Parameter(Token::tokenType temp){
        
        type = temp;
        
    }
    
    void add_to_paramater(string par);
    
    Token::tokenType getType();
    
    string toString();
    
    
};

#endif /* parameter_hpp */
