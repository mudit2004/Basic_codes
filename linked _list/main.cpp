#include<iostream>
using namespace std;
struct node
{
int data;
    int count;
node *link;
};
node *first=NULL;
void insert(int dataIn)
{
node *ptr=new node;
ptr->data=dataIn;
ptr->link=first;
first=ptr;
    (first->count)++;
}
void display()
{
node *temp = first;
while(temp!=NULL)
{
cout<<temp->data<<"  "<<temp->link<<"--->";
temp=temp->link;
}
cout<<endl;
}
void swap()
{
node *temp=first;
node *temp1=first->link;
while(temp->count!=0)
{
int x=temp->data;
temp->data=temp1->data;
temp1->data=x;
cout<<temp->data<<"\t"<<temp1->data<<"\t";
temp=temp1->link;
temp1=temp->link;
    --(temp->count);
}


}
int main()
{
insert(10);
insert(20);
insert(30);
insert(40);

display();
//swap();
return 0;
}
