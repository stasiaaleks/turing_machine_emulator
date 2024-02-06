#include "turingMachine.h"

int main() {
    Rules rules;
    TuringMachine tm(rules.changeFirstLetterRules, "abcabcabc");
    tm.machineExe();
}

