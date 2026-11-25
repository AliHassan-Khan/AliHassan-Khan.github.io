# Disk Layout Planner (C++)

Built from **Lab 03 – Windows Installation & WSL Configuration** (Applications of ICT, CS-117).
The lab's UEFI/GPT install created an EFI System Partition (300 MB, FAT32), a 16 MB MSR and the C: drive.
This program plans that layout for any disk size and shows the MBR limits (about 2 TB, 4 primary partitions).

```
g++ -std=c++17 -Wall -o disk_planner disk_planner.cpp
./disk_planner
```
