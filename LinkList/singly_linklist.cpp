#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node * next;
};

class LinkList{
    node * head;
    int size = 0;
    public:
    LinkList(){
        head = NULL;
    }

    node * create_node(int val){
        node * newNode = new node;
        newNode->data = val;
        newNode->next = NULL;
        return newNode;
    }

    void insert_at_head(int val){
        node * newNode = create_node(val);
        if(head == NULL){
            head = newNode;
            size++;
            return;
        }

        node * temp = newNode;
        temp->next = head;
        head = temp;
        
        this->size++;

    }

    void print(){
        node * temp = this->head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    int length(){
        return this->size;
    }




};

int main(){
    LinkList l;
    cout <<  l.length() << "\n";
    l.insert_at_head(4);
    l.insert_at_head(10);
    l.insert_at_head(20);
    cout <<  l.length() << "\n";

    l.print();


    return 0;
}