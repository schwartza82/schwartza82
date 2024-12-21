//Bit maps
-Coordinate system of top down
-cs50.ly/art 
- RGB system = color system where you can rep any color of the rainbow using red, green, and blue

//hexadecimal system aka base-16
- 0-9 digits and 6 letters of the English alphabet (case insensitive) A B C D E F
- columns are powers of 16

16 1
1  0
- this is 16 in hexadecimal 

FF in hexadecimal = 16 x 15 + 1 x 15 -> 255

-4 bits in binary 1111 = 15
-1111 in binary = FF in hexadecimal (4 bits underneath the hood)

- hexadeciaml often used to describe the locations of the addresses in memory

int n = 50;
- number 50 ends up in computers memory and assigned a name n in a symbol n 

//Pointers introduction
& = ampersand operator allows us to get the address of a piece of data in memory (put before the name of a variable to get address)
* = d-reference operator lets you go to a specific address in memory

//&n for address of n in memory 

#include <stdio.h>
int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}

$ make addresses
$ ./addresses
0x7ffccfdccb5c

-pointers not a feature you can harness in higher-level languages like Python and Java
- C is close enough to the computer's hardware you can get before things get really low level and scary (like assembly language) 

Pointers = variable that contains an address of some variable (think of it like an address)

#include <stdio.h>
int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    //p is the address of an integer
    //%p = pointer
}

$ make addresses
$ ./addresses
0x7fffea4119fc

**pointers very good for data structures in memory**
- helps us create the equivalent of 2-D and 3-D data structures by linking things together

-pointers take up 8 bytes (1 bit) while integers by convention take up 4 bytes

**can be helpful to think of a pointer as a variable that points to something else**
- double pointers ** exist (dear lord) but we won't cover that yet

//Introduction to Data Types and Strings in C

string s = "Hi!" 
- double quotes add /0 (nul) at the end of string. Extra byte for free!
- single quotes for char don't do that

Why is it sufficient for a variable to only store the 1st byte address and not all of the bytes
- Because of the design of strings, we always nul terminate them so it only sufficiences ot know the 1st byte's address

//There is no such thing as a "string" keyword in C
**strings are actually a pointer to a character c**

string s = "HI!"; is actually
char *s = "HI!";

typedef struct
{
  string name;
  string number;
}
person;
- defined a person to be this structure

typedef int integer;
- if you want to create the keyword integer as a datatype, you can typedef it to int
- int becomes a synoynm for integer

typedef char *string;
- this is what's in cs50 library
- associates "string" with char * 
- python has string called stir


#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int n = 50;
    int *p = &n; // on the left side type of variable you want to point at, then a star and then the name of the variable
    printf("%i\n", *p);
    //*p = dereference p ("open the mailbox and print whatever is in the mailbox)
}

//Declaring a pointer requires you to declare the datatype
//When you use a pointer, you just use a star

$ make addresses
$ ./addresses
50

//address of a character vs the character itself

#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%p\n", s);
}

$ make addresses
$ ./addresses
0x603ce9084004


#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);
}
$ make addresses
$ ./addresses
HI!
- %s prints stuff in a sequence until it gets /0

#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
}
$ make addresses
$ ./addresses
H
-%c just has you printing out the literal first character

#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
}
$ make addresses
$ ./addresses
0x63220dc41004
0x63220dc41004

#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%c\n", s);
    printf("%c\n", &s[0]);
    printf("%c\n", &s[1]);
}
$ make addresses
$ ./addresses
0x55c88c224004
0x55c88c224004
0x55c88c224005
0x55c88c224006
0x55c88c224007
-continous 1 byte away from each other

//Pointer arithmetic
#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
}
$ make addresses
$ ./addresses
H
I
!

-square bracket notation is syntactic sugar for this

//randomly touching random bytes of memory cuz we crazy
#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+50000));
}
$ make addresses
$ ./addresses
H
I
Segmentation fault (core dumped)
- here, your touching a segment of memory not allocated to you

//Harnessing Pointer Arithmetic with Strings

