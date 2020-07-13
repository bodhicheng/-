/*
leetcode 460
*/
class LFUCache {
    HashMap<Integer, Node> cache;
    HashMap<Integer, LinkedHashSet<Node>> map;
    int c,min;
    public LFUCache(int capacity) {
        cache = new HashMap<>(capacity);
        map = new HashMap<>();
        c = capacity;
    }

    public int get(int key) {
        Node node = cache.get(key);
        if(node == null) {
            return -1;
        }
        freqInc(node);
        return node.value;
    }

    public void put(int key, int value) {
        if(c == 0) return ;
        Node node = cache.get(key);
        if(node != null) {
            node.value = value;
            freqInc(node);
        } else {
            node = new Node(key,value);
            if(cache.size() == c) removeNode();
            addNode(node);
        }
    }
    void addNode(Node node) {
        cache.put(node.key,node);
        LinkedHashSet<Node> set = map.get(node.freq);
        if(set == null) {
            set = new LinkedHashSet<>();
            map.put(node.freq,set);
        }
        set.add(node);
        min = 1;
    }
    void removeNode () {
        LinkedHashSet<Node> set = map.get(min);
        Node dead = set.iterator().next();
        cache.remove(dead.key);
        set.remove(dead);

    }
    void freqInc(Node node) {
        int freq = node.freq;
        LinkedHashSet<Node> set = map.get(freq);
        set.remove(node);
        if(freq == min && set.isEmpty()) {
            min = freq+1;
        }
        node.freq++;
        LinkedHashSet<Node> newSet = map.computeIfAbsent(freq + 1, k -> new LinkedHashSet<>());
        newSet.add(node);
    }
    class Node {
        int key;
        int value;
        int freq = 1;
        Node() {}
        Node(int k,int v) {
            this.key = k;
            this.value = v;
        }
    }
}