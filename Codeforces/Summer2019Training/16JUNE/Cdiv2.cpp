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

struct hue{
    bool ada;
    int sz;
    char jenis[3];

    operator == (const hue& rhs) const{
        return (sz==rhs.sz && ada==rhs.ada && jenis[0]==rhs.jenis[0] && jenis[1]==rhs.jenis[1] && jenis[2]==rhs.jenis[2]);
    }
};

int n,m;
string s[1001];
vector<int> comp[1001]; // kompres[column];
hue cek[1001][1001];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> s[i];
    }

    for (int j=0;j<m;j++){
        char bef=s[0][j];
        int cnt=1;
        for (int i=1;i<n;i++){
            if (bef!=s[i][j]){
                comp[j].pb(cnt);
                cnt=1;
                bef=s[i][j];
            } else {
                cnt++;
            }
        }
        comp[j].pb(cnt);
    }


    for (int j=0;j<m;j++){
        int row=0,len=comp[j].size();
        
        for (int i=0;i<len-2;i++){
            if (comp[j][i]>=comp[j][i+1] && comp[j][i+1]<=comp[j][i+2]){
                int cd=comp[j][i]-comp[j][i+1];
                cek[row+cd][j].ada=1;
                cek[row+cd][j].sz=comp[j][i+1];
                
                int plus=cd;
                for (int id=0;id<3;id++){
                    cek[row+cd][j].jenis[id]=s[row+plus][j];
                    plus+=comp[j][i+1];
                }
            }

            row+=comp[j][i];
        }
    }

    ll ans=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (!cek[i][j].ada) continue;

            if (j==m-1){
                ans++;
                break;
            }
            int jex=j+1;
            while (cek[i][j]==cek[i][jex] && jex<m) jex++;
            ll tm=(ll)(jex-j);
            ans+=(tm+1)*(tm)/2;
            j=jex-1;
        }
    }

    cout << ans << el;

    return 0;
}