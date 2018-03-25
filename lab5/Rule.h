//
//  Rule.hpp
//  Lab2
//
//  Created by Brandon Derbidge on 2/8/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#ifndef Rule_H_
#define Rule_H_
#pragma once
#include <stdio.h>
#include "Predicate.h"
#include <sstream>


class Rule{
    
    
private:
    vector<Predicate> headPred;
    vector<Predicate> pred;
   
    int index;
    int indexHead;
    
public:
    
    friend class Rule;
    
    Rule(){
        
        index = -1;
        indexHead = 0;
    };
    
    void createHead(string datalog, Token::tokenType type);
    
    void addToHead(string datalog, Token::tokenType type);
    
    void newPredicate(string datalog, Token::tokenType type);
    
    void addToPredicate(string datalog, Token::tokenType type);
    
    void createExpression(string expression);
    
    string toString();
    
    vector<Predicate> getVector(){
        
        return pred;
    }
    
    vector<Predicate> getHeadVec(){
        return headPred;
    }
    
    string getHead(){
        
     return headPred[0].paramVec[0].toString();
        
    }
    
};

#endif /* Rule_hpp */
