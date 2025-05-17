#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};
class linked
{
    node *head;
    node *tail;

public:
    linked()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_front(int value)
    {
        node *newnode = new node(value);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

 
    void search(int pos)
    {
            node *temp = head;
            for (int i = 1; i <= pos - 1; i++)
            {
                temp = temp->next;
            }
             cout<<temp->data;
    }
    
  
    void delete_middle(int pos)
    {
        node *temp = head;
        for (int i = 1; i <= pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
    void print()
    {
        node *temp = head;
        do
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }while (temp != NULL);
     }
 
};
int main()
{
    linked obj;
    int ch, num, pos;
    while (1)
    {
        cout << "\n\n**********************Linked List********************************\n";
        cout << "\nselect your choice:-";
        cout << "\n1.insert at beginning \n2.search \n3.delete";
        cout << "\n4.print\n5.Exit ";
        cout << "\n\n******************************************************\n";
        cout << "\nEnter Your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter a value:";
            cin >> num;
            obj.insert_front(num);
            cout << "Insert first successfully";
        
            break;
        case 2:
            cout << "\nEnter pos:-";
            cin >> pos;
            obj.search(pos);
            

            break;
   
        case 3: 
            cout << "\nEnter pos:-";
            cin >> pos;
            obj.delete_middle(pos);
            cout << "Delete position " << pos << " successfully";
            break;
        case 4:
            obj.print();
            break;
        case 5:
            exit(0);
        }
    }

    return 0;
}
