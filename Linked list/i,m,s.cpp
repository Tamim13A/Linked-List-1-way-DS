#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
};

int main(){
    Node* head=nullptr;
    Node* head1=nullptr; //1st sp
    Node* head2=nullptr; //2nd sp
    int lastSplitPos=-1; //track last sp pos
    //create LL first
    cout<<"Create Linked list at first sir.!\n";
    cout<<"Enter elements (Done for -13): ";
    int value;
    Node*tail=nullptr;

    while(true){
        cin>>value;
        if(value==-13)
        break;

        Node* newNode=new Node{value,nullptr};
        if(head==nullptr){
            head=newNode; //1st element->head
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode; //update tail
        }
    }
    cout<<"Initial Linked List: ";
    Node* temp=head;
    while(temp !=nullptr){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;

    //create menu
    while(true){
        cout<<"\nChoose your mind :->|<-:\n";
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Split\n";
        cout<<"4.Merge\n";
        cout<<"5.Exit\n";
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;

        if(choice==5){ 
            cout<<"Exiting...See you again.!";//exit
            break;
        }
        if(choice ==1){
            cout<<"\nChoose where to Insert:\n";
            cout<<"1.Head\n";
            cout<<"2.Anywhere\n";
            cout<<"3.Tail\n";
             cout<<"Enter your choice: ";

            int insertChoice;
            cin>>insertChoice;
            cout<<"Enter value: ";
            cin>>value;
 
            Node* newNode=new Node{value, nullptr};
            if(insertChoice ==1){
                newNode->next =head;
                head=newNode;
            }else if(insertChoice==2){
                int pos;
                cout<<"Enter Position: ";
                cin>>pos;

                if(pos==0){
                    newNode->next=head;
                    head=newNode;
                }else{
                    Node*temp=head;
                    int count=0;
                    while(temp !=nullptr&&count<pos-1){
                        temp=temp->next;
                        count++;
                    }
                    if(temp !=nullptr){
                        newNode->next=temp->next;
                        temp->next=newNode;
                    }else{
                        cout<<"Position out of the Galaxy::->!\n";
                        delete newNode;
                    }
                }
            }else if(insertChoice==3){
                if(head==nullptr){
                    head=newNode;
                }else{
                    Node*temp=head;
                    while(temp->next !=nullptr){
                        temp=temp->next;
                    }
                    temp->next=newNode;
                }
            }
       
        }else if(choice==2){
            cout<<"\nChoose where to Delete:\n";
            cout<<"1.Anywhere\n";
            cout<<"Enter your choice: ";
            int deleteChoice;
            cin>>deleteChoice;

            if(deleteChoice==1){
                int pos;
                cout<<"Enter Position: ";
                cin>>pos;
                if(pos==0 && head !=nullptr){
                    Node*toDelete=head;
                    head=head->next;
                    delete toDelete;
                }else{
                    Node*temp=head;
                    int count=0;
                    while(temp !=nullptr && count<pos-1){
                        temp=temp->next;
                        count++;
                    }
                    if(temp !=nullptr && temp->next !=nullptr){
                        Node* todelete=temp->next;
                        temp->next=temp->next->next;
                        delete todelete;
                    }else{
                        cout<<"Position out of the Sun.|:->!\n";
                    }
                }
            }
                        
        }else if(choice==3) {
    cout<< "Enter Position to split: ";
    cin>>lastSplitPos;

    // Calculate the length
    int length=0;
    Node* tempTraversal=head; //remane avoid conflict
    while(tempTraversal !=nullptr) {
        length++;
        tempTraversal=tempTraversal->next;
    }
    // Validate position
    if (lastSplitPos<0 || lastSplitPos >=length) {
        cout<< "ERROR!\nSplit position out of your mind.\n";
        continue;
    }
    // Perform the split
    head1=head; // First part
    head2=nullptr;

    if(lastSplitPos==0) {
        head2=head1;
        head1=nullptr;
    }else{
        Node* tempSplit=head1; // Pointer for split
        int count=0;
        while(tempSplit !=nullptr && count<lastSplitPos-1) {
            tempSplit=tempSplit->next;
            count++;
        }
        if (tempSplit !=nullptr) {
            head2=tempSplit->next;
            tempSplit->next=nullptr;
        }
    }
    // Display
    cout<< "1st part of the list: ";
    tempTraversal = head1; // tempTraversal for printing
    while(tempTraversal !=nullptr) {
        cout<< tempTraversal->data << " ";
        tempTraversal=tempTraversal->next;
    }
    cout <<"\n2nd part of the list: ";
    tempTraversal=head2;
    while(tempTraversal !=nullptr) {
        cout<< tempTraversal->data << " ";
        tempTraversal=tempTraversal->next;
    }
    cout<<endl;
    
    }else if(choice==4){
        cout<<"Enter Postion: ";
        int mergePos;
        cin>>mergePos;

        if(mergePos !=lastSplitPos){
            cout<<"ERROR!\nPosition out of the Ocean..|-->!\n";
        }else{
            if(head1==nullptr){
                head1=head2;
            }else{
                Node*temp=head1;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = head2;
            }
            head=head1; //update head show
            head1=nullptr;
            head2=nullptr;
            lastSplitPos=-1; //reset SP Pos

            cout<<"Lists Merged Successfully.\n"; 
        }
    }
    cout<<"Present List: ";
    Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
 return 0;
}   
