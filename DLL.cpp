#include<iostream>

using namespace std;

//Struct double linked list
struct d_NODE {
    int key;
    d_NODE *next;
    d_NODE *prev;
};

struct d_LIST {
    d_NODE * head;
    d_NODE * tail;
};

void original_list(d_LIST*& list);
d_NODE* create_node(int vallue);
d_LIST* create_list(d_NODE * node);
void addHead(d_LIST*&list,int value);
void addTail(d_LIST*&list,int value);
void removeHead(d_LIST*& list);
void removeTail(d_LIST*& list);
void removeAll(d_LIST*& list); 
void removeBefore(d_LIST* &list, int value);
void removeAfter(d_LIST* &list, int value);
void  addPos(d_LIST* &list, int data, int pos);
void  removePos(d_LIST* &list, int data, int pos);
void addBefore(d_LIST* &list, int data, int val);
void addAfter(d_LIST* &list, int data, int val);
void  printList(d_LIST* list);
int countElements(d_LIST* list);
void removeElement(d_LIST* &list, int key);
void removeDuplicate(d_LIST* &list);
void reverseList(d_LIST*& list);


//Main
main(){
    d_LIST* list;
    //create_list
    original_list(list);
    cout<<"1. Original d_list: ";printList(list);

    //addHead
    addHead(list,12);
    cout<<"2. d_list with add 12 to head: ";printList(list);

    //removeHead
    original_list(list);
    removeHead(list);
    cout<<"3. d_list with remove head: ";printList(list);

    //removeTail
    original_list(list);
    removeTail(list);
    cout<<"4. d_list with remove tail: ";printList(list);

    //removeAll
    original_list(list);
    removeAll(list);
    cout<<"5. d_list with remove all: ";printList(list);

    //removeBefore
    original_list(list);
    removeBefore(list,8);
    cout<<"6. d_list with remove befor node key = 8 : ";printList(list);

    //removeAfter
    original_list(list);
    removeAfter(list,8);
    cout<<"7. d_list with remove after node key = 8 : ";printList(list);

    //add positon
    original_list(list);
    addPos(list,27,5);
    cout<<"8. d_list with add node key = 27 at pos = 5 : ";printList(list);

    //remove positon
    original_list(list);
    removePos(list,27,5);
    cout<<"9. d_list with remove node key = 27 at pos = 5 : ";printList(list);

    //add Before
    original_list(list);
    addBefore(list,13,9);
    cout<<"10. d_list with add node key = 13 before node key = 9 : ";printList(list);

    //add After
    original_list(list);
    addAfter(list,13,9);
    cout<<"11. d_list with add node key = 13 after node key = 9 : ";printList(list);

    //Count Element
    original_list(list);
    int count = countElements(list);
    cout<<"12.Elements = "<<count<<endl;

    //ReverseList
    original_list(list);
    reverseList(list);
    cout<<"13.ReverseList: ",printList(list);

    //Remove Duplicates
    original_list(list);
    removeDuplicate(list);
    cout<<"14.Remove duplicate: ",printList(list);

    //Remove Element
    original_list(list);
    removeElement(list, 12);
    cout<<"15. d_list with remove all elements with key=12: ",printList(list);

}




//Define function
d_NODE* create_node(int value)
{
    d_NODE* new_node = new d_NODE;
    new_node->key = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
};

d_LIST* create_list(d_NODE* node)
{
    d_LIST* list = new d_LIST;
    list->head = node;
    return list;
};

void addHead(d_LIST*& list, int value)
{
    d_NODE* temp = create_node(value);
    temp->next = list->head;
    list->head->prev = temp;
    list->head = temp;
};

void addTail(d_LIST*& list, int value)
{
    d_NODE* temp=list->head;
    d_NODE* tempNode = create_node(value);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = tempNode;
    tempNode->prev = temp;
    list->tail = tempNode;
};

void removeHead(d_LIST*& list)
{
    if (list->head->next == NULL) list->head = NULL;
    else {
        d_NODE* temp = list->head;
        list->head = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
};

void removeTail(d_LIST*& list)
{
    d_NODE* temp = list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    };
    list->tail = temp->prev;
    temp->prev->next = NULL;
    temp->prev = NULL;
    delete temp;
};

void removeAll(d_LIST*&list)
{
    d_NODE* temp = list->head;
    while (temp->next != NULL)
    {
        removeHead(list);
        temp = list->head;
    }
    removeHead(list);
};

