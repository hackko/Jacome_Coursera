/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief eight functions 
 *
 * analyze an array of unsigned char data items and report analytics on the maximum, minimum, mean, and median of the data set.
 *
 * @author Ivan JAcome
 * @date 03  12  19
 *
 */



#include <stdio.h>
#include "stats.h"
#include <stdint.h>

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
	printf ("test array : \n");	
	print_array (test, SIZE);
	print_statistics (test, SIZE);



}

/* Add other Implementation File Code Here */

void print_statistics (unsigned char *array, unsigned int length){

	printf("sorted array: \n");
	sort_array(array, length);
	printf ("stadisticas relacionadas con el test son las siguientes: \n");
	printf ("median = %d \r\n", find_median(array, length));
	printf ("mean = %d \r\n" , find_mean(array,length));
	printf("maximum = %d\r\n", find_maximum(array,length));
	printf("minimum = %d \r\n ", find_minimum (array, length));


}

void print_array(unsigned char *array, unsigned int length ){
	int i;
	for (i = 0; i < length; i++){
		printf("array[%d] = %d \r\n ", i , (int)array[i]);

	}
}

int find_median (unsigned char *array, unsigned int length ){
	unsigned int i,j;
	float temp;
	for (i=0; i<length; i++){
		for (j=i+1; j < length; j++){
			if (array[i] > array[j]){
				temp = (int)array[j];
				array[j]=(int)array[i];
				array[i] = temp;
			}
		}
	}

	if (length % 2 == 0){
		return ((int)array[length/2] + (int)array[length/2 -1]) /2;

	}else{
		return (int)array[length/2];
	}

}


int find_mean (unsigned char *array, unsigned int length ){
		int sum = 0 , i;
		for (i=0;i<length;i++){
			sum+=(int)array[i];
		}
		return ((float)sum/length);
}

int find_maximum (unsigned char *array, unsigned int length ){
	int max, index;

	/*Asumimos el primer elemento del array como maximo */
       max = (int)array[0];
	index = 0;

	for (index = 1; index < length ; ++index){
		if (array[index] > max){
			max = (int)array[index];
		}
	}
	return max;

}

int find_minimum (unsigned char *array, unsigned int length ){
	int min, index;
	/* Asumimos que es el primer elemento del array es el minimo */
	min = (int)array[0];
	index = 0;

	for (index = 1; index < length; ++index){
		if (array[index] < min){
			min = (int)array[index];
		}
	}
	return min;
}

void sort_array (unsigned char *array, unsigned int length){
	int i,j;
	int temp;

	for (i=0; i< length; i++){
		for (j= i+1;j <length; j++){
			if (array[i] < array[j]){
				temp = (int)array[j];
				array[j] = (int)array[i];
				array[i] = temp;
			}
		}
		printf ("array[%d] = %d\r\n ",i, (int)array[i]);	
	}
}
