#include <iostream>
#include <deque> 
#include <algorithm>
using namespace std;

/*
 * the way it works is
 * it is always a slide windows from i -> i + k -1
 * whenever add an index to the deque,
 * if its arr[i] >= arr[deque.back()], we can safely
 * remove any of them, because when windows move,
 * if i is in the deque, it will always be arr[i]
 * not any of them before it, so we can remove them.
 * but we still have to keep any smaller after it
 * also need to pop the front if it is <= (i-k)
 * so it is a deque
 */
void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> dq;
    deque<int> oq;


    /* it is an ordered queue with index big->small */
    for(int j = 0; j < k; j++) {
        while(!dq.empty() && arr[dq.back()] <= arr[j]) {
            dq.pop_back();
        }
       dq.push_back(j);
    }
    oq.push_back(dq.front());

    for(int i = k; i < n; i ++) {
        while(!dq.empty() && dq.front() <= (i - k)) {
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        oq.push_back(dq.front());
    }
    for(auto i : oq) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}


