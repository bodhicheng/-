class LFUCache {
public:
    struct Node {
        int key;
        int value;
        int freq = 1;
        list<Node>::iterator iter;
        Node() {}
        Node(int k,int v):key(k),value(v) {}
        bool operator ==(const Node &x) {
            return key == x.key;
        }
    };
    int Capacity;
    int mn;
    unordered_map<int,Node> cache;
    unordered_map<int,list<Node> > freqMap;
    LFUCache(int capacity) {
        Capacity = capacity;
    }

    int get(int key) {
        if(cache.count(key)) {
            Node &node = cache[key];
            freqInc(node);
            return node.value;
        } else return -1;
    }

    void put(int key, int value) {
        if(Capacity == 0) return ;
        if(cache.count(key)) {
            Node &node = cache[key];
            node.value = value;
            freqInc(node);
        } else {
            if(cache.size() == Capacity) removeNode();
            Node node = Node(key,value);
            addNode(node);
        }
    }

    void addNode(Node &node) {
        list<Node> &v = freqMap[1];
        v.push_front(node);
        node.iter = v.begin();
        cache[node.key] = node;
        mn = 1;
    }

    void removeNode() {
        list<Node> &v = freqMap[mn];
        Node &node = v.back();
        cache.erase(node.key);
        v.pop_back();
    }

    void freqInc(Node &node) {
        list<Node> &v = freqMap[node.freq];
        v.erase(node.iter);

        if(node.freq == mn && v.size() == 0) mn++;
        node.freq++;
        freqMap[node.freq].push_front(node);
        node.iter = freqMap[node.freq].begin();
    }
};
