#include <iostream>
#include <string>
using namespace std;
class customer
{
    public:
    long int ticket_no;
    string Name;
    customer*next;

    customer(long int x,string y)
    {
        ticket_no=x;
        Name=y;
        next=nullptr;
    }

};
class queue
{
    private:
    customer*front;
    customer*back;

    public:
    queue()
    {
    front=nullptr;
    back=nullptr;
    }
    void enqueue(long int x,string y)
    {
        customer*t=new customer(x,y);
        if(t==nullptr)
        {
            cout<<"queue overflow"<<endl;
            return;
        }
        else
        {
            if(back==nullptr)
            {
                front=t;
                back=t;
            }
            else
            {
                back->next=t;
                back=t;
            }
        }
    }
    void dequeue()
    {
        if(front ==nullptr)
        {
            cout<<"the queue is underflow please enter the customer details"<<endl;
            return;
        }
        else
        {
            customer*temp=front;
            front=front->next;
            cout<<temp->Name<<endl;
            cout<<temp->ticket_no<<endl;
            delete temp;
        }
    }
    void searchbyticketno(long int ticket_no)
    {
        customer*temp=front;
        if(front ==nullptr)
        {
            cout<<"no customer to search"<<endl;
            return ;
        }
        else
        {
            while(temp!=nullptr)
            {
                if(ticket_no==temp->ticket_no)
                {
                    cout<<"customer details are given below"<<endl;
                    cout<<"Name:"<<temp->Name<<endl;
                    cout<<"Ticket no:"<<temp->ticket_no<<endl;
                    return;
                }
                temp=temp->next;
            }
            cout<<"no customer is found with the ticket no"<<endl;

        }
    }
    void display()
    {
        customer*temp=front;
        while(temp!=nullptr)
        {
            cout<<"name:"<<temp->Name<<endl;
            cout<<"ticketno:"<<temp->ticket_no<<endl;
            temp=temp->next;
        }
    }

};
int main()
{
    queue q;
    long int ticket_counter = 1;
    int choice;
    string name;
    long int ticket_to_search;

    while (true)
    {
        cout << "\n-------- Ticketing System Menu --------\n";
        cout << "1. Issue Ticket\n";
        cout << "2. Serve Customer\n";
        cout << "3. Search by Ticket Number\n";
        cout << "4. Display All Customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                q.enqueue(ticket_counter++, name);
                cout << "Ticket issued successfully.\n";
                break;

            case 2:
                cout << "Serving next customer:\n";
                q.dequeue();
                break;

            case 3:
                cout << "Enter Ticket Number to search: ";
                cin >> ticket_to_search;
                q.searchbyticketno(ticket_to_search);
                break;

            case 4:
                cout << "Current queue of customers:\n";
                q.display();
                break;

            case 5:
                cout << "Exiting... Thank you!\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
