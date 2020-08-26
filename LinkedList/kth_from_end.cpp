#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        next = NULL;
        data = d;
    }
};
node *tail = NULL;
void insert_node(int d, node *&head)
{
    if (head == NULL)
    {
        head = new node(d);
        tail = head;
        return;
    }
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
    return;
}
void insert_k(int k, node* head, int n)
{  
    if (head == NULL or head->next == NULL)
        return;

    node *fast = head;
    node *slow = head;
    int count = 0;
    // cout << fast->data << endl;
    int N = n-k;
    while (k > 0)
    {
        fast = fast->next;
        k--;
    }
    // cout << fast->data << endl;
    while (fast!= NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

   
   
    while(slow!=NULL){
        cout<<slow->data<<" ";
        slow = slow->next;
    }

    while(N>0){
        cout<<head->data<<" ";
        head = head->next;
        N--;
    }

    cout << endl;
    return ;
}
int main()
{
    int n;
    cin >> n;

    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        insert_node(d, head);
    }
    int k;
    cin >> k;
    // cout<<"Helpp"<<endl;
    insert_k(k, head, n);
    return 0;
}