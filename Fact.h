/* 
 * File:   Fact.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 4:00 PM
 */

#ifndef FACT_H
#define	FACT_H

#include "StringList.h"
#include "Domain.h"
#include "Node.h"

class Fact : public Node {
public:
    Fact();
    Fact(TokensReader&);
    Fact(const Fact& orig);
    virtual ~Fact();
};

#endif	/* FACT_H */

