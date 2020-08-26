#include<iostream>
using namespace std;

class node{
public:
	int data;
	node*next =NULL;
	node(int d){
		data = d;
	
	}
};
node*tail_node = NULL;
void insert_node(int data , node* &head){
	if(head==NULL){
		head = new node(data);
		tail_node = head;
		return;
	}
	
	node* temp = new node(data);
	tail_node->next= temp;
	tail_node = temp;
	return;
}
void printKth(int k , node*head){
    node* temphead = head;
    while(k>0){
        temphead = temphead->next;
        k--;
    }
    node* printMe = head;
    while(temphead!=NULL){
        printMe = printMe->next;
        temphead = temphead->next;
    }
    cout<<printMe->data<<endl;
}
int main() {
	node*head=NULL;
	int data; cin>>data; 
	insert_node(data, head);
	while(data!=-1){
		cin>>data;
		if(data!=-1){
			insert_node(data,head);
		}
	}
    int k; cin>>k;
    printKth(k,head);
    
	return 0;
}