#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
    public:
        int val,mn;
        Node* next;
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }

    Node(int val,Node * next){
        this->val = val;
        this->next = next;
    }
};

//stack data structure made from a singly linked list
//each node has an extra mn variable so that we can perform find-min in O(1) time
class stk{
    public: 
        Node* head=nullptr;
        void push(int ele){
            Node* addedEle = new Node(ele);
            addedEle->next = head;
            if(head==nullptr){
                addedEle->mn = ele;
            }
            else{
                addedEle->mn = min(ele,head->mn);
            }
            head = addedEle;
        }
        void pop(){
            if(head==nullptr){
                cout<<"Stack already empty."<<endl;
                return;
            }
            head= head->next;
        }

        int findMin(){
            return (head->mn);
        }

        void printStk(){
            Node* temp = head;
            while(temp!=nullptr){
                cout<<temp->val<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

bool regularCheck(string s){
    map<char,char> mp= {{')','('},{']','['}, {'}','{'}};
    stack<char> st;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(st.empty() || st.top()!=mp[s[i]])return false;
            else st.pop();
        }
    }
    return true;
}




int main(){
    string s="([({})])(]";//not regular
    string t ="([{}])(({}))";//regular
    cout<<regularCheck(s)<<endl;//false
    cout<<regularCheck(t)<<endl;//true

    
    //2//stk is custom stack data structure
    //example of push,pop and findMin operations
    stk st1;
    st1.push(5);
    st1.push(8);
    st1.push(4);
    st1.pop();
    st1.printStk();

    //O(1) findMin function
    cout<<st1.findMin()<<endl;
    st1.push(1);
    cout<<st1.findMin()<<endl;

    return 0;
}
