/*
leetcode 146
*/
class LRUCache {
    LinkedHashMap<Integer,Integer> map;
    int Capacity = -1;
    public LRUCache(int capacity) {
        map = new LinkedHashMap<>(capacity);
        Capacity = capacity;
    }
    
    public int get(int key) {
        if(map.containsKey(key)) {
            int v = map.get(key);
            update(key,v);
            return map.get(key);
            
        } else return -1;
    }
    
    public void put(int key, int value) {
        if(Capacity <= 0) return ;
        if(map.containsKey(key)) {
            update(key,value);
            return ;
        }
        if(map.size() == Capacity) remove();
        map.put(key,value);
        
    }
    void remove() {
        map.remove(map.entrySet().iterator().next().getKey());
    }
    void update(int key,int v) {
        map.remove(key);
        map.put(key,v);
    }
}