#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);
    printf("%s\n", s+1);
    printf("%s\n", s+2);
}

$ make addresses
$ ./addresses
HI!
I!
- string = a sequence of characters identified by their first byte
- printing out a character and then everything after that until the nul character

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (*s == *t)
    //* means "go there"
    //At an address 0x123 and 0x546 there is a character H
    //compares 1st character of both strings but not every other one
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}

//pedantic usage of pointer arithmetic to get character

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (*s == *t && *(s+1) == *(t+1)) //can do that for every character if you really wanted to
    //* means "go there"
    //At an address 0x123 and 0x546 there is a character H
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}

//2 "strings" (char *p pointer for char) separated by a certain number of bytes
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    printf("%p\n", s);
    printf("%p\n", t);
}
$ make comparestring
$ ./comparestring
s: HI!
t: HI!
0x59f2f35066b0
0x59f2f35066f0
- ending b0 vs f0 suggests seperation by certain number of bytes (the rest of the characters after H)

//Copying strings and memory allocation

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
$ code copy.c
$ make copy
$ ./copy
s: hi!
s: Hi!
t: Hi!

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char* s = get_string("s: ");

    char* t = s;
    //value of address being copied as in s and t have the same memory address
    //t and s are NOT copies of the underlying characters

    if(strlen(t) > 0)
     //blindly assuming there's going to be at least one character in s so need if statement
    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}

    //using malloc and free to successfully copy a string
    malloc = memory allocation. Used to ask the operating system (Mac OS, Linux, etc) for some number of bytes of memory. returns 1st bite of memory if it's found free for you
        free = when you're done with some chunk of memory you can "free it" by passing in that same address and just hand it back to your operating system. Lets your operating system know you're free with a chunk of memory and that it can let you use said memory for something else later
        
    **if you use malloc to ask for more and more memory without ever free the memory, you'll run out of memory and you'll computer will likely freeze

#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* s = get_string("s: ");

    char* t = malloc(strlen(s) + 1);
    //asks malloc for how many bytes the user types in plus the nul character
    //t is now a pointer to a random chunk of free space

    for (int i = 0, n = strlen(s) + 1; i< n; i++)
        //included optimization of strlen(s) + 1 function so we don't have to keep calling it
        //here, n never changes so compares static value n to dynamic value i
    {
        t[i] = s[i];
        //copying from right to left for each character in s
    }

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
$ make copy
$ ./copy
s: hi!
s: hi!
t: Hi!

//NULL vs nul 
nul = /0 a singer character
NULL = point (address) to 0. by convention, nothing should go there

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* s = get_string("s: ");
    if (s == NULL)
    //If too much memory is used get_string returns NULL
    {
        return 1;
    }

    char* t = malloc(strlen(s) + 1);
    if (t == NULL)
    //if user asks for too much memory
    {
        return 1;
    }

    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
    //If you allocate memory with malloc or certain other function, you have to free the memory when you're done with it
    //don't need to free memory from get_string b/c cs50 library automatically frees it for you

    return 0;
}

//fixing bugs

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    //asking for 3 things times how big an int is
    x[1] = 72;
    x[2] = 72;
    x[3] = 33;
}

$ make memory
$ ./memory
$ valgrind ./memory
==3930== Memcheck, a memory error detector
==3930== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==3930== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==3930== Command: ./memory
==3930== 
==3930== Invalid write of size 4
==3930==    at 0x109170: main (memory.c:10)
==3930==  Address 0x4b9f04c is 0 bytes after a block of size 12 alloc'd
==3930==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==3930==    by 0x109151: main (memory.c:6)
==3930== 
==3930== 
==3930== HEAP SUMMARY:
==3930==     in use at exit: 12 bytes in 1 blocks
==3930==   total heap usage: 1 allocs, 0 frees, 12 bytes allocated
==3930== 
==3930== 12 bytes in 1 blocks are definitely lost in loss record 1 of 1
==3930==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==3930==    by 0x109151: main (memory.c:6)
==3930== 
==3930== LEAK SUMMARY:
==3930==    definitely lost: 12 bytes in 1 blocks
==3930==    indirectly lost: 0 bytes in 0 blocks
==3930==      possibly lost: 0 bytes in 0 blocks
==3930==    still reachable: 0 bytes in 0 blocks
==3930==         suppressed: 0 bytes in 0 blocks
==3930== 
==3930== For lists of detected and suppressed errors, rerun with: -s
==3930== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)

