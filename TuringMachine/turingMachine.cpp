#include "turingMachine.h"

std::deque<char> TuringMachine::generateTape(string input)
{
    deque<char> tape;
    int strLength = input.length() + 1;

    for (int i = 0; i < input.length(); i++)
    {
        tape.push_back(input[i]);
    }

    return tape;
}

void TuringMachine::machineExe()
{
    PrintTape();
    Sleep(500.0f);

    while (true) {
        bool hasNextStep = MoveToNextStep();

        PrintTape();
        Sleep(500.0f);

        if (!hasNextStep) {
            /* currentCharLocation = 0;
             carrState = 0;*/ //to make an infinite loop
            break;
        }
    }
}

bool TuringMachine::MoveToNextStep()
{
    State currentState{ carrState, tape.at(currentCharLocation) };
    auto findState = rulesMap.find(currentState);

    if (findState != rulesMap.end())
    {
        Instruction& instruction = findState->second;

        tape.at(currentCharLocation) = instruction.toChar;
        currentCharLocation += instruction.direction;

        if (currentCharLocation >= (int)(tape.size()))
        {
            tape.push_back(' ');
        }

        if (currentCharLocation < 0)
        {
            tape.push_front(' ');
            currentCharLocation = 0;
        }

        carrState = instruction.toState;

        if (instruction.toState == -1) {
            return false;
        }

    }
    else
    {
        cout << "Couldn`t find instruction for this state.";
    }
    return true;
}

void TuringMachine::PrintTape()
{
    system("CLS");
    for (int i = 0; i < tape.size(); i++) {
        char c = tape.at(i);

        if (i == currentCharLocation)
        {
            std::cout << '[';
        }

        std::cout << c;

        if (i == currentCharLocation)
        {
            std::cout << ']';
        }

    }
    std::cout << std::endl;
}