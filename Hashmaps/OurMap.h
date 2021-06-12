//saparate chaining 
#include<string>
using namespace std;
template <typename V>
class MapNode{
    public:
        string key;
        V value;
        MapNode *next;

        MapNode(string key, V value){
            this->key = key;
            this->value = value;
        }
        
        //deleting MapNode recursive;
        ~MapNode(){
            delete next;
        }
};

//O(n/b) / O(load factor)
//hashing
template <typename V>
class ourmap{
    MapNode<V> **buckets;
    int count;
    int numBuckets;

    public:
        ourmap(){
            count = 0;
            numBuckets = 5;
            buckets = new MapNode<V> *[numBuckets];
            for (int i = 0; i < numBuckets;i++){
                buckets[i] = NULL;
            }
        }
        ~ourmap(){
            //deleting bucket
            for (int i = 0; i < numBuckets;i++){
                delete buckets[i];
            }
            delete[] buckets;
        }
        
        int size(){
            return count;
        }

    private:
        int getBucketIndex(string key){
            //hashing function
            int hashCode=0;

            int currentCoeff = 1;
            for (int i = key.length() - 1; i >= 0;i--){
                hashCode += key[i] * currentCoeff;
                hashCode = hashCode % numBuckets;
                currentCoeff *= 37;
                currentCoeff = currentCoeff % numBuckets;
            }
            // % for not go beyong bucket size
            return hashCode % numBuckets;
        }

        void rehash(){
            //rehashing if we have load factor > 0.7
            MapNode<V> **temp = buckets;
            buckets = new MapNode<V> *[2 * numBuckets];
            for (int i = 0; i < 2 * numBuckets;i++){
                buckets[i] = NULL;
            }
            int oldBucketCount = numBuckets;
            numBuckets *= 2;
            count = 0;
            //traverse old and inset it into new bucket;
            for (int i = 0; i < oldBucketCount;i++){
                MapNode<V> *head = temp[i];
                while(head!=NULL){
                    string key = head->key;
                    V value = head->value;
                    insert(key, value);
                    head = head->next;
                }
            }
            //delete previous array;
            for (int i = 0; i < oldBucketCount;i++){
                MapNode<V> *head = temp[i];
                delete head;
            }
            delete[] temp;
        }
    public:
        double getLoadFactor(){
            return (1.0 * count) / numBuckets;
        }

    public:
        void insert(string key, V value){
            int bucketIndex = getBucketIndex(key);
            MapNode<V>* head= buckets[bucketIndex];
            while(head!=NULL){
                if(head->key==key){
                    head->value = value;
                    return;
                }
                head = head->next;
            }
            //no value found;
            head = buckets[bucketIndex];
            MapNode<V> *node = new MapNode<V>(key, value);
            node->next = head;
            buckets[bucketIndex] = node;
            count++;
            //load factor find;
            double loadfactor = (1.0*count) / numBuckets;
            if(loadfactor>0.7){
                //rehashing
                rehash();
            }
        }

        V remove(string key){
            int bucketIndex = getBucketIndex(key);
            MapNode<V> *head = buckets[bucketIndex];
            MapNode<V> *pre = NULL;

            while(head!=NULL){
                if(head->key==key){
                    if(pre == NULL){ //first ele
                        buckets[bucketIndex]= head->next;
                    } else{
                        pre->next = head->next;
                    }
                    //free value
                    V value = head->value;
                    //recusive chain break;
                    head->next = NULL;
                    delete head;
                    count--;
                    return value;
                }
                pre = head;
                head = head->next;
            }
            //no node found;
            return 0;
        }

        V getValue(string key){
            int bucketIndex = getBucketIndex(key);
            MapNode<V> *head = buckets[bucketIndex];
            while(head!=NULL){
                if(head->key==key){
                    return head->value;
                }
                head = head->next;
            }
            return 0;
        }

        
};
