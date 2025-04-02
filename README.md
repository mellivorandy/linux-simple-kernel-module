# linux-simple-kernel-module

This is a minimal Linux kernel module adapted from an example in the textbook  
> *Operating System Concepts* by Abraham Silberschatz, Greg Gagne, and Peter Baer Galvin.

The module demonstrates how to load and unload a basic kernel module using `module_init`, `module_exit`, and `printk`.

Note: This project is intended for educational and learning purposes.

---

## Prerequisites

To build and run this kernel module, you need:

- A Linux system with kernel headers installed (e.g., `linux-headers-$(uname -r)`)

- `make` and `gcc`

- Root (sudo) access to load/unload kernel modules

Install example (on Ubuntu/Debian):
```bash
sudo apt update
sudo apt install build-essential linux-headers-$(uname -r)
```

---

## How to Use

1. Clone or copy the files into a folder.

2. Open a terminal and `cd` into the project root directory.

3. Make sure to give `run.sh` execute permission:
    ```bash
    chmod +x run.sh
    ```

4. Run `./run.sh` to build and test the module:
    ```bash
    ./run.sh
    ```

5. View `dmesg` output to confirm the module loaded and unloaded properly.

---

### Credits & Licensing

This example is adapted from the textbook *Operating System Concepts* for educational purposes under fair use.

Modifications were made by Andy Yo for learning and demonstration purposes.

This repository uses dual licensing:

- `simple.c` is licensed under the **GNU General Public License v2 (GPL-2.0)**, as required by the Linux kernel.

- All other files (e.g., Makefile, script, documentation) are licensed under the **MIT License**.

- See [LICENSE](./LICENSE) for details.
