//
//  database.cpp
//  Lab3
//
//  Created by Brandon Derbidge on 3/3/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#include "database.h"

database::database(){
    schemesVec;
    factsVec;
    queriesVec;
    ruleVec;
}

void database::databaseInit(vector<Predicate> sche, vector<Predicate> fact, vector<Predicate> querie, vector<Rule> rulev){
    
    
    schemesVec = sche;
    factsVec = fact;
    queriesVec = querie;
    ruleVec = rulev;
    string name;
    
    
    for ( int i = 0; i < schemesVec.size(); i++) {
        
        createSchemes(schemesVec[i]);
        
        }
    
    
    
    addFacts();
    
    createGraph();
    stack<int> tempstack;
    
    tempstack = reverseGraph.dfsForsetReverse();
    
    forwardGraph.dfsForsetForward(tempstack);
    
    forwardGraph.printDependant();
    
    cout << "Rule Evaluation" << endl;
    graphRules();
    
    cout << "Query Evaluation" << endl;
    query();
    
 
}

void database::graphRules(){
    
    int size = forwardGraph.setSCC.size();
    
    
    for(int i = 0; i < size; i++) {
        
        set<int>::iterator it = forwardGraph.setSCC[i].begin();
        numpasses = 0;
        // check the size of the set
        vector<Predicate> tempvec;
        vector<Predicate> headvec;
        
        
        if(forwardGraph.setSCC[i].size() > 1){
            numpasses++;
            evaluateRules( forwardGraph.setSCC[i]);
            cout << numpasses;
            cout <<" passes: ";
            
            printMultipleSets(forwardGraph.setSCC[i]);
            
           
        }
        else
        {
           
            bool fixed = false;

            fixed = forwardGraph.checkDependancy(*it);
            
            if(fixed == true){
             
               
                evaluateRules(forwardGraph.setSCC[i]);
                
                
                    numpasses++;
                    cout << numpasses;
                    cout <<" passes: R" <<  *it << endl; ;
            
                
            }
            else
            {
               
                tempvec = ruleVec[*it].getVector();
                headvec = ruleVec[*it].getHeadVec();
                
                queryTheRules(tempvec, headvec);
                //evaluateRules(forwardGraph.setSCC[i]);
                numpasses++;
                cout << numpasses;
                cout <<" passes: R" <<  *it << endl; ;
            }
  
        }
        
    }
    cout << endl;
    
}

void database::printMultipleSets(set<int> myset){
    
    int size = myset.size();
    int count = 0;
    
    for(auto f: myset){
        
        if(count == size - 1)
            cout << "R" << f;
        else
            cout << "R" << f << "," ;
        
        count++;
    }
    cout << endl;
    
}


void database::evaluateRules(set<int> ruleset){
    
    
    
    Rule rule;
    vector<Predicate> tempvec;
    vector<Predicate> headvec;
    
    bool returned = false;
    
    for(auto f: ruleset){
        
        
        tempvec = ruleVec[f].getVector();
        headvec = ruleVec[f].getHeadVec();
        if( queryTheRules(tempvec, headvec) == true)
            returned = true;
        
    }
    
    if(returned == true){
        numpasses++;
        evaluateRules(ruleset);
        
    }
    
    
    
}



void database::createGraph(){
    
    vector<Predicate> tempvec;
    vector<Predicate> headvec;
    
    
    
    for(int i = 0; i <ruleVec.size(); i++){
        
        forwardGraph.create(i);
        reverseGraph.create(i);
        
        for(int j = 0; j < ruleVec[i].getVector().size(); j++){
            
            for(int k = 0; k < ruleVec.size(); k++){
                
                if(ruleVec[k].getHead() == ruleVec[i].getVector()[j].getName()){
                    
                    forwardGraph.addToMap(i, k);
                    reverseGraph.addToMap(k, i);
                
                }
                else if(ruleVec.size() == 1)
                {
                    
                    reverseGraph.addToMap(k, i);
                }
                
            }
            
        }
        
    }
   
}


bool database::queryTheRules(vector <Predicate> &rule_param, vector <Predicate> &head_param){
    
    bool querey = false;
    
    Relation relate, headrelate;
    
    vector<Relation> tempRelate;
    
    
    for(int i = 0; i < rule_param.size(); i++){
        
        relate = relationsmap.at(rule_param[i].getName());
        
       relate = parse(rule_param[i], relate, querey);
        
        tempRelate.push_back(relate);
        
    }
    
    
    
    
    
    relate = startJoin(tempRelate);
    
    
    
    Scheme_Relation schemetemp;
    
    for( int i = 1; i < head_param[0].paramVec.size(); i++){
     
       schemetemp.push_back(head_param[0].paramVec[i].toString());
        
    }
    
    
    
    headrelate.newRelation(head_param[0].paramVec[0].toString());
    
    headrelate.uniontable(relate, schemetemp);
    
   return fixedPoint(relate, headrelate);
    

    
}

