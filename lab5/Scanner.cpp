//
//  Scanner.cpp
//  CS236Lab1
//
//  Created by Brandon Derbidge on 1/17/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#include "Scanner.h"


/*The Scanner function looks at all the characters and creates on an object based on the character or list of characters passed into the scanner. */
vector<Token> Scanner::importFile(){
    
    char my_character;
    Token::tokenType toktype;
    
    my_character = myfile.get();
    
    while(!myfile.eof())
    {
        
        if(my_character == '\n')
        {
            lineNumber++;
        }
        else if(isspace(my_character) == false)
        {
           
        
        switch (my_character) {
        
            case ',':
                toktype = Token::COMMA;
                createToken( my_character, toktype);
                break;
            case '.' :
                toktype = Token::PERIOD;
                createToken( my_character, toktype);
                break;
            case '?' :
                toktype = Token::Q_MARK;
                createToken( my_character, toktype);
                break;
            case '(' :
                toktype = Token::LEFT_PARAN;
                createToken( my_character,  toktype);
                break;
            case ')' :
                toktype = Token::RIGHT_PARAN;
                createToken( my_character,  toktype);
                break;
            case '*' :
                toktype = Token::MULTIPLY;
                createToken( my_character, toktype);
                break;
            case '+' :
                toktype = Token::ADD;
                createToken( my_character,  toktype);
                break;
            case '\'' :
                checkString(my_character);
                break;
            case ':' :
                checkColon();
                break;
            case '#' :
                checkComment(my_character);
            
                break;
            default:
               
                if(isalpha(my_character)){
                    scanId(my_character);
                    break;
                }
                else
                {
                
                    toktype = Token::UNDEFINED;
                    createToken( my_character, toktype);
                    break;
                }
        }
            
        
        }
        
        myfile.get(my_character);
    }
    
    
    toktype = Token::EOFTOK;
    
    int line = lineNumber;
    
    
    
    Token mytoken = Token("", line, toktype);
    //mytoken.toString();
    tokenvector.push_back(mytoken);
    
    total_tokens++;
    
    //cout << "Total Tokens = " << total_tokens << endl;
    
    myfile.close();
    
    return tokenvector;
    
}





void Scanner::checkComment(char my_character){
    
    string comment;
    Token::tokenType toktype = Token::COMMENT;
    char charPeek;
   
    
    charPeek = myfile.peek();
    
    if( charPeek == '|')
    {
        //call a function to check the comment
        multipleComment(my_character);
        
    }
    else{
    
        
        while (my_character != '\n') {
            comment += my_character;
            myfile.get(my_character);
        }
        lineNumber++;
       //  createStringToken(comment, commentLine, toktype); The Scanner skips over the comment
        
    }
            
    
    
}


void Scanner::multipleComment(char my_character)
{
    string comment;
    char charPeek;
    Token::tokenType tokcom;
    int comline = lineNumber;

    comment += my_character;
    myfile.get(my_character);
    comment += my_character;
    myfile.get(my_character);
    
    while(myfile.eof() == false)
    {
        
        switch (my_character) {
            case '|':
                charPeek = myfile.peek();
                
                    if( charPeek == '#')
                    {
                        comment +=my_character;
                         myfile.get(my_character);
                        comment += my_character;
                        
                        //create new token
                        tokcom = Token::COMMENT;
                        // createStringToken(comment, comline, tokcom); The Scanner skips over the comment
                        
                        return;
                    }
                    else
                    {
                    
                        comment += my_character;
                    }
                
                break;
                
            case'\n':

                comment += my_character;
                lineNumber++;
                break;
                
            default:
                comment += my_character;
                break;
                
            
        }
        
        myfile.get(my_character);
        
    }
    tokcom = Token::UNDEFINED;
    
    createStringToken(comment, comline, tokcom);
    
   
    
}



/* This function determines whether the characters passed in are an id scheme, fact, rule, or query or undefined*/
void Scanner::scanId(char my_character){
    
    string id;
    Token::tokenType tokenid = Token::ID;
    int idLine = lineNumber;
    char charPeek;
    
    id =+ my_character;
    charPeek = myfile.peek();
    
    while(isdigit(charPeek) || isalpha(charPeek))
    {
        myfile.get(my_character);
        
        //undefined if it's neither a digit or a character it's undefined
        id += my_character;
        
        charPeek = myfile.peek();
        
    }
    
    
  //  map<string, Token::tokenType> idMap = {{"Schemes", Token::SCHEMES},{"Facts", Token::FACTS}, {"Rules", Token::RULES}, {"Queries", Token::QUERIES}};
    
   if(id == "Schemes")
   {
       tokenid = Token::SCHEMES;
   }
   else if(id == "Rules")
   {
       tokenid = Token::RULES;
   }
   else if(id == "Facts")
   {
       tokenid = Token::FACTS;
   }
   else if(id == "Queries")
   {
        tokenid = Token::QUERIES;
   }
    
    //tokenid = idMap.at(id);
    
    createStringToken(id, idLine, tokenid);
    
}


void Scanner::createStringToken(string characters, int line, Token::tokenType toktype)
{
    
    Token mytoken = Token(characters, line, toktype);
//    mytoken.toString();
    tokenvector.push_back(mytoken);
    total_tokens++;
    
}

/*This function creates a new token object.*/
void Scanner::createToken(char my_character, Token::tokenType toktype)
{
    stringstream ss;
    string tokenstring;
    
    ss << my_character;
    ss >> tokenstring;
    
    int line = lineNumber;
    
    
    Token mytoken = Token(tokenstring, line, toktype);
    tokenvector.push_back(mytoken);
    total_tokens++;
    //mytoken.toString();
}


/*This is a function that parses through a string until it hits an end quote unless the end quote is next to anothe end quote*/

void Scanner::checkString(char my_character)
{
    Token::tokenType toktype = Token::STRING;
    char charPeek;
    int line = lineNumber;
    string quotetext;
    
    quotetext +=  my_character;
    myfile.get(my_character);
    
    while (myfile.eof() == false) {
        
        
        if(my_character == '\n')
        {
            quotetext += my_character;
            lineNumber++;
        }
        else if(my_character == '\'')
        {
           charPeek = myfile.peek();
            
            if(charPeek != '\'')
            {
                quotetext += my_character;
                createStringToken(quotetext, line, toktype);
                return;
            }
            
            quotetext += my_character;
            myfile.get(my_character);
            quotetext += my_character;
            
        }
        else
        {
            
            quotetext+= my_character;
	  
        }
        myfile.get(my_character);
    }
    
    toktype = Token::UNDEFINED;
    createStringToken(quotetext, line, toktype);
    
}




void Scanner::checkColon(){
    
    Token::tokenType toktype;
    string colondash = ":-";
    char my_charachter = ':';
    
    char charPeek = myfile.peek();
    
    if(charPeek == '-')
    {
        myfile.get(my_charachter);
        toktype = Token::COLON_DASH;
        
        createStringToken(colondash, lineNumber, toktype);
        
        return;
        
    }
    else{
        toktype = Token::COLON;
        
        createToken(my_charachter, toktype);
        
        return;
        
    }

}



