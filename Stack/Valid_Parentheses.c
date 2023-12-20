// Question Link -> https://leetcode.com/problems/valid-parentheses/

//Solution
struct Stack
{
  int *arr;
  int top;
  unsigned capacity;
};
struct Stack *createstack(unsigned capacity)
{
  struct Stack *obj = (struct Stack *)malloc(sizeof(struct Stack));
  obj->capacity = capacity;
  obj->top = -1;
  obj->arr = (int *)malloc(sizeof(int) * obj->capacity);
  return obj;
}
int isEmpty(struct Stack *obj)
{
  if (obj->top == -1)
  {
    return 1;
  }
  return 0;
}
int isFull(struct Stack *obj)
{
  if (obj->top == obj->capacity - 1)
  {
    return 1;
  }
  return 0;
}
void push(struct Stack *obj, int val)
{
  if (isFull(obj))
  {
    return;
  }
  obj->top++;
  obj->arr[obj->top] = val;
  return;
}
int peek(struct Stack *obj)
{
  if (isEmpty(obj))
  {
    return INT_MIN;
  }
  return obj->arr[obj->top];
}
void pop(struct Stack *obj)
{
  if (isEmpty(obj))
  {
    return;
  }
  obj->top--;
}
bool isMatching(char s, char d)
{
  if ((s == '(' && d == ')') || (s == '{' && d == '}') || (s == '[' && d == ']'))
  {
    return 1;
  }
  return 0;
}
bool isValid(char *s)
{
  struct Stack *st = createstack(strlen(s));
  for (int i = 0; i < strlen(s); i++)
  {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[')
    {
      push(st, s[i]);
    }
    else
    {
      if (isEmpty(st) || !isMatching(peek(st), s[i]))
      {
        return false;
      }
      else
      {
        pop(st);
      }
    }
  }
  bool result = isEmpty(st);
  free(st->arr);
  free(st);
  return result;
}