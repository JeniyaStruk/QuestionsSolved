// blank_proj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdint.h>
using namespace std; 
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A, vector<string>& D) {
	// Implement your solution here
	int neg_cnt[12] = { 0 };
	int neg_tot[12] = { 0 };
	int total_sum = 0;

	//go over the given arrays and distribute per month.
	int month_sizes[12] = { 0 };
	const char* months[12] = { "01","02", "03", "04", "05","06","07", "08", "09", "10","11","12" };
	for (unsigned int i = 0; i < A.size(); i++) // for each month.
	{
		for (int j = 0; j < 12; j++)
		{
			if ((D[i][5] == months[j][0]) && (D[i][6] == months[j][1]))
			{
				if (A[i] < 0)
				{
					neg_tot[j] = neg_tot[j] + A[i];
					neg_cnt[j]++;
				}
			}

		}
		total_sum = total_sum + A[i];
	}

	//start calculating all the months. and check for each month if negation of the card is needed.
	for (int i = 0; i < 12; i++)
	{
		if ((neg_cnt[i] < 3) || (neg_tot[i] > -100))
		{
			total_sum = total_sum - 5;
		}
	}
	return total_sum;
}


int main()
{
	vector<int> A1{ 1, -1, 0, -105, 1 };
	vector<string> D1{ "2020-12-31", "2020-04-04", "2020-04-04", "2020-04-14", "2020-07-12" };
	cout << "total_sum1=" << solution(A1, D1) << endl;

	vector<int> A2{ 100, -100,-100,-100, 300, 0, 2000 };
	vector<string> D2{ "2020-10-31", "2020-04-04","2020-04-04","2020-04-04", "2020-04-05", "2020-08-14", "2020-07-12" };
	cout << "total_sum2=" << solution(A2, D2) << endl;

}
