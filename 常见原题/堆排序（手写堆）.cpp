struct heap {
        vector<int> a;
        int size;
        heap(int n):size(n) {
            a.resize(n);
        }
        heap(int arr[],int n) {
            size = n;
            a.resize(n);
            for(int i=0;i<n;i++) a[i] = arr[i];
        }
        heap(vector<int> &arr) {
            size = arr.size();
            a.resize(size);
            for(int i=0;i<size;i++) a[i] = arr[i];
        }
        void build() {
            for(int i=size/2-1;i>=0;i--) {
                pushDown(i);
            }
        }
        void push(int x) {
            a[size++] = x;
            int i = size-1;
            while(i) {
                int f = (i-1)/2;
                if(a[f]<a[i]) swap(a[i],a[f]);
                i = f;
            }
        }
        void pushDown(int x) {
            int l = (x<<1)|1,r = l+1;
            if(l>=size) return ;
            int mx = x;
            if(a[l]>a[x]) mx = l;
            if(r<size && a[r]>a[mx]) mx = r;
            if(mx == x) return ;
            swap(a[x],a[mx]);
            pushDown(mx);
        }
        int pop() {
            int x = a[0];
            swap(a[0],a[--size]);
            pushDown(0);
            return x;
        }
    };