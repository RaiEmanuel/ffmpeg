#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <pthread.h>
#include <dirent.h> 




int main(){

DIR *d;
  struct dirent *dir;
  d = opendir("./audios");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }

    char audio[51] = {0}, port[6] = {0};
    char command[501] = {0};
    printf("%s\n","Digite nome do arquivo a servir: ");
        fgets(audio, sizeof(audio), stdin);
        audio[strlen(audio) - 1] = '\0';
        printf("%s\n","Digite o numero da porta para escutar: ");
        fgets(port, sizeof(port), stdin);
        port[strlen(port) - 1] = '\0';
    while(1){
        printf("+----------------- SERVIDOR ----------------+\n");
        printf("+----------------- PORT = %s ----------------+\n",port);
        Sleep(1500);
        strcpy(command, "./ffmpeg.exe -i audios/");
        strcat(command, audio);
        strcat(command, " -c copy -listen 1 -f ogg http://localhost:");
        strcat(command, port);
        printf("[execute = %s]\n", command);
        system(command);
        //system("quit");//quit
    }
    //gcc server.c -o server

    return 0;
}