//
//  Parser.cpp
//  Lab2
//
//  Created by Brandon Derbidge on 1/27/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#include "Parser.h"


Parser::Parser(vector<Token> tokVec){
    tokenVector = tokVec;
    index = 0;
    
    
    
}

void Parser::parse(){
    
    
    try{
        
        datalogProgram();
        
    } catch (Token t) {
        
        cout << "Failure!" << endl; //put the output here
        t.toString();
        
        return;
        
    }
    
   
    
    data.databaseInit(log.getSchemes(), log.getFacts(), log.getQueries(), log.getRule());
    
  
    
}
void Parser::datalogProgram(){
    
    
    tokentracker = Token::SCHEMES;
    match();
    
    logtracker = Token::SCHEMES;
    
    tokentracker = Token::COLON;
    match();
    
    
    scheme();
    
    schemeList();
    
    log.resetIndex();
    
    tokentracker = Token::FACTS;
    match();
    
    logtracker = Token::FACTS;
    
    tokentracker = Token::COLON;
    match();
    
    factList();
    
    log.resetIndex();
    
    tokentracker = Token::RULES;
    match();
    
    tokentracker = Token::COLON;
    match();

    ruleList();
    
    log.resetIndex();
    
    tokentracker = Token::QUERIES;
    match();
    
    logtracker = Token::QUERIES;
    
    tokentracker = Token::COLON;
    match();
    
    query();
    
    queryList();
    
    log.resetIndex();
    
    
}


void Parser::scheme(){
    
    tokentracker = Token::ID;
    match();
    
    log.newschemelog(logdata, tokentracker);
    
    tokentracker = Token::LEFT_PARAN;
    match();
    
    
    tokentracker = Token::ID;
    match();
    
    log.addToScheme(logdata, tokentracker);
    
    idList();
    
    tokentracker = Token::RIGHT_PARAN;
    match();
    
    log.incrementIndex();
}



void Parser::schemeList(){

    if(tokenVector[index].getType() == Token::ID)
    {
        scheme();
    
        schemeList();
    }
    else{
        
        ;
        
    }
    
    
}


void Parser::idList(){
  
    if(tokenVector[index].getType() == Token::COMMA)
    {
        tokentracker = Token::COMMA;
        match();
        
        tokentracker = Token::ID;
        match();
        
   /*Here I need to decide if I"m going to add to the head or the normal*/
        
        
        addtoDatalog();
        
        
        idList();
        
    }
    else
    {
        ; //If it reaches here then we have reached the end of the id list
    }
    
}




void Parser::fact(){
    
    tokentracker = Token::ID;
    match();
    
    log.newfactlog(logdata, tokentracker);
    
    tokentracker = Token::LEFT_PARAN;
    match();
    
    
    tokentracker = Token::STRING;
    match();
    
    addtoDatalog();
    
    log.addToFactSet(logdata);
    
    stringList();
    
    tokentracker = Token::RIGHT_PARAN;
    match();

    tokentracker = Token::PERIOD;
    match();
    
    log.incrementIndex();
    
}
void Parser::factList(){
 
    if(tokenVector[index].getType() == Token::ID){
        
        fact();
    
        factList();
    }
    else{
        
        ;
    }
    
}
void Parser::rule(){
    
    
    headPredicate();
    
    tokentracker = Token::COLON_DASH;
    match();
    
    logtracker = Token::RULES;
    
    predicate();
    
    predicateList();
    
    tokentracker = Token::PERIOD;
    match();
    
    log.incrementIndex();
   
    
}
void Parser::ruleList(){
    
    if(tokenVector[index].getType() == Token::ID){
        
        logtracker = Token::COLON_DASH;
        
        rule();
        
        
        ruleList();
    }
    else{
        
        ;
    }
}
void Parser::headPredicate(){
 
    tokentracker = Token::ID;
    match();
    
    log.newHeadRule(logdata, tokentracker);
    
    tokentracker = Token::LEFT_PARAN;
    match();
    
    tokentracker = Token::ID;
    match();
    
    addtoDatalog();
    
    
    idList();
    
    tokentracker = Token::RIGHT_PARAN;
    match();

    
}
void Parser::predicate(){
  
    
    tokentracker = Token::ID;
    match();
    
    
    if(logtracker == Token::RULES)
    {
        log.newPredicateRule(logdata, tokentracker);
    }
    else if (logtracker == Token::QUERIES)
    {
        log.createQuery(logdata, tokentracker);
    }
    
    tokentracker = Token::LEFT_PARAN;
    match();
    
    paramater();
    
    parameterList();
    
    tokentracker = Token::RIGHT_PARAN;
    match();
    
    
}
void Parser::predicateList(){
    
   // COMMA predicate predicateList | lambda
    
    if(tokenVector[index].getType() == Token::COMMA)
    {
        tokentracker = Token::COMMA;
        match();
        
        predicate();
        
        predicateList();
        
    }
    else
    {
        ; //If it reaches here then e have reached the end of the id list
    }
    
}

