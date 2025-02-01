#include<stdio.h>
#include<stdlib.h>
#include<string.h>


 struct task {
    char description[1000];
    int priority;
 };
long Check_empty(FILE *file)
  {
     long position;
     file = fopen("/Users/fat_gum/Desktop/Task.txt","a+");
      if(file == NULL)
       {
         printf("error");
         exit(1);
       }
        fseek(file,0,SEEK_END);
        position = ftell(file);
         
         return position;
  }
void Add(FILE *file)
  {
         struct task new;
         file = fopen("/Users/fat_gum/Desktop/Task.txt","a+");
             
             if(file == NULL)
               {
                   printf("error");
                   exit(1);
               }
                printf("Enter the description : ");
                scanf(" %999[^\n]",new.description);
                printf("Enter the priority : ");
                scanf("%d",&new.priority);

          fprintf(file,"%s : %d\n",new.description,new.priority);

          printf("Added task : %s with the priority: %d\n",new.description,new.priority);

          fclose(file);    
  }
void Delete(FILE *file)
 {
    struct task del;
    char re[100];
    int po;
    int Task_found = 0;
      if(Check_empty(file)!=0)
       {

    FILE *filee;
     filee = fopen("/Users/fat_gum/Desktop/temp.txt","a+");
      if(filee == NULL)
       {
         printf("error");
         exit(1);
       }
     file = fopen("/Users/fat_gum/Desktop/Task.txt","a+");
      if(file == NULL)
       {
         printf("error");
         exit(1);
       }
        rewind(file);
        printf("Enter the description : ");
        scanf(" %999[^\n]",del.description);
        printf("Entel the priority : ");
        scanf(" %d",&del.priority);
          while(fscanf(file,"%99[^:] : %d\n",re,&po)!=EOF)
            {
               if(strstr(re,del.description)!=NULL && po == del.priority)
                 {
                   Task_found = 1;
                   continue;
                 }
                  fprintf(filee,"%s: %d\n",re,po);
            }
          fclose(file);
          fclose(filee);
            
          remove("/Users/fat_gum/Desktop/Task.txt");
          rename("/Users/fat_gum/Desktop/temp.txt","/Users/fat_gum/Desktop/Task.txt");

          if(Task_found == 1)
           {
             printf("Task deleted!");
           }
          else{
                 printf("This task does not exist!");
          }
          
       }
       else
       {
        printf("Your to do list in empty!");
       }
 }
void Display(FILE *file)
 {

  if(Check_empty(file)!= 0)
   {
   char tab[100];

   file = fopen("/Users/fat_gum/Desktop/Task.txt","a+");
     if(file == NULL)
       {
          printf("error");
          exit(1);
       }
        rewind(file);
    while(fgets(tab,sizeof(tab),file)!=NULL)
      {
           printf("%s",tab);
      }
   }
    else{
       printf("Your to do list in empty!");
    }
 }  
   int main()
    {
       FILE *file;
       int choice;
 
          do{
           printf("\nChoose an Option (1-4)");
           printf("\n1.Display the tasks");
           printf("\n2.Add a task");
           printf("\n3.Delete a task");
           printf("\n4.Exit\n");
           
             do{
               scanf("%d",&choice);
                
                if(choice < 1 || choice > 5)
                  {
                     printf("Invalid number!");
                  }
             }while(choice < 1 || choice > 5);

             switch(choice)
                {
                   case 1:
                   Display(file);
                   break;
                   case 2:
                    Add(file);
                    break;
                   case 3:
                    Delete(file);
                    break;
                   case 4:
                    printf("End of Program\a");
                    break;         
                }
          }while(choice!=4);
        
                return 0;
    }
    
