#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const ll MOD = 1e9 + 7;

int q;
ll x, len;
ll st, en;
string s;
string temp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> x;
        cin >> s;
        temp = s;

        len = s.length();
        int id = 0;
        st = 0;
        // en = len-1;
        
        bool lewat = 0;
        // cout << temp.length() << el;
        while (id!=x){
            id++;
            st++;
            // cout << s << el;

            ll times = (s[id-1]-'0') - 1;
            if (!lewat){
                // int times = (s[id-1]-'0');
                for (int i=0;i<times;i++){
                    for (int j=st;j<temp.length();j++){
                        if (len>=x){
                            len++;
                            lewat = 1;
                            continue;
                        }
                        len++;
                        s.pb(temp[j]);
                    }
                }
                int awal = temp.length();
                for (int i=awal;i<s.length();i++){
                    temp.pb(s[i]);
                }
            } else{
                len = (len + (len-st+MOD) * times % MOD) % MOD;
            }

            // cout << len << el;
            // if (len<0){
            //     cout << lewat << " " << times << " => " << id << el;
            //     break;
            // }
            // en = len - 1;
        }
        cout << len << el;
    }

    return 0;
}