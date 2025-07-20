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
    void insert_at_index(int idx, int val){
        if(idx>this->size || idx < 0){
            cout << "Invalid index\n";
            return;
        }
        
        if(idx == 0){
            this->insert_at_head(val);
            return;
        }

        node * current = head;
        int i = 0;
        while(i != idx-1){
            current = current->next;
            i++;
        }

        if(current->next == NULL){
            current->next = this->create_node(val);
            return;
        }
    
        node * newNode = this->create_node(val);

        node * temp = current->next;
        current->next = newNode;
        newNode->next = temp;

        this->size++;
        return;
    }
    void delete_head(){
        node * temp = head;
        head = temp->next;
        this->size--;
        delete temp;
    }

    void delete_at_index(int idx){
        if(idx>this->size || idx < 0){
            cout << "Invalid index\n";
            return;
        }
        if(idx == 0){
            this->delete_head();
            return;
        }

        node * current = head;
        int i = 0;
        while(i != idx-1){
            current = current->next;
            i++;
        }

        node * temp = current->next;


        current->next = temp->next;
        delete temp;
        this->size--;

        return;
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
    l.insert_at_head(1);
    l.insert_at_head(2);
    l.insert_at_index(3, 100);
    l.insert_at_index(6, 500);
    cout <<  l.length() << "\n";
    l.print();
    l.delete_at_index(6);
    cout <<  l.length() << "\n";
    l.print();
    // l.delete_head();
    // cout <<  l.length() << "\n";
    // l.print();

    return 0;
}