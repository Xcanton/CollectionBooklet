/***
 * 不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
 * 
 * Design a HashSet without using any built-in hash table libraries.
*/

#include <vector>
#include <list>


using namespace std;

class MyHashSet {
private:
    vector<list<int>> data;
    static const int base = 769;
    static int hash(int key) {
        return key % base;
    }
public:
    MyHashSet(): data(base) {    }
    
    void add(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++){
            if ((*it) == key) {return;}
        }
        data[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) {
                data[h].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) {return true;}
        }
        return false;
    }
};