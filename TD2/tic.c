#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 512

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <fichier_source>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        fprintf(stderr,"Erreur d'ouverture du fichier source");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int readed_byte;

    lseek(src_fd,-1,SEEK_END);
    int ret;
    do{
        ret = read(src_fd,buffer,1);
        write(STDOUT_FILENO,buffer,1);
    } while (lseek(src_fd,-2,SEEK_CUR));

    return EXIT_SUCCESS;
}
