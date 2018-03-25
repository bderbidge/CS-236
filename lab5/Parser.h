//
//  Parser.hpp
//  Lab2
//
//  Created by Brandon Derbidge on 1/27/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#ifndef Parser_H_
#define Parser_H_

#include <stdio.h>
#include "Scanner.h"
#include <vector>
#include "Token.h"
#include "datalogProgram.h"
#include "database.h"




class Parser{
    
private:
    
    Token::tokenType tokentracker;
    Token::tokenType logtracker;
    vector<Token> tokenVector;
    int index;
    string logdata; //this keeps track of the info I need to put into the datalog class
    datalog log;
    bool express = false;
    string strExpression;
    database data;
    
public:
   
    Parser(vector<Token> tokVec);
    void parse();
    void datalogProgram();
    void scheme();
    void schemeList();
    void idList();
    void fact();
    void factList();
    void rule();
    void ruleList();
    void headPredicate();
    void predicate();
    void predicateList();
    void paramater();
    void parameterList();
    void expression();
    void operatortrack();
    void query();
    void queryList();
    void stringList();
    void match();
    void error(Token t);
    void addtoDatalog();
    
};




#endif /* Parser_hpp */