void Parser::parameterList(){
    //COMMA parameter parameterList | lambda
    
    if(tokenVector[index].getType() == Token::COMMA)
    {
        tokentracker = Token::COMMA;
        match();
        
        paramater();
        
        parameterList();
        
    }
    else{
        
    }
    
    
}

void Parser::paramater(){
    
    //STRING | ID | expression
    
    if(tokenVector[index].getType() == Token::STRING ){
        
        tokentracker = Token::STRING;
        match();
        
        addtoDatalog();
        
    }
    else if (tokenVector[index].getType() == Token::ID)
    {
        
        tokentracker = Token::ID;
        match();
        
        addtoDatalog();
        
    }
    else{
        
        expression();
        
    }
    
    
}


void Parser::expression(){
    //LEFT_PAREN parameter operator parameter RIGHT_PAREN
    
    express = true;

    
    tokentracker = Token::LEFT_PARAN;
    match();
    
    strExpression += logdata;
    
    paramater();
    
    operatortrack();
    
    //create operator
    
    paramater();
    
    // create right parameter
    
    tokentracker = Token::RIGHT_PARAN;
    match();
    
    strExpression  += logdata;
    
    express = false;
    
    log.createExpression(strExpression);
    
    strExpression = "";
    
}
void Parser::operatortrack(){
    
    if (tokenVector[index].getType() == Token::ADD) {
        
        tokentracker = Token::ADD;
        match();
        
        addtoDatalog();
        
    }
    else if (tokenVector[index].getType() == Token::MULTIPLY)
    {
        
        tokentracker = Token::MULTIPLY;
        match();
        
        addtoDatalog();
        
    }else{
        
        error(tokenVector[index]);
    }
    
}


void Parser::query(){
    
    predicate();
    
    log.incrementIndex();
    
    tokentracker = Token::Q_MARK;
    match();
}



void Parser::queryList(){
    
  //query queryList | lambda
   
    if(tokenVector[index].getType() == Token::ID){
        query();
        
        queryList();
    
    }
    else{
        
        ;
    }
    
}


void Parser::stringList(){
    
    
    
    if(tokenVector[index].getType() == Token::COMMA)
    {
        tokentracker = Token::COMMA;
        match();
        
        tokentracker = Token::STRING;
        match();
        
        addtoDatalog();
        
        log.addToFactSet(logdata);
        
        stringList();
    }
    else
    {
        ; //If it reaches here then e have reached the end of the id list
    }
}



/*This function determines which vector in the datalog class to add to.*/
void Parser::addtoDatalog(){
    
    if(express == true)
    {
        strExpression += logdata;
    }
    else if(logtracker == Token::SCHEMES)
    {
        log.addToScheme(logdata, tokentracker);
    }
    else if(logtracker == Token::FACTS)
    {
        log.addToFact(logdata, tokentracker);
    }
    else if(logtracker == Token::COLON_DASH)
    {
        log.addToHeadRule(logdata, tokentracker);
    }
    else if(logtracker == Token::RULES)
    {
        log.addToRuleParam(logdata, tokentracker);
    }
    else{
        log.addToQuery(logdata, tokentracker);
    }
    
    
}



void Parser::match(){
    
    if ( tokentracker == tokenVector[index].getType()){
        
        logdata = tokenVector[index].getValue();
        index++;
    }
    else{
        
       error(tokenVector[index]);
    }
    
}



void Parser::error(Token t){
    
    throw t;
    
}





