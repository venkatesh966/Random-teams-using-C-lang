#include<stdio.h>
#include<stdlib.h>
#include<time.h>>
int TOT=14;//total participants//
int p[20],lcount=0;//array used for shuffling the values//
char arr[50][50];//array for storing information of json file//
void teams();//function for dividing into teams and writing it output file//
void shuffle();//to randomize the values //

void teams(){
  int x,y,i,j,s,k=1,no_of_teams;
  char dec;
  printf("enter size : \n");
  scanf("%d",&s);
  if(s<0||s>14||(s>65&&s<90))
  printf("entered size is wrong\n");
  else{
  x = TOT%s;
  no_of_teams = TOT/s;
  FILE *fptr1;
  fptr1 = fopen("teams.txt","w");

  for(i=0;i<no_of_teams;i++)
  {
  fprintf(fptr1,"%s","\n\n\n\n");
  fprintf(fptr1,"%s","team");
  fprintf(fptr1,"%d: \n",k);
  fprintf(fptr1,"%s","{\n");
  for(j=i*s;j<s+i*s;j++)
  {
//printing equal sized teams//
  fprintf(fptr1,"%s",arr[p[j]]);
    }
  fprintf(fptr1,"%s","\n}\n");
      fprintf(fptr1,"%s","\n\n\n\n\n");
  k=k+1;
  }
  for(;j<TOT;j++)
  {
  	//printing left over members into one team//
  	if(j==TOT-2){
  	 fprintf(fptr1,"%s","team");
      fprintf(fptr1,"%d: \n{",k);}
      fprintf(fptr1,"%s",arr[p[j]]);
  }
  fprintf(fptr1,"%s","\n}\n");
  fclose(fptr1);
}}

void shuffle(){
  int temp,j,i=0,x,y,lim;
  lim = rand()%100;
  for(j=0;j<lim;j++){//Running the loop for lim value times//
  	srand(time(NULL));
    x = rand()%14;
    y = rand()%14;
    temp = p[x];
    p[x] = p[y];
    p[y] = temp;
  } 
  for(i=0;i<TOT;i++)
  printf("\t\tp[%d]=%d\n",i,p[i]);
}


void main(){
    FILE *fptr;
    char filename[15];
    char ch;
    int count=0,j=0,i=0,num;
    printf("Enter the filename to be opened : ");
    scanf("%s", filename);
    // open the file for reading //
    fptr = fopen(filename, "r");
    if (fptr == NULL){
      printf("Cannot open file \n");
      exit(0);
      }
    ch = fgetc(fptr);
    while (ch != EOF){
    if (ch=='[')
      count=count+1;
      if(ch=='{')
      count=count+1;    
    if (count==2){
      if (ch!='}'){
         if(j==0)
		 {
          ch=fgetc(fptr);
		 }
          arr[i][j] = ch;
          j = j+1;}
      else{
        arr[i][++j]='\0';
        i=i+1;
        count=count-1;
        lcount+=1;
        j=0;}}
      ch = fgetc(fptr);}
    fclose(fptr);
for(i=0;i<TOT;i++)
p[i]=i;//passing values to array for shuffling//
shuffle();
teams();}
