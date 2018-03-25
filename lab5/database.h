//
//  database.hpp
//  Lab3
//
//  Created by Brandon Derbidge on 3/3/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#ifndef database_h
#define database_h

#include <stdio.h>
#include <map>
#include "relation.h"
#include <iostream>
#include "datalogProgram.h"
#include "Predicate.h"
#include "graph.h"



class database{

private:
    
    map<string, Relation> relationsmap;
    vector<Predicate> schemesVec;
    vector<Predicate> factsVec;
    vector<Predicate> queriesVec;
    vector<Rule> ruleVec;
    vector<string> renamevec;
    vector<int> projectvec;
    graph forwardGraph;
    graph reverseGraph;
    
    int numpasses = 0;
    
public:
    
    friend class Predicate;
    
    
    database();
   
    
    void databaseInit(vector<Predicate> sche, vector<Predicate> fact, vector<Predicate> querie, vector<Rule> rulev);
    
    void createSchemes(Predicate schvec );
    
    void addTuples(Predicate facts);
    
    void addFacts();
    
    void query();
    
    Relation parse(Predicate pred, Relation relate, bool ruledata);
    
    void evaluateRules(set<int> ruleset );
    
    Relation find(int index, int i, string param, Relation relate);
   
   bool queryTheRules(vector <Predicate> &rule_param, vector <Predicate> &head_param);
    
    Relation startJoin(vector<Relation> &joinrule);
    
    bool fixedPoint(Relation relate, Relation headrelate);
    
    void find2(string param, int index );
    
    void createGraph();
    
    void printMultipleSets(set<int> myset);
    
    void graphRules();
};

#endif /* database_hpp */
