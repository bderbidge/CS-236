//
//  relation.cpp
//  Lab3
//
//  Created by Brandon Derbidge on 3/3/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#include "relation.h"

Relation::Relation(){
    
}

void Relation::newRelation(string newName){
    
    name = newName;
    
};

string Relation::getName(){
    
    return name;
    
}

Relation Relation::select( int index, string value){
    
    Relation r;
    r.schemes = schemes;
    
    r.newRelation(name);
    
    for(auto f : tuples) {
            
        if(f[index] == value){
            
            r.tuples.insert(f);
            
        }
        
        
    }
        
    return r;
}

Relation Relation::select2(int index, int index2){
    
    Relation r;
    r.newRelation(name);
    r.schemes = schemes;
    
    
    
    for(auto f : tuples) {
        
        
        if(f[index] == f[index2]){
            
            r.tuples.insert(f);
            
        }
        
        
    }
    
    return r;
}

void Relation::uniontable(Relation r1, Scheme_Relation scheme){
    
    schemes = scheme;
    vector<int>tempvec;
    
    
    for(int i = 0; i < schemes.size(); i++){
        
        for(int j = 0; j <  r1.schemessorta.size(); j++){
            
            if(r1.schemessorta[j] == schemes[i]){
                tempvec.push_back(r1.indeces[j]);
                
            }
        }
    }

    addtoTuples(r1, tempvec);
    
}

void Relation::addtoTuples(Relation r1, vector<int>tempvec){
    
    
    for(auto tuple: r1.tuples){
        Tuple temptup;
        for(int i = 0; i < tempvec.size(); i++){
            
            temptup.push_back(tuple[tempvec[i]]);
        }
        tuples.insert(temptup);
    }
    
}

void Relation::project(vector<int> indeces){
    
    this->indeces = indeces;
    
}

void Relation::rename(vector<string> schemes){
    
    schemessorta = schemes;
    
    for(int i = 0; i < indeces.size(); i++){
    
        
        
        this->schemes[indeces[i]] = schemes[i];
        
    }
        
    
}

void Relation::print(){
    

    
    if( tuples.size() == 0)
        cout << "No" << endl;
    else
        cout << "Yes(" << tuples.size() << ")" << endl;
    
    
    if (indeces.size() >= 1)
    {
        if(schemessorta.size() > 1){
        
            printMultiple();
            
        }else{
        
            printTuple(0);
        }
    }
    

    
}

void Relation::printTuple(int index){
 
    
    for(auto f: tuples){
        
        for( int i = 0; i < indeces.size(); i ++ ){
            cout<< "  " << schemessorta[index] << "=" << f[indeces[i]] << endl;
        }
    }
}

void Relation::printMultiple(){
    
    for(auto f: tuples){
        cout << "  ";
        for( int i = 0; i < schemessorta.size(); i++)
        {
            if( i + 1 == schemessorta.size())
                cout << schemessorta[i] << "=" << f[indeces[i]];
            else
                cout << schemessorta[i] << "=" << f[indeces[i]] << ", ";
        }
        cout << endl;
    }
    
}

Relation Relation::join(Relation &r1, Relation &r2)
{
    
    
    Relation relate;
    Scheme_Relation newscheme;
    Tuple t3;
    
    newscheme = r1.schemes;
    
    newscheme = addSchemeToRule(r2.schemes, newscheme);
    
    relate.schemes = newscheme;
    
    
    for( auto t1: r1.tuples)
    {
        
        for( auto t2: r2.tuples)
        {
            if (joinable(r1.schemes, r2.schemes, t1, t2) == true)
            {
                t3 = join1(r1.schemes, r2.schemes, t1, t2);
                
               
                relate.tuples.insert(t3);
            }
        }
    }
    
    return relate;
    
}


Scheme_Relation Relation::addSchemeToRule(Scheme_Relation &s1, Scheme_Relation &s2){
    

    
    for( int i = 0; i < s1.size(); i++)
    {
        
        bool duplicate = false;
        
        for(int j =0; j < s2.size(); j++)
            
        {
            
            if(s1[i] == s2[j])
            {
                duplicate = true;
            }
        }
        if(duplicate == false){
            
            s2.push_back(s1[i]);
        }
    }
    
    return s2;
}

bool Relation::joinable(Scheme_Relation &s1, Scheme_Relation &s2, Tuple &t1, Tuple &t2){
    
    for( int i = 0; i < s1.size(); i++){
        
        for(int j = 0; j < s2.size(); j++){
            
            if((s1[i] == s2[j]) && (t1[i] != t2[j]))
            {
                
                return false;
            }
        }
        
    }
    
    return true;
}


Tuple Relation::join1(Scheme_Relation &s1, Scheme_Relation &s2,Tuple &t1, Tuple &t2){
    
    Tuple t3;
    
    t3 = t1;
    for( int i = 0; i < s2.size(); i++)
    {
        bool duplicate = false;

        for(int j = 0; j < s1.size(); j++)
        {
            if (s2[i] == s1[j])
            {
                duplicate = true;
            }
        }
        
        if(duplicate == false){
            
            t3.push_back(t2[i]);
            
        }
    }
    
    
    
    return t3;
}


void Relation::union2(Relation r1)
{
    for(auto f: r1.tuples){
        
        tuples.insert(f);
    
    }
    
}









