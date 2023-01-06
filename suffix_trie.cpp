#include<bits/stdc++.h>
using namespace std;

class node{
public:
    char data;
    unordered_map<char,node*> um;
    bool isTerminal;
    node(char d){
        data = d;
        isTerminal = false;
    }
};

class Trie{
public:
    node* root = new node('\0');
    void insert_helper(string word){
        node *temp = root;
        for(char ch:word){
            if(temp->um.count(ch) == 0){
                node *n = new node(ch);
                temp->um[ch] = n;
            }
            temp = temp->um[ch];
        }
            temp->isTerminal = true;
    }

    bool search(string word){
        node *temp = root;
        for(char ch:word){
            if(temp->um.count(ch) == 0) return false;
            temp = temp->um[ch];
        }
        if(temp->isTerminal) return true;
        else return false;
    }

    void insert(string word){
        for(int i=0;i<word.length();i++){
            insert_helper(word.substr(i));
        }
    }
};

int main(){
    string words[]{"apple","ape","no","news","not","never"};
    Trie t;
    for(auto ch:words){
        t.insert(ch);
    }
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        if(t.search(s)) cout<<s<<" is present"<<endl;
        else cout<<s<<" is not present"<<endl;
    }
    return 0;
}
