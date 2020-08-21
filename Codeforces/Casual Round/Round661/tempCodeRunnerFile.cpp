p);
    for (int i=1;i<=n;i++){
        int l = ar[i].fi, r = ar[i].se;
        cout << l << " " << r << el;
        int temp = ask(r);
        upd(r, temp + 1);
    }
    cout << ask(1) << el;