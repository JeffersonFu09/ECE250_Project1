#include <iostream>
#include "Node.hpp"

//Getters and setters
Node::Node (string name, double val){
    this->name = name;
    this->val = val;
    this->next = nullptr;
}
void Node::setName(string name){
    this->name= name;
}
void Node::setVal(double val){
    this->val = val;
}
void Node::setNext(Node * next){
    this->next = next;
}
string Node::getName(){
    return name;
}
double Node::getVal(){
    return val;
}
Node * Node::getNext(){
    return next;
} 
Node::~Node(){
}