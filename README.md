Solution to the problem:
Prepare a Bank statement for the sum of the money in the account after 2020:
provided 2 array:
Array A: Sums of money which are deducted/added to the account.
Array D: Dates of Array A, each date will be in the format of : 2020-mm-dd, while mm is the month, dd is the day.

for owning the account , the owner has to pay 5 ILS each month unless:
there are at least 3 deductions in that month, and the total sum of the deduction is bigger then 99 ILS.
Please calculate the sum of the account at the end of the year.

Function signature is as such:
int solution(vector<int>& A, vector<string>& D)

Pre-conditions:
Sums in A - -10000 < x < 10000
Dates are all valid dates.
A,D are in the same size.
