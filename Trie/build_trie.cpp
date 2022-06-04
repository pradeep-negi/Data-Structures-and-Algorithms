 #include<iostream>
 #include<unordered_map>
 using namespace std;

class Node{
    public:

    char ch;
    unordered_map<char, Node*> mp;
    bool terminal;

    Node(char ch){
        this->ch=ch;
        terminal=false;
    }

};

class Trie{

    public:
    Node*root;

    Trie(){
        root=new Node('\0');
    }
    

    //insertion
    void insert(string str){
        Node *ptr=root;
        int size=str.length();
        for(int i=0;i<size;i++){
            char ch=str[i];
            if(ptr->mp.find(ch)==ptr->mp.end()){   //the element is not present in the map 
                Node* temp=new Node(ch);
                ptr->mp[ch]= temp;
            }
            ptr=ptr->mp[ch];
        }
        ptr->terminal=true;
    }
  
};

 int main(){
     Trie t;
     t.insert("apple");
     t.insert("app");
     t.insert("news");
     t.insert("no");
     return 0;
 }
