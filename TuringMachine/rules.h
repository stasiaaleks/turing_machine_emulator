#pragma once

#include <iostream>
#include <map>
#include <string>
using namespace std;

struct State
{
	int stateIndex;
	char stateChar;

	bool operator<(const State& other) const {
		return stateIndex < other.stateIndex || (stateIndex == other.stateIndex && stateChar < other.stateChar);
	}

};

struct Instruction
{
	char toChar;
	int direction;
	int toState;
};

class Rules
{
public: Rules() {};

	  std::map<State, Instruction> setRules(std::initializer_list<std::pair<State, Instruction>> ruleList)
	  {
		  std::map<State, Instruction> rulesMap;
		  for (const auto& rule : ruleList)
		  {
			  rulesMap.insert(rule);
		  }

		  return rulesMap;
	  }

	  map<State, Instruction> changeFirstLetterRules = setRules({
			  {{0, 'a'}, {' ', 1, 1}},
			  {{0, 'b'}, {' ', 1, 2}},
			  {{0, 'c'}, {' ', 1, 3}},
			  {{0, ' '}, {' ', 0, -1}},

			  {{1, 'a'}, {'a', 1, 1}},
			  {{1, 'b'}, {'b', 1, 1}},
			  {{1, 'c'}, {'c', 1, 1}},
			  {{1, ' '}, {'a', 0, -1}},

			  {{2, 'a'}, {'a', 1, 2}},
			  {{2, 'b'}, {'b', 1, 2}},
			  {{2, 'c'}, {'c', 1, 2}},
			  {{2, ' '}, {'b', 0, -1}},

			  {{3, 'a'}, {'a', 1, -1}},
			  {{3, 'b'}, {'b', 1, -1}},
			  {{3, 'c'}, {'c', 1, -1}},
			  {{3, ' '}, {'c', 0, -1}},
		  });

	  // А={ a,b,c}. Якщо Р – не  порожнє  слово, тоді за його 1-м символом вставити символ «а» .

	  map<State, Instruction> addARules = setRules({
			  {{0, 'a'}, {'a', -1, 1}},
			  {{0, 'b'}, {'b', -1, 2}},
			  {{0, 'c'}, {'c', -1, 3}},
			  {{0, ' '}, {' ', 0, -1}},

			  {{1, ' '}, {'a', 1, 4}},

			  {{2, ' '}, {'b', 1, 4}},

			  {{3, ' '}, {'b', 1, 4}},

			  {{4, 'a'}, {'a', 0, -1}},
			  {{4, 'b'}, {'a', 0, -1}},
			  {{4, 'c'}, {'a', 0, -1}},
		  });

};




