#ifndef QUEUE_H
#define QUEUE_H

struct Element2
{
 Element2( int x, Element2* y): data(x), prev(y) {}
 Element2( int x): data(x){}
 Element2* prev;
 int data;
};
class Queue
{
private:
 Element2* last;
 Element2* first;
public:
 Queue(): last(0), first(0) {}
 void Push(int x)
 {
 if(last != 0)
 {
 last = new Element2(x, last);
 if ((*first).prev==0) (*first).prev = last;
 }
 else
 {
 last = new Element2(x);
 first = new Element2(x);
 }
 }
 int Pop()
 {
 if(last != 0)
 {
 int el = (*first).data;
 first = (*first).prev;
 return el;
 }
 return -1;
 }
};
#endif // QUEUE_H
