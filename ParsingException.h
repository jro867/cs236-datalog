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
#include <string>

using namespace std;

class ParsingException : public exception {
public:
    ParsingException();
    ParsingException(const ParsingException& orig);
    ParsingException(Token* token);
    
    virtual const char* what() const throw() {
        string msg = "Failure!\n";
        msg.append(this->errorToken->toString());
        return msg.c_str();
    }
    virtual ~ParsingException() throw();
private:
    Token* errorToken;
};

#endif	/* PARSINGEXCEPTION_H */

