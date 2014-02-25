/* 
 * File:   QueryList.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 7:13 PM
 */

#ifndef QUERYLIST_H
#define	QUERYLIST_H

#include "Query.h"
#include "Node.h"

class QueryList : public Node {
public:
    QueryList(TokensReader&);
    QueryList(const QueryList& orig);
    virtual ~QueryList();
    
    static int getSize();
private:
    static vector<Query*> queries;
};

#endif	/* QUERYLIST_H */

