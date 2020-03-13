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

    int n;
    cin >> n;

    int cnt=0;

    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        if (a%2) cnt++;
    }

    cout << min(n-cnt,cnt) << el;

    return 0;
}