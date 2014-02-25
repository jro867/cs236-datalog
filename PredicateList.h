/* 
 * File:   PredicateList.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 5:37 PM
 */

#ifndef PREDICATELIST_H
#define	PREDICATELIST_H

#include "Predicate.h"
#include "Node.h"

class PredicateList : public Node {
public:
    PredicateList(TokensReader&);
    PredicateList(const PredicateList& orig);
    virtual ~PredicateList();
private:

};

#endif	/* PREDICATELIST_H */

