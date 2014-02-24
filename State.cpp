#include "State.h"

using namespace std;

string StateToString(State tokenType){
    string result = "";
    switch(tokenType){
        case Comma:                      result = "Comma"; break;
        case Period:                     result = "Period"; break;
        case SawColon:                   result = "SawColon"; break;
        case Colon_Dash:                 result = "Colon_Dash"; break;
        case SawAQuote:                  result = "SawAQuote"; break;
        case ProcessingString:           result = "ProcessingString"; break;
        case PossibleEndOfString:        result = "PossibleEndOfString"; break;
        case Start:                      result = "Start"; break;
        case End:                        result = "End"; break;
        case QMark:                      result = "QMark"; break;
        case LeftParen:                  result = "LeftParen"; break;
        case RightParen:                 result = "RightParen"; break;
        case Multiply:                   result = "Multiply"; break;
        case Add:                        result = "Add"; break;
        case Id:                         result = "Id"; break;
        case Comment:                    result = "Comment"; break;
        case SawPoundSign:               result = "SawPoundSign"; break;
        case BlockComment:               result = "BlockComment"; break;
        case Undefined:                  result = "Undefined"; break;
        case Eof:                        result = "EOF"; break;
    }
    return result;
};
