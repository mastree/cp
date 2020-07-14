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

string s;
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();

    ll tot = 0;
    ll temp = 1;
    cout << s[0] - 'A' + 1 << el;
    for (int i=n - 1;i>=0;i--){
        ll dig = s[i] - 'A';
        tot += dig * temp;
        temp *= 26;
    }
    // cout << tot << el;

    bool bisa = 1;
    for (ll i=2;i<=10000000;i++){
        if (tot % i == 0){
            bisa = 0;
            break;
        }
    }
    if (bisa){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }

    return 0;
}