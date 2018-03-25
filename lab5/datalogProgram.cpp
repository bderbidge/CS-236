//
//  datalogProgram.cpp
//  Lab2
//
//  Created by Brandon Derbidge on 2/8/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#include "datalogProgram.h"

void datalog::newschemelog(string logdata, Token::tokenType type){
    
    
    Predicate predicate;
    
    predicate.predicateInit(logdata, type);
    
    schemesVec.push_back(predicate);
    
 
    
}

void datalog::addToScheme(string logdata, Token::tokenType type){
    
    schemesVec[index].addParamater(logdata, type);
    
}

void datalog::newfactlog(string logdata, Token::tokenType type){
    
    
    Predicate predicate;
    
    predicate.predicateInit(logdata, type);
    
    factsVec.push_back(predicate);

 
    
}


void datalog::addToFact(string logdata, Token::tokenType type){
    
    factsVec[index].addParamater(logdata, type);
    
    
}

void datalog::addToFactSet(string logdata){
    
    factset.insert(logdata);
}



void datalog::newHeadRule(string logdata, Token::tokenType type){
    
    Rule rule;
    ruleVec.push_back(rule);
    ruleVec[index].createHead(logdata, type);
   
    
 }

void datalog::addToHeadRule(string logdata, Token::tokenType type) {
    
    ruleVec[index].addToHead(logdata, type);
   
    
}

void datalog::newPredicateRule(string logdata, Token::tokenType type){
    
    ruleVec[index].newPredicate(logdata, type);
    
}

void datalog::addToRuleParam(string logdata, Token::tokenType type){
    
    ruleVec[index].addToPredicate(logdata, type);
    
    
}

void datalog::createExpression(string expression){
    
    ruleVec[index].createExpression(expression);
}


void datalog::createQuery(string logdata, Token::tokenType type){
    
    Predicate predicate;
    
    predicate.predicateInit(logdata, type);
    
   queriesVec.push_back(predicate);
    
    
}

void datalog::addToQuery(string logdata, Token::tokenType type){
    
    
    queriesVec[index].addParamater(logdata, type);
}

void datalog::printset(){

    cout << "Domain(" << factset.size() << "):"<< endl;
    for(set<string>::iterator iter=factset.begin(); iter!=factset.end();++iter) {

        cout << "  " <<*iter << endl;
    }
}

void datalog::incrementIndex(){
    
    index++;
}

void datalog::resetIndex(){
    
    index = 0;
    
}

void datalog::toRuleString(){
    
   
    
    for (int i = 0; i < ruleVec.size(); i++) {
    
        cout << "  " << ruleVec[i].toString() << '\n';
    }
    
  
    
}

void datalog::toFactsString(){
    
  
   
    
    for (int i = 0; i < factsVec.size(); i++) {
        
        cout << "  " << factsVec[i].toString() << "." << '\n';
    }
    
    
   
}

void datalog::toScheme(){
    
  
    
   // cout << "THIS IS THE SIZE " << schemesVec.size() << endl;
  
    
    for (int i = 0; i < schemesVec.size(); i++) {
        
        
        cout << "  " << schemesVec[i].toString() << '\n';
    }
 
    
    
}

void datalog::toQueryString(){
    
    
    for (int i = 0; i < queriesVec.size(); i++) {
        
        cout << "  " << queriesVec[i].toString()<< "?" << '\n';
    }
    
    
    
   
   
}

void datalog::printDatalog(){
    
    
    cout << "Schemes(" << schemesVec.size() << "):"<< endl;
    toScheme();
    cout << "Facts(" << factsVec.size()<< "):" << endl;
    toFactsString();
    cout << "Rules(" << ruleVec.size() << "):" << endl;
    toRuleString();
    cout << "Queries(" << queriesVec.size() << "):" << endl;
    toQueryString();
 }












