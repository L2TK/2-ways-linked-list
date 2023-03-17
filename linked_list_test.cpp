#include <iostream>
using namespace std;


class Node
{
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
    void InsertAfter(Node* new_node){
        Node* curr = this;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
        new_node->prev = curr;
    }
    void Remove(Node* curr,string input_name){
        if(curr->name == input_name){
            curr->prev->next = curr->next;
            return;
        }
        Remove(curr->next, input_name);
    }
    void ChangePosition(int pos, int new_pos){
        Node* temp;
        Node* curr = this;
        int index = 0;
        if(pos < new_pos){
            while(curr){
                if(index == pos){
                    temp = curr;
                    curr->prev->next = curr->next;
                    curr = curr->next;
                }
                if(index == new_pos - 1){
                    temp->next = curr->next;
                    curr->next = temp;
                    break;
                }
                curr = curr->next;
                index++;
            }
        }
        else{
            while(curr){
                if(index == new_pos -1){
                    temp = curr;
                }
                if(index == pos){
                    temp->next = curr;
                    curr->prev->next = curr->next;
                    curr->next = temp->next;
                    break;
                }
                index++;
                curr = curr->next;
            }
        }
    }
    void Print(){
        Node* curr = this->next;
        while (curr){
            cout << curr->name << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};


int main(){
    Node* head = new Node();
    head->InsertAfter(new Node("111"));
    head->InsertAfter(new Node("222"));
    head->InsertAfter(new Node("aaa"));
    head->InsertAfter(new Node("333"));
    head->InsertAfter(new Node("444"));
    head->Print();

    head->Remove(head, "aaa");
    head->Print();

    head->InsertAfter(new Node("555"));
    head->Print();

    head->ChangePosition(1,2);
    head->Print();

    head->ChangePosition(3, 1);
    head->Print();

    return 0;
}