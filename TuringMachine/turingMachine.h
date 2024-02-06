#pragma once
#include "rules.h"
#include "Windows.h"
#include <deque>

class TuringMachine
{
private:
    Rules rules;
    map<State, Instruction> rulesMap;
    string input;
    deque<char> tape;
    int carrState = 0;
    int currentCharLocation = 0;

public:

    TuringMachine(map<State, Instruction> rulesMap, string input)
        :input(input), rulesMap(rulesMap)
    {
        tape = generateTape(input);
    }

    std::deque<char> generateTape(string input);
    void machineExe();
    bool MoveToNextStep();
    void PrintTape();
};
