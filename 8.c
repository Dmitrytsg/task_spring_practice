/*Функцию поиска структур с заданным значением выбранного элемента.*/
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

void printing_struct(music*,int,size_t);
void header_print()
{
    puts("\nResult: ");

    printf("|%20s | %20s | %20s | %16s | %15s | %15s |\n","song name","singer name","genre","year of release","song rating","singer rating");
    printf("+---------------------+----------------------+----------------------+------------------+-----------------+-----------------+\n");
}

int menu()
{
    int v;
    do
    {
        CLS;
        puts("---MENU---");
        puts("0 - Song name");
        puts("1 - Singer name");
        puts("2 - Song genre");
        puts("3 - Year of release");
        puts("4 - Song rating");
        puts("5 - Singer rating");
        printf("Enter options: ");
        scanf("%d",&v);
        getchar();
    } while ((v<0)||(v>5));
    return v;
}

int main()
{
    char s1[MAX_STR_LEN];
    char cont_count;
    int slen,choise;
    music* songs = (music*)malloc(1*sizeof(music));
    int cont = 1;
    size_t i = 0;

    while(cont)
    {
        cont = 0;

        if(i!=0) songs = (music*)realloc(songs,(i+1)*sizeof(music));
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
        printf("Song rating: ");
        scanf("%lf",&songs[i].rating_song);
        getchar();

        /*input singer rating*/
        printf("Singer rating: ");
        scanf("%lf",&songs[i].rating_singr);
        getchar();

        /*Continue?*/
        printf("Continue (y/n): ");
        cont_count = getchar();
        getchar();
        if(cont_count == 'y') cont = 1;

        i++;
    }
    cont = 1;
    while(cont)
    {
        cont = 0;

        choise = menu();
        printing_struct(songs,choise,i);

        printf("Continue search (y/n): ");
        cont_count = getchar();
        getchar();
        if(cont_count == 'y') cont = 1;
    }
    free(songs);
    return 0;
}

void printing_struct(music* songs,int ch,size_t i)
{
    char s1[MAX_STR_LEN];
    int slen,year;
    double rating;

    switch(ch){
        case 0:
            /*Song name*/
            printf("Enter song name: ");
            fgets(s1,MAX_STR_LEN,stdin);
            slen=strlen(s1);
            s1[slen-1]='\0';

            header_print();
            for(size_t j=0;j<i;j++)
            {
                if(strcmp(songs[j].n_song,s1)==0)
                {
                    printf("|%20s | %20s | %20s | %16d | %15.3lf | %15.3lf |\n",
                        songs[j].n_song,songs[j].n_singr,songs[j].genre,songs[j].year_of_rels,songs[j].rating_song,songs[j].rating_singr);
                }
            } 
            break;
        case 1:
            /*Singer name*/
            printf("Enter singer name: ");
            fgets(s1,MAX_STR_LEN,stdin);
            slen=strlen(s1);
            s1[slen-1]='\0';

            header_print();
            for(size_t j=0;j<i;j++)
            {
                if(strcmp(songs[j].n_singr,s1)==0)
                {
                    printf("|%20s | %20s | %20s | %16d | %15.3lf | %15.3lf |\n",
                        songs[j].n_song,songs[j].n_singr,songs[j].genre,songs[j].year_of_rels,songs[j].rating_song,songs[j].rating_singr);
                }
            } 
            break;
        case 2:
            /*Song genre*/
            printf("Enter song genre: ");
            fgets(s1,MAX_STR_LEN,stdin);
            slen=strlen(s1);
            s1[slen-1]='\0';

            header_print();
            for(size_t j=0;j<i;j++)
            {
                if(strcmp(songs[j].genre,s1)==0)
                {
                    printf("|%20s | %20s | %20s | %16d | %15.3lf | %15.3lf |\n",
                        songs[j].n_song,songs[j].n_singr,songs[j].genre,songs[j].year_of_rels,songs[j].rating_song,songs[j].rating_singr);
                }
            } 
            break;
        case 3:
            /*year of release*/
            printf("Enter year of release: ");
            scanf("%d",&year);
            getchar();

            header_print();
            for(size_t j=0;j<i;j++)
            {
                if(songs[j].year_of_rels==year)
                {
                    printf("|%20s | %20s | %20s | %16d | %15.3lf | %15.3lf |\n",
                        songs[j].n_song,songs[j].n_singr,songs[j].genre,songs[j].year_of_rels,songs[j].rating_song,songs[j].rating_singr);
                }
            } 
            break;
        case 4:
            /*song rating*/
            printf("Enter song rating: ");
            scanf("%lf",&rating);
            getchar();

            header_print();
            for(size_t j=0;j<i;j++)
            {
                if(songs[j].rating_song==rating)
                {
                    printf("|%20s | %20s | %20s | %16d | %15.3lf | %15.3lf |\n",
                        songs[j].n_song,songs[j].n_singr,songs[j].genre,songs[j].year_of_rels,songs[j].rating_song,songs[j].rating_singr);
                }
            } 
            break;
        case 5:
            /*song rating*/
            printf("Enter singer rating: ");
            scanf("%lf",&rating);
            getchar();

            header_print();
            for(size_t j=0;j<i;j++)
            {
                if(songs[j].rating_singr==rating)
                {
                    printf("|%20s | %20s | %20s | %16d | %15.3lf | %15.3lf |\n",
                        songs[j].n_song,songs[j].n_singr,songs[j].genre,songs[j].year_of_rels,songs[j].rating_song,songs[j].rating_singr);
                }
            } 
            break;
        default:
            printf("No option selected");
    }
}
