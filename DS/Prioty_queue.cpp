#include <bits/stdc++.h>
using namespace std;

class Prioty_queue{
    vector <int> heap;
public :
    void safe_down(int i){
        int l = i*2+1;
        int r = i*2+2;

        if(l>=  (int)heap.size()) return;

        if(r< (int)heap.size() && heap[l] > heap[r]){
            swap(heap[l],heap[r]);
        }
        if(heap[i]>heap[l]){
            swap(heap[i],heap[l]);
            safe_down(l);
        }
    }

    void safe_up(int i){
        if(i==0) return;
        int p = (i-1)/2;
        if(heap[p]>heap[i]){
            swap(heap[i],heap[p]);
            safe_up(p);
        }
    }

    void push(int val){
        heap.push_back(val);
        safe_up(heap.size()-1);
    }

    void pop(){
        heap[0]=heap.back();
        heap.pop_back();
        safe_down(0);
    }

    void emplace(int val){
        heap[0]=val;
        safe_down(0);
    }

    int Size(){
        return heap.size();
    }

    bool Empty(){
        return heap.empty();
    }
    int Top(){
        return heap[0];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Prioty_queue pq;

    pq.push(5);
    pq.push(7);
    pq.push(1);
    pq.push(2);
    pq.pop();
    pq.emplace(10);
    cout << pq.Top();

}