//
//  graph.hpp
//  lab4
//
//  Created by Brandon Derbidge on 4/7/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>
#include <map>
#include "Node.h"
#include <stack>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class graph{
   
private:
    map<int, Node> dismap;
    stack<int> postorder;
    set<int> SCC;
    
   
    
public:
    vector <set<int>> setSCC;
    
    void create(int i);
    
    void addToMap(int index, int index2);
  
    stack<int> dfsForsetReverse();
    
    void dfs(int i , bool forestForward);
    
    void dfsForsetForward(stack<int> mystack);
    
    vector<set<int>> getSCC(){
        
        return setSCC;
    }
    
    void setIdGraph();
    
    bool checkDependancy(int j);
    
    void printDependant();
};

#endif /* graph_hpp */
