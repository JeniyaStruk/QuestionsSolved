#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A, vector<string>& D) {
	// Implement your solution here
	int** arr = new int* [12];
	for (int i = 0; i < 12; i++)
		arr[i] = new int[A.size()];

	//go over the given arrays and distribute per month.
	int month_sizes[12] = { 0 };
	const char* months[12] = { "01","02", "03", "04", "05","06","07", "08", "09", "10","11","12" };
	for (unsigned int i = 0; i < A.size(); i++) // for each month.
	{
		for (int j = 0; j < 12; j++)
		{
			if ((D[i][5] == months[j][0]) && (D[i][6] == months[j][1]))
			{
				arr[j][month_sizes[j]] = A[i];
				month_sizes[j]++;
			}

		}
	}

	//start calculating all the months. and check for each month if negation of the card is needed.
	int total_sum = 0;
	for (int i = 0; i < 12; i++)
	{
		cout << "month size=" << month_sizes[i] << endl;
		bool neg_flag = true;
		int neg_cnt = 0;
		int neg_tot = 0;
		for (int j = 0; j < month_sizes[i]; j++)
		{
			total_sum += arr[i][j];
			if ((arr[i][j] < 0) && (neg_flag == true))
			{
				neg_cnt++;
				neg_tot = neg_tot + arr[i][j];
			}
			if ((neg_cnt >= 3) && (neg_tot <= -100))
			{
				neg_flag = false;
				cout << " passed negetive barrier" << endl;
			}
			cout << "arr[" << i+1 << "][" << j << "] =" << dec<< (int)arr[i][j] << endl;
		}
		if (neg_flag == true)
		{
			total_sum -= 5;			
		}
		cout << "total_sum=" << total_sum << endl;
		cout << "****" << endl;
	}
	cout << "total_sum=" << total_sum << endl;
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

