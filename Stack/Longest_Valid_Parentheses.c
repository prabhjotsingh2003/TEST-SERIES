// LeetCode Question Link -> https://leetcode.com/problems/longest-valid-parentheses/

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
int max(int a, int b)
{
  if (a > b)
  {
    return a;
  }
  return b;
}
int longestValidParentheses(char *s)
{
  struct Stack *st = createstack(strlen(s));
  int ans = 0;
  int *dp = (int *)calloc(strlen(s), sizeof(int));
  for (int i = 0; i < strlen(s); i++)
  {
    if (s[i] == ')' && isEmpty(st))
      continue;
    else if (s[i] == '(')
      push(st, i);
    else
    {
      int length = i - peek(st) + 1;
      if (peek(st) > 1)
      {
        length += dp[peek(st) - 1];
      }
      dp[i] = length;
      ans = max(ans, length);
      pop(st);
    }
  }
  return ans;
}