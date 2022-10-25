## Investigate Memory Actions

Memory actions generally mean:

* memory access: read, write or execute
* memory allocation
* memory deallocation

By far, the most important actions are allocation and deallocation.
Because, if not done right, these can get to memory loss and poor memory use.

Memory loss generally happens in the form of memory leaks.

### Memory Leaks

A memory leak occurs when we lose reference to a memory area.
That is, a pointer used to point to a memory area.
And then it's pointing to a new memory area and the old memory area is lost.

Enter the `support/memory-leak/` folder.
It stores two files showing memory leaks:

* one in C++: `memory_leak.cpp`
* one in C: `memory_leak_malloc.`

Let's build and run the two executables:

```
student@os:~/.../lab/support/memory-leak$ make
g++    -c -o memory_leak.o memory_leak.cpp
cc   memory_leak.o  -lstdc++ -o memory_leak
cc    -c -o memory_leak_malloc.o memory_leak_malloc.c
cc   memory_leak_malloc.o  -lstdc++ -o memory_leak_malloc
```

Running them yields similar output:

```
student@os:~/.../lab/support/memory-leak$ ./memory_leak
Andrei Popescu is 22 years old and likes Linux
Ioana David is 23 years old and likes macOS
student@os:~/.../lab/support/memory-leak$ ./memory_leak_malloc
Andrei Popescu is 22 years old and likes Linux
Ioana David is 23 years old and likes macOS
```

