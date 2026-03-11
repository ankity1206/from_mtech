# Getting Started:

## Step 1: Create the C file on Ubuntu
Create/open a file in the <kbd>user/</kbd> directory of xv6:
```bash
vim hello_world.c
```

## Step 2: Paste this code 
```c
#include "kernel/types.h"
#include "user/user.h"

int main() {
  printf("Hello, welcome to world of xv6\n");
  exit(0);
}
```
## Step 3: "Register" it in the Makefile
```bash
cd ~/xv6
vim Makefile
```
Add your file name in UPROGS (don't write the extension of the file)
```makefile
UPROGS=\
    $U/_cat\
    $U/_echo\
    $U/_hello_world\    <-- Add this (make sure the backslash \ is at the end)
    ...

```

## Step 4: Bake and Run
```bash
make qemu
```

## Step 5: Test
Once xv6 boots and the $ appears:

Type ls to confirm hello_world is there.

Type hello_world to run it.
