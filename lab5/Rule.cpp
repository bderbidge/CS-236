//
//  Rule.cpp
//  Lab2
//
//  Created by Brandon Derbidge on 2/8/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#include "Rule.h"

void Rule::createHead(string datalog, Token::tokenType type){
    
    Predicate predicate;
    
    predicate.predicateInit(datalog, type);
    
    headPred.push_back(predicate);
    
    
}



void Rule::addToHead(string datalog, Token::tokenType type){
    
    headPred[indexHead].addParamater(datalog, type);
    
}



void Rule::newPredicate(string datalog, Token::tokenType type){
    
    Predicate predicate;
    
    predicate.predicateInit(datalog, type);
    
    pred.push_back(predicate);
    
  
    index++;
}



void Rule::addToPredicate(string datalog, Token::tokenType type){
    
    pred[index].addParamater(datalog, type);
    
}



void Rule::createExpression(string expression){
    
    
    pred[index].createExpression(expression);
    
}

string Rule::toString(){
    
    string rule_stream;
    
    rule_stream += headPred[0].toString() + " :- ";
    

    
    for (int i = 0; i < pred.size(); i++) {
        
        if(i == pred.size() - 1)
        {
            rule_stream +=  pred[i].toString() + ".";
        }
        else{
            
            rule_stream += pred[i].toString() + ",";
            
        }
    }
    
    
    return rule_stream;
}



