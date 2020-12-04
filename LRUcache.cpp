#include "pch.h"
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache
{
    list<int> dq;
    unordered_map <int, list<int>::iterator > mapit;
    int capacity;
    public:
    LRUCache(int n)
    {
        capacity = n;
    }
    void display()
    {
        for(auto i = dq.begin(); i!=dq.end(); i++)
        {
            cout<<(* i)<<" ";
        }
        cout<<endl;
    }
    void refer(int x)
    {
        // not present in cache
        if (mapit.find(x) == mapit.end()) {
            // cache is full
            if (dq.size() == capacity) {
                // delete least recently used element
                int last = dq.back();
    
                // Pops the last elmeent
                dq.pop_back();
    
                // Erase the last
                mapit.erase(last);
            }
        }
    
        // present in cache
        else
            dq.erase(mapit[x]);
    
        // update reference
        dq.push_front(x);
        mapit[x] = dq.begin();
    }

};



    int main()
    {
        LRUCache ca(5);
        ca.refer(1);
        ca.refer(2);
        ca.refer(3);
        ca.refer(1);
        ca.refer(4);
        ca.refer(5);
        ca.display();   

        return 0;
    }