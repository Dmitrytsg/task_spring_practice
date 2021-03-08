/*Функцию сортировки по значению текстового поля методом вставок в
лексикографическом порядке.
Сортровка по полю названия песни*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#define OS linux
#define CLS system("clear")
#define MAX_STR_LEN 120

typedef struct T
{
    char* n_song;
    char* n_singr;
    char* genre;
    int year_of_rels;
    double rating_song;
    double rating_singr;
} music;

char **str_split(char *str, int length,char sep);

void clear_string_array(char **str_array,int count);

void print_header();

void print_struct(music* ms);

void clear_struct(music *song_00);

music *struct_fill(char **str);

void sorting_insertion(music **song_00,int num);

int main()
{
    music** songs=NULL;
    char s1[MAX_STR_LEN];
    char **s2=NULL;
    char sep;
    int num_str,slen,count,i;
    FILE *df;

    printf("Enter separator:");
    sep = getchar();
    getchar();
    
    CLS;

    df = fopen("data.txt","r");
    if(df!=NULL)
    {
        num_str=0;
        while((fgets(s1,MAX_STR_LEN,df))!=NULL) num_str++;
        rewind(df);
        songs=(music**)malloc(num_str*sizeof(music*));/*allocate mem due number string*/
        if(songs!=NULL)
        {
            for(i=0,count=0;i<num_str;i++,count++)
            {
                fgets(s1,MAX_STR_LEN,df);
                slen=strlen(s1);
                s1[slen]='\0';
                slen=strlen(s1);

                s2 = str_split(s1,slen,sep);
                if(s2!=NULL) 
                {
                    songs[i]=struct_fill(s2);
                    if(songs[i]==NULL)
                    {
                        puts("No memory allocation! -- struct ");
                        i=num_str;
                    }
                }
                else puts("Error at data reading!");
            }
        }
        else puts("No memory allocation! -- array struct");
        fclose(df);

        if(songs!=NULL)
        {
            sorting_insertion(songs,count);
            print_header();
            for(i=0;i<count;i++)
            {
                print_struct(songs[i]);
                clear_struct(songs[i]);
            }
        }

        free(songs);
        songs=NULL;
    }
    else puts("Data error!");
    
    return 0;
}


music *struct_fill(char **str)
{
    music *song_00=NULL;

    song_00=(music*)malloc(sizeof(music));
    if(song_00!=NULL)
    {
        song_00->n_singr=str[0];
        song_00->n_song=str[1];
        song_00->genre=str[2];
        song_00->year_of_rels=atoi(str[3]);
        song_00->rating_song=atof(str[4]);
        song_00->rating_singr=atof(str[5]);
    }
    return song_00;
}

char **str_split(char *str, int length,char sep)
{
    char **str_array=NULL;
    int i,j,k,m;
    int key,count; //key - flag memory allocation,
    
    for(j=0,m=0;j<length;j++)
    {
        if(str[j]==sep) m++;
    }
    key = 0;
    str_array=(char**)malloc((m+1)*sizeof(char*));
    if(str_array!=NULL)
    {
        for(i=0,count=0;i<=m;i++,count++)//allocate mem for element
        {
            str_array[i]=(char*)malloc(length*sizeof(char));//more memory alloc due to length
            if(str_array[i]!=NULL) key = 1;
            else
            {
                key = 0;
                i = m;
            }
        }
        if(key)
        {
            k=0;
            m=0;
            for(j=0;j<=length;j++)
            {
                if(str[j]!=sep) str_array[m][j-k]=str[j];
                else
                {
                    str_array[m][j-k]='\0';
                    k=j+1;
                    m++;
                }
            }
        }
    }
    else clear_string_array(str_array,count);

    return str_array;
}

void clear_string_array(char **str_array,int count)
{
    int i;

    for(i=0;i<count;i++)
    {
        free(str_array[i]);
        str_array[i] = NULL;
    }
    free(str_array);
    str_array=NULL;
}

void clear_struct(music *song_00)
{
    free(song_00->n_song);
    free(song_00->n_singr);
    free(song_00->genre);
    song_00->n_song=NULL;
    song_00->n_singr=NULL;
    song_00->genre=NULL;
    free(song_00);
    song_00=NULL;
}

void print_header()
{
    printf("|%20s | %15s | %10s | %16s | %15s | %15s |\n","song name","singer name","genre","year of release","song rating","singer rating");
    for(int i=0;i<109;i++) printf("%c",'-');
    printf("\n");
}

void print_struct(music* ms)
{
    printf("|%20s | %15s | %10s | %16d | %15.3lf | %15.3lf |\n",
               ms->n_song,ms->n_singr,ms->genre,ms->year_of_rels,ms->rating_song,ms->rating_singr);
}

void sorting_insertion(music **song_00,int num)
{
    music *temp;
    int j;
    for(int i=0;i<num;i++)
    {
        j = i - 1;
        temp = song_00[i];
        while((j>=0)&&(strcmp(song_00[j]->n_song,temp->n_song)>0))
        {
            song_00[j+1] = song_00[j];
            j--;
            
        }
        song_00[j+1] = temp;
    }
}