
#include <bits/stdc++.h>
using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"

struct node
{
    int data;
    node *link;
};

node *head = 0;

void insert(int val)
{
    node *temp = new node;
    temp->data = val;
    temp->link = 0;

    if (head == 0 || val < head->data)
    {
        temp->link = head;
        head = temp;
        return;
    }

    node *t = head;

    while (t->link != 0 && t->link->data < val)
    {
        t = t->link;
    }

    temp->link = t->link;
    t->link = temp;
}

void Delete(int val)
{
    if (head == 0)
    {
        cout << RED << "List is empty!" << RESET << endl;
        cout << endl;
        return;
    }

    node *t = head;

    if (t->data == val)
    {
        head = t->link;
        delete t;

        cout << GREEN << "Value deleted!" << RESET << endl;
        cout << endl;
        return;
    }

    node *prev;

    while (t != 0 && t->data != val)
    {
        prev = t;
        t = t->link;
    }

    if (t == 0)
    {
        cout << RED << "Value not found!" << RESET << endl;
        cout << endl;
        return;
    }

    prev->link = t->link;
    delete t;

    cout << GREEN << "Value deleted!" << RESET << endl;
    cout << endl;
}

void search(int item)
{
    node *t = head;
    int pos = 1;

    while (t != 0)
    {
        if (t->data == item)
        {
            cout << GREEN << "Item found!" << RESET << endl;
            cout << YELLOW << "Position: " << pos << RESET << endl;
            cout << endl;
            return;
        }

        t = t->link;
        pos++;
    }

    cout << RED << "Item not found!" << RESET << endl;
    cout << endl;
}

void print()
{
    node *t = head;

    if (head == 0)
    {
        cout << RED << "List is empty!" << RESET << endl;
        cout << endl;
        return;
    }

    cout << CYAN << "Sorted Linked List: " << RESET;

    while (t != 0)
    {
        cout << t->data << " ";
        t = t->link;
    }

    cout << endl;
    cout << endl;
}

int main()
{
    int choice, val;
    int n = 20;

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        int num = rand() % 10000;
        insert(num);
    }

    while (true)
    {
        cout << endl;
        cout << CYAN << "============================" << RESET << endl;
        cout << MAGENTA << "     SORTED LINKED LIST" << RESET << endl;
        cout << CYAN << "============================" << RESET << endl;

        cout << GREEN << "1. Insert" << RESET << endl;
        cout << YELLOW << "2. Delete" << RESET << endl;
        cout << BLUE << "3. Search" << RESET << endl;
        cout << CYAN << "4. Display" << RESET << endl;
        cout << RED << "5. Exit" << RESET << endl;

        cout << CYAN << "============================" << RESET << endl;
        cout << "Enter choice: ";
        cin >> choice;

        cout << endl;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> val;

            insert(val);

            cout << GREEN << "Value inserted!" << RESET << endl;
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter value: ";
            cin >> val;

            Delete(val);

            cout << "After Deletion: " << endl;
            print();
        }
        else if (choice == 3)
        {
            cout << "Enter value: ";
            cin >> val;

            search(val);
        }
        else if (choice == 4)
        {
            print();
        }
        else if (choice == 5)
        {
            cout << GREEN << "Program Exit!" << RESET << endl;
            break;
        }
        else
        {
            cout << RED << "Invalid Choice!" << RESET << endl;
            cout << endl;
        }
    }

    return 0;
}
