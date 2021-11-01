#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <curl/curl.h>

int main(){
    char audio[51] = {0}, port[6] = {0};
    char command[501] = {0};
    printf("%s\n","Digite nome do arquivo a baixar: ");
    fgets(audio, sizeof(audio), stdin);
    audio[strlen(audio) - 1] = '\0';
    //------
    printf("%s\n","Digite o numero da porta para escutar: ");
    fgets(port, sizeof(port), stdin);
    port[strlen(port) - 1] = '\0';
    //-------
    strcpy(command, "./ffmpeg.exe -i http://localhost:");
    strcat(command, port);
    strcat(command, " -c copy ");
    strcat(command, audio);
    printf("[execute = %s]\n",command);
    system(command);
    strcpy(command, "./ffplay.exe ");
    strcat(command, audio);
    printf("[execute = %s]\n",command);
    system(command);
    //gcc client.c -o client
    return 0;
}