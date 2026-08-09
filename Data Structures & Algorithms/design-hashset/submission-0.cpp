
#include<cstring>
class MyHashSet {

private :
  int t[1000001];
public:
    MyHashSet() {
        memset(t,-1,sizeof(t));
        
    }
    
    void add(int key) {
        t[key]=1;
        
    }
    
    void remove(int key) {
        t[key]=-1;
        
    }
    
    bool contains(int key) {
        return t[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */