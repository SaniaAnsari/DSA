#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
// Insert
void insert(int value)
{
    Node *temp = new Node; // create newnode using 'new' keyword

    // // temp=(Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
    }
}
// Display
void display()
{
    if (head == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    Node *temp = head;
    cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
// Search
void search(int value)
{
    int pos = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << temp->data << " found at positon  " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
}
// Delete
void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "linked list is empty" << endl;
        return;
    }
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted" << endl;
        return;
    }
    Node *pre = NULL;
    Node *cur = head;
    while (cur != NULL)
    {
        if (cur->data == value)
        {
            pre->next = cur->next;
            delete cur;
            cout << "Node deleted" << endl;
            return;
        }

        pre = cur;
        cur = cur->next;
    }
    cout << "Not found" << endl;
}

int main()
{
    int choice = 0, value;

    while (choice <= 4)
    {
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Delete";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Value: ";
            cin >> value;
            insert(value);
            break;
        case 2:
            display();
            break;
        case 3:
            cout << "Value: ";
            cin >> value;
            search(value);
            break;
        case 4:
            cout << "Value: ";
            cin >> value;
            deleteNode(value);
            break;
        case 5:
            cout << "Exit";
            break;
        default:
            cout << "Invalid";
            break;
        }
    }
    // insert(10);
    // insert(20);
    // insert(30);
    // cout << "before deletion" << endl;
    // display();
    // search(20);
    // deleteNode(30);
    // cout << "after deletion" << endl;
    // display();

    return 0;
}
