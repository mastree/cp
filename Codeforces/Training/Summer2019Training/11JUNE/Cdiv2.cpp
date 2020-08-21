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

struct heh{
    string s;
    int vow,last;

    bool operator<(const heh& rhs) const{
        if (vow!=rhs.vow) return vow<rhs.vow;
        return last<rhs.last;
    }
    bool operator==(const heh& rhs) const{
        return (vow==rhs.vow && last==rhs.last);
    }
};

heh ar[1000001];
map <char,bool> vow;
int cnt[1000001]={0};
vector <string> v;
vector <heh> v2;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vow['a']=1;vow['i']=1;vow['u']=1;vow['e']=1;vow['o']=1;;
    for (int i=0;i<n;i++){
        cin >> ar[i].s;
        int len=ar[i].s.length();char c;
        int cn=0;

        for (int j=0;j<len;j++){
            if (vow[ar[i].s[j]]){
                cn++;c=ar[i].s[j];
            }
        }

        cnt[cn]++;
        
        ar[i].vow=cn;
        ar[i].last=int(c-'a');
    //    cerr << i << el;
    }

    sort(ar,ar+n);
    int c1=0,c2=0;

    for (int i=1;i<=1000000;i++){
        c1+=cnt[i]/2;
    }

    if (c1<=1){
        cout << 0 << el;
        return 0;
    }

    int vlen=c1/2,isi=0,i;
    for (i=0;i<n-1;i++){
        if (ar[i]==ar[i+1]){
            if (isi<vlen){
                v.pb(ar[i].s);
                v.pb(ar[i+1].s);
                i++;
                isi++;
            } else {
                v2.pb(ar[i]);
            }
        } else {
            v2.pb(ar[i]);
        }
    }

    if (i==n-1) v2.pb(ar[i]);

   // vlen=v.size()/2;
    cout << isi << el;
    int vd=0,id=0,vlen2=v2.size();
    for (int k=0;k<isi;k++){
        while (!(v2[id].vow==v2[id+1].vow) && id<(vlen2-1)) id++;
        cout << v2[id].s << " " << v[vd] << el;
        cout << v2[id+1].s << " " << v[vd+1] << el;
        vd+=2;id+=2;
    }

    return 0;
}