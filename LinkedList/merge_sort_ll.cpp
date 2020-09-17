#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next = NULL;
	Node(int d){
		data = d;
		next = NULL;
	}
};
Node* tail = NULL;
void input_node(int data, Node*& head){
	if(head==NULL){
		head = new Node(data);
		tail = head;
		
	}
	
	tail->next = new Node(data);
	tail = tail->next;
	
}
void print(Node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

Node* merge_linkedlist(Node*a , Node*b){
	if(a==NULL){
		return b;
	}

	if(b==NULL){
		return a;

	}
	Node* c;
	if(a->data < b->data){
		c = a;
		c->next = merge_linkedlist(a->next,b);

	}
	else{
		c = b;
		c->next = merge_linkedlist(a,b->next);
	}

	return c;


}



Node* mid(Node*head){
    if(head ==NULL || head->next==NULL ){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* mergeSort(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* m = mid(head);
    Node* a = head;
    Node* b = m->next;
	
    m->next = NULL;
print(a);
	print(b);
    a = mergeSort(a);
    b = mergeSort(b);

    Node* c = merge_linkedlist(a,b);
    return c;


}











int main() {
	
	

	int t; cin>>t;
	while(t--){
		Node* head1 = NULL;
		int n , n1;
		cin>>n;
		while(n--){
			int d; cin>>d;
			input_node(d,head1);
		}
		cin>>n1;
		while(n1--){
			int d; cin>>d;
			input_node(d,head1);
		}
 
		Node* ans = mergeSort(head1);
		print(ans);
	}

	return 0;
}