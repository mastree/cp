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

const int N = 2e5;

int q;
bool cek[N];
vector <int> v;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s;

        for (int i=0;i+2<s.length();i++){
            bool satu, dua, satudua=0;

            satu = (s[i]=='o' && s[i+1]=='n' && s[i+2]=='e');
            dua = (s[i]=='t' && s[i+1]=='w' && s[i+2]=='o');
            if (i+4<s.length()){
                string tm="";
                for (int pl=0;pl<5;pl++){
                    tm.pb(s[i+pl]);
                }
                // cout << tm << el;
                if (tm=="twone"){
                    satudua=1;
                }
            }

            if (satudua){
                if (!cek[i+2]){
                    cek[i+2]=1;
                    v.pb(i+2);
                }
            }
            else if (satu && !cek[i]){
                if (!cek[i+1]){
                    cek[i+1]=1;
                    v.pb(i+1);
                }
            } else if (dua){
                cek[i+1]=1;
                v.pb(i+1);
            }
        }

        cout << v.size() << el;
        for (auto x : v){
            cek[x]=0;
            cout << x+1 << " ";
        }
        cout << el;

        v.clear();
    }

    return 0;
}