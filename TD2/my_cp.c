#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <fichier_source> [fichier_destination]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
/*
    struct stat st;
    if (stat(argv[1], &st) != 0 || !S_ISREG(st.st_mode)) {
        fprintf(stderr, "Erreur : %s n'est pas un fichier ordinaire\n", argv[1]);
        exit(EXIT_FAILURE);
    }
*/

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        fprintf(stderr,"Erreur d'ouverture du fichier source");
        exit(EXIT_FAILURE);
    }

    int dest_fd;
    if (argc == 3) {
        if (access(argv[2], F_OK) != -1) {
            fprintf(stderr, "Erreur : %s existe déjà\n", argv[2]);
            exit(1);
        }
        dest_fd = open(argv[2], O_RDWR);
        if (dest_fd < 0) {
            fprintf(stderr,"Erreur de création du fichier destination");
            exit(1);
        }
    } else {
        dest_fd = STDOUT_FILENO;
    }

    char buffer[BUFFER_SIZE];
    int readed_byte;

    while (readed_byte = read(src_fd,buffer,BUFFER_SIZE) > 0){
        if (write(dest_fd,buffer,BUFFER_SIZE) == -1)
        {
            fprintf(stderr,"Erreur lors de l'ecriture");
        } 
    }

    close(src_fd);
    if (argc == 3) {
        close(dest_fd);
    }

    return 0;
}

