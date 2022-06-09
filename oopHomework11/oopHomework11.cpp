#include <iostream>
using namespace std;
#include"Dequeue.h"

int main()
{
    Deque<int, 5>deque;
    deque.push_rear(1);
    deque.push_rear(3);
    deque.push_rear(5);
    deque.push_rear(7);
    //deque.push_rear(9);
    //deque.pop_front();
    //deque.pop_rear();
    //deque.push_front(9);

    deque.display();

}
