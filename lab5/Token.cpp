//
//  Token.cpp
//  CS236Lab1
//
//  Created by Brandon Derbidge on 1/17/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//


#include "Token.h"

Token::Token( string val, int line, tokenType tok){
    
    value = val;
    lineNumber = line;
    kind = tok;
}

int Token::getLine(){
    
    return lineNumber;
}

string Token::getToken(){
    
    map<tokenType, string> tokenMap = {{COMMA, "COMMA" }, {PERIOD, "PERIOD"} ,{Q_MARK, "Q_MARK"}, {LEFT_PARAN, "LEFT_PAREN"}, {RIGHT_PARAN, "RIGHT_PAREN"}, {COLON, "COLON"}, {COLON_DASH, "COLON_DASH"}, {MULTIPLY, "MULTIPLY"}, {ADD, "ADD"}, {SCHEMES, "SCHEMES"}, {FACTS,"FACTS"}, {RULES, "RULES"}, {QUERIES, "QUERIES"}, {ID, "ID"}, {STRING, "STRING"}, {COMMENT, "COMMENT"}, {WHITESPACE,"WHITESPACE"}, { UNDEFINED, "UNDEFINED"}, {EOFTOK,"EOF"}};
    
    string tokkind = tokenMap.at(kind);
    return tokkind;
}

string Token::getValue(){
    
    return value;
}

void Token::toString(){
    
    stringstream ss;
    string output;
    
    cout << "(" << getToken() << "," << "\"" << getValue() << "\"" << "," << getLine() << ")" << endl;
    
    
}

Token::tokenType Token::getType(){
    
    return kind;
}






