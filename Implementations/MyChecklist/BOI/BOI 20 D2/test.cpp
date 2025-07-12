#include <iostream>
#include <set>
#include <assert.h>
#define ll long long
using namespace std;
 
ll n; 
 
inline bool ask(ll x)
{
	bool ret;
	assert(1 <= x && x <= n);
	cout << "? " << x << endl;
	cin >> ret;
	return ret;
}
 
int main()
{
	int t = 1;
	while (t--)
	{
		cin >> n;
		ll s = 0, c = 0, L = 1, R = n - 1;
		for (int i = 0; L <= R; i++)
		{
			ll M = (R - L + 1 > 2) ? (L + R >> 1) : R;
			if (i & 1) {c -= M;}
			else {c += M;}
			s = min(s, c);
			L = M + 1;
		}
		s = -s + 1;
		L = 1, R = n - 1; ll ans = n;
		if (n > 1) ask(s);
		for (int i = 0; L <= R; i++)
		{
			ll M = (R - L + 1 > 2) ? (L + R >> 1) : R;
			if (i & 1) s -= M;
			else s += M;
			if (ask(s)) {ans = M; R = M - 1;}
			else {L = M + 1;}
		}
		cout << "= " << ans << endl;
	}
	
	return 0;
}