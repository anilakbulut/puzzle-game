/*ANIL AKBULUT 151044029 - PUZZLE GAME!*/

/*Used libraries*/
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
/*Fixed values used*/
#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18


int get_line_size(char *line);
void copy_string(char *source, char *destination);
void remove_newline(char *line);
void print_dictionary(char *dict[]);
void print_coord(int coord[DICT_SIZE][4]);
void print_dictionary(char *dict[]);


/*This function combines dict with random map*/
void united_map(char map[][DICT_SIZE],int coord[][4],char *dict [DICT_SIZE]);
/*This function creates a random character in map*/
void random_map(char map[][DICT_SIZE]);
/*This function prints completed map on screen */
void print_random_map(char map[][DICT_SIZE]);
/*This function includes the search have made in map*/
void find_word(char map[][DICT_SIZE],char *dict[DICT_SIZE]);
/*This function print the words from right to left and
works with the first coordinate*/
void sag_bas(char map[][DICT_SIZE],char word[],int c1,int c2);
/*This function print the words from right to left and
works with the last coordinate*/
void sag_son(char map[][DICT_SIZE],char word[],int c1,int c2);
/*This function print the words from up to down and
works with the first coordinate*/
void asagi_bas(char map[][DICT_SIZE],char word[],int c1,int c2);
/*This function print the words from up to down and
works with the last coordinate*/
void asagi_son(char map[][DICT_SIZE],char word[],int c1,int c2);
/*This function print the words in the right diagonal direction and
works with the first coordinate*/
void sag_capraz_bas(char map[][DICT_SIZE],char word[],int c1,int c2);
/*This function print the words in the right diagonal direction and
works with the last coordinate*/
void sag_capraz_son(char map[][DICT_SIZE],char word[],int c1,int c2);
/*This function print the words in the left diagonal direction and
works with the first coordinate*/
void sol_capraz_bas(char map[][DICT_SIZE],char word[],int c1,int c2);
/*This function print the words in the left diagonal direction and
works with the last coordinate*/
void sol_capraz_son(char map[][DICT_SIZE],char word[],int c1,int c2);
/*This function counts uppercase latters in the map[][]*/
int uppercase_letter(char map[][DICT_SIZE]);

int uppercase_letter(char map[][DICT_SIZE]){
	int i,j,count=0;
	for(i=0;i<DICT_SIZE;i++){
		for(j=0;j<DICT_SIZE;j++){
			if(map[i][j]>=65 && map[i][j]<=90)	count++;
		}
	}
	/*count is a return value and it includes count uppercase latters*/
	return count;
}
void sag_bas(char map[][DICT_SIZE],char word[],int c1,int c2){

	int k=0,flag=0;
	int t_c2=c2;
	while(word[k]!=0){ 
		if(word[k]==map[c1][c2] || word[k]- 32 ==map[c1][c2]){
			c2++;
		}
		else break;
		k++;
	}
	if(word[k]==0) flag=1;
	k=0;
	if(flag==1){
		while(word[k]!=0){
			if(map[c1][t_c2]>=97 && map[c1][t_c2]<=122 ) map[c1][t_c2] -=  32;
			t_c2++;
			k++;
		}
	}

}
void sag_son(char map[][DICT_SIZE],char word[],int c1,int c2){
	int k=0,flag=0;
	int t_c2=c2;
	int lenght=0,temp_lenght=0;
	while(word[k]!=0){
		k++;
		lenght++;
		temp_lenght++;
	}
	while(lenght>0){ 
		if(word[lenght-1]==map[c1][c2] || word[k]- 32 ==map[c1][c2]){
			c2--;
		}
		else break;
		lenght--;
	}
	if(lenght==0) flag=1;
	lenght=temp_lenght;
	if(flag==1){
		while(lenght>0){
			if(map[c1][t_c2]>=97 && map[c1][t_c2]<=122 ) map[c1][t_c2] -=  32;
			t_c2--;
			lenght--;
		}
	}
}

