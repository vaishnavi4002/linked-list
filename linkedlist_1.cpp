#include <iostream>

using namespace std;
class node{
    public:
       int data;
       node* next;

    node(int d){
       data=d;
       next=NULL;
    }

    ~node(){
      int value=this->data;
      if(this->next!=NULL){
        delete next;
        this->next=NULL;
      }
      cout<<"free up the space of value"<<value<<endl;
  }
};

void insertAtHead(node* &head,int data){
      node* temp=new node(data);
      temp->next=head;
      head=temp;
}


void insertAtTail(node* &tail,int data){
      node* temp=new node(data);
      
      tail->next=temp;
      temp->next=NULL;
      tail=temp;
      
}
 
void insertAtPosition(node* &head,node* &tail,int position,int data){
     node* temp=head;

    if(position==1){
       insertAtHead(head,data)  ;
       return;
    }


     int i=1;
     while(i<position-1){
          temp=temp->next;
          i++;

     }
     if(temp->next==NULL){
        insertAtTail(tail,data);
          return;
     }

     node* nodeToInsert=new node(data);
     nodeToInsert->next=temp->next;
     temp->next=nodeToInsert;

     


}

void deleteNode(int position, node* & head) { 

    //deleting first or start node
    if(position == 1) {
        node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}



void print(node* &head){
    node* temp=head;
     while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
     }cout<<endl;
}


int main(){
     node* node1 = new node(10);
      print(node1);
      node* head=node1;
      node*tail =node1;
      insertAtHead(head,12);
      print(head);
      insertAtTail(tail,15);
      print(head);
      
      insertAtPosition(head,tail,4,5);
      print(head);

      deleteNode(2,head);
    print(head);

    //   cout<<head->data<<endl;
    //     cout<<tail->data<<endl;

    
    return 0;
}