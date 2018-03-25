//
//  datalogProgram.hpp
//  Lab2
//
//  Created by Brandon Derbidge on 2/8/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#ifndef datalogProgram_H_
#define datalogProgram_H_
#pragma once

#include <stdio.h>
#include "Predicate.h"
#include "Rule.h"
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

class datalog{
    
protected:
    
    vector<Predicate>schemesVec;   // Each index is a new scheme.
    vector<Predicate>factsVec;     // Each index is a new Fact
    vector<Predicate>queriesVec;
    vector<Rule>ruleVec;
    int index;
    set<string> factset;
public:
    
    datalog(){
        
        index = 0;
    
    }
    
    void newschemelog(string logdata, Token::tokenType type);
    
    void addToScheme(string logdata, Token::tokenType type);
    
    void newfactlog(string logdata, Token::tokenType type);
    
    void addToFact(string logdata, Token::tokenType type);
    
    void addToFactSet(string logdata);
    
    void newHeadRule(string logdata, Token::tokenType type);
    
    void addToHeadRule(string logdata, Token::tokenType type);
    
    void newPredicateRule(string logdata, Token::tokenType type);
    
    void addToRuleParam(string logdata, Token::tokenType type);
    
    void createQuery(string logdata, Token::tokenType type);
    
    void addToQuery(string logdata, Token::tokenType type);
    
    void createExpression(string expression);
    
    void incrementIndex();
    
    void resetIndex();
    
    void toScheme();
    
    void toRuleString();
    
    void toFactsString();
    
    void toQueryString();
    
    void printDatalog();
    
    void printset();
    
    vector<Predicate> getSchemes(){
        return schemesVec;
    };
    
    vector<Predicate> getFacts(){
        return factsVec;
    };
    
    vector<Predicate> getQueries(){
        return queriesVec;
    };
    
    vector<Rule> getRule(){
        return ruleVec;
    }
};





#endif /* datalogProgram_hpp */
