#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : protected Cache {
    int number;
public:
    LRUCache(int acp) /*: Cache::cp(acp) */{ number = 0; Cache::cp = acp; Cache::head = NULL; Cache::tail = NULL;}
    void set(int key, int value) {
        Node *p = NULL, *tp;
        /* hit, move to head */
        if (mp.end() != mp.find(key)) {
            p = mp[key];
            if (p != head) {
                tp = p->prev;
                tp->next = p->next;
                if (p->next)
                    p->next->prev = tp;
            }
        } else {
            p = new Node(key, value);

            /* no hit, add to head */
            p->next = head;
            if (head) {
                head->prev = p;
            }

            head = p;
            if (!tail) {
                tail = p;
            }
            /* if > cp, remove the last from list and map */
            if ((++number > cp) && tail) {
                Node *tprev = tail->prev;
                if (tprev) {
                    tprev->next = NULL;
                }
                mp.erase(mp.find(tail->key));
                if (tail == head) {
                    head = NULL;
                }
                delete tail;
                tail = tprev;
                --number;
            }
            if (number) {
                mp.insert({key, p});
            }
        }
    }
    int get(int key) {
        if (mp.end() != mp.find(key)) {
            Node *p = NULL;

            p = mp[key];
            return p->value;
        }
        return -1;
    }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

