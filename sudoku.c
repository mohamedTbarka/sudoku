#include <stdio.h>
#include <stdbool.h>
#define N 9


void initiate_grid(int** grid) {
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			grid[i][j]=-1;
}

bool neighbors_check(int k, int i, int j, int grid[N][N]) {
        int square_i = i / 3 ;
        int square_j = j / 3;

        for(int i=square_i * 3; i<=square_i * 3 + 2; i++)
                for(int j = square_j * 3 ; j<=square_j * 3 + 2; j++)
                        if(grid[i][j] == k)
                                return true;
	return false;
}

bool row_check(int number, int i,  int grid[N][N]) {
        for(int j=0; j<N; j++)
                if(grid[i][j]==number)
                        return true;
	return false;
}

bool column_check(int number, int j, int grid[N][N]) {
        for(int i=0; i<N; i++)
                if(grid[i][j] == number)
                        return true;
	return false;
}

bool first_diagonal_check(int number,  int grid[N][N]) {
        bool flag = false;
        int j = 0;
        while(grid[j][j] != number && j < N)
                j++;
        if(j!=N)
                flag=true;
        return flag;
}

bool second_diagonal_check(int number, int grid[N][N]) {
        bool flag = false;
        int j = 0;
        while(grid[j][N-1-j] != number && j <N)
                j++;
        if(j!=N)
                flag=true;
        return flag;
}

void print_grid(int grid[9][9]) {
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++) {
			printf("%d ", grid[i][j]);
			if(j==N-1)
				printf("\n");
		}
}

void main() {
	int grid[N][N];
	grid[0][0] = 1;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			grid[i][j]=-1;
	print_grid(grid);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {		
			if (i==j)  {

				int k=1;
			while((neighbors_check(k, i,j, grid) == true || row_check(k, i, grid) == true || column_check(k, i, grid) == true || first_diagonal_check(k,  grid) == true) && k <= N) {
                                        k++;
					printf("%d\n", k);
					printf("joker_1\n");
                                }
				if(k != 10)
	                                grid[i][j]=k;
				else
					grid[i][j]=0;

			} else if(i+j==8) {
				int k=1;
                                while((neighbors_check(k, i,j, grid) == true || row_check(k, i, grid) == true || column_check(k, j, grid) == true || second_diagonal_check(k, grid ) == true) && k <=N) {
                                        k++;
					printf("joker_2");

                                }
				if(k != 10) {
	                                grid[i][j]=k;
				} else {
					grid[i][j]=0;
				}
				


			} else {
				int k=1;
				while((neighbors_check(k, i,j, grid) == true || row_check(k, i, grid) == true || column_check(k, j, grid) == true) && k <=N) {
					k++;
					printf("joker_3");
				}
				if(k != 10)
					grid[i][j]=k;
				else
					grid[i][j]=0;

			}
		}
	}
	print_grid(grid);
}
