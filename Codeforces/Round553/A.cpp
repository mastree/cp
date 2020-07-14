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

const int N = 100;

int n;
string s;

string gen = "ACTG";

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;
    int ans = MOD;
    for (int i=0;i<=n - 4;i++){
        int cur = 0;
        for (int j=0;j<4;j++){
            int a = gen[j] - 'A';
            int b = s[i + j] - 'A';
            if (a > b) swap(a, b);
            cur += min(b - a, 26 - b + a);
        }
        ans = min(ans, cur);
    }
    cout << ans << el;

    return 0;
}