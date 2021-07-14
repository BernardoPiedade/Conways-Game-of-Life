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

	sleep(1);
}

int** checkCells(int** arr, int** arr2, int width, int height){
	
	for(size_t i = 0; i < width; i++){
		for(size_t j = 0; j < height; j++){
			
			int neighbours = 0;

			//top corner left
			if(i == 0 && j == 0){
				arr2[i][j] = 0;

			}

			//bot corner right
			else if(i == (height - 1) && j == (width - 1)){
				arr2[i][j] = 0;

			}

			//top corner right
			else if(i == 0 && j == (width - 1)){
				arr2[i][j] = 0;

			}

			//bot corner left
			else if(i == (height - 1) && j == 0){
				arr2[i][j] = 0;

			}

			//wall left
			else if((i > 0 && i < (height - 1)) && j == 0){
				arr2[i][j] = 0;

			}

			//wall right
			else if((i > 0 && i < (height - 1)) && j == (width - 1)){
				arr2[i][j] = 0;

			}

			//wall top
			else if((j > 0 && j < (width - 1)) && i == 0){
				arr2[i][j] = 0;

			}

			//wall bot
			else if((j > 0 && j < (width - 1)) && i == (height - 1)){
				arr2[i][j] = 0;

			}

			//other cells
			else if((i > 0 && i < (height - 1)) && (j > 0 && j < (width - 1))){

				if(arr[i][j] == 1){
					
					if(arr[i-1][j] == 1){
						neighbours++;
					}

					if(arr[i-1][j+1] == 1){
						neighbours++;
					}

					if(arr[i][j+1] == 1){
						neighbours++;
					}

					if(arr[i+1][j+1] == 1){
						neighbours++;
					}

					if(arr[i+1][j] == 1){
						neighbours++;
					}

					if(arr[i+1][j-1] == 1){
						neighbours++;
					}

					if(arr[i][j-1] == 1){
						neighbours++;
					}

					if(arr[i-1][j-1] == 1){
						neighbours++;
					}

					if(neighbours < 2 || neighbours > 3){
						arr2[i][j] = 0;
					}

	

				}
				else if(arr[i][j] == 0){

					if(arr[i-1][j] == 1){
						neighbours++;
					}

					if(arr[i-1][j+1] == 1){
						neighbours++;
					}

					if(arr[i][j+1] == 1){
						neighbours++;
					}

					if(arr[i+1][j+1] == 1){
						neighbours++;
					}

					if(arr[i+1][j] == 1){
						neighbours++;
					}

					if(arr[i+1][j-1] == 1){
						neighbours++;
					}

					if(arr[i][j-1] == 1){
						neighbours++;
					}

					if(arr[i-1][j-1] == 1){
						neighbours++;
					}

					if(neighbours == 3){
						arr2[i][j] = 1;
					}


				}
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
		
	}

	return 0;
}
