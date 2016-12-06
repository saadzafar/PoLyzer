/**
 * @file polyAnalyzer.c
 * @brief program to read, calculate and print area of a polygon from its coordinates
 * 
 * @author Saad Bin Zafar
 * @version 4.0 05/21/14
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "Polygon.h"

int main()
{
     FILE * plgData; /*pointer to point to text file for reading polygon coordinates*/
	 Polygon *Poly; /*pointer to point to created Polygon variable*/
	 char file_Name[20]; /*array to store name of text file to be opened*/
	 int button; /*store the value for the user selection in the switch-case menu*/
	 int i; /*variable to iterate while reading polygon from file*/
	 float shift_x;
	 float shift_y;
	 
	 do
	 {
	      printf("***********MENU***********\n--------------------------\n");
	  	  printf("Press 1 to read Polygon from file\n");
	  	  printf("Press 2 to calculate the area of the Polygon\n");
	  	  printf("Press 3 to print the coordinates of the Polygon\n");
		  printf("Press 4 to vertically shift polygon\n");
		  printf("Press 5 to horizontally shift polygon\n");
		  printf("Press 6 to exit the program\n\n\n");
		  button = getch();
		  switch (button)
		  {
		       case '1':
	                printf("REMEMBER TO ENTER THE FILE EXTENSION\nPlease enter the file name: ");
	                gets(file_Name);
	                if ((plgData = fopen(file_Name, "r")) == NULL)
					{
					     printf("\nThe file contains no values or does not exist!\n\n");
				    }
					else
					{
					     printf("\nThe file has successfully been opened\n\n");
				         Poly = plg_read(plgData);
					     printf("Polygon coordinates successfully read from file!\n\n");
						 plg_isClosed(Poly);
						 printf("The Polygon has %i vertices\n", (Poly->numberOfVertices - 1));
						 printf("----------------------------\n");
						 for (i = 0; i < Poly->numberOfVertices ; i++)
						 {
			
							  printf("%0.2f, %0.2f\n", Poly->xCoordinates[i], Poly->yCoordinates[i]);
						 }
						 printf("----------------------------\n\n");
				    }
			   break;
			   case '2':
			        printf("The area of the polygon is: ");
	                printf("%lf\n\n", plg_getArea(Poly));
			   break;
			   case '3':
	                plg_write(Poly, plgData);
			   break;
			   case '4':
			        plg_horizShift(Poly);
			   break;
			   case '5':
			        plg_horizShift(Poly);
			   break;
			   case '6':	
					pol_delete(Poly);
					printf("Thank you for using the program\nGOOD BYE!\n");
					fflush(stdin);
					return 0;
			   break;
		  }
	  }
	  while (button != '6');
	  
	  
	 getch();
	 return 0;
	 
}

