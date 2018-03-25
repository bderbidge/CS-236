//
//  parameter.cpp
//  Lab2
//
//  Created by Brandon Derbidge on 2/8/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#include "parameter.h"

void Parameter::add_to_paramater(string par){
    
    value = par;
    
}

string Parameter::toString(){
    
    return value;
}

Token::tokenType Parameter::getType(){
    
    return type;
}


