//
//  graph.cpp
//  lab4
//
//  Created by Brandon Derbidge on 4/7/17.
//  Copyright © 2017 Brandon Derbidge. All rights reserved.
//

#include "graph.h"


void graph::create(int i){
    
    Node newnode;
    newnode.setID(i);
    dismap[i] = newnode;
 
}

void graph::addToMap(int index, int index2){
    
    
    
    if(dismap.count(index) == 0){
        
        Node newnode;
        newnode.setID(index);
        dismap[index] = newnode;
        dismap[index].addToAdjecent(index2);

        
    }else{
        
        dismap[index].addToAdjecent(index2);
        
    }
    
  
    
    
}


void graph::setIdGraph(){
    
    for(int i = 0; dismap.size(); i++){
        dismap[i].setID(i);
    }
}

//dfsForest searches through all the nodes and then if it hasn't been visited call dfs.

stack<int> graph::dfsForsetReverse(){
    
    bool forestForward = false;
    
  
    for(int i = 0; i < dismap.size(); i++){
        
        
        if(dismap.at(i).getvisited() == false){
            
            dfs(i, forestForward);
        }
    }
    return postorder;
}

//dfs checks the neighbors and if they haven't been visited then call itself again using recursion.

void graph::dfs(int i, bool forestForward){
    
    dismap[i].setvisit();
    
    set<int> tempset = dismap[i].getadjacent();
    
   
   
    for (auto f: tempset) {
        
        
        if(dismap[f].getvisited() == false)
        {
            dfs(f, forestForward);
        }
        
       
    }
    
    if(forestForward == false){

       
        postorder.push(i);
    }
    else{
        
        
        SCC.insert(i);
        
        
    }
    
}


void graph::dfsForsetForward(stack <int> mystack){
    
    bool forestForward = true;
    postorder = mystack;
    
    
    /*cout << "Forest" << endl;
    for(int i = 0; i < postorder.size(); i++){
        cout << mystack.top() << endl;
        
    }
    cout << endl;*/
    
    do{
        
        if(postorder.size() > 0){
            
            if(dismap[postorder.top()].getvisited() == false)
            {
                dfs(postorder.top(), forestForward);
                
                setSCC.push_back(SCC);
            }
            
            
        
        
            SCC.clear();
        
            postorder.pop();
        }
        
    }while(postorder.empty() == false);
    forestForward = false;
    
   
}

bool graph::checkDependancy(int j){
    
    bool found = false;
    for(auto f: dismap[j].getadjacent())
    {
        if(j == f){
            found = true;
        }
    }
    
    return found;
}

void graph::printDependant(){
    
    cout <<"Dependency Graph" << endl;
    for (int i = 0; i < dismap.size(); i++) {
        
        cout << "R" << i << ":";
        int size = dismap[i].getadjacent().size();
        int count = 0;
        for ( auto j : dismap[i].getadjacent()) {
            
           
            if(count == size - 1)
                 cout << "R" << j;
            else
                cout << "R" << j << "," ;
            
            count++;
        }
        cout << endl;
        
    }
    cout << endl;
}