- invalidly writing to 4 bytes that we shouldn't be because not indexed at 0

==3930== 12 bytes in 1 blocks are definitely lost in loss record 1 of 1 
    -aka "memory is lost" so we should free x at the end of the program

FIXED BUGS!
    
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    if (x == NULL)
    {
        return 1;
    }
    x[0] = 72;
    x[1] = 72;
    x[2] = 33;
    free(x);
    return 0;
}

$ valgrind./memory
bash: valgrind./memory: No such file or directory
$ make memory
$ valgrind ./memory
==6162== Memcheck, a memory error detector
==6162== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==6162== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==6162== Command: ./memory
==6162== 
==6162== 
==6162== HEAP SUMMARY:
==6162==     in use at exit: 0 bytes in 0 blocks
==6162==   total heap usage: 1 allocs, 1 frees, 12 bytes allocated
==6162== 
==6162== All heap blocks were freed -- no leaks are possible
==6162== 
==6162== For lists of detected and suppressed errors, rerun with: -s
==6162== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


//Handling Garbage Values
- Generally, in C, if you don't initalize a variable or you don't iniitalize an array with explicit values there are going to be "garbage values"
- Garbage values = remnants of that memory being used before for something else while your program is running
- Important especially for big programs

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int scores[1024];
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}
- here, we're asking for 1024 bytes and will inevitably end up poking around in bytes w random addresses and get random numbers instead of 0

ALWAYS INITALIZE YOUR VARIABLES YOURSELF OR BY PROMPTING THE USER


//manipulating values of pointers

int main(void)
{
    int *x; //pointer called x that will store the address of an integer
    int *y;  //pointer called y that will store the address of an integer

    x = malloc(sizeof(int)); //allocating enough memory to fit 1 integer and store address malloc finds in x

    *x = 42; //go to x and put the number of 42 there (at an address)
    *y = 13; //since we didn't ask the computer to allocate any memory, y was not initialized with an equal sign at any point to anything. THEREFORE y HAS A GARGABE VALUE INSIDE OF IT VERY BAD

    y = x;

    *y = 13;
}

//Alternative to manipulate pointers that's good

int main(void)
{
    int *x; //pointer called x that will store the address of an integer
    int *y;  //pointer called y that will store the address of an integer

    x = malloc(sizeof(int)); //allocating enough memory to fit 1 integer and store address malloc finds in x

    *x = 42; //go to x and put the number of 42 there (at an address)

    y = x;

    *y = 13; //have dereferenced y with star y after actually giving it a value although this value is a duplicate value (y was initialized at 42 I think?!?!)
}

//BINKY POINTER EXPLAINATION

//this code allocates 2 pointers that can point to integers
//pointers initially don't point to anything. pointees need to be set up in a separate step
int *x;
int *y;

//allocating a pointee
malloc(sizeof(int))

//left hand side sets x to point to the pointee
x = malloc(sizeof(int))

//Deferencing the pointer x to store the number 42 into its pointed. Tink of it like following the arrow to store it's pointee
*x = 42;

//something like *y = 13; wouldn't work b/c the pointee for y hasn't been set up
//here the pointer y is being set to point to the same thing as x (the malloc(size(int)) I think)
//now y is fixed!!
y = x; 

//since the pointers are both sharing the 13, they both see the 13
*y = 13;

//swapping values using pointers
- use of temporary variables. Visualization of using a 3rd cup to transfer different liquids from two glasses

Logic in code would look like: 
void swap(int a, int b)
{
    int tmp = a; //tmp = temporary
    a = b;
    b = tmp;
}
**IN C THIS CODE DOESN'T WORK


