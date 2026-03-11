# xv6 RISC-V Installation & Removal Guide

To set up the **xv6** teaching operating system on **Ubuntu (WSL2)** using an Intel processor.

---

## 🛠 Part 1: Installation

### 1. Update Ubuntu
Ensure your package list is current:
```bash
sudo apt-get update && sudo apt-get upgrade -y
```

### 2. Install the RISC-V Toolchain & Emulator
```bash
sudo apt install -y git build-essential gdb-multiarch qemu-system-misc \
  gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu
```

### 3. Clone the xv6 Source Code
```bash
cd ~
git clone --depth 1 https://github.com/mit-pdos/xv6-riscv.git
cd xv6-riscv
```

### 4. Compile and Launch
```bash
make CPUS=1 qemu
```

> Success looks like: A prompt that says init: starting sh followed by a $.
> Test it: Type ls to see files or echo hello xv6.

#### 5. How to Exit
Since you are in "no-window" mode (nox), you cannot just close the window.
<p>
Exit QEMU: <kbd>Ctrl</kbd> + <kbd>A</kbd>, then <kbd>X</kbd>
</p>

### 6. To enter xv6:
```bash
cd ~/xv6
make qemu
```
## 🗑 Part 2: Complete Removal

### 1. Delete the xv6 Source Code
```bash
rm -rf ~/xv6-riscv
```

### 2. Uninstall Development Tools
```bash
sudo apt purge -y qemu-system-misc gcc-riscv64-linux-gnu \
  binutils-riscv64-linux-gnu gdb-multiarch
```

### 3. Cleanup Dependencies
```bash
sudo apt-get autoremove -y
```
