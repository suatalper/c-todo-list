/*
 * C To-Do List Application
 * Author: Suat Alper
 * 
 * Note: Logic to be implemented.
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void menu();
void view_tasks();
void add_task();
void mark_as_complete();

void mark_as_complete(){
    FILE *task_file_complete;
    FILE *temp_fp ;

    temp_fp = fopen("temp.txt","w");
    task_file_complete = fopen("tasks.txt","r");

    if (task_file_complete != NULL)
    {
        printf("Mevcut Görevler:\n");
        int ch ;
        while ((ch = fgetc(task_file_complete)) != EOF)
        {
            printf("%c",ch);
        }
        fclose(task_file_complete);
    }
    printf("Lutfen tamamlanan gorevin numarasini giriniz: \n");
    int completed_task_number;
    scanf("%d",&completed_task_number);

    // Logic to mark the task as complete would go here
    if (temp_fp != NULL)
    {
        printf("----Mevcut Görevler----");
        view_tasks();
    }
    
    printf(">> Gorev %d tamamlandi olarak isaretlendi.\n", completed_task_number);
    menu();
}

void view_tasks(){

    FILE *task_file_view;
    task_file_view = fopen("tasks.txt","r");

    if (task_file_view != NULL)
    {
        printf("Mevcut Görevler:\n");
        int ch ;
        while ((ch = fgetc(task_file_view)) != EOF)
        {
            printf("%c",ch);
        }
        fclose(task_file_view);
    }
}

int get_next_task_id() {
    FILE *fp = fopen("tasks.txt", "r");
    if (fp == NULL) {
        return 1; // If file doesn't exist, start IDs from 1
    }
    char line[256];
    int last_id = 0 ,current_id;

    while (fgets(line,sizeof(line),fp))
    {
        if (sscanf(line, "Task %d", &current_id) == 1)
        {
          last_id = current_id;    
        }   
    }
    fclose(fp);
    return last_id + 1;
}

void add_task() {
    char task[256];
    int priority = 0 ;
    int task_number = get_next_task_id();

    FILE *task_file_read ;
    task_file_read = fopen("tasks.txt","r");

    if (task_file_read != NULL)
    {
        printf("Mevcut Görevler:\n");
        int ch ;
        while ((ch = fgetc(task_file_read)) != EOF)
        {
            printf("%c",ch);
        }

        printf("\n-----------------------\n");
        fclose(task_file_read);
    }
    printf("Please enter the task : \n");
    scanf("%s", task);
    printf("Please enter the task priority (1-10) : \n");
    scanf("%d", &priority);
    
    FILE *task_file_add;
    task_file_add = fopen("tasks.txt","a");
    if (task_file_add != NULL)
    {
        fprintf(task_file_add, "Task %d : %s , Priority : %d\n", task_number, task, priority);
        fclose(task_file_add);
        printf(">> Gorev basariyla eklendi: Task %d\n", task_number);
    }else(printf("Dosya açılmadı bir sorun var !"));
    menu();      
}

void menu() {
    int menu_choice;
    printf("To-Do List Menu:\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Mark Task as Complete\n");
    printf("4. Exit\n");
    scanf("%d", &menu_choice);

    if (menu_choice == 1)
    {
        // Add Task logic
        add_task();
    }
    else if (menu_choice == 2)
    {
        // View Tasks logic
        view_tasks();
    }
    else if (menu_choice == 3)
    {
        mark_as_complete();
        // Mark Task as Complete logic
    }
    else if (menu_choice == 4)
    {
        // Exit logic
    }
    else
    {
        printf("Invalid choice. Please try again.\n");
        menu();

    }
}
int main() {
    // TODO: Implement the flow described in FLOWCHART.md

    SetConsoleOutputCP(65001);
    menu();
    printf("To-Do List Application\n");
    return 0;
}