#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    int tmp = a; //tmp = temporary
    a = b;
    b = tmp;
}
- When you call a function and pass in 2 arguments like A and B you're passing those arguments by *value*(copies of those values aka literally 1 and 2)
- By reference = passing by addresses of variables
- need to pass by reference to actually swap variables

Concept of scope 
- a and b in swap function exist only between curly brackets of the swap function. No effect on main which has different variables x and y 

Different regions/segments of a computers memory top to bottom

Machine code
    |
Globals
    |
Heap (heap of memory where malloc grabs memory from!!)
    |
Stack (The stack is where functions have variables and have arguments stored temporarily. Think of how a stack of plates grows upwards. )

Use conditionals to make sure the heap and the stack don't collide

//explaining swap example in the stack


void swap(int a, int b)
{
    int tmp = a; //tmp = temporary
    a = b;
    b = tmp;
}

Calling the main function of any program, a slice of a memory called a "frame" is called at the bottom of the stack
- main has 2 variables x and y, 1 and 2 taking up chunks of memory in main 

If main calls a function like swap we get another frame (a slice). Once swap is done executing (explicitly returns or finished running) this memory is freed up. 
- Technically still there abd garbage values remain 

*when we call swap, it will consider the 2 variables in main and give us three variables: a, b and temp

now:
int tmp = a; //temp takes a copy of a
a = b; //a takes on a copy of b
b = temp; //b gets a copy of temp. temp is empty and has the garbage value 1

WHEN SWAP RETURNS x and y are untouched

//fixing swap
int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}
void swap(int *a, int *b) //a and b are addresses of integers
{
    int tmp = *a; //tmp will store the value of at *a (1)
    *a = *b; //following treatsure map to other mailbox and then setting it to the whatever is at the value of b. value at *b = 1
    *b = tmp; //go to b and change it to the temporary variable which is the same as a, so that's where the final value gets swapped. Start at b and go to b (value is 1) and store that value in temp
}
***just like you can declare variables as storing addresses, you can declare arguments to functions AKA parameters as taking addresses
- circumventing local scope of variables

//FIXED SWAP FINAL 

#include <stdio.h>
void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a; //tmp = temporary
    *a = *b;
    *b = tmp;
}

Output:
$ make swap
$ ./swap
x is 1, y is 2
x is 2, y is 1

//Memory limitations and potential issues in C
- heap overflow = touching memory in the heap you shouldnt touch (from the stack I think)
- stack overflow = touching memory in the stack you shouldn't touch

Buffer overflow =  a chunk of memory that the computer is using for some purpose

//Final revelation

cs50 library: 
get_char
get_double
get_float
get_int
get_long 
get_string


//manipulating files

//Save names and numbers to a CSV file (like a simple spreadhsset)

#include <cs50.h>
#include <stdio.h>
#include <string.h>

phonebook.c
int main(void)
{
    FILE *file = fopen("phonebook.csv", "a"); //need to use addresses/pointers to manipulate files
    //fopen opens a file and returns a pointer in said file in memory
    //file name is phonebook.csv and this example is in append mode which will allow more names and numbers to be added to this file
    string name = get_string("Name: ");
    string number = get_string("Number: ");

    fprintf(file, "%s, %s,\n", name, number);
    //fprintf requires you to say what file you want to write

    fclose(file);
}

phonebook.csv
name, number

Terminal:
$ make phonebook
$ ./phonebook
Name: David 
Number: 1+555+555+5555


phonebook.csv
name, number
David , 1+555+555+5555,

//if you downloaded his to your mac you could double click the csv file and excel or apple numbers would open up!

bmp file formate are maps of bits

09:10:19  Understanding Hexadecimal Representation
09:19:54  Getting the Address of a Variable
09:44:01  Introduction to Data Types and Strings in C
10:03:55  Harnessing Pointer Arithmetic with Strings
10:17:37  Exploring string manipulation
10:19:27  Copying strings and memory allocation
10:47:25  Handling Garbage Values
11:09:12  Swapping values using pointers in C,
11:13:00  Memory limitations and potential issues in C,

