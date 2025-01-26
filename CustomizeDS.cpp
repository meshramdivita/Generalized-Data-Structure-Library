#include<iostream>
using namespace std;

// Single Linked list
template <class T>
struct nodeSL
{
    struct nodeSL *next;
    T data;
};

// Doubly Linked list
template <class T>
struct nodeDS{
    int data ;
    struct nodeDS *next; 
    struct nodeDS *prev;
};

// Circular Linked list
template <class T>
struct nodeCS
{
    int data;
    struct nodeCS * next;
};

// Doubly Circular Liked list
template <class T>
struct nodeDC 
{
    int data;
    struct nodeDC * next;
    struct nodeDC * prev;
};

// Stack 
template< class T>
struct nodeS {
    T data ;
    struct nodeS *next;
};

// Queue
template< class T>
struct nodeQ{
    int data ;
    struct nodeQ * next;
};

template <class T>
class SingleLL
{
    public :
      struct nodeSL<T>* head ;
      int iCount;
    
    SingleLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no , int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    void Display();
    int Count ();   
};
template <class T>
class DoublySLL
{
    public:
        struct nodeDS<T> * head;
        int iCount;

        DoublySLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertatPos(T no , int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteatPos(T iPos);
        void Display();
        int Count();
};

template <class T>
class CircularSLL
{
    public:
         struct nodeCS<T> * head;
         struct nodeCS<T> * tail;
         int iCount;
    
         CircularSLL();
         void InsertFirst(T no);
         void InsertLast(T no);
         void InsertAtPos(T no , int ipos);
         void DeleteFirst();
         void DeleteLast();
         void DeleteAtPos(int iPos);
         void Display();
         int Count();
};

template <class T>
class DoublyCircularSLL
{
    public:
         struct nodeDC<T> * head;
         struct nodeDC<T> * tail;
         int iCount;
    
         DoublyCircularSLL();
         void InsertFirst(T no);
         void InsertLast(T no);
         void InsertAtPos(T no , int ipos);
         void DeleteFirst();
         void DeleteLast();
         void DeleteAtPos(int iPos);
         void Display();
         int Count();
};

template< class T>
class Stack
{
    public:
       struct nodeS<T>* head;
       int iCount ;

   Stack(); 
   void Push(T no);
   int Pop();
   void Display();
   int Count();
};

template< class T>
class Queue
{
    public :
       struct nodeQ<T>* head;
       int iCount ;

    Queue();
   void Equeue(T no);
   int Dequeue();
   void Display();
   int Count();

};

template <class T>      // Constructor
SingleLL<T>::SingleLL()
{
    head =  NULL;
    iCount = 0 ; 
}

template <class T>
void SingleLL<T>::InsertFirst(T no)
{
    struct nodeSL<T> * newn = NULL;
    newn = new nodeSL<T>;
    newn->data = no;
    newn->next = NULL;

    if(head==NULL)
    {
        head = newn;
    }
    else 
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
}

template <class T>
void SingleLL<T>::InsertLast(T no)
{
    struct nodeSL<T>* newn = NULL;
    struct nodeSL<T>* temp = head;
    newn = new nodeSL<T>;
    newn->data = no;
    newn->next = NULL;

    if(head==NULL)
    {
        head = newn;
    }
    else 
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next =  newn;
    }
    iCount++;
}

