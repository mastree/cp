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
    bool udh;
    pair<int,int> a,b;
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    while (q--){
        int n,m;
        cin >> n >> m;

        string s[n];
        for (int i=0;i<n;i++){
            cin >> s[i];
        }

        hue cek[26];
        for (int i=0;i<26;i++) cek[i].udh=0;
        bool bisa=1;
        int count=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (s[i][j]!='.'){
                    if (!cek[s[i][j]-'a'].udh){
                        
                        cek[s[i][j]-'a'].udh=1;
                        char c=s[i][j];
                        int x1=-1,x2=-1;
                        int y1=-1,y2=-1;

                        for (int k=0;k<n;k++){
                            if (s[k][j]==c){
                                if (x1==-1) x1=k;
                                else x2=k;
                            }
                        }
                        for (int k=0;k<m;k++){
                            if (s[i][k]==c){
                                if (y1==-1) y1=k;
                                else y2=k;
                            } 
                        }

                        if (x2==-1 && y1!=-1){
                            cek[c-'a'].a=mp(i,y1);
                            cek[c-'a'].b=mp(i,max(y1,y2));
                            for (int k=y1;k<=max(y1,y2);k++){
                                if (s[i][k]<c){
                                    bisa=0;
                                    break;
                                }
                            }
                        } else if (x1!=-1 && y2==-1){
                            cek[c-'a'].a=mp(x1,j);
                            cek[c-'a'].b=mp(max(x2,x1),j);
                            for (int k=x1;k<=max(x1,x2);k++){
                                if (s[k][j]<c){
                                    bisa=0;
                                    break;
                                }
                            }
                        } else{
                            bisa=0;
                        }

                        if (!bisa) break;

                    } else{
                        pair <int,int> a1=cek[s[i][j]-'a'].a;
                        pair <int,int> a2=cek[s[i][j]-'a'].b;
                        if (a1.fi==a2.fi){
                            if (i!=a1.fi){
                                bisa=0;
                            }
                        } else if (j!=a1.se){
                            bisa=0;
                        }
                    }
                } 

            }
            if (!bisa) break;
        }

        if (!bisa){cout << "NO" << el;continue;}
        for (int i=25;i>=0;i--){
            if (cek[i].udh){
                if (count==0) count=i+1;
            } else if (i<count){
                cek[i].udh=1;
                cek[i].a=cek[i+1].a;
                cek[i].b=cek[i+1].b;
            }
        }

        cout << "YES" << el << count << el;
        for (int i=0;i<26;i++){
            if (cek[i].udh){
                cout << cek[i].a.fi+1 << " " << cek[i].a.se+1 << " " << cek[i].b.fi+1 << " " << cek[i].b.se+1 << el;
            }
        }
    }

    return 0;
}