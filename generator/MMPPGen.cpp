#include "MMPPGen.h"

Define_Module(MMPPGen);

MMPPGen::~MMPPGen()
{
	deleteMatrix();
}

void MMPPGen::initialize()
{
	state = 0;
	states = par("states");
	stateSignal = registerSignal("state");
	generateMatrix();
	SimpleGen::initialize();
}

bool MMPPGen::canSendMessage()
{
	emit(stateSignal, state);
	return true;
}

double MMPPGen::getDelay()
{
	int delay = poisson(lambdas[state]);

	if (bernoulli(getOutIntensity()))
	{
		double nextIntensity = getNextIntensity();
		double prevIntensity = getPrevIntensity();

		if (nextIntensity > 0 && bernoulli(nextIntensity))
		{
			EV<< state << "=>" << state+1 << endl;
			++state;
		}
		else if (prevIntensity > 0 && bernoulli(prevIntensity))
		{
			EV << state-1 << "<=" << state << endl;
			--state;
		}
	}

	return delay > 0 ? delay : 0;
}

double** MMPPGen::generateMatrix()
{
	int i, j;
	double d, sum;

	//
	// Allocate space for matrix and lambdas vector
	//

	matrix = new double*[states];
	lambdas = new double[states];

	for (i = 0; i < states; i++)
	{
		matrix[i] = new double[states];
		// Fill with zeros
		memset(matrix[i], 0, sizeof(double[states]));
		// Generate lambda
		lambdas[i] = uniform(2, 10);
	}

	//
	// Calculate Markov matrix
	//

	i = 0;

	d = uniform(0, 1);
	matrix[i][i] = d;
	matrix[i][i + 1] = 1 - d;

	while (i++ < states - 2)
	{
		sum = 0;

		//
		// Calculate probability rates
		//

		// pp - go to previous state
		// po - go out from current state
		// pn - go to next state
		for (j = i - 1; j - i < 2; j++)
		{
			d = uniform(0, 1);
			matrix[i][j] = d;
			sum += d;
		}

		// Normalize probability rates
		// pp+po+pn=1
		if (sum < 1)
		{
			matrix[i][j - 1] = 1 - sum;
		}
		else
		{
			for (j = i - 1; j - i < 2; j++)
			{
				matrix[i][j] /= sum;
			}
		}
	}

	d = uniform(0, 1);
	matrix[i][i] = d;
	matrix[i][i - 1] = 1 - d;

	dumpMatrix();

	return matrix;
}

void MMPPGen::dumpMatrix()
{
	for (int i = 0; i < states; i++)
	{
		for (int j = 0; j < states; j++)
		{
			EV<< "[" << std::fixed << std::setprecision(4) << matrix[i][j] << "]";
		}
		EV << endl;
	}
}

void MMPPGen::deleteMatrix()
{
	for (int i = 0; i < states; i++)
		delete[] matrix[i];
	delete[] matrix;
	delete[] lambdas;
}

double inline MMPPGen::getOutIntensity()
{
	return matrix[state][state];
}

double inline MMPPGen::getNextIntensity()
{
	return (state == states - 1 ? 0 : matrix[state][state + 1]);
}

double inline MMPPGen::getPrevIntensity()
{
	return (state == 0 ? 0 : matrix[state][state - 1]);
}
