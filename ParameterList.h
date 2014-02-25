/* 
 * File:   ParameterList.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 5:38 PM
 */

#ifndef PARAMETERLIST_H
#define	PARAMETERLIST_H

#include "Parameter.h"
#include "Node.h"

class ParameterList : public Node {
public:
    ParameterList(TokensReader&);
    ParameterList(const ParameterList& orig);
    virtual ~ParameterList();
private:

};

#endif	/* PARAMETERLIST_H */

