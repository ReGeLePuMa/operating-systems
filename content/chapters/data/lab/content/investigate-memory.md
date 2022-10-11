## Investigate Memory Actions

### GDB

Investigat aplicații existente (din exterior):
Folosit Valgrind + gdb pentru aplicatiile de mai sus.

### Deluge (Python)

Urmărit cod sursă pentru aplicații existente:
Putem folosi tot deluge pentru a vedea portiunile de alocat memorie (python)

### Servo (Rust)

Rust: https://github.com/servo/servo 

### Alocator (D)

D: https://github.com/dlang/phobos/tree/master/std/experimental/allocator
In C: https://github.com/redis/redis , https://github.com/vim/vim , https://github.com/git/git 

## Implement Memory Support

Dezvoltat peste cod existent (deja scris de noi):

### Reference Counting

Implementat in C++\D o structura simpluta in care se face reference counting
Structura este scrisa in totalitate de noi, ei trebuie sa adauge constructor/destructor/ operator de asignare.

### Passing Arguments: Pointer vs. Value vs. Reference

Modificat cod sursă pentru aplicații existente:
Trimis parametri prin valoare/pointer (C++\D) => de masurat performanta
Putem folosi codul de la redis, vim, git etc.
