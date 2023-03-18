#include <iostream>
using namespace std;

class Node{
private:
    string name;
    Node* prev;
    Node* next;
public:
    Node(){
        name = "";
        prev = nullptr;
        next = nullptr;
    }
    Node(string input_name){
        name = input_name;
        prev = nullptr;
        next = nullptr;
    }
    
    Node* GetPrev(){ return prev; }
    Node* GetNext(){ return next; }
    string GetName(){ return name; }

    void SetPrev(Node* node){  prev = node; }
    void SetNext(Node* node){  next = node; }
    void SetName(string name){  this->name = name; }


    void InsertAfter(Node* new_node){
        new_node->next = this->next;
        this->next = new_node;
        new_node->prev = this;
    }

    void InsertBefore(Node* new_node){
        new_node->prev = this->prev;
        this->prev = new_node;
        new_node->next = this;        
    }

    void Remove(){
        this->prev->next = this->next;
        this->next->prev = this->prev;
    }

    void Print(){
        cout << this->name << " ";
    }
};

class LinkedList{
    private:
        int size;
        Node* head;
        Node* tail;
    public:
        LinkedList(){
            head = new Node();
            tail = head;
            size = 0;
        }
        void InsertAfter(Node* new_node){
            tail->InsertAfter(new_node);
            tail = new_node;
            size++;
        }

        void Remove(string inputStr){
            Node* curr = head;
            while(curr){
                if(curr->GetName() == inputStr){
                    curr->Remove();
                    break;
                }
                curr = curr->GetNext();
            }
            size--;
        }

        void ChangePosition(int pos, int new_pos){
            Node* curr;
            Node* temp;
            int index;
            if(pos < new_pos){
                index = 0;
                curr = head;
                while(curr){
                    if(index == pos){
                        temp = curr;
                        curr->Remove();
                        curr = curr->GetNext();
                    }
                    if(index == new_pos-1){
                        curr->InsertAfter(temp);
                        break;
                    }
                    index++;
                    curr = curr->GetNext();
                }
            }
            else{
                index = size+1;
                curr = tail;
                while(curr){
                    if(index == pos){
                        temp = curr;
                        curr->Remove();
                        curr = curr->GetPrev();
                        cout << temp->GetName() << endl;
                        cout << curr->GetName() << endl;
                    }
                    if(index == new_pos){
                        curr->InsertBefore(temp);
                        break;
                    }
                    index--;    
                    curr = curr->GetPrev();
                }
            }
        }
        void Print(){
            Node* curr = head->GetNext();
            for(int i = 0; i < size; i++){
                cout << curr->GetName() << " ";
                curr = curr->GetNext();
            }
            cout << endl;
        }
};

int main(){
    LinkedList* ll = new LinkedList();
    ll->InsertAfter(new Node("111"));
    ll->InsertAfter(new Node("222"));
    ll->InsertAfter(new Node("aaa"));
    ll->InsertAfter(new Node("333"));
    ll->InsertAfter(new Node("444"));
    ll->Print();

    ll->Remove("aaa");
    ll->Print();

    ll->InsertAfter(new Node("555"));
    ll->Print();

    ll->ChangePosition(1,5);
    ll->Print();
    ll->ChangePosition(4,5);
    ll->Print();
    ll->ChangePosition(1,2);
    ll->Print();
    // ll->ChangePosition(5, 1);
    // ll->Print();

    return 0;
}