class Solution {
public:
    ListNode* sortList(ListNode* head) {
        srand(time(NULL));
        int n = 0; ListNode *p = head;
        while(p) p = p -> next,n++;
        return qsort(head,n);
    }
    ListNode* qsort(ListNode* head,int l) {
        if(l<=1) return head;
        ListNode *ret = head;
        int w = partition(ret,l);
        ListNode *p = ret;
        for(int i=0;i<w;i++) p = p->next;
        ListNode *h = qsort(ret,w-1);
        qsort(p,l-w);
        return h;
    }
    int partition(ListNode *&head,int l) {
        int w = rand()%l;
        ListNode *p = head,*q = head;
        for(int i=0;i<w;i++) p = p->next;
        int x = p -> val;
        ListNode *h = new ListNode(0),*hp = h;
        ListNode *r = new ListNode(0),*rp = r;
        int ret = 0;
        while(q && l--) {
            if(q != p) 
                if(q->val<=x) {
                    hp -> next = q;
                    hp = hp ->next;
                    ret++;
                } else {
                    rp -> next = q;
                    rp = rp -> next;
                }
            q = q->next;
        }
        hp->next = p; hp = hp->next;
        hp ->next = r->next;
        rp ->next = q==NULL?NULL:q->next;
        head = h->next;
        return ret+1;
    }
};