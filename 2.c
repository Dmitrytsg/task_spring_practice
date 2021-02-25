/*Функцию формирования одномерного массива структур до тех пор, пока
при вводе данных с клавиатуры не появится заданное значение для некоторого
поля структуры.*/
/*заданное значение: если для поля rating_song значение будет меньше или равно 4,ввод завершится*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#define OS linux
#define CLS system("clear")
#define MAX_STR_LEN 60

typedef struct T
{
    char* n_song;
    char* n_singr;
    char* genre;
    int year_of_rels;
    double rating_song;
    double rating_singr;
} music;

int main()
{
    music* songs = (music*)malloc(1*sizeof(music));
    int cont = 1;
    size_t i = 0;

    while(cont)
    {
        if(i!=0) songs = (music*)realloc(songs,(i+1)*sizeof(music));
        char s1[MAX_STR_LEN];
        int slen;
        songs[i].n_song = (char*)malloc(MAX_STR_LEN*sizeof(char));
        songs[i].n_singr = (char*)malloc(MAX_STR_LEN*sizeof(char));
        songs[i].genre = (char*)malloc(MAX_STR_LEN*sizeof(char));

        CLS;
        printf("Song number: %zu\n\n",i+1);
        
        /*input Song name*/
        printf("Song name: ");
        fgets(s1,MAX_STR_LEN,stdin);
        slen=strlen(s1);
        s1[slen-1]='\0';
        songs[i].n_song = (char*)realloc(songs[i].n_song, slen*sizeof(char));
        if(songs[i].n_song != NULL) strcpy(songs[i].n_song,s1);

        /*input singer name*/
        printf("Singer name: ");
        fgets(s1,MAX_STR_LEN,stdin);
        slen=strlen(s1);
        s1[slen-1]='\0';
        songs[i].n_singr = (char*)realloc(songs[i].n_singr, slen*sizeof(char));
        if(songs[i].n_singr != NULL) strcpy(songs[i].n_singr,s1);

        /*input genre*/
        printf("Genre: ");
        fgets(s1,MAX_STR_LEN,stdin);
        slen=strlen(s1);
        s1[slen-1]='\0';
        songs[i].genre = (char*)realloc(songs[i].genre, slen*sizeof(char));
        if(songs[i].genre != NULL) strcpy(songs[i].genre,s1);

        /*input year of release*/
        printf("Year of release: ");
        scanf("%d",&songs[i].year_of_rels);
        getchar();

        /*input song rating*/
        printf("Song rating(only > 4): ");
        scanf("%lf",&songs[i].rating_song);
        getchar();
        if(songs[i].rating_song<=4)
        {
            songs[i].rating_singr = 0;
            cont = 0;
        }
        else
        {
            /*input singer rating*/
            printf("Singer rating: ");
            scanf("%lf",&songs[i].rating_singr);
            getchar();
        }
        i++;
    }

    puts("\nResult: ");

    printf("|%20s | %20s | %20s | %16s | %15s | %15s |\n","song name","singer name","genre","year of release","song rating","singer rating");
    printf("+---------------------+----------------------+----------------------+------------------+-----------------+-----------------+\n");

    for(size_t j=0;j<i;j++) printf("|%20s | %20s | %20s | %16d | %15.3lf | %15.3lf |\n",
               songs[j].n_song,songs[j].n_singr,songs[j].genre,songs[j].year_of_rels,songs[j].rating_song,songs[j].rating_singr);
    free(songs);
    return 0;
}
