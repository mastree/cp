typedef vector<vector<ll>> matrix;

matrix mult(matrix a, matrix b){
    matrix ret(2, vector<ll>(2, 0));

    for (int i=0;i<2;i++){
        for (int k=0;k<2;k++){
            for (int j=0;j<2;j++){
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }

    return ret;
}

matrix fmat(matrix a, ll b){
    matrix ret(2, vector<ll>(2, 0));
    if (b == 0){
        ret[0] = {1, 0};
        ret[1] = {0, 1};
        return ret;
    }
    if (b == 1){
        return a;
    }
    ret = fmat(a, b / 2);
    ret = mult(ret, ret);
    if (b & 1){
        ret = mult(ret, a);
    }

    return ret;
}