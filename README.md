# Introdction
miniv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6). It is implemented for a modern RISC-V multiprocessor using ANSI C.


# Building and running

You will need a [RISC-V "newlib" tool chain](https://github.com/riscv/riscv-gnu-toolchain) 
and qemu compiled for riscv64-softmmu. 

Once they are installed, you can run:
```
git clone git@github.com:iyangsj/miniv6.git
cd miniv6
make qemu
```

# Testing
```
python3 ./test.py test
```


# Acknowledgments

See [xv6](https://github.com/mit-pdos/xv6-riscv/blob/riscv/README)
