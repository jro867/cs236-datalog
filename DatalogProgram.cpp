#include "DatalogProgram.h"
#include <iostream>
using namespace std;
DatalogProgram::DatalogProgram(){    
}

DatalogProgram::DatalogProgram(vector <Token*>* tokens) {
    for(int i = 0; i < tokens->size(); i++){
        cout << TokenTypeToString(tokens->at(i)->getTokenType()) << endl;
    }
}

DatalogProgram::DatalogProgram(const DatalogProgram& orig) {
}

DatalogProgram::~DatalogProgram() {
}

