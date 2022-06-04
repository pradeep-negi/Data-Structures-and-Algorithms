#include <iostream>
using namespace std;

class Node{

public:
    string key;
    int val;
    Node* next;
    Node(string k, int value){
        key=k;
        val=value;
        next=NULL;
    }

    ~Node(){
        if(next!=NULL)
            delete next;
    }

};

class HashTable{

public:
    int cs; 
    int ms;
    Node** table;

    int hashfun(string k){
        int h=1;
        int size=k.length();
        int sum=0;
        for(int i=0;i<size;i++){
            sum=(sum+k[i]*h)%ms;
            h=(h*29)%ms;
        }
        return sum;
    }

    void rehash(){

        Node** oldtable=table;
        int oldsize=ms;
        ms=2*ms+1;
        table=new Node*[ms];
        for(int i=0;i<ms;i++)
            table[i]=NULL;
        
        for(int i=0;i<oldsize;i++){
            Node* temp=oldtable[i];
            while(temp!=NULL){
                string k=temp->key;
                int value=temp->val;
                insert(k, value);
                temp=temp->next;
            }
            if(oldtable[i]!=NULL)
                delete oldtable[i];

        }
        delete []oldtable;
    }

    HashTable(int default_size=7){

        cs=0;
        ms=default_size;
        table=new Node*[ms];
        for(int i=0;i<ms;i++){
            table[i]=NULL;
        }

    }

    void insert(string key, int value){

        Node* temp=new  Node(key, value);
        int idx=hashfun(key);
        temp->next=table[idx];
        table[idx]=temp;
        cs++;
        float l_factor=cs/(float)ms;
        if(l_factor>0.7){
            rehash();
        }

    }

    void print(){
        for(int i=0;i<ms;i++){
            Node* temp=table[i];
            cout<<"bucket "<<i<<"->";
            while(temp!=NULL){
                cout<<temp->key<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    Node * search(string key){
        int idx=hashfun(key);
        Node* temp=table[idx];
        while(temp!=NULL){
            if(key==temp->key)
                return temp;
            temp=temp->next;
        }

        return NULL;
    }
};

int main() {
	// your code goes here
    HashTable t;
    t.insert("apple",100);
    t.insert("orange",120);
    t.insert("papaya",116);
    t.insert("litchi",150);
    t.insert("guava",100);
    t.print();
    Node* ans= t.search("guava");
    if(ans==NULL)
        cout<<"fruit not found"<<endl;
    else
        cout<<"the value of fruit is :"<<ans->val<<endl;
	return 0;
}

