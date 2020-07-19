class LRUCache {
public:
    struct Node {
        int key;
        int value;
        list<Node>::iterator iter;
        Node() {}
        Node(int k,int v):key(k),value(v) {}
    };
    unordered_map<int,Node> cache;
    list<Node> s;
    int Capacity;
    LRUCache(int capacity) {
        Capacity = capacity;
    }

    int get(int key) {
        if(cache.count(key)) {
            Node &node = cache[key];
            update(node);
            return node.value;
        } else return -1;
    }

    void put(int key, int value) {
        if(cache.count(key)) {
            Node &node = cache[key];
            node.value = value;
            update(node);
        } else {
            if(Capacity == 0) return ;
            if(Capacity == cache.size()) removeNode();
            Node node = Node(key,value);
            addNode(node);
        }
    }

    void addNode(Node &node) {
        s.push_front(node);
        node.iter = s.begin();
        cache[node.key] = node;
    }

    void removeNode() {
        Node &node = s.back();
        cache.erase(node.key);
        s.pop_back();
    }
    void update(Node &node) {
        s.erase(node.iter);
        s.push_front(node);
        node.iter = s.begin();
    }
};