We investigate the memory leaks of the two programs by using [Valgrind](https://valgrind.org/):

```
student@os:~/.../lab/support/memory-leak$ valgrind ./memory_leak
==22362== Memcheck, a memory error detector
==22362== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==22362== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==22362== Command: ./memory_leak
==22362==
Andrei Popescu is 22 years old and likes Linux
Ioana David is 23 years old and likes macOS
==22362==
==22362== HEAP SUMMARY:
==22362==     in use at exit: 72 bytes in 1 blocks
==22362==   total heap usage: 4 allocs, 3 frees, 73,872 bytes allocated
==22362==
==22362== LEAK SUMMARY:
==22362==    definitely lost: 72 bytes in 1 blocks
==22362==    indirectly lost: 0 bytes in 0 blocks
==22362==      possibly lost: 0 bytes in 0 blocks
==22362==    still reachable: 0 bytes in 0 blocks
==22362==         suppressed: 0 bytes in 0 blocks
==22362== Rerun with --leak-check=full to see details of leaked memory
==22362==
==22362== For counts of detected and suppressed errors, rerun with: -v
==22362== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

student@os:~/.../lab/support/memory-leak$ valgrind ./memory_leak_malloc
==22369== Memcheck, a memory error detector
==22369== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==22369== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==22369== Command: ./memory_leak_malloc
==22369==
Andrei Popescu is 22 years old and likes Linux
Ioana David is 23 years old and likes macOS
==22369==
==22369== HEAP SUMMARY:
==22369==     in use at exit: 148 bytes in 1 blocks
==22369==   total heap usage: 3 allocs, 2 frees, 1,320 bytes allocated
==22369==
==22369== LEAK SUMMARY:
==22369==    definitely lost: 148 bytes in 1 blocks
==22369==    indirectly lost: 0 bytes in 0 blocks
==22369==      possibly lost: 0 bytes in 0 blocks
==22369==    still reachable: 0 bytes in 0 blocks
==22369==         suppressed: 0 bytes in 0 blocks
==22369== Rerun with --leak-check=full to see details of leaked memory
==22369==
==22369== For counts of detected and suppressed errors, rerun with: -v
==22369== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

As we are doing allocations that are not freed, this results in memory leaks.

For `malloc()`-based programs, we can use [`mtrace()` feature]() and [`mtrace` command]() to verify proper allocations with `malloc()` and deallocations with `free()`.
We call `mtrace()` in the program (in `memory_leak_malloc.c`) to enable `malloc()` and `free()` checking.

To use `mtrace()` we define the `MALLOC_TRACE` environment variable:

```
student@os:~/.../lab/support/memory-leak$ MALLOC_TRACE=mem.trace ./memory_leak_malloc
Andrei Popescu is 22 years old and likes Linux
Ioana David is 23 years old and likes macOS
```

Subsequently we use the `mtrace` tool to show information about the leaked data:

```
student@os:~/.../lab/support/memory-leak$ mtrace ./memory_leak_malloc mem.trace

Memory not freed:
-----------------
           Address     Size     Caller
0x000056506d8be6a0     0x94  at 0x56506c3777ec
```

The size (`0x94`) is the same value shown by Valgrind (`148`).

`mtrace` provides an outcome similar to Valgrind.
Valgrind is however more powerful: it works on different types of memory (not only those allocated with `malloc()`) and it doesn't require access to the source code (and the compiler phase).

#### Practice

1. Print the size of the `Student` class and the `struct student` structure to see if it equates to the leak shown by Valgrind.

2. Solve the memory leaks in both programs.
   Validate with Valgrind.

#### Quiz

TODO

### Memory Actions (and Leaks) in Existing Programs

We can use Valgrind to investigate existing programs in the system.
This tells us whether they possess memory leaks:

```
student@os:~/.../lab/support/memory-leak$ valgrind ls
==24669== Memcheck, a memory error detector
==24669== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==24669== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==24669== Command: ls
==24669==
Makefile  memory_leak  memory_leak.cpp  memory_leak_malloc  memory_leak_malloc.c  memory_leak_malloc.o  memory_leak.o
==24669==
==24669== HEAP SUMMARY:
==24669==     in use at exit: 21,696 bytes in 14 blocks
==24669==   total heap usage: 51 allocs, 37 frees, 61,331 bytes allocated
==24669==
==24669== LEAK SUMMARY:
==24669==    definitely lost: 0 bytes in 0 blocks
==24669==    indirectly lost: 0 bytes in 0 blocks
==24669==      possibly lost: 0 bytes in 0 blocks
==24669==    still reachable: 21,696 bytes in 14 blocks
==24669==         suppressed: 0 bytes in 0 blocks
==24669== Rerun with --leak-check=full to see details of leaked memory
==24669==
==24669== For counts of detected and suppressed errors, rerun with: -v
==24669== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

student@os:~/.../lab/support/memory-leak$ valgrind ps
==24671== Memcheck, a memory error detector
==24671== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==24671== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==24671== Command: ps
==24671==
  PID TTY          TIME CMD
24671 pts/22   00:00:00 memcheck-amd64-
26732 pts/22   00:00:01 bash
==24671==
==24671== HEAP SUMMARY:
==24671==     in use at exit: 264,929 bytes in 25 blocks
==24671==   total heap usage: 692 allocs, 667 frees, 334,268 bytes allocated
==24671==
==24671== LEAK SUMMARY:
==24671==    definitely lost: 0 bytes in 0 blocks
==24671==    indirectly lost: 0 bytes in 0 blocks
==24671==      possibly lost: 0 bytes in 0 blocks
==24671==    still reachable: 264,929 bytes in 25 blocks
==24671==         suppressed: 0 bytes in 0 blocks
==24671== Rerun with --leak-check=full to see details of leaked memory
==24671==
==24671== For counts of detected and suppressed errors, rerun with: -v
==24671== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

student@os:~/.../lab/support/memory-leak$ valgrind bash -c 'echo "ha"'
==24675== Memcheck, a memory error detector
==24675== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==24675== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==24675== Command: bash -c echo\ "ha"
==24675==
ha
==24675==
==24675== HEAP SUMMARY:
==24675==     in use at exit: 43,056 bytes in 672 blocks
==24675==   total heap usage: 774 allocs, 102 frees, 51,405 bytes allocated
==24675==
==24675== LEAK SUMMARY:
==24675==    definitely lost: 12 bytes in 1 blocks
==24675==    indirectly lost: 0 bytes in 0 blocks
==24675==      possibly lost: 0 bytes in 0 blocks
==24675==    still reachable: 43,044 bytes in 671 blocks
==24675==         suppressed: 0 bytes in 0 blocks
==24675== Rerun with --leak-check=full to see details of leaked memory
==24675==
==24675== For counts of detected and suppressed errors, rerun with: -v
==24675== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

We can see that `ls` and `ps` don't have memory leaks.
However, the shell (Bash) shows a memory leak of 12 bytes (on the test system).
This may be a false positive or the subject of an actual investigation.

Note that the `still reachable` section of the output refers to memory that wasn't freed but still has pointers referring it.
A true memory leak occurs when no pointers refer any memory area.

#### Practice

1. Investigate 2-3 other executables in the system using Valgrind.

1. Use `ltrace` to list `malloc()` and `free()` calls made by the investigated system executables.

#### Quiz

TODO

### jemalloc

TODO: use [jemalloc](http://jemalloc.net/) as allocator.

### malloc in Musl

TODO: See implementation of `malloc()` and `free()` in [Musl libc](https://elixir.bootlin.com/musl/v1.2.3/source/src/malloc).

### Deluge (Python)

Urmărit cod sursă pentru aplicații existente:
Putem folosi tot deluge pentru a vedea portiunile de alocat memorie (python)

### Servo (Rust)

Rust: https://github.com/servo/servo

### Alocator (D)

D: https://github.com/dlang/phobos/tree/master/std/experimental/allocator
In C: https://github.com/redis/redis , https://github.com/vim/vim , https://github.com/git/git
