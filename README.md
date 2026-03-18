# How to download it?
```
git clone https://github.com/Trenek/JTUDZK_Template --recursive
```
Alternatively
```
git clone https://github.com/Trenek/JTUDZK_Template
cd JTUDZK_Template
git submodule update --init --recursive
```
# How to compile it?
Linux
```
cmake -B build
cmake --build build --target all -j16
```
Windows (MinGW)
```
cmake -B build -G "MinGW Makefiles"
cmake --build build --target all -j16
```

