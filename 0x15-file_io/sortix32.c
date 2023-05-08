#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUF_SIZE 64

int main(int argc, char **argv)
{
    Elf32_Ehdr header;

    header.e_ident[EI_MAG0] = ELFMAG0;
    header.e_ident[EI_MAG1] = ELFMAG1;
    header.e_ident[EI_MAG2] = ELFMAG2;
    header.e_ident[EI_MAG3] = ELFMAG3;
    header.e_ident[EI_CLASS] = ELFCLASS32;
    header.e_ident[EI_DATA] = ELFDATA2LSB;
    header.e_ident[EI_VERSION] = EV_CURRENT;
    header.e_ident[EI_OSABI] = ELFOSABI_SYSV;
    header.e_ident[EI_ABIVERSION] = 0;

    header.e_type = ET_EXEC;
    header.e_machine = EM_386;
    header.e_version = EV_CURRENT;
    header.e_entry = 0x08048000;
    header.e_phoff = sizeof(header);
    header.e_shoff = 0;
    header.e_flags = 0;
    header.e_ehsize = sizeof(header);
    header.e_phentsize = sizeof(Elf32_Phdr);
    header.e_phnum = 1;
    header.e_shentsize = 0;
    header.e_shnum = 0;
    header.e_shstrndx = SHN_UNDEF;

    int fd = open("sortix32", O_CREAT|O_WRONLY|O_TRUNC, 0644);
    if (fd == -1) {
        fprintf(stderr, "Error: cannot create file 'sortix32'\n");
        exit(98);
    }

    if (write(fd, &header, sizeof(header)) != sizeof(header)) {
        fprintf(stderr, "Error: cannot write ELF header to file 'sortix32'\n");
        exit(98);
    }

    close(fd);

    return 0;
}