void asagi_bas(char map[][DICT_SIZE],char word[],int c1,int c2){

	int k=0,flag=0;
	int t_c1=c1;
	while(word[k]!=0){ 
		if(word[k]==map[c1][c2] || word[k]- 32 ==map[c1][c2]){
			c1++;
		}
		else break;
		k++;
	}
	if(word[k]==0) flag=1;
	k=0;
	if(flag==1){
		while(word[k]!=0){
			if(map[t_c1][c2]>=97 && map[t_c1][c2]<=122 ) map[t_c1][c2] -=  32;
			t_c1++;
			k++;
		}
	}
}
void asagi_son(char map[][DICT_SIZE],char word[],int c1,int c2){
	int k=0,flag=0;
	int t_c1=c1;
	int lenght=0,temp_lenght=0;
	while(word[k]!=0){
		k++;
		lenght++;
		temp_lenght++;
	}
	while(lenght>0){ 
		if(word[lenght-1]==map[c1][c2] || word[lenght-1]- 32 ==map[c1][c2]){
			c1--;
		}
		else break;
		lenght--;
	}
	if(lenght==0) flag=1;
	lenght=temp_lenght;
	if(flag==1){
		while(lenght>0){
			if(map[t_c1][c2]>=97 && map[t_c1][c2]<=122 ) map[t_c1][c2] -=  32;
			t_c1--;
			lenght--;
		}
	}	
}
void sag_capraz_bas(char map[][DICT_SIZE],char word[],int c1,int c2){
	int k=0,flag=0;
	int t_c1=c1;
	int t_c2=c2;
	while(word[k]!=0){ 
		if(word[k]==map[c1][c2] || word[k]- 32 ==map[c1][c2]){
			c1++;
			c2++;
		}
		else break;
		k++;
	}
	if(word[k]==0) flag=1;
	k=0;
	if(flag==1){
		while(word[k]!=0){
			if(map[t_c1][t_c2]>=97 && map[t_c1][t_c2]<=122 ) map[t_c1][t_c2] -=  32;
			t_c1++;
			t_c2++;
			k++;
		}
	}	
}
void sag_capraz_son(char map[][DICT_SIZE],char word[],int c1,int c2){
	int k=0,flag=0;
	int t_c1=c1;
	int t_c2=c2;
	int lenght=0,temp_lenght=0;
	while(word[k]!=0){
		k++;
		lenght++;
		temp_lenght++;
	}
	while(lenght>0){ 
		if(word[lenght-1]==map[c1][c2] || word[lenght-1]- 32 ==map[c1][c2]){
			c1--;
			c2--;
		}
		else break;
		lenght--;
	}
	if(lenght==0) flag=1;
	lenght=temp_lenght;
	if(flag==1){
		while(lenght>0){
			if(map[t_c1][t_c2]>=97 && map[t_c1][t_c2]<=122 ) map[t_c1][t_c2] -=  32;
			t_c1--;
			t_c2--;
			lenght--;
		}
	}	
}
void sol_capraz_bas(char map[][DICT_SIZE],char word[],int c1,int c2){
	int k=0,flag=0;
	int t_c1=c1;
	int t_c2=c2;
	while(word[k]!=0){ 
		if(word[k]==map[c1][c2] || word[k]- 32 ==map[c1][c2]){
			c1++;
			c2--;
		}
		else break;
		k++;
	}
	if(word[k]==0) flag=1;
	k=0;
	if(flag==1){
		while(word[k]!=0){
			if(map[t_c1][t_c2]>=97 && map[t_c1][t_c2]<=122 ) map[t_c1][t_c2] -=  32;
			t_c1++;
			t_c2--;
			k++;
		}
	}		
}
void sol_capraz_son(char map[][DICT_SIZE],char word[],int c1,int c2){
	int k=0,flag=0;
	int t_c1=c1;
	int t_c2=c2;
	int lenght=0,temp_lenght=0;
	while(word[k]!=0){
		k++;
		lenght++;
		temp_lenght++;
	}
	while(lenght>0){ 
		if(word[lenght-1]==map[c1][c2] || word[lenght-1]- 32 ==map[c1][c2]){
			c1--;
			c2++;
		}
		else break;
		lenght--;
	}
	if(lenght==0) flag=1;
	lenght=temp_lenght;
	if(flag==1){
		while(lenght>0){
			if(map[t_c1][t_c2]>=97 && map[t_c1][t_c2]<=122 ) map[t_c1][t_c2] -=  32;
			t_c1--;
			t_c2++;
			lenght--;
		}
	}	
}
void find_word(char map[][DICT_SIZE],char *dict[DICT_SIZE]){
	char word[WORD_LEN],reverse_word[WORD_LEN];
	int c1,c2;
	int i=0,j=0,lenght=0,finish=0,up_letter=0,temp_up_letter,count=0;
	temp_up_letter=uppercase_letter(map);
	printf("Enter the 'exit' to finish\n");
	/*The program asks for words until the user has typed exit
		and all words in the map are entered*/
	while(finish!=1 && count<DICT_SIZE){
		printf("Enter the word:");
		scanf("%s",word);
		i=0;
		if(word[i]=='e' && word[i+1]=='x' && word[i+2]=='i' && word[i+3]=='t') finish=1;
		if(finish!=1){
			printf("Enter the coord:");
			scanf("%d%d",&c1,&c2);

			i=0;
			while(word[i]!=0){
				lenght++;
				i++;
			}
			for(i=0;i<WORD_LEN;i++){
				reverse_word[i] = word[lenght-1];
				lenght--;
			}
			/*The entered words are sent to the following functions,
			 and the function is fullfilled*/
			sag_bas(map,word,c1,c2);
			sag_son(map,word,c1,c2);
			sag_bas(map,reverse_word,c1,c2);
			sag_son(map,reverse_word,c1,c2);

			asagi_bas(map,word,c1,c2);
			asagi_son(map,word,c1,c2);
			asagi_bas(map,reverse_word,c1,c2);
			asagi_son(map,reverse_word,c1,c2);

			sag_capraz_bas(map,word,c1,c2);
			sag_capraz_son(map,word,c1,c2);
			sag_capraz_bas(map,reverse_word,c1,c2);
			sag_capraz_son(map,reverse_word,c1,c2);

			sol_capraz_bas(map,word,c1,c2);
			sol_capraz_son(map,word,c1,c2);
			sol_capraz_bas(map,reverse_word,c1,c2);
			sol_capraz_son(map,reverse_word,c1,c2);
		

			printf("\n");
			/*After each word entry the map is shown on the screen*/
			print_random_map(map);
			printf("\n");
			/*After each word entry,the number of capital letters
			on the map is checked */
			up_letter=uppercase_letter(map);
			if(up_letter!=temp_up_letter){
				temp_up_letter=up_letter;
				count++;
			}
			if(count==DICT_SIZE) printf("Congratulations you're done !!!\n");
		}
	}

}

