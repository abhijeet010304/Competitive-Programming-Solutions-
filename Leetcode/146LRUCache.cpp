/*
Brute force 
*/
class LRUCache {
public:
    vector<pair<int,int>> cache;
    int cap ;
    LRUCache(int capacity) {
        cap = capacity;

    }


    int get(int key) {

        for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                int val = cache[i].second;
                pair<int,int> temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);

                return val;
            }
        }
        return -1;

    }

    void put(int key, int value) {
        bool found= false;
        for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                found =true;
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});
                break;
            }
        }
        if(found)return ;
        else{
            if(cache.size()==cap){
                cache.erase(cache.begin());
                cache.push_back({key,value});
            }
            else{
                cache.push_back({key,value});
            }
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
