#include "Node.h"

#include <string>
#include<iostream>
using namespace std;
Node::Node() {
}

Node::Node(Token* token) : leftChild(NULL), rightSibling(NULL) {
    this->value = token->getTokensValue();
}

Node::Node(string _value) : value(_value), leftChild(NULL), rightSibling(NULL) {  }

Node::Node(int _value) : leftChild(NULL), rightSibling(NULL) { 
    this->setValue(_value);
}

Node::Node(vector <Token*>* tokens) : value(""), leftChild(NULL), rightSibling(NULL) {
    
}

Node::Node(const Node& orig){
    this->value = orig.value;
    this->leftChild = orig.leftChild;
    this->rightSibling = orig.rightSibling;
}

// TODO: fix this!
Node::~Node() {
//    if(leftChild != NULL)
//        delete leftChild;
//    if(rightSibling != NULL)
//        delete rightSibling;
//    delete this;
}

void Node::setValue(int _value) {
    ostringstream os; 
    os << _value; 
    this->value = os.str();
}
void Node::setLeftChild(Node* child){
    this->leftChild = child;
}
void Node::setRightSibling(Node* sibling){
    this->rightSibling = sibling;
}
void Node::setNL(bool _printNL) {
    this->printNL = _printNL;
}
Node* Node::getLeftChild(){
    return this->leftChild;
}
Node* Node::getRightSibling(){
    return this->rightSibling;
}
string Node::toString() {
    return toString(0);
}
string Node::toString(int level) {
    string tree;
    if(this->leftChild != NULL)
        tree.append(this->leftChild->toString());
    if(this->value != "") {
        while(level-- > 0) {
            tree.append("\t");
        }
        tree.append(this->value);
    }
    if(this->printNL)
        tree.append("\n");
    if(this->rightSibling != NULL)
        tree.append(this->rightSibling->toString());
    return tree;
}