template <class T>
void SingleLL<T>::InsertAtPos(T no , int iPos)
{
    struct nodeSL<T> *newn = NULL;
    struct nodeSL<T> *temp = head;

    int i ;

    if((iPos < 1)||(iPos > iCount+1))
    {
        cout<<"invalid Position";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else 
    {
        newn = new nodeSL<T>;
        newn->data = no;
        newn->next = NULL;
            
        for(i=1;i<iPos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SingleLL<T>::DeleteFirst()
{
    struct nodeSL<T> *temp = NULL;

    if(head==NULL)
    {
        return;
    }
    else if((head)->next==NULL)
    {
        delete head;
        head = NULL;
    }
    else 
    {
        temp = head;
        head = head->next;
        delete(temp);
        cout << "First element deleted successfully.\n";
    }
    iCount--;
} 

template <class T>
void SingleLL<T>::DeleteLast()
{
    if(head == NULL)
    {
       return ;
    }
    else if((head)->next == NULL)
    {
       delete head;
       head = NULL;
    }
    else 
    {
       struct nodeSL<T> *temp = head;
       while(temp->next->next!=NULL)
       {
          temp = temp->next;
       }
       delete temp->next;
       temp->next = NULL;
       cout << "Last element deleted successfully.\n";
    }
    iCount--;
}

template <class T>
void SingleLL<T>::DeleteAtPos(int iPos)
{
    int i;
    if((iPos < 1) ||(iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        struct nodeSL<T> *temp = NULL;
        struct nodeSL<T> *target = NULL;

        temp = head;

        for(i=1;i<iPos-1;i++)
        {
            temp = temp->next;
        }
        target = temp->next ;
        temp->next = target->next;
        delete(target);
        cout << " element deleted successfully.\n";
    }
    iCount--;
}

template <class T>
void SingleLL<T>::Display()
{
    struct nodeSL<T> *temp = head;
    cout<<"\nElement of the linked list :";
    while(temp!=NULL)
    {
        cout<<" -> " << temp->data ;
        temp = temp->next;
    }
    cout<<" -> NULL\n";
}

template <class T>
int SingleLL<T>:: Count ()
{
    return iCount;
}

template <class T>
DoublySLL<T>::DoublySLL()
{
    head = NULL;
    iCount = 0 ; 
}

template <class T>
void DoublySLL<T>::InsertFirst(T no)
{
    struct nodeDS<T> * newn = NULL;
    newn = new nodeDS<T> ;  
    newn->data = no; 
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else 
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    iCount++;
}
template <class T>
void DoublySLL<T>::InsertLast(T no)
{
    struct nodeDS<T> * newn = NULL;
    struct nodeDS<T> * temp = head;

    newn = new nodeDS<T>;   
    newn->data = no; 
    newn->next = NULL;
    newn->prev = NULL;
    if(head == NULL)
    {
        head = newn;
    }
    else 
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}
template <class T>
void DoublySLL<T>::InsertatPos(T no , int iPos)
{ 
    int i = 0 ; 
    struct nodeDS<T> * newn = NULL;
    struct nodeDS<T> * temp = NULL;
    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid Number ";
        return ;
    }
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount+1)
    {
        InsertLast(no);
    }
    else 
    {
        newn = new nodeDS<T> ;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = head;

        for(i=1;i<iPos-1;i++)
        {
            temp = temp->next ;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublySLL<T>::DeleteFirst()
{
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
        cout << "First element deleted successfully.\n";
    }
    iCount--;
}

template <class T>
void DoublySLL<T>::DeleteLast()
{
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        struct nodeDS<T> * temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp->next = NULL;
        cout << "Last element deleted successfully.\n";
    }
    iCount--;
}


template <class T>
void DoublySLL<T>::DeleteatPos(T iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout << "Invalid Position!" << endl;
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeDS<T> *temp = head;
        struct nodeDS<T> *target = NULL;

        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        
        target = temp->next;
        temp->next = target->next;
        temp->next->prev = temp;
        delete target;
        cout << "Element deleted successfully.\n";
    }
    iCount--;
}

template <class T>
void DoublySLL<T>::Display()
{
    struct nodeDS<T>* temp = head;
    cout<<"\nElements of LinkedList are :";
    while(temp != NULL)
    {
        cout<<"| <=> "<<temp->data<<"| ";
        temp = temp -> next;
    }
    cout<<"->NULL\n";
} 

template <class T>
int DoublySLL<T>:: Count()
{
    return iCount;
}
template <class T>
CircularSLL<T>::CircularSLL()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template <class T>
void CircularSLL<T>::InsertFirst(T no)
{
    struct nodeCS<T> * newn = NULL;
    newn = new nodeCS<T>;
    newn->data = no;
    newn->next = NULL;

    if((head==NULL)&&(tail==NULL))
    {
        head = newn;
        tail = newn;
    }
    else 
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
    tail->next = head;
}

template <class T>
void CircularSLL<T>::InsertLast(T  no)
{
    struct nodeCS<T> * newn = NULL;
    newn = new nodeCS<T>;
    newn->data = no;
    newn->next = NULL;

    if((head==NULL)&&(tail==NULL))
    {
        head = newn;
        tail = newn;
    }
    else 
    {
        tail->next = newn;
        tail = newn;
    }
    iCount++;
    tail->next = head;
}

template <class T>
void CircularSLL<T>::InsertAtPos(T no , int ipos)
{
    int i ;

    struct nodeCS<T> * temp = NULL;
    struct nodeCS<T> * newn = NULL;

    if(ipos < 1 || ipos > iCount+1)
    {
        cout<<"Empty linked list ";
    }
    else if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else 
    {
        newn = new nodeCS<T>;
        newn->data = no;
        newn->next = NULL;

        temp = head;

        for(i=1;i<ipos-1;i++)
        {
           temp = temp->next; 
        }         
        newn->next = temp->next ;
        temp->next = newn;  
    }
    iCount++;
}

template <class T>
void CircularSLL<T>::DeleteFirst()
{
    struct nodeCS<T>* temp = NULL; 
    if(head == NULL && tail == NULL)
    {
        cout<<"The linked list is empty";
    }
    else if(head == tail)
    {
        delete(head);
        head = NULL;
        tail = NULL;
    }
    else 
    {
        temp = head;
        head = head->next;
        delete temp;

        tail->next = head;
        cout << "First element deleted successfully.\n";
    }
    iCount--;
   
}

template <class T>
void CircularSLL<T>::DeleteLast()
{
    struct nodeCS<T> * temp = NULL; 
    if(head == NULL && tail == NULL)
    {
        cout<<"The linked list is empty";
    }
    else if(head == tail)
    {
        delete(head);
        head = NULL;
        tail = NULL;
    }
    else 
    {
        temp = head;

        while(temp->next != tail)
        {
            temp = temp->next;
        }
        delete(tail);
        tail = temp;
        temp->next = head;
        cout << "Last element deleted successfully.\n";
    }
    iCount--;
}

template <class T>
void CircularSLL<T>::DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }
    else if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        struct nodeCS<T> *temp = head;
        struct nodeCS<T> *target = NULL;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        cout << " element deleted successfully.\n";

    }
    iCount--;
}

