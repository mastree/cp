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
        string s;
        cin >> s;
        int n = s.length();
        
        vector <string> ans;
        for (int i=0;i<n;i++){
            if (s[i] != '0'){
                string temp;
                int len = n - i - 1;
                temp.pb(s[i]);
                for (int j=0;j<len;j++) temp.pb('0');
                ans.pb(temp);
            }
        }
        cout << ans.size() << el;
        for (auto x : ans){
            cout << x << " ";
        }
        cout << el;
    }

    return 0;
}