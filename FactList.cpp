#include "FactList.h"

vector<Fact*> FactList::facts;
FactList::FactList() {
}
FactList::FactList(TokensReader& tokenReader) {
    if(tokenReader.getNext()->getTokenType() == ID) {
        Fact* fact = new Fact(tokenReader);
        this->setLeftChild(fact);
        facts.push_back(fact);
        fact->setRightSibling(new FactList(tokenReader));
    } else {
        // empty
    }
}

FactList::FactList(const FactList& orig) {
}

FactList::~FactList() {
}

int FactList::getSize() {
    return facts.size();
}