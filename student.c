//STUDENT INFORMATION
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char name[50];
    int regNo;
    float marks[3];
    float avg;
}student;
void ReadInformation(student *st,int n){
    for(int i=0;i<n;i++){
        printf("\nEnter the details of student %d\n",i+1);
        printf("Name of the student: ");
        scanf("%s",st[i].name);
        printf("Register number : ");
        scanf("%d",&st[i].regNo);
        for(int j=0;j<3;j++){
            printf("Marks of test-%d: ",j+1);
            scanf("%f",&st[i].marks[j]);
        }
    }   
}
void DisplayInformation(student *st, int n){
    printf("\nInformation of students\n");
    for(int i=0;i<n;i++){
        printf("\nstudent %d :-",i+1);
        printf("Name: %s\n",st[i].name);
        printf("Register Number: %d\n",st[i].regNo);
        for(int j=0;j<3;j++){
            printf("Mark of test-%d: %.2f\n",(j+1),st[i].marks[j]);
        }
        printf("Average of best two marks: %.2f\n",st[i].avg);
    }
}
void Average(student *st, int n){
    printf("Average calculated successfully\n");
    for(int i=0;i<n;i++){
        float first=st[i].marks[0];
        float second=st[i].marks[1];
        float third=st[i].marks[2];
        float sum;
        if(first<second && first<third){
            sum=second+third;
        }
        else if(second<first && second<third){
            sum=first+third;
        }
        else{
            sum=first+second;
        }
        st[i].avg=sum/2; 
    }
}
void SortRegNo(student *st, int n){
    printf("Students sorted by register number\n");
    student temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(st[i].regNo>st[j].regNo){
                temp=st[i];
                st[i]=st[j];
                st[j]=temp;
            }
        } 
    }

}
int main(){
    int n,ch;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    student *st=(student *)malloc(n*sizeof(student));
    if(st==NULL){
        printf("Memory allocation failed!!\n");
        return 1;
    }
    do{
        printf("\nMenu:\n");
        printf("1. Read Student Information\n");
        printf("2. Display Student Information\n");
        printf("3. Calculate Average of Best Two Test Marks\n");
        printf("4. Sort Students by Registration Number\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: ReadInformation(st,n);
            break;
            case 2: DisplayInformation(st,n);
            break;
            case 3: Average(st,n);
            break;
            case 4: SortRegNo(st,n);
            break;
            case 5: printf("Exiting the program...\nThank you...\n");
            break;
            default: printf("Invalid choice...\nTry again.....\n");
    }
    }while(ch!=5);
    free(st);
    return 0;  
}