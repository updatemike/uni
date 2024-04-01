# Intro
```c
//This is a single-line comment
/*
This is a multi-line
comment
*/

//These are libraries/dependencies
#include <stdio.h>
#include "intro.h"

//This is the main function, it exists in every c program.
int main() {
  printf("message");
  return 0;
}
```
## Data types and sizes (64 bit OS)
```
type    bytes   bits
text
char    1       8
decimal numbers/values
short   2       16
int     4       32
long    8       64
floating numbers/values
float   4       32
double  8       64
other
pointer 8       64
```

To get actual size in c:  
```c
sizeof(char);
```

You can define constants as such:  
```c
#define MAX 100
```

You can cast a type to another:  
```c
float x;
(double) x;
```

## Cycles
### While
```c
int val = 0;
while(val < MAX) {
  printf("%d", val++);
}
```
### For
```c
for(int val = 0; val < MAX; val++) {
  printf("%d", val);
}
```

## Input/Output
## scanf()
Will read the first value that matches the type (decimal number in this case), from stdin, until it finds a whitespace and assigns it to a variable 
Returns how many values were read.  
```c
int x;
scanf("%d", &x);
```

## printf()
Will print into stdout.  
```c
printf("%d", x);
```
```
%02d    print decimal with at least 2 numbers and fill left with 0's
%.2f    print float with 2 floating points
%99s    read/print string with max 99 chars
%ld     long decimal
%sd     short decimal
```

## getchar()
Reads a character.
```c
char ch;
ch = getchar();
```

# Operators
```
sign        functionality
=           assignment
==          comparison (equal)
!=          comparison (not equal)
<           comparsion (smaller)
>           comparison (greater)
||          or
&&          and
i++         post-increment i + 1
++i         pre-increment i + 1
```

# Vectors
## Uni-dimensional
```c
#define MAX = 10;
int vec[MAX] = {0};
vec[0] = 10;
printf("%d", vec[0]); 
//Will print 10;
```

## Bi-dimensional
```c
#define LIN 10
#define COL 10

int vec[LIN][COL];
vec[0][0] = 10;
printf("%d", vec[0][0]);
//Will print 10;
```

## Copy vectors
Vectors need to be copied position by position.  
```c
int vec1[SIZE], vec2[SIZE];
for(int i = 0; i < SIZE; i++)
  vec2[i] = vec1[i];
```

## Strings
In c strings are vectors that end with the char '\0'.  
```c
#define SIZE 100

char string[SIZE];
scanf("%99s", string);
string[SIZE - 1] = '\0';
printf("%s", string);
```
Note string doesn't need & for assignment and that the scanf size is 1 smaller than SIZE because you need to make sure there is space for '\0'.  
Also note that scanf only reads until it finds a whitespace (' ', '\t', '\n', etc).  

### String library (string.h)
You can check function docs with:  
```man <name-of-function>```
```c
#include <string.h>
```
function              functionality       return
strcmp(str1, str2)    compare strings     int
strcpy(str1, str2)    copy str2 to str1   char *
strdup(str)           duplicate str       char *
strlen(str)           size of str         int

# Functions
Functions need to be declared before being called.   
```c
//Function declaration
void example(int x);
//Function gets called
int main() {
  example(1);
  return 0;
}
//Function definition
void example(int x) {
  function body
}
```
A function always has a return type, void means it returns nothing.  
For example main() return an int.  

## Parameters: Value vs Reference
All arguments are copied to local variables when used.  
You never alter the original values unless you use pointers to the argument's adress.  
Note that vectors are in the general sense a pointer so any change alters the original vector. To avoid this make copies.  

# Structures
```c
#define LIC_SIZ

//Structure definition
typedef struct _car_ {
  char licence[LIC_SIZ];
  float miles;
  float price;
} Car;

//Structure declaration, all values set to 0
Car car1 = {0};

//Strucuture manipulation
car1.miles = 100.20;
printf("%.2f", car1.miles); //100.20
```

## Structure operations
```c
//Structures have to be compared per value, you can't do car1 == car2
car1.price == car2.price;

//Functions can use and return structures
Car example(Car car1) {
  car1.price = 0;
  return car1;
}
```