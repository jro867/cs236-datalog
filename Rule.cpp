/* 
 * File:   Rule.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 5:33 PM
 */

#include "Rule.h"

// headPredicate COLON_DASH predicate predicateList PERIOD
Rule::Rule(TokensReader& tokenReader) {
    this->printNL = true;
    this->level = 1;
    if(tokenReader.getCurrent()->getTokenType() != ID) {
        throw ParsingException(tokenReader.getCurrent());
    }
    Node* headPredicate = new HeadPredicate(tokenReader);
    this->setLeftChild(headPredicate);
    if(tokenReader.getNext()->getTokenType() != COLON_DASH) {
        throw ParsingException(tokenReader.getCurrent());
    }
    Node* colon_dash = new Node(tokenReader.getCurrent());
    headPredicate->setRightSibling(colon_dash);
    Node* predicate = new Predicate(tokenReader);
    colon_dash->setRightSibling(predicate);
    Node* predicateList = new PredicateList(tokenReader);
    predicate->setRightSibling(predicateList);
    if(tokenReader.getCurrent()->getTokenType() != PERIOD) {
        throw ParsingException(tokenReader.getCurrent());
    }
    predicateList->setRightSibling(new Node(tokenReader.getCurrent()));
}

Rule::Rule(const Rule& orig) {
}

Rule::~Rule() {
}

