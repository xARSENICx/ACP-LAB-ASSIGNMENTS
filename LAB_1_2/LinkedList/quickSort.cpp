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


Node* getTail(Node* cur) 
{ 
    while (cur != nullptr && cur->next != nullptr) 
        cur = cur->next; 
    return cur; 
}

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


Node* partition(Node* head, Node* end, Node* &newHead, Node* &newEnd) 
{ 
    Node* pivot = end; 
    Node *prev = nullptr, *cur = head, *tail = pivot; 
    while (cur != pivot) {
        if (cur->val < pivot->val) { 
            if (newHead == nullptr) 
                newHead = cur; 
  
            prev = cur; 
            cur = cur->next; 
        } 
        else
        { 
            if (prev!=nullptr) 
                prev->next = cur->next; 
            Node* tmp = cur->next; 
            cur->next = nullptr; 
            tail->next = cur; 
            tail = cur; 
            cur = tmp; 
        }
    } 

    if (newHead == nullptr) 
        newHead = pivot; 
  
    newEnd = tail; 
    
    return pivot; 
} 


Node* quickSortHelper(Node* head,Node* end) 
{ 
    if (head==nullptr || head == end) 
        return head; 
  
    Node *newHead = nullptr, *newEnd = nullptr; 
  
    Node* pivot = partition(head, end, newHead, newEnd); 

    //sort on left side of pivot
    if (newHead != pivot) { 
        Node* tmp = newHead; 
        while (tmp->next != pivot) 
            tmp = tmp->next; 
        tmp->next = nullptr; 
  
        newHead = quickSortHelper(newHead, tmp); 
  
        tmp = getTail(newHead); 
        tmp->next = pivot; 
    } 
    //sort right side of pivot
    pivot->next = quickSortHelper(pivot->next, newEnd); 
    return newHead; 
} 
 
void quickSort(Node* &head){
    Node* temp = head;
    while(temp->next!=nullptr)temp = temp->next;
    head = quickSortHelper(head,temp);
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
    quickSort(head);
    printList(head);//outputs 1 1 2 25 33 99 

    return 0;
}
