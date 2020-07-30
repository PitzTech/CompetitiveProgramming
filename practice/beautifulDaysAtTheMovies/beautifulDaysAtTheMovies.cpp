/**
 * Question link: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem
 */
#include <bits/stdc++.h>
using namespace std;

int reverse(int n)
{
    int reverse = 0, rem = 0;
    while (n != 0)
    {
        rem = n % 10;
        reverse = reverse * 10 + rem;
        n /= 10;
    }
    return reverse;
}
// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k)
{
    int bdays = 0;
    for (int day = i; day <= j; ++day)
    {
        if (abs(reverse(day) - day) % k == 0)
        {
            ++bdays;
        }
    }
    return bdays;
}

int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int i, j, k;
    cin >> i >> j >> k;
    cout << beautifulDays(i, j, k) << endl;
}