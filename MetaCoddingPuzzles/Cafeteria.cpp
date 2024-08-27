#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long calc_personal(long long sum, long long K)
{
	if (sum <= 0)
		return 0;
	long long value = (sum / (K + 1)) + sum % (K + 1);
	return value;
}

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
	sort(&S[0], &S[M - 1]);
	long long num_of_additions = 0;
	long long cur_idx = 1;
	for (long long i = 0; i < M; i++)
	{
		long long last_idx = S[i] - K - 1;
		num_of_additions += calc_personal(last_idx - cur_idx + 1, K);
		cur_idx = S[i] + K + 1;
	}
	num_of_additions += calc_personal(N - cur_idx + 1, K); // for after the last M.
	return num_of_additions;
}

int main()
{
	long long N = 10;
	long long K = 2;
	long long M = 2;
	vector<long long> S = { 2,6 };
	cout << getMaxAdditionalDinersCount(N, K, M, S) << endl;
}
