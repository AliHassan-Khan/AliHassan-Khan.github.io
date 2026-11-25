// Disk Layout Planner
// Based on Lab 03 (Windows installation): a UEFI/GPT install creates an
// EFI System Partition, an MSR and the C: drive. This program plans that
// layout for a given disk size and shows why MBR is limited.
//
// Build:  g++ -std=c++17 -Wall -o disk_planner disk_planner.cpp
// Usage:  ./disk_planner

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Partition {
    std::string name;
    std::string fs;
    double sizeMB;
};

int main() {
    const double MB_PER_GB = 1024.0;
    const double MBR_LIMIT_GB = 2048.0;  // about 2 TiB with 512-byte sectors
    const double ESP_MB = 300.0;         // values used in the lab
    const double MSR_MB = 16.0;

    double diskGB;
    int choice;
    std::cout << "=== Disk Layout Planner ===\n";
    std::cout << "Disk size in GB: ";
    if (!(std::cin >> diskGB) || diskGB < 1) {
        std::cout << "Please enter a valid size (1 GB or more).\n";
        return 1;
    }
    std::cout << "Partition style (1 = GPT/UEFI, 2 = MBR/BIOS): ";
    if (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cout << "Please choose 1 or 2.\n";
        return 1;
    }

    double usableMB = diskGB * MB_PER_GB;
    std::vector<Partition> layout;

    if (choice == 1) {
        layout.push_back({"EFI System Partition", "FAT32", ESP_MB});
        layout.push_back({"Microsoft Reserved", "none", MSR_MB});
        layout.push_back({"C: (Windows)", "NTFS", usableMB - ESP_MB - MSR_MB});
    } else {
        if (diskGB > MBR_LIMIT_GB) {
            std::cout << "\nWarning: MBR cannot address more than ~2 TB.\n"
                      << "Only the first 2048 GB will be usable.\n";
            usableMB = MBR_LIMIT_GB * MB_PER_GB;
        }
        layout.push_back({"C: (Windows)", "NTFS", usableMB});
    }

    std::cout << "\n" << std::left << std::setw(24) << "Partition"
              << std::setw(8) << "FS" << std::right << std::setw(14) << "Size (MB)" << "\n";
    std::cout << std::string(46, '-') << "\n";
    for (const auto& p : layout) {
        std::cout << std::left << std::setw(24) << p.name << std::setw(8) << p.fs
                  << std::right << std::setw(14) << std::fixed << std::setprecision(0)
                  << p.sizeMB << "\n";
    }

    std::cout << "\nMax primary partitions: " << (choice == 1 ? "128 (Windows)" : "4") << "\n";
    std::cout << "Firmware mode         : " << (choice == 1 ? "UEFI" : "Legacy BIOS") << "\n";
    return 0;
}
