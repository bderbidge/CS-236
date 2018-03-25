//
//  Predicate.cpp
//  Lab2
//
//  Created by Brandon Derbidge on 2/8/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#include "Predicate.h"

void Predicate::predicateInit(string ID, Token::tokenType type){
    
    Parameter param(type);
    
    param.add_to_paramater(ID);
    
    paramVec.push_back(param);
    
    index++;
    
    
}

void Predicate::addParamater(string ID, Token::tokenType type){

    Parameter param(type);
    
    param.add_to_paramater(ID);
    
    paramVec.push_back(param);
    
    index++;
}

void Predicate::createExpression(string expression){
    
    Token::tokenType type = Token::ADD;
    
    Parameter param(type);
   
    param.add_to_paramater(expression);
    
    paramVec.push_back(param);
    
    index++;
    
}


string Predicate::toString(){
   
    string predicate_string;
    
    predicate_string += paramVec[0].toString() + "(";
    
    for (int i = 1; i < paramVec.size(); i++) {
        
        if(i == paramVec.size() - 1 )
        {
            predicate_string += paramVec[i].toString() + ")";
        }
        else{
            
    predicate_string += paramVec[i].toString() + ",";
        
        }
    }
    

    
    return predicate_string;
}





