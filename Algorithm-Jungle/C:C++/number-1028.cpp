#include<cstdlib>
#include<iostream>
using namespace std;
void f(int n)
{
	if (n != 0)
	{
		cout << n % 8;
		n = n / 8;
		f(n);
	}
}
int main()
{
	int n;
	cin >> n;
	f(n);
	return 0;
}