void united_map(char map[][DICT_SIZE],int coord[][4],char *dict [DICT_SIZE]){
	int i=0,j=0,k=0,temp;
	int x1,y1,x2,y2;
	for(i=0;i<DICT_SIZE;i++){
		/*Coordinates are assigned from coord array*/
		x1=coord[i][k];
		y1=coord[i][k+1];
		x2=coord[i][k+2];
		y2=coord[i][k+3];

		if(x1==x2){ 
			/*Words in dict array are printed to the right
			in map*/
			if(y1<y2){
					while(y1!=y2+1){
						map[x1][y1]=dict[i][j];
						y1++;
						j++;
				}			
			}
			/*Words in dict array are printed to the left
			in map*/
			else if(y1>y2){ 
					while(y1!=y2-1){
						map[x1][y1]=dict[i][j];
						y1--;
						j++;
				}			
			}
		}
		else if(y1==y2){ 
			/*Words in dict array are printed to the down
			in map*/
			if(x1<x2){ 
				while(x1!=x2+1){
					map[x1][y1]=dict[i][j];
					j++;
					x1++;
				}
			}
			else if(x1>x2){
			/*Words in dict array are printed to the up
			in map*/
					while(x1!=x2-1){
					map[x1][y1]=dict[i][j];
					j++;
					x1--;
				}
			}	
		}
		else if(x1<x2 && y1<y2){
			/*Words in the dict array are printed in
			the right-down direction in map*/
			while(x1!=x2+1){
				map[x1][y1]=dict[i][j];
				x1++;
				y1++;
				j++;
			}
		}
		else if(x1>x2 && y1>y2){
			/*Words in the dict array are printed in
			the left-up direction in map*/
			while(x1!=x2-1){
				map[x1][y1]=dict[i][j];
				x1--;
				y1--;
				j++;
			}
		}
		else if(x1<x2 && y1>y2){
			/*Words in the dict array are printed in
			the left-down direction in map*/
			while(x1!=x2+1){
				map[x1][y1]=dict[i][j];
				x1++;
				y1--;
				j++;
			}
		}
		else if(x1>x2 && y1<y2){
			/*Words in the dict array are printed in
			the right-up direction in map*/
			while(x1!=x2-1){
				map[x1][y1]=dict[i][j];
				x1--;
				y1++;
				j++;
			}
		}
		j=0;
	}
}
void print_random_map(char map[][DICT_SIZE]){
	int i,j;
	/*Random map is printed on the screen*/
	for(i=0;i<DICT_SIZE;i++){
		for(j=0;j<DICT_SIZE;j++){
			printf("%c ",map[i][j]);
		}
		printf("\n");
	}
}

void random_map(char map[][DICT_SIZE]){
	int i,j;
	/*Random character are generated for random map*/
	for(i=0;i<DICT_SIZE;i++){
		for(j=0;j<DICT_SIZE;j++){
			map[i][j]=97+rand()%26;
		}
	}
}

int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
    char *ch_iter = line;
    // go until you see new line
    while(*ch_iter != '\n' && *ch_iter != 13) {
        ch_iter++; // next char

    }
    *ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}

int main(){
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];    
    char line[LINE_LEN];
	FILE *fp = fopen("word_hunter.dat", "r");

	char map[DICT_SIZE][DICT_SIZE];
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);
	//print_dictionary(dict);
	//print_coord(coord);
	
	// WRITE HERE...
	srand(time(NULL));
	printf("Puzzle Game!\n");
	/*First random map is produced*/
	random_map(map);
	/*Then words are placed*/
	united_map(map,coord,dict);
	printf("\n");
	/*Then the map is shown on the display*/
	print_random_map(map);
	/*Then the puzzle game is started*/
	find_word(map,dict);
	return 0;
}