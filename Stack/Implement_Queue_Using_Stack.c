// LeetCode Question Link -> https://leetcode.com/problems/implement-queue-using-stacks/

//Solution
typedef struct
{
  int *arr[100];
  int top;
  int startindex;
} MyQueue;

MyQueue *myQueueCreate()
{
  MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));
  obj->top = -1;
  obj->startindex = -1;
  return obj;
}

void myQueuePush(MyQueue *obj, int x)
{
  obj->top++;
  obj->arr[obj->top] = x;
  return;
}

int myQueuePop(MyQueue *obj)
{
  return obj->arr[++obj->startindex];
}

int myQueuePeek(MyQueue *obj)
{
  return obj->arr[1 + obj->startindex];
}

bool myQueueEmpty(MyQueue *obj)
{
  return obj->startindex == obj->top;
}

void myQueueFree(MyQueue *obj)
{
  free(obj->arr);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/