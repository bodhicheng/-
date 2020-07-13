class Solution {
public:
    vector<int> sortArray(vector<int>& a) {
        srand(time(NULL));
        qsort(a,0,a.size()-1);
        return a;
    }
    void qsort(vector<int> &a,int l,int r) {
        stack<int> s;
        s.push(l); s.push(r);
        while(!s.empty()) {
            int dr = s.top(); s.pop();
            int dl = s.top(); s.pop();
            if(dl>=dr) continue;
            int w = partition(a,dl,dr);
            s.push(dl); s.push(w-1);
            s.push(w+1); s.push(dr);
        }
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