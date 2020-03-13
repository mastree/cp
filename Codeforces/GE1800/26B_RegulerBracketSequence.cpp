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

const int N = 1000010;

struct hue {
    ll tot, op, cl;
};

string s;
int n;
hue stree[4*N];

void constree(int low, int high, int pos){
 //   cerr << low << " " << high << el;
    if (low==high){
        stree[pos].tot=0;
        if (s[low]=='(') stree[pos].op=1;
        else stree[pos].cl=1;
        return;
    }

    int left=2*pos+1;
    int mid=(low+high)/2;

    constree(low,mid,left);
    constree(mid+1,high,left+1);

    hue tree1=stree[left], tree2=stree[left+1];
    ll del=min(tree1.op,tree2.cl);
    
    stree[pos].tot=tree1.tot+tree2.tot+del;
    stree[pos].op=tree1.op+tree2.op-del;
    stree[pos].cl=tree1.cl+tree2.cl-del;
 //   cout << low << " " << high << " " << pos << " " << stree[pos].tot << el;
}

hue cari(int low, int high, int qlow, int qhigh, int pos){
    if (qlow>high || qhigh<low){
        hue tm;
        tm.tot=0;
        tm.op=0;
        tm.cl=0;
        return tm;
    }
    if (qlow<=low && high<=qhigh) return stree[pos];

    int left=2*pos+1;
    int mid=(low+high)/2;
    hue res1=cari(low,mid,qlow,qhigh,left);
    hue res2=cari(mid+1,high,qlow,qhigh,left+1);

    hue res;
    ll del=min(res1.op,res2.cl);
    res.tot=res1.tot+res2.tot+del;
    res.op=res1.op+res2.op-del;
    res.cl=res1.cl+res2.cl-del;

//    cout << low << " " << high << " " << pos << " " << res.tot << el;
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n=s.length();
    constree(0,n-1,0);

    int q;
    cin >> q;

    hue tm=cari(0,n-1,0,n-1,0);
    cout << tm.tot*2 << el;

    return 0;
}