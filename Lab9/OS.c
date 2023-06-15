#include <stdio.h>

int tph, philname[20], status[20], howhung, hu[20], cho; 

void one() 
{ 
  int pos=0, x, i; 
  printf("\nAllow one philosopher to eat at any time\n"); 
  for(i=0;i<howhung; i++, pos++) { 
    printf("\nP %d is granted to eat", philname[hu[pos]]);
    for(x=pos;x<howhung;x++) 
      printf("\nP %d is waiting", philname[hu[x]]); 
  } 
}
void two()
{
  int i, j, s = 0, t, r, x;
  printf("\n Allow two philosophers to eat at the same time\n");
  for (i = 0; i < howhung; i++)
  {
    for (j = i + 1; j < howhung; j++)
    {
      if (abs(hu[i] - hu[j]) != 1) // Check if the philosophers are not adjacent
      {
        printf("\nCombination %d ", (s + 1));
        t = hu[i];
        r = hu[j];
        s++;
        printf("\nP %d and P %d are granted to eat", philname[hu[i]], philname[hu[j]]);
        for (x = 0; x < howhung; x++)
        {
          if ((hu[x] != t) && (hu[x] != r))
            printf("\nP %d is waiting", philname[hu[x]]);
        }
      }
    }
  }
}

int main() 
{
  int i; 

    printf("\n\nDINING PHILOSOPHER PROBLEM"); 
    printf("\nEnter the number of philosophers : "); 
  scanf("%d",&tph); 
  for(i=0;i<tph;i++) { 
    philname[i] = (i+1); 
    status[i]=1; 
  } 
  printf("How many are hungry : "); 
  scanf("%d", &howhung); 
  if(howhung==tph) { 
    printf("\nAll are hungry..\nDead lock stage will occur"); 
    printf("\nExiting.."); 
  } 
  else { 
      for(i=0;i<howhung;i++) { 
        printf("\nEnter the position of hungry philosopher %d: ", (i+1));
        scanf("%d", &hu[i]);
        hu[i]--; // Adjust the position by subtracting 1
        status[hu[i]] = 2; 
      }
do { 
        printf("\n\nEnter the option\n1.Allow one philosopher to eat at any time\n2.Allow two philosophers to eat at the same time\n3.Exit\n");
        scanf("%d", &cho); 
        switch(cho) { 
          case 1: one(); 
              break; 
          case 2: two(); 
              break; 
          case 3:
            printf("\nExiting.."); 
            return 0; 
          default: printf("\nInvalid option.."); 
          } 
        }while(1); 
  } 
} 

