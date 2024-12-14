// Maze Robot Puzzle Problem { PGCAT Question }

#include <stdio.h>
#define max(a, b, c) a>b ? (a>c ? a : c) : (b>c ? b : c);
int maze[20][20];
int row, column;

int calculateRewards(int rw, int col, int mazes[][20]){
	static int rewards = 0;
	int r, c, d, md = 0;

	if(rw+1 >= row && col+1 >= column)
		return rewards;

	if(rewards == 0){
		md = mazes[rw][col];
		printf("%d ::", md);
	}
	else{
		md = (mazes[rw][col])%rewards;
		printf("%d ::", md);
	}
	rewards = rewards + md;

	if(rw+1 >= row){
		c = mazes[rw][col+1];
		r = 0;
		d = 0;
	}else if(col+1 >= column){
		r = mazes[rw+1][col];
		c = 0;
		d = 0;
	}else{
		r = mazes[rw+1][col];
		c = mazes[rw][col+1];
		d = mazes[rw+1][col+1];
	}
		
	
	if(r%rewards > c%rewards && r%rewards > d%rewards)
		return rewards + calculateRewards(rw+1, col, mazes);
	else if(c%rewards > r%rewards && c%rewards > d%rewards)
		return rewards + calculateRewards(rw, col+1, mazes);
	else
		return rewards + calculateRewards(rw+1, col+1, mazes);
}

int main(){
	int i, j, k;
	int rewards, r_w = 0, c_l = 0;

	printf("Enter the Row and the Column: \n");
	scanf("%d %d", &row, &column);

	printf("Enter the values of the Maze: \n");
	for(i = 0; i < row; i++){
		for(j = 0; j < column; j++){
			scanf("%d", &maze[i][j]);
		}
	}

	rewards = calculateRewards(r_w, c_l, maze);
	printf("Rewards gets Robot on Maze: %d", rewards);

	return 0;
}

// 1 2 3 4
// 5 6 7 8
// 9 10 11 12