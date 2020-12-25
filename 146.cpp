#include<bits/stdc++.h>
using namespace std;

list<int> cache;
unordered_map<int, pair<int, list<int>::iterator>> mp;
int cache_size;
LRUCache(int capacity) {
  cache_size = capacity; 
}

int get(int key) {
  if (mp.find(key) != mp.end()) {
    list<int>::iterator it = mp[key].second;
    cache.erase(it);
    cache.push_front(key);
    mp[key].second = cache.begin();
    return mp[key].first;
  }
  return -1;
}

void put(int key, int value) {
  if (mp.find(key) != mp.end()) {
    cache.erase(mp[key].second);
  }
  cache.push_front(key);
  mp[key].second = cache.begin();
  mp[key].first = value;
  if (mp.size() > cache_size) {
    int least_used = cache.back();
    cache.pop_back();
    mp.erase(least_used);
  }
}