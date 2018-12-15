#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#define size 11

typedef enum {t, f} bool;

void rows(int val[][9]);
void cols(int val[][9]);
void box1(int val[][9]);
void box2(int val[][9]);
void box3(int val[][9]);
void box4(int val[][9]);
void box5(int val[][9]);
void box6(int val[][9]);
void box7(int val[][9]);
void box8(int val[][9]);
void box9(int val[][9]);

int main(int argc, char *argv){
	int val[9][9];
	int row, col;

	for(row = 0; row < 9; row++){
		printf("%d, row >>",row);
		for(col = 0; col < 9; col++)
			scanf("%d",&val[row][col]);
	}
	printf("-----print-----\n");
	for(row = 0; row < 9; row++){
		for(col = 0; col < 9; col++){
			printf("%d ",val[row][col]);
		}
		printf("\n");
	}
	printf("---------------\n");
	
	pid_t pidval[size], pid;
	int run ,child_pid,status;
	
	for(run = 0;run < size; run++){
		pidval[run] = fork();
		
		if(pidval[run] < 0)
			return 0;
		else if(pidval[run] == 0){
			pid = fork();
			if(pid == 0){
				switch(run){
				case 1:
				printf("-----row-----\n");
				rows(val);
				child_pid=wait(&status);
				printf("-------------\n");
				break;

				case 2:
                                printf("-----col-----\n");
                                cols(val);
				child_pid=wait(&status);
                                printf("-------------\n");
                                break;

				case 3:
                                printf("-----box1----\n");
                                box1(val);
				child_pid=wait(&status);
                                printf("-------------\n");
                                break;

				case 4:
                                printf("-----box2----\n");
                                box2(val);
				child_pid=wait(&status);
                                printf("-------------\n");
                                break;

				case 5:
                                printf("-----box3----\n");
                                box3(val);
				child_pid=wait(&status);
                                printf("-------------\n");
                                break;

				case 6:
                                printf("-----box4----\n");
                                box4(val);
				child_pid=wait(&status);
                                printf("-------------\n");
                                break;

				case 7:
                                printf("-----box5----\n");
                                box5(val);
				child_pid=wait(&status);
                                printf("-------------\n");
                                break;

				case 8:
                                printf("-----box6----\n");
                                box6(val);
				child_pid=wait(&status);
                                printf("-------------\n");
                                break;

				case 9:
                                printf("-----box7----\n");
                                box7(val);
				child_pid=wait(&status);
                                printf("-------------\n");
                                break;

				case 10:
                                printf("-----box8----\n");
                                box8(val);
				child_pid=wait(&status);
                                printf("-------------\n");
                                break;

				case 11:
                                printf("-----box9----\n");
                                box9(val);
				child_pid=wait(&status);
                                printf("-------------\n");
                                break;
				}
			}
			child_pid=wait(&status);
			exit(0);
		}
	}
	printf("------------- End --------------\n");
	return 0;
}

void rows(int val[][9]){
	int i , j , num;
	bool check[9] = {t ,t ,t ,t ,t ,t ,t ,t ,t};
	
	for(i = 0; i < 9 ; i++){
		for(j = 0; j < 9; j++){
			num = val[i][j];
			if(check[num-1] == f){
				printf("%d row [%d,%d] is equls\n",i+1 ,i+1 ,j+1);
				break;
			}else{
				check[num-1] = f;
			}
		}
		check[0] = t;
		check[1] = t;
		check[2] = t;
		check[3] = t;
		check[4] = t;
		check[5] = t;
		check[6] = t;
		check[7] = t;
		check[8] = t;
	}
}

void cols(int val[][9]){
	int i , j , num;
        bool check[9] = {t ,t ,t ,t ,t ,t ,t ,t ,t};

        for(i = 0; i < 9 ; i++){
                for(j = 0; j < 9; j++){
                        num = val[j][i];
                        if(check[num-1] == f){
                                printf("%d col [%d,%d] is equls\n",i+1 ,i+1 ,j+1);
				break;
                        }else{
                                check[num-1] = f;
                        }
                }
                check[0] = t;
                check[1] = t;
                check[2] = t;
                check[3] = t;
                check[4] = t;
                check[5] = t;
                check[6] = t;
                check[7] = t;
                check[8] = t;
        }
}

