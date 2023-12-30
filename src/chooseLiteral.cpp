#include "../include/cnf.hpp"

void chooseLiteral() {
    switch (heuristic) {
        case INC:
            while (variables[curVar].getValue() != FREE) curVar++;
            variables[curVar].setValue(TRUE);
            assig.push(curVar);
            break;
        case DLIS:
            break;
        case DLCS:
            break;
        case MOM:
            break;
        case JW:
            break;
    }
    updateWatchedLiterals(curVar);
}