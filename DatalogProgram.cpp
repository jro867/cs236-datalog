#include "DatalogProgram.h"
#include <iostream>
using namespace std;
DatalogProgram::DatalogProgram(){    
}

DatalogProgram::DatalogProgram(TokensReader& tokenReader) {
        Node* schemeList = readSchemes(tokenReader);
        Node* factList = readFacts(tokenReader, schemeList);
        Node* ruleList = readRules(tokenReader, factList);
        Node* queryList = readQueries(tokenReader, ruleList);
        addDomain(queryList);
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
            // Since we need at least one scheme
            if(tokenReader.getNext()->getTokenType() == ID) {
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
    } else {
        throw ParsingException(tokenReader.getCurrent());
    }
    return iter;
}
Node* DatalogProgram::readFacts(TokensReader& tokenReader, Node* schemeList) {
    Node* iter = schemeList;
    if(tokenReader.getCurrent()->getTokenType() == FACTS) {
        Node* fact = new Node(tokenReader.getCurrent());
        iter->setRightSibling(fact);
        
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
Node* DatalogProgram::readRules(TokensReader& tokenReader, Node* factList) {
    Node* iter = factList;
    if(tokenReader.getCurrent()->getTokenType() == RULES) {
        Node * rules = new Node(tokenReader.getCurrent());
        iter->setRightSibling(rules);
        if(tokenReader.getNext()->getTokenType() == COLON) {
            Node* colon = new Node(tokenReader.getCurrent());
            colon->setNL(true);
            rules->setRightSibling(colon);
            RuleList* ruleList = new RuleList(tokenReader);
            colon->setRightSibling(ruleList);
            
            Node* tail;
            Node* size = generateListSize(RuleList::getSize(), tail);
            tail->setRightSibling(colon);
            rules->setRightSibling(size);
            
            iter = ruleList;
        }
    } else {
        throw ParsingException(tokenReader.getCurrent());
    }
    return iter;
}
Node* DatalogProgram::readQueries(TokensReader& tokenReader, Node* ruleList) {
    Node* iter = ruleList;
    if(tokenReader.getCurrent()->getTokenType() == QUERIES){
        // set child to new Node Scheme
        Node * queries = new Node(tokenReader.getCurrent());
        iter->setRightSibling(queries);
        if(tokenReader.getNext()->getTokenType() == COLON) {
            Node * colon = new Node(tokenReader.getCurrent());
            colon->setNL(true);
            // Since we need at least one scheme
            if(tokenReader.peek()->getTokenType() == ID) {
                QueryList* queryList = new QueryList(tokenReader);
                colon->setRightSibling(queryList);
                iter = queryList;

                Node* tail;
                Node* size = generateListSize(QueryList::getSize(), tail);
                queries->setRightSibling(size);
                tail->setRightSibling(colon);
            } else {
                throw ParsingException(tokenReader.getCurrent());
            }
        } else {
            throw ParsingException(tokenReader.getCurrent());
        }
    } else {
        throw ParsingException(tokenReader.getCurrent());
    }
    return iter;
}

Node* DatalogProgram::addDomain(Node* queryList) {
    queryList->setRightSibling(new Node("Domain"));
    set<string> domain = Domain::getDomain();
    Node* tail;
    Node* size = generateListSize(domain.size(), tail);
    queryList->getRightSibling()->setRightSibling(size);
    tail->setRightSibling(new Node(":"));
    tail->getRightSibling()->setNL(true);
    Node* iter = tail->getRightSibling();
    set<string>::iterator domainIter = domain.begin();
    for(domainIter; domainIter != domain.end(); domainIter++)
    {
        Node* domainVal = new Node(*domainIter);
        domainVal->setNL(true);
        domainVal->setLevel(1);
        iter->setRightSibling(domainVal);
        iter = iter->getRightSibling();
    }
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