/* 
 * File:   Query.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 7:13 PM
 */

#ifndef QUERY_H
#define	QUERY_H

#include "Predicate.h"
#include "Node.h"

class Query : public Node{
public:
    Query(TokensReader&);
    Query(const Query& orig);
    virtual ~Query();
private:

};

#endif	/* QUERY_H */

