#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double h,l;
    cin >> h >> l;
    cout << fixed <<setprecision(10) << (l*l+h*h)/(2*h)-h << endl;

    return 0;
}