template <class T>
void CircularSLL<T>::Display()
{
    struct nodeCS<T> * temp = head;
    if(head == NULL && tail == NULL)
    {
        cout<< "Linked list is empty ";
        return;
    }
    cout<<"\nElement of the lined list: ";
    do
    {
        cout<<"-> "<< temp->data;
        temp = temp->next;
    }while(temp != tail -> next);
    cout<<"->NULL\n";
}

template <class T>
int  CircularSLL<T>::Count()
{
    return iCount;
}
template <class T>
DoublyCircularSLL<T>::DoublyCircularSLL()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template <class T>
void DoublyCircularSLL<T>::InsertFirst(T no)
{
    struct nodeDC<T> * newn = NULL;
    newn = new nodeDC<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((head==NULL)&&(tail==NULL))
    {
        head = newn;
        tail = newn;
    }
    else 
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    iCount++;
    tail->next = head;
    head->prev = tail;
}

template <class T>
void DoublyCircularSLL<T>::InsertLast(T  no)
{
    struct nodeDC<T> * newn = NULL;
    newn = new nodeDC<T>;
    newn->data = no;
    newn->next = NULL;

    if((head==NULL)&&(tail==NULL))
    {
        head = newn;
        tail = newn;
    }
    else 
    {
        tail->next = newn;
        tail = newn;
        newn->prev = tail;
    }
    iCount++;
    tail->next = head;
    head->prev = tail;
}

template <class T>
void DoublyCircularSLL<T>::InsertAtPos(T no , int ipos)
{
    int i ;

    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    if(ipos < 1 || ipos > iCount+1)
    {
        cout<<"Invalid position";
        return;
    }
    else if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else 
    {
        newn = new nodeDC<T>;
        newn->data = no;
        newn->next = NULL;

        temp = head;

        for(i=1;i<ipos-1;i++)
        {
           temp = temp->next; 
        }         
        newn->next = temp->next ;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        tail->next = head;
        head->prev = tail;

    }
    iCount++;
}

template <class T>
void DoublyCircularSLL<T>::DeleteFirst()
{
    struct nodeDC<T>* temp = NULL; 
    if(head == NULL && tail == NULL)
    {
        cout<<"The linked list is empty";
        return;
    }
    else if(head == tail)
    {
        delete(head);
        head = NULL;
        tail = NULL;
    }
    else 
    {
        temp = head;
        head = head->next;

        tail->next = head;
        head->prev = tail;

        delete temp;
        cout << "First element deleted successfully.\n";
    }
    iCount--;
   
}

