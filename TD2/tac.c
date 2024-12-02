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
    int nb_byte;

    do
    {
        lseek(src_fd,-1,SEEK_CUR);
        nb_byte++;
    } while (ret = '\n');
    
    for (int i = 0; i < nb_byte; i++){
        
    }
    

    return EXIT_SUCCESS;
}