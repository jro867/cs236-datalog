/* 
 * File:   ParsingException.h
 * Author: nuxer
 *
 * Created on February 24, 2014, 1:15 PM
 */

#ifndef PARSINGEXCEPTION_H
#define	PARSINGEXCEPTION_H

#include "Token.h"
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class ParsingException : public runtime_error {
public:
    ParsingException();
    ParsingException(const ParsingException& orig);
    ParsingException(Token* token);
    
    virtual ~ParsingException() throw();
};

#endif	/* PARSINGEXCEPTION_H */