void box1(int val[][9]){
	int i , j , num;
        bool check[9] = {t ,t ,t ,t ,t ,t ,t ,t ,t};

        for(i = 0; i < 3 ; i++){
                for(j = 0; j < 3; j++){
                        num = val[i][j];
                        if(check[num-1] == f){
                                printf("1st box [%d,%d] is equls\n" ,i+1 ,j+1);
				continue;
                        }else{
                                check[num-1] = f;
                        }
                }
        }
}

void box2(int val[][9]){
        int i , j , num;
        bool check[9] = {t ,t ,t ,t ,t ,t ,t ,t ,t};

        for(i = 0; i < 3 ; i++){
                for(j = 3; j < 6; j++){
                        num = val[i][j];
                        if(check[num-1] == f){
                                printf("2nd box [%d,%d] is equls\n",i+1 ,j+1);
                                continue;
                        }else{
                                check[num-1] = f;
                        }
                }
        }
}

void box3(int val[][9]){
        int i , j , num;
        bool check[9] = {t ,t ,t ,t ,t ,t ,t ,t ,t};

        for(i = 0; i < 3 ; i++){
                for(j = 6; j < 9; j++){
                        num = val[i][j];
                        if(check[num-1] == f){
                                printf("3rd box [%d,%d] is equls\n",i+1 ,j+1);
                                continue;
                        }else{
                                check[num-1] = f;
                        }
                }
        }
}

void box4(int val[][9]){
        int i , j , num;
        bool check[9] = {t ,t ,t ,t ,t ,t ,t ,t ,t};

        for(i = 3; i < 6 ; i++){
                for(j = 0; j < 3; j++){
                        num = val[i][j];
                        if(check[num-1] == f){
                                printf("4th box [%d,%d] is equls\n",i+1 ,j+1);
                                continue;
                        }else{
                                check[num-1] = f;
                        }
                }
        }
}

void box5(int val[][9]){
        int i , j , num;
        bool check[9] = {t ,t ,t ,t ,t ,t ,t ,t ,t};

        for(i = 3; i < 6 ; i++){
                for(j = 3; j < 6; j++){
                        num = val[i][j];
                        if(check[num-1] == f){
                                printf("5th box [%d,%d] is equls\n",i+1 ,j+1);
                                continue;
                        }else{
                                check[num-1] = f;
                        }
                }
        }
}

void box6(int val[][9]){
        int i , j , num;
        bool check[9] = {t ,t ,t ,t ,t ,t ,t ,t ,t};

        for(i = 3; i < 6 ; i++){
                for(j = 6; j < 9; j++){
                        num = val[i][j];
                        if(check[num-1] == f){
                                printf("6th box [%d,%d] is equls\n",i+1 ,j+1);
                                continue;
                        }else{
                                check[num-1] = f;
                        }
                }
        }
}

void box7(int val[][9]){
        int i , j , num;
        bool check[9] = {t ,t ,t ,t ,t ,t ,t ,t ,t};

        for(i = 6; i < 9 ; i++){
                for(j = 0; j < 3; j++){
                        num = val[i][j];
                        if(check[num-1] == f){
                                printf("7th box [%d,%d] is equls\n",i+1 ,j+1);
                                continue;
                        }else{
                                check[num-1] = f;
                        }
                }
        }
}

void box8(int val[][9]){
        int i , j , num;
        bool check[9] = {t ,t ,t ,t ,t ,t ,t ,t ,t};

        for(i = 6; i < 9 ; i++){
                for(j = 3; j < 6; j++){
                        num = val[i][j];
                        if(check[num-1] == f){
                                printf("8th box [%d,%d] is equls\n",i+1 ,j+1);
                                continue;
                        }else{
                                check[num-1] = f;
                        }
                }
        }
}

void box9(int val[][9]){
        int i , j , num;
        bool check[9] = {t ,t ,t ,t ,t ,t ,t ,t ,t};

        for(i = 6; i < 9 ; i++){
                for(j = 6; j < 9; j++){
                        num = val[i][j];
                        if(check[num-1] == f){
                                printf("9th box [%d,%d] is equls\n",i+1 ,j+1);
                                continue;
                        }else{
                                check[num-1] = f;
                        }
                }
        }
}

