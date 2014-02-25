/* 
 * File:   Rule.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 5:33 PM
 */

#ifndef RULE_H
#define	RULE_H

#include "HeadPredicate.h"
#include "Predicate.h"
#include "PredicateList.h"
#include "Node.h"

class Rule : public Node {
public:
    Rule(TokensReader&);
    Rule(const Rule& orig);
    virtual ~Rule();
private:

};

#endif	/* RULE_H */

