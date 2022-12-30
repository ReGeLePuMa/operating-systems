# Data

Data represents information that is to be processed to produce a final result or more data.
Computers store, retrieve and compute data. This process involves 4 entities: the programmer, the programming language, the operating system and the hardware.

From a programmer's perspective, data is represented by the variables.
These are declared and utilized depending on the rules of the programming language that is employed.
The programming language analyzes the use of these variables and outputs code that uses an interface provided by the operating system.
This interface offers the possibility to allocate/deallocate different variables in certain memory regions.
Next, the operating system manages the execution of the program and provides the actual physical addresses that are used to interact with the data.

Moreover, the operating system governs the competing access of multiple programs to memory ensuring that a program does not have access to a different programs memory.

## Setup

If you have already cloned the repository, make sure it is updated.
Run this command inside the repository clone directory:

```
git pull --rebase
```

The command may fail if you have uncommitted changes.
If that is the case, commit changes and retry.

If you haven't already cloned the repository, do it and enter the repository:

```
git clone https://github.com/open-education-hub/operating-systems
cd operating-sytems
```

While inside the repository clone top directory, run the `update-repo.sh` script:

```
bash util/update-repo.sh data
```

The script may fail if you have uncommitted changes and it will instruct you to commit them.
If that is the case, commit changes and re-run the script.

Navigate to the chapter lab directory:

```
cd content/chapters/data/lab/
```

Now go through the items below.

## Contents

1. [Working with Memory](content/working-memory.md)
1. [Process Memory](content/process-memory.md)
1. [Investigate Memory](content/investigate-memory.md)
1. [Memory Support](content/memory-support.md)
1. [Memory Security](content/memory-security.md)
