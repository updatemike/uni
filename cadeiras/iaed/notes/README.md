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
## Data types and sizes (64 bit CPU)
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
There is also unsigned that foregoes negative values (ex: unsigned int).  

To get actual size in c:  
```c
sizeof(char);
```
You can cast a type to another:  
```c
float x;
(double) x;
```
## Variables  
```c
/* Sequence of declarations */
int superior, inferior, step;
char c, name[1000];

/* Declaration by line */
int superior;
int inferior;
int step;
char c;
char name[1000];
```
## Constants  
You can define constants as such:  
```c
#define MAX 100
enum months = {NO,YES}; //NO = 0, YES = 1.
const int x = 1;
```
Constants cannot be changed.  
## Declaration and Scope
Where you declare a variable matters.  
```c
int global; //Global variable
void example() {
  int local = 0; //Local variable
}
```
Remember that it matters if a variable is initialized with a value to prevent odd behaviour.  
In c global and static variables are initialized to 0 automatically, unless you give it another value.  
Static variables get defined once and future definitions are ignored and the value is kept.  
```c
int a, b, c;
int count() {
  static int i; //i = 0
  return ++i;
}
a = count() //a = 1
b = count() //b = 2
c = count() //c = 3
```
# Input/Output
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
## Special characters
```
Character           Result
\n                  New Line
\t                  Tab
\0                  Null terminator
\\                  \
```
# Operators
```
sign        functionality
=           assignment
==          relation (equal)
!=          relation (not equal)
<           relation (smaller)
>           relation (greater)
||          or
&&          and
i++         post-increment i + 1
++i         pre-increment i + 1
```
Operators follow the general precedence rule:  
() >> Unary >> Arithmetics >> Relational >> Logic
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
## Vector Initialization
```c
int example[] = {1, 2, 3}; //Length 3 with set values.
char example[][4] = {"AAA", "BBB"}; //Room for '\0' 
int example[10] = {1, 2, 3}; //Length 10 with 3 set values, rest is set to 0.
```
## Copy vectors
Vectors need to be copied position by position.  
```c
int vec1[SIZE], vec2[SIZE];
for(int i = 0; i < SIZE; i++)
  vec2[i] = vec1[i];
```
## Strings
In c strings are vectors that terminate with the char '\0'.  
```c
#define SIZE 100

char string[SIZE];
scanf("%99s", string);
//scanf doesn't null terminate a string, you need to do it.
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
```
function              functionality       return
strcmp(str1, str2)    compare strings     int
strcpy(str1, str2)    copy str2 to str1   char *
strdup(str)           duplicate str       char *
strlen(str)           size of str         int
```
# Conditionals and Cycles
## Conditionals
### If
```c
int val = MAX;
//executes instruction if condition is true
if(val == MAX) //val == MAX is true (1)
  printf("%d", val); //happens
```
### Switch
```c
//lets pretend getchar() returns 'q'
char c = getchar();
switch(c) {
  case 'a':
    printf("a");
    break;
  case 'q': //this is the case
    printf("q"); //this happens
    break; //this happens 
  default:
    printf("Didn't input 'a' or 'q'.");
    break;
}

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
### Do-While
```c
int val = 0;
do {
  printf("%d", val++);
}
while(val < MAX);
```
## Break and Continue
The instruction 'break' terminates a cycle.  
The instruction 'continue' skips to the next iteration of the cycle.  
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
For example main() returns an int.  
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

//You can copy a whole structure
car2 = car1;
//Or just a value
car2.price = car1.price;

//Functions can use and return structures
Car example(Car car1) {
  car1.price = 0;
  return car1;
}
```
# Pointers and Addresses
As the name implies pointers point at something in memory.  
```c
int x = 0;
int *p_x = &x;
*p_x == 0; //true
```
int * signifies a pointer to an integer.  
& signifies the memory address of something.  
Pointers are normally named pX or p_x or xPtr (for x).  
In the example above the pointer p_x that points to an integer (int *), is pointing at the address of x (&x).  
*p_x is called dereferencing a pointer. It allows us to get/set the values of what it is pointing at.
## Pointers and functions
```c
int x = 1, y = 2;
swap(x, y);
void swap(int a, int b) {
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}
```
The above example won't do anything. x == 1 and y == 2. But with pointers and addresses this changes.  
```c
int x = 1, y = 2;
swap(&x, &y);
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
```
Now the values will swap. x == 2, y == 1.  
## NULL pointer
```c
#include <stdlib.h>
int *ptr = NULL;
```
Special pointer that means this pointer points at nothing.  
## Pointer declaration
As seen before vectors are similar (not exactly the same) to pointers. As such a pointer can be declared as such.  
```c
char *ex1 = "hello";
char ex2[] = "hello";
```
Both allocate 5 bytes for 'h', 'e', 'l', 'l', 'o', '\0'.  
Main diference being that you can´t change where ex2 points to since it's a fixed vector, but you can still change values like ex2[0] = 'H'.  
## Pointer aritmethics
```c
int vec[3] = {1, 2, 3};
int *p_vec = vec;
vec[1] == *(vec + 1); //True, value is 2
*(p_vec + 1) == 2; //True
```