# MBR Boot Sector Analyzer (C++)

Built from **Lab 04 – Disks, Partitions & Boot** (Applications of ICT, CS-117).
In the lab I read an MBR by hand in GHex; this program does the same job automatically.

It reads the first 512 bytes of a disk image, checks the `55 AA` boot signature at offset 510,
and decodes the four partition entries (bootable flag, type byte, start LBA, size).

```
g++ -std=c++17 -Wall -o mbr_analyzer mbr_analyzer.cpp
./mbr_analyzer --make-demo demo.img   # makes a 16 MB practice image
./mbr_analyzer demo.img
```