void removeBefore(d_LIST*& list,int value)
{
    d_NODE* temp = list->head;
    while (temp->key != value)
    {
        temp = temp->next;
    };
    d_NODE* tempNode = temp->prev;
    temp->prev->prev->next = temp;
    temp->prev->next = NULL;
    temp->prev = temp->prev->prev;
    tempNode->prev = NULL;
    delete tempNode;
};

void removeAfter(d_LIST*& list, int value)
{
    d_NODE* temp = list->head;
    while (temp->key != value)
    {
        temp = temp->next;
    };
    d_NODE* tempNode = temp->next;
    temp->next = temp->next->next;
    tempNode->next->prev = tempNode->prev;
    tempNode->prev = NULL;
    tempNode->next = NULL;
    delete tempNode;
};

void addPos(d_LIST*& list, int value, int pos)
{
    if (pos <= 0) cout<<"Invalid position"<<endl;
    d_NODE* temp = list->head;
    d_NODE* node_insert = create_node(value);
    int i = 1;
    while (i != pos)
    {
        temp = temp->next;
        i++;
    };
    d_NODE* tempNode = temp->prev;
    temp->prev->next = node_insert;
    temp->prev = node_insert;
    node_insert->next = temp;
    node_insert->prev = tempNode;
};

void removePos(d_LIST*& list, int value, int pos)
{
    if (pos <= 0) cout<<"Invalid position"<<endl;
    d_NODE* temp = list->head;
    int i = 1;
    while (i != pos)
    {
        temp = temp->next;
        i++;
    };
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
};

void addBefore(d_LIST*& list, int data, int value)
{
    d_NODE* node_insert = create_node(data);
    d_NODE* temp = list->head;
    while (temp->key != value) 
    {
        temp= temp->next;
    };
     d_NODE* tempNode = temp->prev;
    temp->prev->next = node_insert;
    temp->prev = node_insert;
    node_insert->next = temp;
    node_insert->prev = tempNode;
};

void addAfter(d_LIST*& list,int data,int value)
{
    d_NODE* node_insert = create_node(data);
    d_NODE* temp = list->head;
    while (temp->key != value) 
    {
        temp= temp->next;
    };
    d_NODE* tempNode = temp->next;
    temp->next->prev = node_insert;
    temp->next = node_insert;
    node_insert->prev = temp;
    node_insert->next = tempNode;
};

void printList(d_LIST* list)
{
    if (list->head == NULL) cout<<"Empty List";
    for (d_NODE* node = list->head; node; node= node->next)
        cout<<node->key<<"  ";
    cout<<endl;
};

int countElements(d_LIST* list)
{
    int count =0;
    for (d_NODE* node = list->head; node; node= node->next) count++;
    return count;
};

void removeElement(d_LIST*& list,int key)
{
    while (list->head->key == key)
    {
        removeHead(list);
    };
    d_NODE* temp = list->head;
    int vt=1;
    while ( temp->next != NULL)
    {

        if (temp->next->key == key)
        {
            
            d_NODE* tempNode = temp->next;
            temp->next->next->prev = temp;
            temp->next = temp->next->next;
            temp = temp->next;
            tempNode->next = NULL;
            tempNode->prev = NULL;
            delete tempNode;
        }
        else{
            temp = temp->next;
        }
    }
};

void removeDuplicate(d_LIST*& list)
{
    d_NODE* temp = list->head;
    d_NODE* duplicateNode = NULL;
    while ( temp ->next != NULL)
    {   
        duplicateNode=temp->next;
        while ( duplicateNode->next != NULL)
        {
            if (temp->key == duplicateNode->key)
            {
                d_NODE* tempNode = duplicateNode;
                tempNode->next->prev = duplicateNode->prev;
                duplicateNode->prev->next = duplicateNode->next;
                duplicateNode = duplicateNode->next;
                tempNode->next = NULL;
                tempNode->prev = NULL;
                delete tempNode;
            }
            else {
                duplicateNode = duplicateNode->next;
            }
        }
        temp= temp->next;   
    }
    }   

void reverseList(d_LIST*& list)
{
    d_NODE* current= list->head;
    d_NODE* tempNode = current->prev;

    while (current != NULL)
    {
        tempNode = current->prev;
        current->prev = current->next;
        current->next = tempNode;
        current = current->prev;
    }
    if (tempNode != NULL) list->head=tempNode->prev;
};

void original_list(d_LIST*& list)
{
    d_NODE* init_Node;
    init_Node = create_node(12);
    list = create_list(init_Node);
    addTail(list,5);
    addTail(list,12);
    addTail(list,22);
    addTail(list,3);
    addTail(list,4);
    addTail(list,12);
    addTail(list,3);
    addTail(list,3);
    addTail(list,8);
    addTail(list,9);
    addTail(list,10);
}
