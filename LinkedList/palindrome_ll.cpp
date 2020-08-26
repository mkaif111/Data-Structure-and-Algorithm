#include<iostream>
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
node* tail ;
void insert_ll(int d, node* &head){
	if(head==NULL){
		head = new node(d);
		tail = head;
		
	}
	tail->next = new node(d);
	tail = tail->next;
}
node* reverse(node* head){
	if(head == NULL or head->next == NULL){
		return head;
	}
	node* shead = reverse(head->next);
	head->next->next = head->next;
	head->next = NULL;
	return shead;
}
bool palindrome(node* head){
	if(head==NULL or head->next == NULL)
		return 1;
	node* rev = reverse(head);
	while(head!=NULL){
		if(head->data!=rev->data)
			return 0;
		head = head->next;
		rev = rev->next;
	}
	return 1;
}
int main() {
	int n;
	cin>>n;
	node*head = NULL;
	for(int i=0;i<n;i++){
		int d; cin>>d;
		insert_ll(d,head);
	}
	if(palindrome(head)){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<"\n";
		
	}
	return 0;
}