#include <stdio.h>
#include <stdlib.h>

char r;
long tmax,N;    //tempo di esecuzione e numero di celle
char *c,*ctemp;

void Inizio();  //definizione dei paramentri iniziali


int main()
{
	long t,i;
	FILE *risultati;

	Inizio();

	risultati=fopen("risultati.dat","w");
	if(risultati==NULL)
	{
		printf("Errore nell'apertura del file. Il programma sarà chiuso.\n");
		exit(0);
	}

	c=(char *)calloc(N,sizeof(char));
	ctemp=(char *)calloc(N,sizeof(char));

	ctemp[(int)(0.5*N)]=1;
  	c[(int)(0.5*N)]=1;

  	for(t=0;t<tmax;t++)
	{
    	for(i=0;i<N;i++) if(c[i]==1) fprintf(risultati,"%li %li\n",i-(int)(0.5*N),t);
    	for(i=1;i<N-1;i++)
		{
		  if(r=='1') ctemp[i]=c[i-1]^c[i+1];
		  else ctemp[i]=(c[i-1]^c[i+1])^c[i];
    	}
    	for(i=0;i<N;i++) c[i]=ctemp[i];
  	}
	fclose(risultati);
	
	free(c);
	free(ctemp);

	exit(0);
}


void Inizio()
{
	printf("Le possibili regole da scegliere sono: \n");
	printf("1) 90\n");
	printf("2) 150\n");
	printf("Scegliere: ");
	scanf("%c",&r);
	while(r!='1' && r!='2')
	{
		printf("Valore non previsto. Reinserire: ");
		scanf("%c",&r);
	}

	printf("Inserire il tempo di esecuzione: ");
	scanf("%li",&tmax);                      //valore consigliato:200
	while(tmax<=0)
	{
		printf("Il valore deve essere maggiore di zero. Reinserire: ");
		scanf("%li",&tmax);
	}

	printf("Inserire il numero di celle: ");
	scanf("%li",&N);                         //valore consigliato:400
	while(N<=0)
	{
		printf("Il valore deve essere maggiore di zero. Reinserire: ");
		scanf("%li",&N);
	}
}
