#include "DatalogProgram.h"
#include <iostream>
using namespace std;
DatalogProgram::DatalogProgram(){    
}

DatalogProgram::DatalogProgram(TokensReader& tokenReader) {
    Node* start = readSchemes(tokenReader);
    start = readFacts(tokenReader, start);
    start = readRules(tokenReader, start);
    start = readQueries(tokenReader, start);
}



DatalogProgram::DatalogProgram(const DatalogProgram& orig) {
}

DatalogProgram::~DatalogProgram() {
}

Node* DatalogProgram::readSchemes(TokensReader& tokenReader) {
    Node* iter = NULL;
    if(tokenReader.getCurrent()->getTokenType() == SCHEMES){
        // set child to new Node Scheme
        Node * schemeNode = new Node(tokenReader.getCurrent());
        this->setLeftChild(schemeNode);
        if(tokenReader.getNext()->getTokenType() == COLON) {
            Node * colonNode = new Node(tokenReader.getCurrent());
            colonNode->setNL(true);
            SchemesList* schemeList = new SchemesList(tokenReader);
            colonNode->setRightSibling(schemeList);
            iter = schemeList;
            
            Node* tail;
            Node* size = generateListSize(SchemesList::getSize(), tail);
            schemeNode->setRightSibling(size);
            tail->setRightSibling(colonNode);
        } else {
            throw ParsingException(tokenReader.getCurrent());
        }
    } else {
        throw ParsingException(tokenReader.getCurrent());
    }
    return iter;
}
Node* DatalogProgram::readFacts(TokensReader& tokenReader, Node* start) {
    Node* iter = start;
    if(tokenReader.getCurrent()->getTokenType() == FACTS) {
        Node* fact = new Node(tokenReader.getCurrent());
        start->setRightSibling(fact);
        
        if(tokenReader.getNext()->getTokenType() == COLON) {
            Node* colon = new Node(tokenReader.getCurrent());
            colon->setNL(true);
            FactList* facts = new FactList(tokenReader);
            colon->setRightSibling(facts);
            
            Node* tail;
            Node* size = generateListSize(FactList::getSize(), tail);
            tail->setRightSibling(colon);
            fact->setRightSibling(size);
            
            iter = facts;
        } else {
            throw ParsingException(tokenReader.getCurrent());
        }
    } else {
        throw ParsingException(tokenReader.getCurrent());
    }
    return iter;
}
Node* DatalogProgram::readRules(TokensReader& tokenReader, Node* start) {
    
}
Node* DatalogProgram::readQueries(TokensReader& tokenReader, Node* start) {
    
}

Node* DatalogProgram::generateListSize(int _size, Node*& last) {
    Node* leftParen = new Node("(");
    Node* size = new Node(_size);
    Node* rightParen = new Node(")");
    leftParen->setRightSibling(size);
    size->setRightSibling(rightParen);
    last = rightParen;
    return leftParen;
}