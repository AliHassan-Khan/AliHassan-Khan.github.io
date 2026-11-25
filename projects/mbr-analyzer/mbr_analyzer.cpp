// MBR Boot Sector Analyzer
// Based on Lab 04 (Disks, Partitions & Boot): reading an MBR in a hex editor.
// Reads the first 512 bytes of a disk image and reports the boot signature
// and the four partition-table entries.
//
// Build:  g++ -std=c++17 -Wall -o mbr_analyzer mbr_analyzer.cpp
// Usage:  ./mbr_analyzer <disk_image>
//         ./mbr_analyzer --make-demo demo.img   (creates a 16 MB practice image)

#include <array>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using Sector = std::array<uint8_t, 512>;

const int PART_TABLE_OFFSET = 446;  // 0x1BE
const int ENTRY_SIZE = 16;
const int SIGNATURE_OFFSET = 510;   // 0x1FE

std::string partitionType(uint8_t t) {
    switch (t) {
        case 0x00: return "Empty (unused)";
        case 0x05: return "Extended (CHS)";
        case 0x07: return "NTFS / exFAT";
        case 0x0B: return "FAT32 (CHS)";
        case 0x0C: return "FAT32 (LBA)";
        case 0x0F: return "Extended (LBA)";
        case 0x82: return "Linux swap";
        case 0x83: return "Linux filesystem";
        case 0xEE: return "GPT protective MBR";
        case 0xEF: return "EFI System Partition";
        default:   return "Other / unknown";
    }
}

// MBR stores multi-byte numbers in little-endian order.
uint32_t readLE32(const Sector& s, int pos) {
    return static_cast<uint32_t>(s[pos]) |
           (static_cast<uint32_t>(s[pos + 1]) << 8) |
           (static_cast<uint32_t>(s[pos + 2]) << 16) |
           (static_cast<uint32_t>(s[pos + 3]) << 24);
}

bool makeDemo(const std::string& path) {
    std::ofstream out(path, std::ios::binary);
    if (!out) return false;
    std::string zeros(16 * 1024 * 1024, '\0');  // 16 MB = 32768 sectors
    out.write(zeros.data(), zeros.size());
    out.seekp(PART_TABLE_OFFSET);
    uint8_t entry[16] = {0x80, 0, 0, 0, 0x83, 0, 0, 0,
                         0x00, 0x08, 0x00, 0x00,   // start LBA 2048
                         0x00, 0x78, 0x00, 0x00};  // 30720 sectors
    out.write(reinterpret_cast<char*>(entry), 16);
    out.seekp(SIGNATURE_OFFSET);
    uint8_t sig[2] = {0x55, 0xAA};
    out.write(reinterpret_cast<char*>(sig), 2);
    return true;
}

int main(int argc, char* argv[]) {
    if (argc == 3 && std::string(argv[1]) == "--make-demo") {
        if (!makeDemo(argv[2])) { std::cerr << "Could not create file.\n"; return 1; }
        std::cout << "Demo image written to " << argv[2] << "\n";
        return 0;
    }
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <disk_image>\n"
                  << "       " << argv[0] << " --make-demo <file>\n";
        return 1;
    }

    std::ifstream in(argv[1], std::ios::binary);
    if (!in) { std::cerr << "Cannot open " << argv[1] << "\n"; return 1; }

    Sector s{};
    in.read(reinterpret_cast<char*>(s.data()), s.size());
    if (in.gcount() != 512) { std::cerr << "File is smaller than 512 bytes.\n"; return 1; }

    std::cout << "=== MBR Analysis: " << argv[1] << " ===\n";
    bool valid = (s[SIGNATURE_OFFSET] == 0x55 && s[SIGNATURE_OFFSET + 1] == 0xAA);
    std::cout << std::hex << std::uppercase << std::setfill('0');
    std::cout << "Boot signature (offset 510): "
              << std::setw(2) << int(s[SIGNATURE_OFFSET]) << " "
              << std::setw(2) << int(s[SIGNATURE_OFFSET + 1])
              << (valid ? "  -> valid (55 AA)\n" : "  -> INVALID, not a bootable MBR\n");
    std::cout << std::dec << std::setfill(' ');
    if (!valid) return 2;

    bool gpt = false;
    for (int i = 0; i < 4; ++i) {
        int base = PART_TABLE_OFFSET + i * ENTRY_SIZE;
        uint8_t status = s[base];
        uint8_t type = s[base + 4];
        uint32_t lba = readLE32(s, base + 8);
        uint32_t sectors = readLE32(s, base + 12);
        if (type == 0xEE) gpt = true;

        std::cout << "\nPartition " << (i + 1) << " (type byte at offset " << base + 4 << ")\n";
        if (type == 0x00) { std::cout << "  Unused\n"; continue; }
        std::cout << "  Bootable : " << (status == 0x80 ? "yes (active)" : "no") << "\n"
                  << "  Type     : 0x" << std::hex << std::uppercase << std::setw(2)
                  << std::setfill('0') << int(type) << std::dec << std::setfill(' ')
                  << " (" << partitionType(type) << ")\n"
                  << "  Start LBA: " << lba << "\n"
                  << "  Sectors  : " << sectors << "\n"
                  << "  Size     : " << std::fixed << std::setprecision(2)
                  << (sectors * 512.0 / (1024 * 1024)) << " MB\n";
    }
    std::cout << "\nPartition scheme: "
              << (gpt ? "GPT (protective MBR found)" : "MBR (msdos)") << "\n";
    return 0;
}
