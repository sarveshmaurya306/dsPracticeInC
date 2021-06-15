#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
    vector<int> pq;
    public:
        bool isEmpty(){
            return pq.size() == 0;
        }
        
        //return the size of priority queue
        int getSize(){
            return pq.size();
        }

        int getMin(){
            if(isEmpty()){
                return 0; //priority queue is empty;
            }
            return pq.at(0);
        }
        //log(n)
        void insert(int element){
            pq.push_back(element);
        
            int childIndex = pq.size() - 1;
            //upheapify
            while(childIndex>0){
                int parentIndex = (childIndex - 1) / 2;

                if(pq[childIndex]< pq[parentIndex]) {
                    swap(pq[childIndex], pq[parentIndex]);
                } else {
                    break;
                }
                childIndex = parentIndex;
            }
        }
        // O(logn)
        int removeMin(){
            if(isEmpty()){
                return 0; //empty pq;
            }
            int deletedElement = pq.at(0);
            swap(pq.at(0), pq.at(pq.size() - 1));
            pq.pop_back();

            //down heapify
            int parentIndex = 0;
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;

            while(leftChildIndex< pq.size()){
                int minIndex = parentIndex;
                if(pq[minIndex] > pq[leftChildIndex]){
                    minIndex = leftChildIndex;
                }
                if(rightChildIndex<pq.size() && pq[minIndex] > pq[rightChildIndex]){
                    minIndex = rightChildIndex;
                }
                if(parentIndex==minIndex){
                    break;
                }

                swap(pq[parentIndex], pq[minIndex]);
                parentIndex = minIndex;
                leftChildIndex = 2 * parentIndex + 1;
                rightChildIndex = 2 * parentIndex + 2;
            }

            return deletedElement;
        }
};

//space => O(N)