template <class T>
void DoublyCircularSLL<T>::DeleteLast()
{
    struct nodeDC<T> * temp = NULL; 
    if(head == NULL && tail == NULL)
    {
        cout<<"The linked list is empty";
        return;
    }
    else if(head == tail)
    {
        delete(head);
        head = NULL;
        tail = NULL;
    }
    else 
    {
        temp = tail;
        tail=tail->prev;
    
        tail->next = head;
        head->prev = tail;

        delete temp ;
        cout << "First element deleted successfully.\n"; 
    }
    iCount--;
}

template <class T>
void DoublyCircularSLL<T>::DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }
    else if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        struct nodeDC<T> *temp = head;
        struct nodeDC<T> *target = NULL;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        temp->next->prev = temp;
        
        delete target;
        cout << "element deleted successfully.\n";
    }
    iCount--;
}

template <class T>
void DoublyCircularSLL<T>::Display()
{
    struct nodeDC<T> * temp = head;
    if(head == NULL && tail == NULL)
    {
        cout<< "Linked list is empty ";
        return;
    }
    cout<<"\nElement of the lined list: ";
    do
    {
        cout<<"-> "<< temp->data;
        temp = temp->next;
    }while(temp != tail -> next);
    cout<<"->NULL\n";
}

template <class T>
int DoublyCircularSLL<T>::Count()
{
    return iCount;
}

template< class T>
Stack<T>::Stack()
{
    head = NULL;
    iCount = 0;
}

template< class T>
void Stack<T>::Push(T no)
{
    struct nodeS<T> * newn = NULL;
    newn = new nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else 
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
}

template< class T>
int Stack<T>::Pop()
{
    T no = -1 ;
    struct nodeS<T>* temp = NULL;

    if(head == NULL)
    {
        cout<<"Stack is empty \n";
        return -1;
    }
    else if(head->next==NULL)
    {
        no = head->data;
        delete(head);
        head = NULL;
    }
    else 
    {
        T no = head->data;
        temp = head; 
        head = head->next;
        delete temp;
    }
    iCount--;
    return no;
}

