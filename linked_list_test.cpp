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
        Node* curr;
        Node* tail;
    public:
        LinkedList(){
            head = new Node();
            tail = new Node();
            curr = head;
            size = 0;
        }
        void InsertAfter(Node* new_node){
            curr->InsertAfter(new_node);
            curr = curr->GetNext();
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
                        curr = curr->GetPrev();
                    }
                    if(index == new_pos){
                        curr->InsertAfter(temp);
                        break;
                    }
                    index++;
                    curr = curr->GetNext();
                }
            }
            else{
                index = size;
                curr = tail;
                while(curr){
                    if(index == pos){
                        temp = curr;
                        curr->Remove();
                        curr = curr->GetNext();
                    }
                    if(index == new_pos - 1){
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
            while(curr){
                curr->Print();
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

    // ll->ChangePosition(3, 2);
    // ll->Print();

    return 0;
}