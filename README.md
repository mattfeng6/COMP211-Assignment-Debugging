# COMP211-Assignment-Error

## Goals of Assignment

The transition from high level programming languages to C can be difficult. Unfamiliarity with the language and methods of testing your code in a new environment can lead to serious problems as we begin to work on increasingly complicated lab assignments. By giving you an overview of error types, as well as debugging using gdb and Valgrind, this assignment seeks to connect you to resources that will help you be able to test your code, point out where things are going wrong, and identify syntactical errors–before you come to office hours!

## Discussion Questions

### Link to discussion form:
https://docs.google.com/forms/d/e/1FAIpQLSeHOpjHH3kXY7pgFwDAsW4qPdll6VX7yutfrKWfKzRqcJp5wQ/viewform

* _What is your debugging process?_

* _How much time do you normally spend on debugging compared to writing code?_

* _What are some types of errors that you've seen in your labs?_

* _What are some sources you use for debugging? The internet (e.g. stackoverflow)? Slides from class or other lab resources? Office hours?_

* _Have you ever heard of or used gdb, Valgrind, assert?_



## Types of Errors

Error is an illegal operation performed by the user which results in abnormal working of the program. If an error occurs in a program, the code would fail to compile, stop working during execution, or generate garbage values or incorrect output.

There are mainly five common types of errors, which are **_Syntax Error, Run Time Error, Logical Error, Semantic Error, and Linker Error_**.



### Syntax Error

Syntax Error is the type of error that usually happens when a programmer does not follow the syntax rule of the programming language. This type of error would make the program fail to compile and hence is also known as the compilation error.

**Examples:**
* _Missing semicolon(;)_
* _Missing parenthesis({})_
* _Assigning value to a variable without declaring it_



### Runtime Error

Runtime Error is the type of error that occurs during program execution(run-time). It only occurs after the program has been compiled successfully. Hence, for the runtime error, the compiler could not help target where the error is.

**Examples:**
* _Division error (division by zero)_
* _Undefined Variables_



### Logical Error

Logical Error is the type of error that fails to gain the correct output after the program execution. It usually occurs when programmers write the code with mistakes in it.

**Examples:**
* _No output_



### Semantic Error

Semantic Error is the type of error that the compiler is unable to understand. This usually is due to the not meaningful statement in the program.

**Examples:**
```
int main(){
  int a, b, c;
  a + b = c;
}
```


### Linker Error

Linker Error is the type of error that occurs when after compilation we link the different object files with the main object file. This may be due to the incorrect header file. Further details will be discussed later this semester.

**Examples:**
* _Writing Main() instead of main()_



## Introduction to GDB and Valgrind

C allows programmers to directly manage memory in a way many other high level programming languages do automatically. This is a powerful tool, but one that must be used carefully. Segmentation faults occur when your program attempts to access a restricted area of memory and typically have to do with your pointers incorrectly referencing, allocating, or freeing memory. Instead of manually tracing through code to try to find the error, gdb and Valgrind can help speed up a tricky debugging process. These methods can also extend to general issues you might need help debugging in C!


### GDB
1. Open and familiarize yourself with crash.c.

2. Compile crash.c using **_gcc -g crash.c -o crash_**.

    a. The -g option which tells the compiler to embed debugging information for the debugger to use.
    
    b. The -o ExecutableName option names your executable file ExecutableName instead of a.out.
    
3. Run crash with **_./crash_** and see what happens. A segmentation fault should occur.

4. Let’s start gdb with **_gdb crash_** to figure out where the segmentation fault is occurring.

5. Now that we have successfully loaded gdb with crash, try using **_run_** to see what type of information we get.

6. Use the backtrace command to list all the function calls that lead to the crash in the stack frame. Take a look at the messages. As we can see, main() at crash.c:16 calls concatenate(str=0xsomeaddress "hello ") at crash.c:9 which calls some lower level functions that lead to our crash. We can’t control anything past concatenate(str=0xsomeaddress "hello "), so let’s take a closer look at line 9.

7. To set a breakpoint at line 9, do **_break crash.c:9_**.

8. Rerun the program after having set the breakpoint. Make sure to say yes when it asks to start at the beginning. Notice that crash.c only executes up to line 9.

9. To retrieve all the variables we’re interested in, we can use the print command.
    
    a. **_print str_** tells us the variable str is “hello “, as we’ve defined, which seems correct.
    
    b. **_print p_** tells us p is a null pointer. We’re trying to concatenate a string to a pointer which hasn’t been allocated, which resulted in a segmentation fault. Note that because p is a global variable, it was automatically initialized to 0 (null pointer). If it were not, it would have contained an arbitrary value and it would have no longer been obvious that it pointed to an invalid address in memory.

10. Press **_q_** to exit gdb. See if you can make the program execute correctly! _(Hint: You’ll have to allocate memory for the pointer p using malloc. Don’t forget to free this memory when you’re done with it!)_


### Take a look at these linked resources if you’re interested in more gdb commands.

* https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Debugging.html
* http://www.cs.toronto.edu/~krueger/csc209h/tut/gdb_tutorial.html
* https://u.osu.edu/cstutorials/2018/09/28/how-to-debug-c-program-using-gdb-in-6-simple-steps/


### Note

You might get this warning: “warning: Error disabling address space randomization: Operation not permitted” when running gdb. To enable permissions, add the following code to **_docker_compose.yml_**, which you can find in the learncli211 folder.

security_opt: - seccomp:unconfined

cap_add: - SYS_PTRACE

The file should look something like this.

```
version: '3.2'
services:
  	bash:
   		image: learncli/bash
    		working_dir: /mnt/learncli/workdir
   		volumes:
      			- type: bind
        			source: "${WORKDIR:-./}"
        			target: /mnt/learncli
  	comp211:
   		image: learncli/comp211:latest
    		working_dir: /mnt/learncli/workdir
    		volumes:
      			- type: bind
        			source: "${WORKDIR:-./}"
        			target: /mnt/learncli
    		security_opt:
     			 - seccomp:unconfined
    		cap_add:
      			- SYS_PTRACE
```

## Code

Using your new knowledge of error types and debugging methods, try to get this program to execute correctly!

### Practice Code

```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *p;

void concatenate(char* str) {
  // concatenate contents of str to contents of p
  strcat(p, str);
}

int main() {
  char a[6] = "hello ";
  char b[10] = "world...\n";
  concatenate(a);
  concatenate(b);
  printf("%s", p);
  return 0;
}
```

## References
* https://www.geeksforgeeks.org/errors-in-cc/
* https://www.scaler.com/topics/c/types-of-errors-in-c/


## COPYRIGHT
_This assignment project is made from_

**Zhennan Feng, Taixi Lu, and Ruth Wu**

_Under the supervision of_

**Professor Brent Munsell** and **Professor Tessa Joseph-Nicholas**.
