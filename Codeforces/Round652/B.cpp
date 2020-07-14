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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int n;
        string s;
        cin >> n >> s;

        string ans = "";
        // bool nemu = 0;
        int cnt0 = 0;
        for (int i=n - 1;i>=0;i--){
            if (s[i] == '0'){
                cnt0++;
            } else{
                if (cnt0){
                    cnt0 = 1;
                } else{
                    ans.pb('1');
                }
            }
        }
        for (int i=0;i<cnt0;i++) cout << '0';
        cout << ans << el;
    }

    return 0;
}