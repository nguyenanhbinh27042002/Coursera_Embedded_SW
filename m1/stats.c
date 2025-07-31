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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
void printf_array(unsigned char data[], int length)
{
  for(int i = 0; i < length ; i++)
  {
    printf("%d\t",data[i]);
  };
  printf("\n");
};

unsigned char find_maximum(unsigned char data[], int length)
{
  unsigned char max = data[0];
  for(int  i = 0; i < length ; i++)
  {
    if(data[i] > max)
    {
      max = data[i];
    }
  }
  return max;
};

unsigned char find_minimum(unsigned char data[], int length)
{
  unsigned char min = data[0];
  for(int i = 0; i < length ; i++)
  {
    if(data[i] < min)
    {
      min = data[0];
    }
  }
  return min;
};

void sort_array(unsigned char data[], int length)
{ 
  unsigned char temp;
  for(int i = 0; i < length-1 ; i++)
  {
    for(int j = i+1; j< length; j++)
    {
      temp = data[i];
      data[i] = data[j];
      data[j] = temp;
    }
  }
};

unsigned char find_median(unsigned char data[], int length)
{
  unsigned char temp[SIZE];
  for(int i = 0; i < length; i++)
  {
    temp[i] = data[i];
  }
  sort_array(temp,length);
  if(length %2 == 0)
  {
    return((temp[length/2]-1) + temp[length/2]);
  }
  else
  {
    return (temp[length/2]);
  }
};

unsigned char find_mean(unsigned char data[], int length)
{
  int sum = 0;
  for(int i = 0; i < length; i++)
  {
    sum += data[i];
  }
  return (unsigned char)(sum/length);
};

void printf_statistic(unsigned char data[], int length)
{
  unsigned char min =  find_minimum(data,length);
  unsigned char max = find_maximum(data,length);
  unsigned char mean = find_mean(data,length);
  unsigned char medium = find_median(data,length);
  printf("Statistic \n");
  printf("Max:%u\n",max);
  printf("Min:%u\n",min);
  printf("Mean:%u\n",mean);
  printf("Medium:%u\n",medium);
};

void main() 
{

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */;
  printf("Original\n");
  printf_array(test,SIZE);
  printf_statistic(test,SIZE);
};

/* Add other Implementation File Code Here */
