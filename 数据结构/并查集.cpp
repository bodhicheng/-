int f[N];

void init() {
    for(int i=0;i<N;i++) f[i] = i;
}

int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

void union(int x, int y){
    int fa = find(x);
    int fb = find(y);
    f[fa] = fb;
}