// LeetCode Question Link -> https://leetcode.com/problems/remove-duplicate-letters/

//Solution
struct Stack
{
  char *arr;
  int top;
  unsigned capacity;
};
struct Stack *createstack(unsigned capacity)
{
  struct Stack *obj = (struct Stack *)malloc(sizeof(struct Stack));
  obj->top = -1;
  obj->capacity = capacity;
  obj->arr = (char *)malloc(sizeof(char) * obj->capacity);
  return obj;
}
int isFull(struct Stack *obj)
{
  if (obj->top == obj->capacity - 1)
  {
    return 1;
  }
  return 0;
}
int isEmpty(struct Stack *obj)
{
  if (obj->top == -1)
  {
    return 1;
  }
  return 0;
}
void push(struct Stack *obj, char value)
{
  if (isFull(obj))
  {
    return;
  }
  obj->arr[++obj->top] = value;
}
void pop(struct Stack *obj)
{
  if (isEmpty(obj))
  {
    return;
  }
  obj->top--;
}
char peek(struct Stack *obj)
{
  if (isEmpty(obj))
  {
    return '\0';
  }
  return obj->arr[obj->top];
}

char *removeDuplicateLetters(char *s)
{
  int freq[26] = {0};
  bool visited[26] = {false};
  for (int i = 0; i < strlen(s); i++)
  {
    freq[s[i] - 'a']++;
  }
  struct Stack *st = createstack(strlen(s));
  for (int i = 0; i < strlen(s); i++)
  {
    while (!isEmpty(st) && peek(st) > s[i] && freq[peek(st) - 'a'] > 0 && visited[s[i] - 'a'] == false)
    {
      visited[peek(st) - 'a'] = false;
      pop(st);
    }
    if (!visited[s[i] - 'a'])
    {
      push(st, s[i]);
      visited[s[i] - 'a'] = true;
    }
    freq[s[i] - 'a']--;
  }

  struct Stack *st1 = createstack(strlen(s));
  int i = 0;
  while (!isEmpty(st))
  {
    push(st1, peek(st));
    i++;
    pop(st);
  }
  free(st->arr);
  free(st);
  char *ans = (char *)malloc((i + 1) * sizeof(char));
  int k = 0;
  while (!isEmpty(st1))
  {
    ans[k] = peek(st1);
    k++;
    pop(st1);
  }
  ans[k] = '\0';
  return ans;
}