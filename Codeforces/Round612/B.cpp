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

int n, k;
string s[2000];
map <string, int> cek, ada;
ll ans = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> s[i];
        ada[s[i]]++;
    }

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            // if (i==j) continue;
            string res = "";
            string a = s[i], b = s[j];
            for (int id=0;id<k;id++){
                if (a[id]==b[id]){
                    res.pb(a[id]);
                } else{
                    bool S=0, E=0, T=0;
                    if (a[id]=='S' || b[id]=='S') S=1;
                    if (a[id]=='E' || b[id]=='E') E=1;
                    if (a[id]=='T' || b[id]=='T') T=1;
                    if (!S){
                        res.pb('S');
                    } else if (!E){
                        res.pb('E');
                    } else{
                        res.pb('T');
                    }
                }
            }
            ans += ada[res];
        }
    }

    cout << ans/3 << el;

    return 0;
}