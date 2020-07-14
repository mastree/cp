#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

int a, b, a2, b2, x;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> a2 >> b2 >> x;
    int awal = a * 60 + b;
    int akhir = a2 * 60 + b2;
    cout << akhir - awal - x << el;

    return 0;
}