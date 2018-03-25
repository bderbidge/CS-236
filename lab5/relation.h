//
//  relation.hpp
//  Lab3
//
//  Created by Brandon Derbidge on 3/3/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#ifndef relation_h
#define relation_h

#include <stdio.h>
#include <iostream>
#include <set>
#include "tuple.h"
#include "scheme_relation.h"


using namespace std;

class Relation{
private:
    
    string name = " ";
    
    Scheme_Relation schemes;
    set<Tuple> tuples;
    vector<int> indeces;
    vector<string> schemessorta;
    
public:
    Relation();
    
    friend class database;
    
    void newRelation(string newName);
    Relation select( int index, string value);
    Relation select2( int index, int index2);
    
    void project(vector<int> indeces);
    void rename(vector<string> schemes);
    void addToScheme();
    
    string getName();
    
    bool find(Tuple tuple);
    void print();
    void printTuple(int index);
    void printMultiple();
    
    Relation join(Relation &r1, Relation &r2);
    bool joinable(Scheme_Relation &s1, Scheme_Relation &s2, Tuple &t1, Tuple &t2);
    Tuple join1(Scheme_Relation &s1, Scheme_Relation &s2, Tuple &t1, Tuple &t2);
    Scheme_Relation addSchemeToRule(Scheme_Relation &s1, Scheme_Relation &s2);
    void uniontable(Relation r1, Scheme_Relation scheme);
  
    void union2(Relation r1);
    
    void addtoTuples(Relation r1,  vector<int>tempvec);
};



#endif /* relation_hpp */
