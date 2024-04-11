​#include <stdio.h>

​
​int compare(char *s1, char *s2);

​
​void main()

​
​{

​
​  printf("%d\n", compare("abCd", "abc"));

​
​}

​
​int compare(char *s1, char *s2)

​
​{

​
​  while(*s1&&*s2&&_____)

​
​  {

​
​    s1++;

​
​    s2++;

​
​  }

​
​  return *s1-*s2;

​
​}