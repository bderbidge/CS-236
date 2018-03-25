//
//  Expression.hpp
//  Lab2
//
//  Created by Brandon Derbidge on 2/8/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#ifndef Expression_H_
#define Expression_H_

#include <stdio.h>
#include "parameter.h"


#endif /* Expression_hpp */

class Expression : public Parameter {
    
    
private:
    
    string right_param;
    string left_param;
    string the_operator;
    Token::tokenType type;
    
    
public:
    
    Expression(Token::tokenType temp):Parameter(Token::tokenType(temp) ){
        
        
        type = temp;
        
    }
    
    
};
