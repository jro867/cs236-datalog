/* 
 * File:   Query.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 7:13 PM
 */

#include "Query.h"

Query::Query(TokensReader& tokenReader) {
    this->printNL = true;
    this->level = 1;
    this->setLeftChild(new Predicate(tokenReader));
    if(tokenReader.getNext()->getTokenType() != Q_MARK) 
        throw ParsingException(tokenReader.getCurrent());
    this->getLeftChild()->setRightSibling(new Node(tokenReader.getCurrent()));
}

Query::Query(const Query& orig) {
}

Query::~Query() {
}

