#include<stdio.h>

int count = 0;

void addStudent();
void displayStudents();
void searchStudent();
void updateMarks();
void deleteStudent();
void sortStudents();
 void highestStudent();



struct student{
    int roll;
    char name[50];
    float marks1;
    float marks2;
    float marks3;
    float total;
    float averageMarks;
};

struct student students[50];

int main(){
    int choice;

    
    while(1){
        printf("\n(:-===== STUDENT RECORD MANAGEMENT SYSTEM =====-:)\n");
        printf("1. ADD A NEW STUDENT\n");
        printf("2. DISPLAY ALL STUDENTS");
        printf("3. SEARCH STUDENT USING ROLL NUMBER \n");
        printf("4. UPDATE STUDENTS MARKS\n");
        printf("5. DELETE STUDENT\n");
        printf("6. SORT STUDENTS ACC. TO TOTAL MARKS\n");
        printf("7. STUDENTS WITH HIGHEST MARKS\n");
        printf("8. EXIT THE PROGRAM\n");

        printf("enter your choice : ");
        scanf("%d",&choice);

        if( choice == 1){
            addStudent();


        }
        else if ( choice == 2){
            displayStudents();

        }
        else if( choice == 3){
            searchStudent();

        }
        else if( choice == 4){
            updateMarks();

        }
        else if( choice == 5){
            deleteStudent();

        }
        else if( choice == 6){
            sortStudents();

        }
        else if( choice == 7){
            highestStudent();

        }
        else if( choice == 8){
            printf(" exiting the program.... \n");
            break;
        }
        else {
            printf("please choose valid choice : ) ");

        }



    }
}
    
    // addstudent functin is for adding the details of students as mention
    void addStudent(){
        if(count == 50){
            printf("max limit reached of the list \n");
            return;
        }

        printf("enter roll number :- ");
        scanf("%d", &students[count].roll);

        printf("enter student name :- ");
        scanf("%s",students[count].name);

        printf("enter marks of subject 1 :-n ");
        scanf("%f", &students[count].marks1);

        printf("enter marks of subject 2 :-");
        scanf("%f",&students[count].marks2);

        printf("enter marks of subject 3 :- ");
        scanf("%f", &students[count].marks3);

        students[count].total = students[count].marks1 + students[count].marks2 + students[count].marks3 ;

        students[count].averageMarks = students[count].total / 3 ;

        count++;

        printf("student details added in system :) \n");

    }

    //display students. use of this function is use to display students details as 
    // mention in the structure like roll ,name , ...........

    void displayStudents(){


        if(count == 0){
            printf(" list is empty \n");
            return;
        }

        printf("\n student records \n");

        printf("roll \t name \t m1 \t m2 \t m3 \t total \t average \t \n");


        for( int i = 0 ; i < count ; i++){

            printf("%d \t %s \t %f \t %f \t %f \t %f \t %f \t \n", 
                students[i].roll ,
                students[i].name ,
                students[i].marks1 ,
                students[i].marks2,
                students[i].marks3,
                students[i].total,
                students[i].averageMarks);

        }
    }

    // search student function is used to find the student using the roll number
    //then returnn the students details like name, roll, marks, total,.......

    void searchStudent(){

        int roll; 
      

        if (count == 0){
            printf("list is empty\n");
            return;
        }

        printf("enter roll no. :- ");
        scanf("%d",&roll);

        for (int i = 0 ; i < count ; i++){
            if (students[i].roll == roll){
                printf("student details :- \n");

                printf("roll number : %d\n" ,students[i].roll);
                printf("name : %s\n",students[i].name);
                printf("marks1 : %f\n", students[i].marks1);
                printf("marks2 : %f\n", students[i].marks2);
                printf("marks3 : %f\n", students[i].marks3);
                printf("total : %f\n", students[i].total);
                printf("averageMarks : %f\n", students[i].averageMarks);
                
                return;
            }
        }

        
            printf(" student not in the system :( ");
        

    }


    void updateMarks(){
        if (count == 0){
            printf("list is empty\n");
            return;
        }
        
        int roll;

        printf("enter student roll no. :- \n");
        scanf("%d", &roll);

        for(int i = 0 ; i < count ; i++){
            if( students[i].roll == roll){
                printf(" enter marks1 to update :- ");
                scanf( "%f", &students[i].marks1);

                printf(" enter marks2 to update :- ");
                scanf( "%f", &students[i].marks2);

                printf(" enter marks3 to update :- ");
                scanf( "%f", &students[i].marks3);

                students[i].total = students[i].marks1 + 
                                    students[i].marks2+
                                    students[i].marks3;

                
                students[i].averageMarks = students[i].total / 3;

                printf("student marks updated sucessfully :) ");

                return;


                
            }
        }
        printf("student not found :(");

    }


    // 5. delete or remove student fromm the record


    void deleteStudent(){
        int roll;

        if(count == 0 ){
            printf("no student record :( \n");
            return;
        }

        printf("enter student roll :- \n");
        scanf("%d",&roll);

        for(int i = 0 ; i < count ; i++){
            if(students[i].roll == roll){
                for(int j = i ; j < count-1 ; j++){
                    students[j] = students[j+1];
                    count--;
                    printf("student deleted succesfully :) \n");
                    return;
                }
            }
            printf("student not found :( \n");

        }

        
    }


    // 6. sorting according to total marks

    void sortStudents(){
        struct student temp;

          if(count == 0 ){
            printf("no student record :( \n");
            return;
        }

        for(int i= 0 ; i < count - 1 ; i++){
            for(int j = 0 ; j <count - i -1 ; j++){
                if(students[j].total < students[j+1].total){
                    temp = students[j];
                    students[j] =  students[j + 1];
                    students[j+1] = temp ;
                }
            }
        }
       printf("student sorted on the basis of marks(high to low) :) \n");
    }



    // 7.  students with highest marks

    void highestStudent(){
        sortStudents();

        printf("student with highest marks :- \n");
        printf("roll no. :- %d\n",students[0].roll);
         printf("name :- %s\n",students[0].name);
         printf("total marks :- %f\n",students[0].total);
         printf("average :- %f\n",students[0].averageMarks);
        

    }