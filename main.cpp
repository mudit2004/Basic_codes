//
//  main.cpp
//  xxxx
//
//  Created by Mudit Golchha on 10/10/22.
//

//
//  xxxxx.cpp
//
//
//  Created by Mudit Golchha on 10/10/22.
//

#include <iostream>
using namespace std;

struct node{
    int data;
    node *link;
};
class Q
{
public:
    node *front;
    node *rear;
    node *qlink = new node();
    int count;
    void create()
    {
        qlink = new node();
        count = 0;
        qlink->front = NULL;
        qlink->rear = NULL;
    }
    bool isEmpty(){
        if(qlink->count == 0)
            return true;
        else
            return false;
    }

    void display(){
        node *temp = qlink->front;
        while(temp!= NULL){
            cout<<temp->data<<" -> ";
            temp = temp->link;
        }
        cout<<"Null"<<endl;
    }

    bool queueFront(int &dataout){
        bool s;
        if(isEmpty())
            s = false;
        else{
            dataout  = qlink->front->data;
            s = true;
        }
        return s;
    }

    void destroy(){
        node *temp1 = qlink->front;
        while(temp1 != NULL){
        node *del = temp1;
        temp1 = temp1->link;
        qlink->front = temp1;
        --(qlink->count);
        delete del;
        }
        display();
        delete qlink;
    }

    void enqueue(int datain){
        node *newnode = new node();
        if(newnode == NULL)
            cout<<"Oveflow !!";
        else{
            newnode->link = NULL;
            newnode->data = datain;
            if(isEmpty()){
                qlink->front = newnode;
                qlink->rear = newnode;
            }
            else{
                qlink->rear->link = newnode;
                qlink->rear = newnode;
            }
            ++(qlink->count);
            cout<<"Count : "<<qlink->count;
        }
    }

    int dequeue(){
        if(isEmpty())
            cout<<" Queue is empty ";
        else{
            int tempdata = qlink->front->data;
            node *temp = qlink->front;
            if(qlink->front == qlink->rear)
                qlink->front = qlink->rear = NULL;
            else
                qlink->front = qlink->front->link;
            delete temp;
            --(qlink->count);
            cout<<"Count : "<<qlink->count<<endl;
            return tempdata;
        }
        return -1;
    }
};


int main(){
    Q obj;
    int ch,data,dataout;
    char chr;bool s;
    create();
    int des = 0;
    do{
        cout<<"\nEnter the choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter data to insert: ";
                cin>>data;
                obj.enqueue(data);
                break;
            case 2:
                dataout = obj.dequeue();
                if(dataout != -1)
                    cout<<"Removed element    : "<<dataout<<endl;
                break;
            case 3:
                s = obj.queueFront(data);
                if(s ==false)
                    cout<<"Queue Empty\n";
                else
                    cout<<"Queue Front : "<<data;
                break;
            case 4:
                obj.destroy();
                des =1;
                break;
            case 5:
                obj.display();
                break;
            default:
                cout<<"Enter the choice !!!!";
        }
    if(des != 0)
        cout<<" Queue destroyed ";
    }while(des == 0);
}
    
                    
                        

