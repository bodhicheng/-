class Solution {
public:
    vector<int> sortArray(vector<int>& a) {
        srand(time(NULL));
        qsort(a,0,a.size()-1);
        return a;
    }
    void qsort(vector<int> &a,int l,int r) {
        if(l >= r) return ;
        int w = partition(a,l,r);
        qsort(a,l,w-1);
        qsort(a,w+1,r);
    }
    int partition(vector<int> &a,int l,int r) {
        int w = rand()%(r-l+1) + l;
        swap(a[w],a[r]);
        int x = a[r],i = l;
        for(int j=l;j<=r;j++) {
            if(a[j]<=x) swap(a[j],a[i++]);
        }
        return i-1;
    }
};