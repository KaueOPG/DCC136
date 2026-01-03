#include "AlgorithmParameters.h"
#include <iostream>

using namespace std;

struct AlgorithmParameters default_algorithm_parameters() {
	struct AlgorithmParameters ap{};

	ap.nbGranular = 20;
	ap.mu = 25;
	ap.lambda = 40;
	ap.nbElite = 4;
	ap.nbClose = 5;

	ap.nbIterPenaltyManagement = 100;
	ap.targetFeasible = 0.2;
	ap.penaltyDecrease = 0.85;
	ap.penaltyIncrease = 1.2;

	ap.seed = 0;
	ap.nbIter = 20000;
	ap.nbIterTraces = 500;
	ap.timeLimit = 0;
	ap.useSwapStar = 1;

	return ap;
}

void print_algorithm_parameters(const AlgorithmParameters & ap)
{
	cout << "=========== Algorithm Parameters =================" << endl;
	cout << "---- nbGranular              is set to " << ap.nbGranular << endl;
	cout << "---- mu                      is set to " << ap.mu << endl;
	cout << "---- lambda                  is set to " << ap.lambda << endl;
	cout << "---- nbElite                 is set to " << ap.nbElite << endl;
	cout << "---- nbClose                 is set to " << ap.nbClose << endl;
	cout << "---- nbIterPenaltyManagement is set to " << ap.nbIterPenaltyManagement << endl;
	cout << "---- targetFeasible          is set to " << ap.targetFeasible << endl;
	cout << "---- penaltyDecrease         is set to " << ap.penaltyDecrease << endl;
	cout << "---- penaltyIncrease         is set to " << ap.penaltyIncrease << endl;
	cout << "---- seed                    is set to " << ap.seed << endl;
	cout << "---- nbIter                  is set to " << ap.nbIter << endl;
	cout << "---- nbIterTraces            is set to " << ap.nbIterTraces << endl;
	cout << "---- timeLimit               is set to " << ap.timeLimit << endl;
	cout << "---- useSwapStar             is set to " << ap.useSwapStar << endl;
	cout << "==================================================" << endl;
}