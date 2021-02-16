#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define tests boost; ll test; cin >> test; while(test--)
#define printlst(lst, N)for (ll i = 0; i < N; i++) cout << lst[i] << " ";cout << endl
#define inputlst(lst, N) for (ll i = 0; i < N; i++) cin >> lst[i]
#define sortlst(lst) sort(lst.begin(), lst.end())
#define setbits(n) __builtin_popcount(n)
#define sortarr(x, n) sort(x, x + n)
#define fora(i, x, y) for (ll i = x; i < y; ++i)
#define ford(i, x, y) for (ll i = x; i >= y; --i)
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vl> vovl;
typedef vector<vi> vovi;
typedef vector<string> vs;
typedef set<ll> sl;
typedef unordered_map<ll, ll> uml;
typedef map<ll, ll> ml;
const ll N = 1000001, mod = 1000000007, inf = INT64_MAX;
ll factorialNumInverse[N + 1], naturalNumInverse[N + 1], fact[N + 1];
void InverseofNumber()
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[mod % i] * (mod - mod / i) % mod;
}
void InverseofFactorial()
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % mod;
}
void nCrPreComputation()
{
    InverseofNumber();
    InverseofFactorial();
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
ll nCrMod(ll N, ll R)
{
    ll ans = ((fact[N] * factorialNumInverse[R]) % mod * factorialNumInverse[N - R])% mod;
    return ans;
}
string bin(unsigned ll int n)
{
    string ans = "";
    while(n)
    {
        ans = to_string(1&n) + ans;
        n = n >> 1;
    }
    return ans;
}
ll gcd(ll a , ll b)
{
   if(b == 0) return a;
   a %= b;
   return gcd(b, a);
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
	boost;
    nCrPreComputation();
    cout << nCrMod(15, 4) << endl;
    cout << gcd(343, 49) << endl;
    cout << bin(75677454) << endl;
	return 0;
}