//
//  main.cpp
//  CS236Lab1
//
//  Created by Brandon Derbidge on 1/17/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//
#include "Scanner.h"
#include "Token.h"
#include "Parser.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
   
    vector<Token> tokenVector;
    
    Scanner Scan(argv[1]);
    tokenVector = Scan.importFile();
    
    Parser Parser(tokenVector);
    Parser.parse();
    
    return 0;
}
