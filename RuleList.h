#ifndef RULELIST_H
#define	RULELIST_H

#include "Token.h"
#include "TokenType.h"
#include <vector>

class RuleList {
public:
    RuleList();
    RuleList(vector <Token*>* tokens);
    RuleList(const RuleList& orig);
    virtual ~RuleList();
private:

};

#endif	/* RULELIST_H */

