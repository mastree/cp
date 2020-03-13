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

int q;
int n;

string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        cin >> s;

        string ans = s;
        int k = 1;
        for (int i=2;i<=n;i++){
            string temp = "";

            for (int j=i-1;j<n;j++){
                temp.pb(s[j]);
            }

            if ((n - i) & 1){
                for (int j=0;j<i-1;j++){
                    temp.pb(s[j]);
                }
            } else{
                for (int j=i-2;j>=0;j--){
                    temp.pb(s[j]);
                }
            }

            if (ans > temp){
                ans = temp;
                k = i;
            }
        }

        cout << ans << el;
        cout << k << el;
    }

    return 0;
}