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
        schemeNode->setRightSibling(new Node("("));
        Node* schemeListSize = new Node("0");
        schemeNode->getRightSibling()->setRightSibling(schemeListSize);
        schemeListSize->setRightSibling(new Node(")"));
        if(tokenReader.getNext()->getTokenType() == COLON) {
            Node * colonNode = new Node(tokenReader.getCurrent());
            schemeListSize->getRightSibling()->setRightSibling(colonNode);
            SchemesList* schemeList = new SchemesList(tokenReader);
            schemeListSize->setValue(schemeList->getSize());
            colonNode->setRightSibling(schemeList);
            iter = schemeList;
        } else {
            throw ParsingException(tokenReader.getCurrent());
        }
    } else {
        throw ParsingException(tokenReader.getCurrent());
    }
    return iter;
}
Node* DatalogProgram::readFacts(TokensReader& tokenReader, Node* start) {
    if(tokenReader.getCurrent()->getTokenType() == FACTS) {
        Node* facts = new Node(tokenReader.getCurrent());
        start->setRightSibling(facts);
        if(tokenReader.getNext()->getTokenType() == COLON) {
            Node* colon = new Node(tokenReader.getCurrent());
            facts->setRightSibling(colon);
//            colon->setRightSibling(new FactsList());
        } else {
            throw ParsingException(tokenReader.getCurrent());
        }
    } else {
        throw ParsingException(tokenReader.getCurrent());
    }
}
Node* DatalogProgram::readRules(TokensReader& tokenReader, Node* start) {
    
}
Node* DatalogProgram::readQueries(TokensReader& tokenReader, Node* start) {
    
}