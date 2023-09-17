#include<bits/stdc++.h>
using namespace std;
// In this example, member functions of one class are friend functions of other class
class Node;
class List {
    Node *head, *tail;
    public:
        List(Node* h = 0) : head(h), tail(0) {}
        void display();
        void append(Node *);
};

class Node {
    int data;
    Node* next;
    public:
        Node(int i) : data(i) , next(0) {}
        // Here member function of List class are friend functions of Node class
        // Now these functions can access private data of Node class(data,next)
        friend void List::display();
        friend void List::append(Node *);
};

void List::append(Node* newNode) {
    if(!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = tail->next;
    }
}

void List::display() {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp=temp->next;
    }
}
int main()
{
    List* l = new List();
    Node n1(1),n2(2),n3(3),n4(4);
    l->append(&n1);
    l->append(&n2);
    l->append(&n3);
    l->append(&n4);
    l->display();

    return 0;
}