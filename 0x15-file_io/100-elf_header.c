#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ELF_HEADER_SIZE 64

typedef struct {
    unsigned char magic[4];
    unsigned char class;
    unsigned char data;
    unsigned char version;
    unsigned char os_abi;
    unsigned char abi_version;
    unsigned char padding[7];
    uint16_t type;
    uint16_t machine;
    uint32_t version2;
    uint32_t entry_hi;
    uint32_t entry_lo;
    uint32_t phoff_hi;
    uint32_t phoff_lo;
    uint32_t shoff_hi;
    uint32_t shoff_lo;
    uint32_t flags;
    uint16_t ehsize;
    uint16_t phentsize;
    uint16_t phnum;
    uint16_t shentsize;
    uint16_t shnum;
    uint16_t shstrndx;
} __attribute__((packed)) ElfHeader;

void print_error(const char *message)
{
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(98);
}

void print_elf_header(const ElfHeader *header)
{
    int i;

    printf("  Magic:   ");
    for (i = 0; i < 4; i++)
        printf("%02x ", header->magic[i]);
    printf("\n");

    printf("  Class:                             %s\n",
           header->class == 1 ? "ELF32" : (header->class == 2 ? "ELF64" : "Invalid"));

    printf("  Data:                              %s\n",
           header->data == 1 ? "2's complement, little endian" :
           (header->data == 2 ? "2's complement, big endian" : "Invalid"));

    printf("  Version:                           %d (current)\n", header->version);

    printf("  OS/ABI:                            ");
    switch (header->os_abi) {
        case 0: printf("UNIX - System V"); break;
        case 1: printf("UNIX - HP-UX"); break;
        case 2: printf("UNIX - NetBSD"); break;
        case 3: printf("UNIX - GNU"); break;
        case 6: printf("UNIX - Solaris"); break;
        case 7: printf("UNIX - AIX"); break;
        case 8: printf("UNIX - IRIX"); break;
        case 9: printf("UNIX - FreeBSD"); break;
        case 10: printf("UNIX - Tru64"); break;
        case 11: printf("Novell - Modesto"); break;
        case 12: printf("UNIX - OpenBSD"); break;
        case 13: printf("VMS - OpenVMS"); break;
        case 14: printf("HP - Non-Stop Kernel"); break;
        case 15: printf("AROS"); break;
        case 16: printf("FenixOS"); break;
        case 17: printf("Nuxi CloudABI"); break;
        default: printf("Unknown");
    }
    printf("\n");

    printf("  ABI Version:                       %d\n", header->abi_version);

    printf("  Type:                              0x%x\n", header->type);

    printf("  Entry point address:               0x%08x%08x\n",
           header->entry_hi, header->entry_lo);
}

void read_elf_header(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_error("open");
    }

    ElfHeader header;
    ssize_t bytes_read = read(fd, &header, ELF_HEADER_SIZE);
    if (bytes_read == -1) {
        close(fd);
        print_error("read");
    } else if (bytes_read != ELF_HEADER_SIZE) {
        close(fd);
        fprintf(stderr, "Failed to read ELF header\n");
        exit(98);
    }

    close(fd);

    print_elf_header(&header);
}

int main(int argc, char *argv[])
{
    struct stat st;
    int fd;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    if (stat(argv[1], &st) == -1) {
        print_error("stat");
    }

    if (!S_ISREG(st.st_mode)) {
        fprintf(stderr, "%s is not a regular file\n", argv[1]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("open");
    }

    read_elf_header(argv[1]);

    close(fd);

    return 0;
}

