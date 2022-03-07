#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll maxN = 1e9 + 10;

vector<int> prime;
 
// Function to calculate prime
// factors of n
void sieve(long long n)
{
    // run the sieve of Eratosthenes
    bool check[1000007] = { 0 };
    long long i, j;
 
    // 0(false) means prime,
    // 1(true) means not prime
    check[0] = 1, check[1] = 1,
    check[2] = 0;
 
    // no even number is
    // prime except for 2
    for (i = 4; i <= n; i += 2)
        check[i] = true;
 
    for (i = 3; i * i <= n; i += 2)
        if (!check[i]) {
 
            // all the multiples of each
            // each prime numbers are
            // non-prime
            for (j = i * i; j <= n; j += 2 * i)
                check[j] = true;
        }
 
    prime.push_back(2);
 
    // get all the primes
    // in prime vector
    for (int i = 3; i <= n; i += 2)
        if (!check[i])
            prime.push_back(i);
 
    return;
}
 
// Count the number of numbers
// up to m which are divisible
// by given prime numbers
long long count(long long a[],
                int n, long long m)
{
    long long parity[3] = { 0 };
 
    // Run from i= 000..0 to i= 111..1
    // or check all possible
    // subsets of the array
    for (int i = 1; i < (1 << n); i++) {
        long long mult = 1;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                mult *= a[j];
 
        // take the multiplication
        // of all the set bits
 
        // if the number of set bits
        // is odd, then add to the
        // number of multiples
        parity[__builtin_popcount(i) & 1]
            += (m / mult);
    }
 
    return parity[1] - parity[0];
}
 
// Function calculates all number
// not greater than 'm' which are
// relatively prime with n.
long long countRelPrime(
    long long n,
    long long m)
{
 
    long long a[20];
    int i = 0, j = 0;
    long long pz = prime.size();
    while (n != 1 && i < pz) {
 
        // if square of the prime number
        // is greater than 'n', it can't
        // be a factor of 'n'
        if ((long long)prime[i]
                * (long long)prime[i]
            > n)
            break;
 
        // if prime is a factor of
        // n then increment count
        if (n % prime[i] == 0)
            a[j] = (long long)prime[i], j++;
 
        while (n % prime[i] == 0)
            n /= prime[i];
        i++;
    }
 
    if (n != 1)
        a[j] = n, j++;
    return m - count(a, j, m);
}
 
void countRelPrimeInRange(
    long long n, long long l,
    long long r)
{
    sieve(sqrt(maxN));
    long long result
        = countRelPrime(n, r)
          - countRelPrime(n, l - 1);
    // cout << result << "\n";
    if (result > 0) cout << result << el;
    else cout << -1 << el;
}

int main(){
    ll n;
    cin >> n;
    countRelPrimeInRange(n, 2, n / 2);
    return 0;
}