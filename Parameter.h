/* 
 * File:   Parameter.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 5:38 PM
 */

#ifndef PARAMETER_H
#define	PARAMETER_H

#include "Expression.h"
#include "Node.h"

class Parameter : public Node {
public:
    Parameter(TokensReader&);
    Parameter(const Parameter& orig);
    virtual ~Parameter();
private:

};

#endif	/* PARAMETER_H */

