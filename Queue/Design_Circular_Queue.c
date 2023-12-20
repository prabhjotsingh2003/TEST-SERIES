// LeetCode Question Link -> https://leetcode.com/problems/design-circular-queue/description/

//Solution

typedef struct
{
  int front;
  int rear;
  int *arr;
  int size;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k)
{
  MyCircularQueue *obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
  obj->front = -1;
  obj->rear = -1;
  obj->arr = (int *)malloc(sizeof(int) * k);
  obj->size = k;
  return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
  return obj->front == -1 && obj->rear == -1;
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
  return (obj->rear + 1) % obj->size == obj->front;
}
bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
  if (myCircularQueueIsFull(obj))
  {
    return false;
  }
  else if (myCircularQueueIsEmpty(obj))
  {
    obj->front++;
    obj->rear++;
    obj->arr[obj->rear] = value;
    return true;
  }
  else
  {
    obj->rear = (obj->rear + 1) % obj->size;
    obj->arr[obj->rear] = value;
    return true;
  }
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
  if (obj->front == -1 && obj->rear == -1)
  {
    return false;
  }
  else if (obj->front == obj->rear)
  { // only one lement is left
    obj->front = -1;
    obj->rear = -1;
    return true;
  }
  else
  {
    obj->front = (obj->front + 1) % obj->size;
    return true;
  }
}

int myCircularQueueFront(MyCircularQueue *obj)
{
  if (myCircularQueueIsEmpty(obj))
  {
    return -1;
  }
  return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
  if (myCircularQueueIsEmpty(obj))
  {
    return -1;
  }
  return obj->arr[obj->rear];
}

void myCircularQueueFree(MyCircularQueue *obj)
{
  free(obj->arr);
  free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/