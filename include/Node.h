#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <bits/stdc++.h>
#include "../include/DFA.h"

using namespace std;

class Edge;
class Node
{
    public:
        Node(int nodeName, bool endState);
        virtual ~Node();
        int getName();
        void setName(int stateName);
        bool isEndState();
        void setEndState(bool acceptingState);
        void addEdge(Edge* edge);
       // string getDestination(char c);
        string getTokenName();
        void setTokenName(string tokenName);
        vector<Edge*> getAllEdges();
        void setPriority(int priority);
        int getPriority();
        bool marked = false;
        vector<Node *> NNodes;

    protected:

    private:
        vector<Edge*>edges;
        int nodeName;
        bool endState;
        string tokenName;
        int priority;

};

#endif // NODE_H

