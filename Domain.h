/* 
 * File:   Domain.h
 * Author: nuxer
 *
 * Created on February 25, 2014, 9:25 AM
 */

#ifndef DOMAIN_H
#define	DOMAIN_H

#include <set>
#include <string>

using namespace std;

class Domain {
public:
    Domain();
    Domain(const Domain& orig);
    virtual ~Domain();
    
    static void addToDomain(string);
    static set<string> getDomain();
private:
    static set<string> domain;
};

#endif	/* DOMAIN_H */

