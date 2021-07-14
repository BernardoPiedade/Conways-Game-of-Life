#include <iostream>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void draw(int** arr, int width, int height){

	for(int n = 0; n < 10; n++){
		std::cout << "\n\n";
	}

	std::cout << "--------------------------------------------------------------------------------------" << std::endl;

	for(size_t i = 0; i < height; i++){
		for(size_t j = 0; j < width; j++){
			if(arr[i][j] == 0){
				std::cout << " ";
			}
			else if(arr[i][j] == 1){
				std::cout << "*";
			}
		}
		std::cout << std::endl;
	}
}

int countNeighbours(int** arr, int x, int y){

	int sum = 0;
	
	for(size_t i = -1; i < 2; i++){
		for(size_t j = -1; j < 2; j++){
			sum += arr[x + i][y + j];
		}
	}
	sum -= arr[x][y];
	return sum;
}

int** checkCells(int** arr, int** arr2, int width, int height){
	
	for(size_t i = 0; i < height; i++){
		for(size_t j = 0; j < width; j++){
			
			int neighbours = 0;

			//top corner left
			if(i == 0 && j == 0){
				arr2[i][j] = 0;
				continue;
			}

			//bot corner right
			if(i == (height - 1) && j == (width - 1)){
				arr2[i][j] = 0;
				continue;
			}

			//top corner right
			if(i == 0 && j == (width - 1)){
				arr2[i][j] = 0;
				continue;
			}

			//bot corner left
			if(i == (height - 1) && j == 0){
				arr2[i][j] = 0;
				continue;
			}

			//wall left
			if((i > 0 && i < (height - 1)) && j == 0){
				arr2[i][j] = 0;
				continue;
			}

			//wall right
			if((i > 0 && i < (height - 1)) && j == (width - 1)){
				arr2[i][j] = 0;
				continue;
			}

			//wall top
			if((j > 0 && j < (width - 1)) && i == 0){
				arr2[i][j] = 0;
				continue;
			}

			//wall bot
			if((j > 0 && j < (width - 1)) && i == (height - 1)){
				arr2[i][j] = 0;
				continue;
			}

			//other cells
			neighbours = countNeighbours(arr, i, j);

			if(arr[i][j] == 0 && neighbours == 3){
				arr2[i][j] = 1;
			}else if(arr[i][j] == 1 && (neighbours < 2 || neighbours > 3)){
				arr2[i][j] = 0;
			}else{
				arr2[i][j] = arr[i][j];
			}
			
		}
	}

	return arr2;

}


int** fillArray(int width, int height){
	
	int** arr = 0;
	arr = new int*[height];

	for(size_t i = 0; i < height; i++){
		
		arr[i] = new int[width];

		for(size_t j = 0; j < width; j++){
			arr[i][j] = rand() % 2 + 0;
		}
	}	

	return arr;
}

int main(){

	int width = 100;
	int height = 30;

	int** arr = fillArray(width, height);
	
	int** arr2 = fillArray(width, height);

	while(true){
		
		arr = checkCells(arr, arr2, width, height);
		
		draw(arr, width, height);
	
		sleep(1);	
	}

	return 0;
}
