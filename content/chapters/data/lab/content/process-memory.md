## Process Memory

### Memory Regions

To better manage a program's memory, the operating systems creates an address space for each process.
The address space is compartmentalized in multiple areas, each with its own role.
Memory addresses use different permissions to decide what actions are allowed.

Let's investigate the memory areas of a given process.
Run the command:

```
pmap -p $$
```

see total size

to show the memory areas of the current shell process.

Demo: hello world + sleep to view the memory regions

#### Practice

Use another program (in another language) that does hello world + sleep

#### Quiz

TODO

### Memory Layout of Statically-Linked and Dynamically-Linked Executables

#### Practice

TODO

#### Quiz

TODO

### Memory Layout of Multi-threaded Programs

#### Practice

TODO

#### Quiz

TODO

### Modifying Memory Region Size

C program, with modifying different memory regions

Python3 program that modifies memory region.

Use strace

#### Practice

TODO

#### Quiz

TODO

### Allocating and Deallocating Memory

alocare explicită sau implicită

#### Practice

TODO

#### Quiz

TODO

### Memory Mapping

(??) Un program scris in C care citeste un fisier mic, mediu si mare cu 2 implementari: una cu read, cealalta cu mmap. De masurat performanta celor 2 implementari in cele 3 cazuri si de gasit explicatiile (folosire strace). => mai bine la calcul? (numarul de context switch-uri e mai mic la mmap)

#### Quiz

TODO

#### Practice

TODO
