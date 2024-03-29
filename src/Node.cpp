#include "../include/Node.h"
using namespace std;

Node::Node(int nodeName, bool endState) {
    this->nodeName = nodeName;
    this->endState = endState;
}

Node::~Node()
{
    //dtor
}
int Node::getName(){
    return nodeName;
}
void Node::setName(int nodeName) {
    this->nodeName =nodeName;
}
bool Node::isEndState(){
    return endState;
}
void Node::setEndState(bool endState) {
    this->endState = endState;
}
void Node::addEdge(Edge* edge){
 this->edges.push_back(edge);
}

vector<Edge *>Node::getAllEdges(){
    return this->edges;
}
void Node::setPriority(int priority){
    this->priority = priority;
}
int Node::getPriority(){
    return priority;
}

string Node::getTokenName() {
    return tokenName;
}
void Node::setTokenName(string tokenName) {
    Node::tokenName = tokenName;
}
