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
int ans = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int len;
    cin >> len;
    cin >> s;
    for (int i=0;i<len;i++){
        if (s[i]=='R' || s[i]=='L'){
            ans++;
        }
    }
    cout << ans+1 << el;

    return 0;
}