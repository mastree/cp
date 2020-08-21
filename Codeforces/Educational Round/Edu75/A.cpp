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

        int len=s.length();
        s = "*" + s + "*";

        map <char, bool> cek;
        char bef='*';
        int cnt=0;
        for (int i=1;i<=len+1;i++){
            if (s[i]!=bef){
                if (cnt&1){
                    cek[bef]=1;
                }

                bef=s[i];
                cnt=1;
            } else{
                cnt++;
            }
        }

        for (auto x : cek){
            cout << x.fi;
        }
        cout << el;
    }

    return 0;
}