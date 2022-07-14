class MyHashMap {
public:
   vector<list<pair<int, int>>> arr;
int size;
MyHashMap() {
    size = 1113;   //Chosen a large prime number to avoid collision
    arr.resize(1113);
}

void put(int key, int value) {
    int bucket = key%size;
    remove(key);
    arr[bucket].push_back({key, value});
}

int get(int key) {
    int bucket = key%size;
    list<pair<int,int>> ::iterator itr = search(key);
    if(itr == arr[bucket].end()) return -1;
    return itr->second;
}

void remove(int key) {
    int bucket = key%size;
    list<pair<int,int>> ::iterator itr = search(key);
    if(itr != arr[bucket].end()) {
        arr[bucket].erase(itr);
    }
}

list<pair<int,int>> :: iterator search(int key) {
    int bucket = key%size;
    list<pair<int,int>>:: iterator  itr = arr[bucket].begin();
    while(itr != arr[bucket].end()) {
        if(itr->first == key) {
            return itr;
        }
        itr++;
    }
    return itr;
}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */