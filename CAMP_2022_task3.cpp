#include <iostream>

int main()
{
	const int N = 5;
	const float PH[] = { 0.1, 0.2, 0.4, 0.8, 0.9 };
	const char tests[] = { 'H','H','H','T','H','T','H','H' };
	float hypothesis_prob[] = { 0.2, 0.2, 0.2, 0.2, 0.2 };
	float result_prob[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	float full_prob = 0;

	for (int i = 0; i < N; ++i)
		full_prob += PH[i] * 0.2;

	for (int i = 0; i < 8; ++i)
	{
		if (tests[i] == 'H')
		{
			for (int j = 0; j < N; ++j)
			{
				hypothesis_prob[j] = (PH[j] * hypothesis_prob[j]) / full_prob;
				result_prob[i] += hypothesis_prob[j] * PH[j];
			}
		}
		else
		{
			for (int j = 0; j < N; ++j)
			{
				hypothesis_prob[j] = ((1 - PH[j]) * hypothesis_prob[j]) / full_prob;
				result_prob[i] += hypothesis_prob[j] * PH[j];
			}
		}
		full_prob = result_prob[i];
		std::cout << result_prob[i] << std::endl;
	}
}