class MyHashSet {
    //APPROACH 1
    //PROBLEM- In this approach we have limited size of vector that is 10^6 only
    //if key cross this range then we cant store it,also it is complex also
    /*
public:
    vector<int> m;
    int siz;
    MyHashSet() {
        siz = 1e6+1;
        m.resize(siz);
    }
    
    void add(int key) {
        m[key] = 1;
    }
    
    void remove(int key) {
        m[key]=0;
    }
    
    bool contains(int key) {
        if(m[key]) return true;
        else return false;
    }
    */
    //APPROACH 2 
    //This is approach is less complex and we dont have siz problem as we are using hash        //function and Channing method in it.
    public:
    vector<list<int>> m;
    int siz;
    MyHashSet() {
        siz = 1000;//eg. size
        m.resize(siz);
    }
    //create a hash function which return index of key in vector through maths operation
    int hash(int key){
        return key%siz;
    }
    //make a search function to search postion of key in doubly list at ith position
    list<int> :: iterator search(int key){
        int i = hash(key);
        return find(m[i].begin(),m[i].end(),key);
    }
    void add(int key) {
        if(contains(key))return;
        int i= hash(key);
        m[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i=hash(key);
        m[i].erase(search(key));//it will delete the node at position givin by search
                                //its a function to delete a node in doubly linked list
    }
    
    bool contains(int key) {
        int i = hash(key);
        if(search(key)!=m[i].end()) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */