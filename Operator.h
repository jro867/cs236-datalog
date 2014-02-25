/* 
 * File:   Operator.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 5:38 PM
 */

#ifndef OPERATOR_H
#define	OPERATOR_H

#include "Node.h"

class Operator : public Node {
public:
    Operator(TokensReader&);
    Operator(const Operator& orig);
    virtual ~Operator();
private:

};

#endif	/* OPERATOR_H */

