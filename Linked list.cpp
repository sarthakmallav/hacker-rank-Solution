#include <iostream>
using namespace std;
//head is the pointer which points to the adrress of the first element of the linked list, In main() you can see we intialise with head=0(Otherwise it can throw random value)
class node{
public:
    int data;
    node *next;

    node(int d){
        data=d;
        next=NULL;
    }
};
node* insertAtHead(node *&head, int d){
    node *ptr=new node(d);
    ptr->next=head;
    head=ptr;

    return head;
} 

node* insertAtIndex(node *&head, int d,int index){
    node *ptr=new node(d);
    node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }

    ptr->next=p->next;
    p->next=ptr;

    return head;
}

node* insertAtEnd(node *&head, int d){
    node *ptr=new node(d);
    node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

void printlist(node *head){
        while(head!=NULL){
            cout<< head->data<<" -> ";
            head=head->next;
            
        }
        cout<<endl;
}

int main(){
    node *head=NULL;
    printlist(head);
    insertAtHead(head,1);
    printlist(head);
    insertAtEnd(head,9);
    insertAtEnd(head,10);
    insertAtEnd(head,11);
    insertAtEnd(head,12);
    insertAtEnd(head,13);
    printlist(head);
    insertAtIndex(head,99,2);
    printlist(head);
    return 0;
}
