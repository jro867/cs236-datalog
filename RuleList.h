#ifndef RULELIST_H
#define	RULELIST_H

#include "Token.h"
#include "TokenType.h"
#include "Node.h"
#include <vector>

using namespace std;

class RuleList: public Node {
public:
    RuleList();
    RuleList(vector <Token*>* tokens);
    RuleList(const RuleList& orig);
    virtual ~RuleList();
private:

};

#endif	/* RULELIST_H */

