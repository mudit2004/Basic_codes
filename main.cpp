//
//  main.cpp
//  sample48
//
//  Created by Mudit Golchha on 13/10/22.
//


#include<iostream>
using namespace std;
struct node
{
    int data;
    node *link;
};
node *first=NULL;
void insertnode(int datain)
    {
        node *ppre=new node;
        ppre->data=datain;
        ppre->link=first;
        first=ppre;
        cout<<"Insert Success!\n";
    }
void display()
{
        node *temp=first;
        while(temp!=NULL)
        {
            cout<<"data:"<<temp->data<<" ";
            temp=temp->link;
        }
        cout<<"\n";
}
void swap()
{
     node *ploc=first;
    node *p=ploc->link;
    while(p!=NULL)
    {
        int flag;
        flag=ploc->data;
        ploc->data=p->data;
        p->data=flag;
        cout<<ploc->data<<" "<<p->data<<" ";
        ploc=p->link;
        if(ploc!=NULL)
        p=ploc->link;
    
    }
        if(p==NULL)
        {
            cout<<ploc->data<<endl;
        }
}
int main()
{
    node *ppre=new node;
    //node *ploc=new node;
    //node *p=new node;
    int datain,choice;
    do{
    cout<<"ENter choice:\n";
    cout<<"1.Insert\n2.display\n3.swap\n";
    cin>>choice;
    switch(choice){
        
    case 1:
    {
        cout<<"ENter data:\n";
        cin>>datain;
        insertnode(datain);
        break;
    }
    case 2:
        {
            display();
            break;
        }
    case 3:
    {
        swap();
        break;
    }
    default:
    return 0;
}
}while(choice!=4);
    return 0;
}
