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

int n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i=0;i<n - 1;i++){
        if (s[i] != s[i + 1]){
            cout << "YES" << el;
            cout << s[i] << s[i + 1] << el;
            return 0;
        }
    }
    cout << "NO" << el;

    return 0;
}