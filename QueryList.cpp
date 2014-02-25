/* 
 * File:   QueryList.cpp
 * Author: nuxer
 * 
 * Created on February 24, 2014, 7:13 PM
 */

#include "QueryList.h"
vector<Query*> QueryList::queries;
QueryList::QueryList(TokensReader& tokenReader) {
    if(tokenReader.peek()->getTokenType() == ID) {
        Query* query = new Query(tokenReader);
        this->setLeftChild(query);
        QueryList::queries.push_back(query);
        this->getLeftChild()->setRightSibling(new QueryList(tokenReader));
    } else {
        // empty
    }
}

QueryList::QueryList(const QueryList& orig) {
}

QueryList::~QueryList() {
}

int QueryList::getSize() {
    return QueryList::queries.size();
}