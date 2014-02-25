#ifndef RULELIST_H
#define	RULELIST_H

#include "Rule.h"
#include "Node.h"
#include <vector>

using namespace std;

class RuleList: public Node {
public:
    RuleList(TokensReader&);
    RuleList(const RuleList& orig);
    virtual ~RuleList();
    
    static int getSize();
private:
    static vector<Rule*> rules;
};

#endif	/* RULELIST_H */

