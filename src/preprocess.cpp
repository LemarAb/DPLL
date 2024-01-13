
#include "../include/cnf.hpp"

void preprocess() {
    if (heuristic == Heuristics::MOM) {
        for (int i = 1; i <= numOfClauses; i++) {
            if (cnf[i].active == minimalWidth) {
                minimalClauses.insert(i);
            }
        }
    }

    // Find pure lits and assign them to pure lit queue
    // TODO: Change the structure where you check only one occ list. Only one is enough.
    for (int i = 1; i <= numOfVars; i++) {
        if (vars[i].static_neg_occ.size() == 0 && vars[i].static_pos_occ.size() > 0) {
            vars[i].prioPureLit = true;
            // std::cout << "Var no: " << i << " is a pure lit"
            //   << "\n"
            //   << std::flush;
            vars[std::abs(i)].enqueued = true;
            pureLitQueue.push(i);
        }
        if (vars[i].static_pos_occ.size() == 0 && vars[i].static_neg_occ.size() > 0) {
            vars[i].prioPureLit = true;
            // std::cout << "Var no: " << i << " is a pure lit"
            //   << "\n"
            //   << std::flush;
            vars[std::abs(i)].enqueued = true;
            pureLitQueue.push(-i);
            // TODO FOR LATER: Fix the queue structure
        }
    }
}