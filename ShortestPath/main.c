#include<stdio.h>
#include<string.h>
#define MAX 40
#define infinity 6666 //:)
int graph[ MAX ][ MAX ];
int sayi;

struct node
{
  int onceki;
  int dist;
  int state;

};

void rota(int path)
{

     if(path==1)
        printf("Ankara");

     if(path==2)
        printf("Eskisehir");

     if(path==3)
        printf("Bolu");

     if(path==4)
        printf("Cankiri");

     if(path==5)
        printf("Kirsehir");

     if(path==6)
        printf("Kirikkale");

     if(path==7)
        printf("Aksaray");

     if(path==8)
        printf("Konya");

     if(path==9)
        printf("Afyon");

     if(path==10)
        printf("Kutahya");

     if(path==11)
        printf("Bilecik");

     if(path==12)
        printf("Kastamonu");

     if(path==13)
        printf("Karabuk");

     if(path==14)
        printf("Corum");

     if(path==15)
        printf("Yozgat");

     if(path==16)
        printf("Nevsehir");

     if(path==17)
        printf("Kayseri");

     if(path==18)
        printf("Nigde");

     if(path==19)
        printf("Isparta");

     if(path==20)
        printf("Antalya");

     if(path==21)
        printf("Karaman");

     if(path==22)
        printf("Mersin");
     else if(path>22)
       printf("%d",path);

    }



int dijkstra(int source, int son, int path[ MAX ], int* sdist)  //https://ozanmanav.blogspot.com.tr/2015/12/dijkstra-algoritmasi-c-ornegi-iki-dugum_18.html
{

    struct node stt[ MAX ];
    int i, min, count = 0, crt, newdist, u, v;
    *sdist = 0;

    for (i = 1; i <= sayi; i++)
    {
        stt[i].onceki = 0;
        stt[i].dist = infinity;
        stt[i].state = 0;
    }

    stt[source].onceki = 0;
    stt[source].dist = 0;
    stt[source].state = 1;

    crt = source;
    while (crt != son)
    {
        for (i = 1; i <= sayi; i++)
        {

            if (graph[crt][i] > 0 && stt[i].state == 0)
            {
                newdist = stt[crt].dist + graph[crt][i];

            if (newdist < stt[i].dist)
                {
                stt[i].onceki = crt;
                stt[i].dist = newdist;
                }
            }
        }

    min = infinity;
    crt = 0;

        for (i = 1; i <= sayi; i++)
        {
            if (stt[i].state == 0 && stt[i].dist < min)
            {
                min = stt[i].dist;
                crt = i;
            }
        }
            if (crt == 0)
            return 0;
            stt[crt].state = 1;
    }
        while (crt != 0)
        {
            count++;
            path[count] = crt;
            crt = stt[crt].onceki;
}

        for (i = count; i > 1; i--)
        {
            u = path[i];
            v = path[i - 1];
            *sdist += graph[u][v];
}
return (count);
}


int main()
{
    int i;
    int p=0;
    int kaynak, hedef;
    int path[ MAX ];
    int shortdist, count;
    FILE* file;
       file=fopen("mesafeler.txt", "r");
       int  j, maliyet, k=0;

    for (i=0 ; i<MAX ; i++ )
      {
        for (k=0 ; k<MAX; k++ )
           {
            graph[i][k]=0;
           }
      }
    for (k=0 ;!feof(file); k++)
    {       p++;
            fscanf(file , "%d %d %d" , &i ,&j, &maliyet);
            graph[i][j]=maliyet;
            graph[j][i]=maliyet;
    }
    sayi = p;

    FILE* file2;
    file2=fopen("sehirler.txt", "r");
    printf("Sehir kodlari: \n");
    for (i=0;!feof(file2);i++)
    {
        char a;
        a=fgetc(file2);
        printf("%c", a);
    }
    printf("\n\n\n");



    int o;
    printf("Secim yapiniz: \n1)Iki sehir arasi mesafe\n2)Bir sehir ile diger tum sehirler arasi mesafeler\n\nSecim: ");
    scanf("%d",&o);
    if(o==1)
      {
        printf("\n1.Sehirin kodunu giriniz : ");
        scanf("%d", &kaynak);
        printf("2.Sehir kodunu giriniz : ");
        scanf("%d", &hedef);
        printf("\n");

        count = dijkstra(kaynak, hedef, path, &shortdist);

      if (shortdist != 0)
     {
        printf("En kisa yol : ");
        for (i = count; i > 1; i--)
            {
            rota(path[i]);
            printf(" >>> ");
            }
            rota(path[i]);
            printf("\n");
            printf("En kisa mesafe : %d km\n\n", shortdist);
     }

    else
    printf("Yol bulunmamaktadýr");

    }

    if(o==2)
 {
      int j;
      printf("Sehirin kodunu giriniz:  ");
      scanf("%d", &kaynak);
      printf("\n");
      for(i=1;i<sayi;i++)
   {
      if(kaynak!=i)

      {
      count = dijkstra(kaynak, i, path, &shortdist);


      printf("En kisa yol : ");
          for (j = count; j > 1; j--)
          {
                rota(path[j]);
                printf(" >>> ");
          }

        rota(path[j]);
        printf("\n");
        rota(kaynak);
        printf("-");
        rota(i);
        printf(" ");
        printf("arasi en kisa mesafe : %d km\n", shortdist);
        printf("\n\n\n");

      }
   }
 }

return 0;
}

