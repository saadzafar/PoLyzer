/**
 * @file Polygon.c
 * @brief function implementations for Polygon.h
 * 
 * @author Saad Bin Zafar
 * @version 3.0 05/21/14
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "Polygon.h"

Polygon * plg_new(double * xCor, double * yCor, int numOfVert)
{
     int i;
     Polygon * newPol = (Polygon *) malloc(sizeof(Polygon));
	 newPol->numberOfVertices = numOfVert;
	 
	 newPol->xCoordinates = malloc(sizeof(double) * (numOfVert + 1));
	 newPol->yCoordinates = malloc(sizeof(double) * (numOfVert + 1));
	 
	 for (i = 0; i < newPol->numberOfVertices; i++)
	 {
	      newPol->xCoordinates[i] = xCor[i];
		  newPol->yCoordinates[i] = yCor[i];
	 }
	 
	 return newPol;
}

void pol_delete (Polygon * pol)
{
     if (pol != NULL)
	 {
	      if (pol->xCoordinates != NULL)
		  {
		       free(pol->xCoordinates);
		  }
		  
		  if (pol->yCoordinates != NULL)
		  {
		       free(pol->yCoordinates);
		  }
		  free(pol);
		  printf("Polygon successfully deleted from memory\n");
	  }
	  else (printf("No polygon to delete!\n"));
}

Polygon * plg_read(FILE * plgData)
{
     Polygon * newPlg = (Polygon *) malloc(sizeof(Polygon));
	 double x, y;
	 int v = 0;
	 int i;
	 while (fscanf(plgData, "%lf %lf", &x, &y) == 2)
	 {
	      v++;
	 }
	 
	 newPlg->numberOfVertices = v;
	 newPlg->xCoordinates = malloc(sizeof(double) * v);
	 newPlg->yCoordinates = malloc(sizeof(double) * v);
	 
	 fseek(plgData, 0, SEEK_SET);
	 
	 for (i = 0; i < v; i++)
	 {
	      fscanf(plgData, "%lf %lf", &(newPlg->xCoordinates[i]), &(newPlg->yCoordinates[i]));
	 }
	 
	 fclose(plgData);
	 
	 return newPlg;
}

void plg_write(Polygon * pol, FILE * plgData)
{
     int i;
     printf("Please enter name of file to save to (INCLUDE FILE EXTENSION): ");
	 scanf("%s", &pol->f_name);
	 printf("\n");
	 fflush(stdin);
     plgData = fopen(pol->f_name, "w");
	 for (i = 0; i < pol->numberOfVertices; i++)
	 {
	      fprintf(plgData, "%lf %lf\n", pol->xCoordinates[i], pol->yCoordinates[i]);
	 }
	 printf("Polygon coordinates successfully printed to file\n\n");
}


double plg_getArea(Polygon * pol)
{
     int sumx;
	 int sumy;
	 int i;
	 double area;
	 double temp_Area;
	 double temp_x = 0;
	 double temp_y = 0;
	 
	 if(pol != NULL)
	 {
	 
          for (i = 0; i < (pol->numberOfVertices); i++)
	      {
               temp_x = temp_x + ((pol->xCoordinates[i]) * (pol->yCoordinates[i+1]));
		       temp_y = temp_y + ((pol->yCoordinates[i]) * (pol->xCoordinates[i+1]));
	      }
		  
	      temp_Area = ((temp_x)+(temp_y));
	      area = ((temp_Area)/2);
		  return area;
	 }
	 else printf("No Polygon coordinates found!");
	 return 0;	     
}

void plg_vertShift(Polygon * pol)
{
     int i;
	 double shift_y;

     printf("Enter the amount of vertical shift: ");
	 scanf("%lf", &shift_y);
	 printf("\n");
	 printf("----------------------------\n");
     for (i = 0; i < pol->numberOfVertices; i++)
	 {
	      pol->yCoordinates[i] = pol->yCoordinates[i] + shift_y;
		  printf("%0.2f, %0.2f\n", pol->xCoordinates[i], pol->yCoordinates[i]);
	 }
	 printf("----------------------------\n\n");
}

void plg_horizShift(Polygon * pol)
{
     int i;
	 double shift_x;

     printf("Enter the amount of horizontal shift: ");
	 scanf("%lf", &shift_x);
	 printf("\n");
	 printf("----------------------------\n");
     for (i = 0; i < pol->numberOfVertices; i++)
	 {
	      pol->xCoordinates[i] = pol->xCoordinates[i] + shift_x;
		  printf("%0.2f, %0.2f\n", pol->xCoordinates[i], pol->yCoordinates[i]);
	 }
	 printf("----------------------------\n\n");
}
void plg_isClosed(Polygon * pol)
{
     if ((pol->xCoordinates[0] == pol->xCoordinates[pol->numberOfVertices - 1]) && (pol->yCoordinates[0] == pol->yCoordinates[pol->numberOfVertices - 1]))
	 {
	      printf("Polygon is closed\n\n");
	 }
	 else
	 {
	      printf("Polygon is OPEN!!\n\n");
	 }
}

