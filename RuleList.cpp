#include "RuleList.h"

using namespace std;
vector<Rule*> RuleList::rules;

RuleList::RuleList(TokensReader& tokenReader) {
    if(tokenReader.getNext()->getTokenType() == ID) {
        Rule* rule = new Rule(tokenReader);
        this->setLeftChild(rule);
        RuleList::rules.push_back(rule);
        rule->setRightSibling(new RuleList(tokenReader));
    } else {
        // empty
    }
}

RuleList::RuleList(const RuleList& orig) {
}

RuleList::~RuleList() {
}

int RuleList::getSize() {
    return rules.size();
}
