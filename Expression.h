/* 
 * File:   Expression.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 5:38 PM
 */

#ifndef EXPRESSION_H
#define	EXPRESSION_H

#include "Parameter.h"
#include "Operator.h"
#include "Node.h"

class Expression : public Node {
public:
    Expression(TokensReader&);
    Expression(const Expression& orig);
    virtual ~Expression();
private:

};

#endif	/* EXPRESSION_H */