template< class T>
void Stack<T>::Display()
{
    cout<<"\nThe number of elements are :";

    struct nodeS<T>* temp = head;

    while(temp!=NULL)
    {
        cout<<"| "<<temp->data<<" |";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template< class T>
int Stack<T>::Count()
{
   return iCount ; 
}

template< class T>
Queue<T>::Queue()
{
    head = NULL;
    iCount = 0; 
}

template< class T>
void Queue<T>::Equeue(T no)
{
    struct nodeQ<T>* temp = NULL;
    struct nodeQ<T>* newn = NULL ;
    newn = new nodeQ<T>;
    newn->data = no ;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else 
    {
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template< class T>
int Queue<T>:: Dequeue()
{
    struct nodeQ<T>* temp = NULL;
    int no = -1;

    if(head == NULL)
    {
        cout<<"Queue is empty.\n ";
        return -1;
    }
    else if(head->next==NULL)
    {
        no = head->data;
        delete head;
        head = NULL;
    }
    else 
    {
        T no = head->data ;
        temp = head;
        head = head->next;
        delete temp;
    }
    iCount--;
    return no;
}

template< class T>
void Queue<T>::Display()
{
    cout<<"\n The element of the linked list :";

    struct nodeQ<T> * temp = NULL;
    temp = head;

    while(temp!=NULL)
    {
        cout<<"|" << temp->data<< "| ";
        temp = temp->next ;
    }
    cout<<"NULL\n";
}

template< class T>
int Queue<T>::Count()
{
    return iCount;
}

int main() 
{
    SingleLL<int> sll;
    DoublySLL<int> dll;
    CircularSLL<int> cll;
    DoublyCircularSLL<int>dcll;
    Stack<int>S;
    Queue<int>Q;
    
    cout<<"--------------------------------------------------------------------------------------------------\n";
    cout<<"Please select the option based on your requirenment.............. \n";
    cout<<"----------------------------------------------------------------------------------------------------\n";


    int Choice = 0 ;
    int Menu;
    int iValue , iPosition ;

    while (true)
    {
        cout<<"1.Singly Linear Linked List \n ";
        cout<<"2.Doubly Linear Linked List \n";
        cout<<"3.Circular Linear Linked List\n";
        cout<<"4.Doubly Circular Linked List \n";
        cout<<"5.Stack\n";
        cout<<"6.Queue\n";
        cout<<"7.Terminate the project\n";

        cout<<"-----------------------------------------------------------------------------------------------------\n";

        cout<<"Enter your Choice : ";
        cin>>Choice;
        
        cout<<"-----------------------------------------------------------------------------------------------------\n";
         
        
        if(Choice == 1)
        {
            int op = 0;
            while(true)
            {
                cout<<"Enter the Single Linked List :\n";
                cout<<"1.Insert first \n";
                cout<<"2.Insert Last \n";
                cout<<"3.Insert At Position\n";
                cout<<"4.Delete first \n";
                cout<<"5.Delete Last \n";
                cout<<"6.Delete at Position\n";
                cout<<"7.Display\n";
                cout<<"8.Back to main Meanu\n";
                cout<<"Enter your Choice : ";
                cin>>op;
                cout<<"-----------------------------------------------------------------------------------------------------\n";
               
                
                if(op == 1)
                {
                    cout<<"Enter the iValue :\n";
                    cin>>iValue ;
                    sll.InsertFirst(iValue);
                }
                else if(op == 2)
                {
                    cout<<"Enter the iValue :\n";
                    cin>>iValue;
                    sll.InsertLast(iValue);
                }
                else if (op == 3)
                {
                    cout<<"Enter the iValue and Position";
                    cin>>iValue >>iPosition;
                    sll.InsertAtPos(iValue,iPosition);
                }
                else if(op == 4)
                {
                     sll.DeleteFirst();
                }
                else if(op == 5)
                {
                    sll.DeleteLast();
                }
                else if(op == 6)
                {
                    cout<<"Enter the Position\n";
                    cin>>iPosition;
                    sll.DeleteAtPos(iPosition);
                }
                else if(op == 7)
                {
                    sll.Display();
                }
                else if(op == 8)
                {
                    break;
                }
                else 
                {
                    cout<<"Invalid Position\n";
                }
            }
        }

        else if(Choice == 2)
        {
            int op = 0; 
            while(true)
            {
                cout<<"Enter the Single Linked List :\n";
                cout<<"1.Insert first \n";
                cout<<"2.Insert Last \n";
                cout<<"3.Insert At Position\n";
                cout<<"4.Delete first \n";
                cout<<"5.Delete Last \n";
                cout<<"6.Delete at Position\n";
                cout<<"7.Display\n";
                cout<<"8.Back to main Meanu\n";
                cout<<"-----------------------------------------------------------------------------------------------------\n";
                

                if(op == 1)
                {
                    cout<<"Enter the Value\n";
                    cin>>iValue;
                    dll.InsertFirst(iValue);
                }
                else if(op == 2)
                {
                    cout<<"Enter the Value\n";
                    cin>>iValue;
                    dll.InsertLast(iValue);
                }
                else if(op == 3)
                {
                    cout<<"Enter the Value\n";
                    cin>>iValue>>iPosition;
                    dll.InsertatPos(iValue,iPosition);
                    
                }
                else if(op == 4)
                {
                    dll.DeleteFirst();
                }
                else if(op == 5)
                {
                    dll.DeleteLast();
                }
                else if(op == 6)
                {
                    cout<<"Enter the Position";
                    cin>>iPosition;
                    dll.DeleteatPos(iPosition);
                }
                else if(op == 7)
                {
                    dll.Display();
                }
                else if(op == 8)
                {
                   break;
                }
                else 
                {
                    cout<<"Invalid Position\n";
                }
            }
        }
        else if(Choice == 3)
        {
            int op = 0;
            while(true)
            {
                cout<<"Enter the Single Linked List :\n";
                cout<<"1.Insert first \n";
                cout<<"2.Insert Last \n";
                cout<<"3.Insert At Position\n";
                cout<<"4.Delete first \n";
                cout<<"5.Delete Last \n";
                cout<<"6.Delete at Position\n";
                cout<<"7.Display\n";
                cout<<"8.Back to main Meanu\n";
                cout<<"-----------------------------------------------------------------------------------------------------\n";

        
                if(op == 1)
                {
                    cout<<"Enter the value :\n";
                    cin>>iValue;
                    cll.InsertFirst(iValue);
                }
                else if(op == 2)
                {
                    cout<<"Enter the value :\n";
                    cin>>iValue;
                    cll.InsertLast(iValue);
                }
                else if(op == 3)
                {
                   cout<<"Enter the value and Position:\n";
                   cin>>iValue>>iPosition;
                   cll.InsertAtPos(iValue,iPosition);
                }
                else if(op == 4)
                {
                   cll.DeleteFirst();
                }
                else if(op == 5)
                {
                   cll.DeleteLast();
                }
                else if(op == 6)
                {
                    cout<<"Enter the Position:\n";
                    cin>>iPosition;
                    cll.DeleteAtPos(iPosition);
                }
                else if(op == 7)
                {
                    cll.Display();
                }
                   else if(op == 8)
                {
                    break;
                }
                else 
                {
                    cout<<"Invalid Position\n";
                }
            }
        }
        else if(Choice == 4)
        {
            int op = 0; 
            while(true)
            {
                cout<<"Enter the Single Linked List :\n";
                cout<<"1.Insert first \n";
                cout<<"2.Insert Last \n";
                cout<<"3.Insert At Position\n";
                cout<<"4.Delete first \n";
                cout<<"5.Delete Last \n";
                cout<<"6.Delete at Position\n";
                cout<<"7.Display\n";
                cout<<"8.Back to main Meanu\n";
                cout<<"-----------------------------------------------------------------------------------------------------\n";

               
                if(op == 1)
                {
                    cout<<"Enter the value :\n";
                    cin>>iValue;
                    dcll.InsertFirst(iValue);
                }
                else if(op == 2)
                {   
                    cout<<"Enter the value :\n";
                    cin>>iValue;
                    dcll.InsertLast(iValue);
                }
                else if(op == 3)
                {
                    cout<<"Enter the value and position:\n";
                    cin>>iValue>>iPosition;
                   dcll.InsertAtPos(iValue,iPosition);
                }
                else if(op == 4)
                {
                    dcll.DeleteFirst();
                }
                else if(op == 5)
                {
                    dcll.DeleteLast();
                }
                else if(op == 6)
                {
                    cout<<"Enter the Position :\n";
                    cin>>iPosition;
                    dcll.DeleteAtPos(iPosition);
                }
                else if(op == 7)
                {
                    dcll.Display();
                }
                else if(op == 8)
                {
                   break;
                }
                else 
                {
                     cout<<"Invalid Position :";
                }
            }
        }
        else if(Choice == 5)
        {
            int op = 0; 
            while(true)
            {
                cout<<"Enter the Single Linked List :\n";
                cout<<"1.Insert First \n"; 
                cout<<"2.Delete first \n";
                cout<<"3.Display\n";
                cout<<"4.Back to main Meanu\n";
                
        
                if(op == 1)
                {
                    cout<<"Enter the value :\n";
                    cin>>iValue;
                    S.Push(iValue);
                }
                else if(op == 3)
                {
                    S.Display();
                }
                else if(op == 2)
                {
                    int iRet = S.Pop();
                    cout<<"Poped element is : "<<iRet<<"\n";
                }
            }
        }
        else if(Choice == 6 )
        {
            int op = 0 ; 
            while(true)
            {
                cout<<"Enter the Single Linked List :\n";
                cout<<"1.Insert Last \n"; 
                cout<<"2.Delete first \n";
                cout<<"3.Display\n";
                cout<<"4.Back to main Meanu\n";
                cout<<"-----------------------------------------------------------------------------------------------------\n";

               
                 
                if(op == 1)
                {
                    cout<<"Enter the iValue :\n";
                    cin>>iValue;
                    Q.Equeue(iValue);
                }
                else if(op == 3)
                {
                    Q.Display();
                }
                else if(op == 2)
                {
                    int iRet = Q.Dequeue();
                    cout<<"The Equeue of the element : "<<iRet<<"\n";
                }
                else if(op == 4)
                {
                    break;
                }
                else 
                {
                    cout<<"Invalid Position\n";
                }
            }
        }
        else if(Choice == 7)
        {
            cout<<"Thank you for using the Data Structure Libaray!!!!...... \n";
            break;
        }
        else 
        {
            cout<<"Invalid Option ";
        }
    }
}
