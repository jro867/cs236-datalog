/* 
 * File:   Predicate.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 5:37 PM
 */

#ifndef PREDICATE_H
#define	PREDICATE_H

#include "Parameter.h"
#include "ParameterList.h"
#include "Node.h"

class Predicate : public Node {
public:
    Predicate(TokensReader&);
    Predicate(const Predicate& orig);
    virtual ~Predicate();
private:

};

#endif	/* PREDICATE_H */

