//
//  Predicate.hpp
//  Lab2
//
//  Created by Brandon Derbidge on 2/8/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#ifndef Predicate_H_
#define Predicate_H_
#pragma once
#include <stdio.h>
#include "parameter.h"
#include <vector>


using namespace std;



class Predicate{
    
private:
    
    int index;
    
public:
    
    vector<Parameter>paramVec; // the first spot is the name of the scheme. The following indexes are the paramaters
    
    Predicate(){
        index = 0;
       
        
    };
    
    void predicateInit(string ID,Token::tokenType type);
    
    void addParamater(string ID, Token::tokenType type);
    
    void createExpression(string expression);
    
    string toString();
    
    string getName(){
    
        return paramVec[0].toString();
    };
    
};

#endif /* Predicate_hpp */
