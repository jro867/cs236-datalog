#ifndef DATALOGPROGRAM_H
#define	DATALOGPROGRAM_H

#include "Token.h"
#include "TokenType.h"
#include <vector>
#include <iostream>
using namespace std;

class DatalogProgram {
public:
    DatalogProgram();
    DatalogProgram(vector <Token*>* tokens);
    DatalogProgram(const DatalogProgram& orig);
    virtual ~DatalogProgram();
private:

};

#endif	/* DATALOGPROGRAM_H */

