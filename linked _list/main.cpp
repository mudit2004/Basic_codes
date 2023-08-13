//
//  main.cpp
//  sample 45
//
//  Created by Mudit Golchha on 12/10/22.
//

#include <iostream>
using namespace std;
struct node {
    int data;
    node* link;
};
struct list{
    int count;
    node* head;
};
list *first = NULL;
void create(){
    first = new list;
    first->count = 0;
    first->head  = NULL;
    }
void insert(node *ppr,int val){
        node *p = new node;
        p->data = val;
        if(ppr == NULL){
            p->link= first->head;
            first->head = p;
        }
        else{
            p->link = ppr->link;
            ppr->link = p;
        }
    first->count++;
    }
bool search(node *&ppr,node *&ploc,int datain){
    ploc = first->head;
    while((ploc != NULL) && (ploc->data)>datain){
        ppr = ploc;
        ploc = ploc->link;
    }
    if(ploc != NULL && ploc->data == datain){
        return true;
    }
    return false;
}

void display(){
    node *temp = first->head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
    cout<<first->count;
    cout<<endl;
}

void del(node *ppr, node *ploc,int datain){
    if(ppr==NULL){
        first->head = ploc->link;
        ploc->link= NULL;
    }
    else{
        ppr->link = ploc->link;
        ploc->link = NULL;
    }
    first->count--;
}



int main(){
    create();
    node *ppr = NULL;  node *ploc = NULL;
    insert(ppr,45);
    insert(ppr,46);
    insert(ppr,47);
    insert(ppr,48);
    insert(ppr,49);
    insert(ppr,50);
    insert(ppr,51);
    insert(ppr,52);
    
    display();
    cout<<search(ppr,ploc,47)<<endl;
    //cout<<"tt\n";
    if(search(ppr,ploc,51))
        del(ppr,ploc,51);
    display();
    return 0;
}
