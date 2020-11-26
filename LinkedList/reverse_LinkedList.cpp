#include<iostream>
#include<vector>
#include<string>

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void reverseLinkedList(node* &head ){
    node* curr = head;
    node* prev = NULL;
    node* NEXT = NULL;
    while(curr!=NULL){
        NEXT = curr->next;
        curr->next = prev;
        prev = curr;
        curr = NEXT;
    }
    head = prev;
}
void printLinkedList(node* head){
    if(head==NULL)
        return ;
    
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}

int main(){
    node* head = new node(10);
    head->next = new node(15);
    head->next->next = new node(100);
    head->next->next->next = new node(90);

    printLinkedList(head);

    reverseLinkedList(head);
    printLinkedList(head);
}