#include<iostream>
using namespace std;

struct cqueue
{
    int size;
    int f;
    int r;
    int *arr;

};

int Isfull(struct cqueue* p)
{
    if((p->r+1)%(p->size)==p->f)
    return 1;
    else
    return 0;
}


int Isempty(struct cqueue* p)
{
    if(p->f == p->r)
    return 1;
    else
    return 0;
}



void enqueue(struct cqueue* p, int data)
{
    if(Isfull(p))
    cout<<"Queue is Full"<<endl;
    else
    {
        p->arr[p->r] = data;
        p->r = (p->r+1)%p->size;
        cout<<"Enqueued element : "<<data<<endl;
    }
}

void display(struct cqueue* q)
{
    for(int i=q->f; i<q->r%q->size; i++ )
    {
        cout<<q->arr[i%q->size]<<" ";
    }
}
int dequeue(struct cqueue* p)
{
    int a = -1;
    if(Isempty(p))
    {
        cout<<"Queue is empty"<<endl; 
    }
    else
    {
        a = p->arr[p->f];   
        p->f = (p->f+1)%p->size;
    }
    return a;
}

int main()
{
    
    struct cqueue q;
    cout<<"Enter size"<<endl;
    cin>>q.size;

    q.f = q.r = 0;

    q.arr = new int[q.size];
    
    enqueue(&q,5);
    enqueue(&q,10);
    enqueue(&q,15);
    enqueue(&q,20);
    enqueue(&q,25);

    cout<<"Dequeued element : "<<dequeue(&q)<<endl;
    cout<<"Dequeued element : "<<dequeue(&q)<<endl;
    cout<<"Dequeued element : "<<dequeue(&q)<<endl;
    enqueue(&q,30);
    enqueue(&q,35);

    display(&q);
    

    return 0;
}


