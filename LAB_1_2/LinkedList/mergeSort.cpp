#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Node{
    public:
        int val;
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

void printList(Node* head){
    if(head==nullptr){
        cout<<endl;
        return;
    }
    cout<<(head->val)<<" ";
    printList(head->next);
}

void append(Node* &head, int ele){
    Node* addedEle = new Node(ele);
    if(head==nullptr){
        head = addedEle;
        return;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = addedEle;
}


void divide(Node* &head,Node* &first,Node* &second){
    int sz = 0;
    Node* temp = head;
    while(temp!=nullptr){
        sz++;
        temp = temp->next;
    }
    int idx = sz/2;
    temp = head;
    while(idx>1){
        temp = temp->next;
        idx--;
    }
    first = head;
    second = temp->next;
    temp->next = nullptr;
}

Node* merge(Node* &first,Node* &second){
    if(first==nullptr){
        return second;
    }
    else if(second==nullptr){
        return first;
    }
    Node* ans;
    if(first->val<second->val){
        ans = first;
        first = first->next;
        ans->next = merge(first,second);
    }
    else{
        ans = second;
        second = second->next;
        ans->next = merge(first,second);
    }
    return ans;
}

void mergesort(Node* &head){
    if(head==nullptr || head->next==nullptr){
        return;
    }
    Node* first;
    Node* second;
    divide(head,first,second);
    // cerr<<first->val<<" "<<second->val<<endl;
    mergesort(first);
    mergesort(second);
    head = merge(first,second);
}

int main(){

    Node* head=nullptr;
    append(head,99);
    append(head,1);
    append(head,25);
    append(head,33);
    append(head,2);
    append(head,1);

    printList(head);//outputs 99 1 25 33 2 1
    mergesort(head);
    printList(head);//outputs 1 1 2 25 33 99 


    return 0;
}
