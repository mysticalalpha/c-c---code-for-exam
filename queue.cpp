// Queue using C++
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *rht;
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void insertion(int value)
    {
        if (front == rear && front == NULL)
        {
            Node *temp = new Node;
            temp->data = value;
            temp->rht = NULL;
            front = rear = temp;
        }
        else
        {
            Node *temp = new Node;
            temp->data = value;
            temp->rht = NULL;
            rear->rht = temp;
            rear = temp;
        }
    }

    void deletion()
    {
        if (front == rear && front == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = new Node;
            temp = front;
            front = front->rht;
            delete temp;
        }
    }
    void display()
    {
        Node *temp = new Node;
        temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->rht;
        }
    }
};

int main()
{
    Queue q;
    q.insertion(1);
    q.insertion(2);
    q.insertion(3);
    q.insertion(4);
    q.insertion(5);
    q.display();
    return 0;
}