bool database::fixedPoint(Relation relate, Relation headrelate){
    
    
    int beginSize = relationsmap.at(headrelate.getName()).tuples.size();

    
    relationsmap.at(headrelate.getName()).union2(headrelate);
    
    
    renamevec.clear();
    projectvec.clear();
    int endSize = relationsmap.at(headrelate.getName()).tuples.size();
    
    renamevec.clear();
    projectvec.clear();
    
    if(beginSize != endSize)
        return true;
    else
        return false;
    
}

Relation database::startJoin(vector<Relation> &joinrule){
    
    Relation relate;
    
    relate = joinrule[0];
    
  
    
    
    if(joinrule.size() >1){
       
        for(int i = 1; i < joinrule.size(); i++){
        
            relate = relate.join(relate, joinrule[i]);
        
        }

    }
    
    for(int i = 0; i < relate.schemes.size(); i++){
        
        find2(relate.schemes[i], i);
        
    }
    
    relate.project(projectvec);
    relate.rename(renamevec);
    
  
    
    return relate;
}

void database::find2(string param, int index){
    
    
    bool radified = false;
    
    for(int j = 0; j < renamevec.size(); j++)
    {
        
        if(param == renamevec[j])
        {
            radified = true;
        }
        
    }
    
    if(radified == false){
        renamevec.push_back(param);
        projectvec.push_back(index);
    }
    
}

void database::createSchemes(Predicate schvec){
    
    string name;
    string schemestr;

    
    Relation relate;
    Scheme_Relation scheme;
    
    name = schvec.getName();
    
    relate.newRelation(name);
    
    for (int j = 1; j < schvec.paramVec.size(); j++) {
        
        schemestr = schvec.paramVec[j].toString();
        
        scheme.push_back(schemestr);
        
    }
    
    relate.schemes = scheme;
    
    relationsmap[name] = relate;
    
    
}

void database::addFacts(){
    
    
    for ( int i = 0; i < factsVec.size(); i++) {
        
        addTuples(factsVec[i]);
        
    }

    
    
}


void database::addTuples(Predicate facts){
    
    string name;
    string factstr;
    
    Tuple tuple;
    

    for (int j = 1; j < facts.paramVec.size(); j++) {
        
        factstr = facts.paramVec[j].toString();
                tuple.push_back(factstr);
        
    }

    
    name = facts.getName();
    
    relationsmap.find(name)->second.tuples.insert(tuple);
    
}



void database::query(){
    
    bool querey = true;
    
    Relation relate;
    
    //cout << "Schemes populated after "<< numpasses << " passes through the Rules." << endl;

    
    for(int i = 0; i < queriesVec.size(); i++){
        
        relate = relationsmap.at(queriesVec[i].getName());
        
        parse(queriesVec[i], relate, querey);
        
        
    }
    
    
}


Relation database::parse(Predicate pred, Relation relate, bool quereydata){
    
    
    int index;
    
    
    for(int i= 1; i < pred.paramVec.size(); i++)
    {
        
        
        index = i -1;
        
        if( pred.paramVec[i].getType() == Token::STRING )
        {
            relate = relate.select(index, pred.paramVec[i].toString());
            
        }
        else if(pred.paramVec[i].getType() == Token::ID)
        {
            
            relate = find(index, i, pred.paramVec[i].toString(), relate);
            
        }
        
        
    }
    
    relate.project(projectvec);
    relate.rename(renamevec);
    
   if(quereydata)
    {
             cout << pred.toString() << "? ";
        relate.print();
    }
    renamevec.clear();
    projectvec.clear();
    
    return relate;
}



Relation database::find(int index, int i, string param, Relation relate){
    
    bool radified = false;
    
    for(int j = 0; j < renamevec.size(); j++)
    {
        
        if(param == renamevec[j])
        {
            relate = relate.select2(index, projectvec[j]);
            radified = true;
        }
        
    }
    //relate = find(i, pred, relate);
    if(radified == false){
        renamevec.push_back(param);
        projectvec.push_back(index);
    }
    
    return relate;
}




