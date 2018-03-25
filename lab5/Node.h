//
//  Node.hpp
//  lab4
//
//  Created by Brandon Derbidge on 4/7/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include <set>
#include <iostream>

using namespace std;


class Node{
    
private:
    
    bool visited = false;
    set <int> adjacencyList;
    int id;
    
public:
    
    
    void addToAdjecent(int a){
        
        adjacencyList.insert(a);
        
       /* cout << "this is node " << id << endl;
        for(auto f: adjacencyList){
            
            cout << f << endl;
        }
        cout << endl;*/
    }
    
    bool getvisited(){
        return visited;
    }
    
    void setvisit(){
        
        visited = true;
    }
    
    set<int> getadjacent(){
        
        return adjacencyList;
    }
    
    void setID(int i){
        
        id = i;
    }
    
    int getID(){
        
        return id;
    }
};


#endif /* Node_hpp */
