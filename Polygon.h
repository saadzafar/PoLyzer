/**
 * @file polygon.h
 * @brief ADT containing function prototypes for Polygon
 * 
 * @author Saad Bin Zafar
 * @version 3.0 05/21/14
 */

#ifndef POLYGON
#define POLYGON
#endif

/*Function Prototypes*/

/**
 * Polygon complex data type
 * which stores the attributes of a Polygon
 */
typedef struct
{
     char f_name[20];
     double * xCoordinates;
	 double * yCoordinates;
	 int numberOfVertices;
}Polygon;

/**
 * plg_new creates a new Polygon with malloc.
 * Initialize all ADT data members with its parameter values
 * and returns Polygon.
 * @param xCor - a dynamic array for the x coordinates of the points in a Polygon.
 * @param yCor - a dynamic array for the y coordinates of the points in a Polygon.
 * @param numOfVert - an integer storing the number of points in the Polygon.
 * @return a pointer of the new Polygon created.
 */
Polygon * plg_new(double * xCor, double * yCor, int numOfVert);

/**
 * plg_delete Frees the memory allocated to the Polygon passed into this function.
 * @param pol - a Polygon structure pointer.
 */
void plg_delete(Polygon * pol);

/**
 * plg_read accepts a Polygon and a file pointer as parameters.
 * reads the polygon point data from the file and passes the data to plg_new.
 * @param pol pointer to Polygon.
 * @param plgData File * to a file plgData open for reading
 * @return a pointer of the new polygon created from file
 */
Polygon * plg_read(FILE * plgData);

/**
 * plg_write saves Polygon points to a file.
 * @param plgData File * to a file plgData open for writing.
 * @param pol - a Polygon structure pointer.
 */ 
void plg_write(Polygon * pol, FILE * plgData);

/**.
 * Calculates and returns the area of the Polygon.
 * @param pol - a Polygon structure.
 * @return a double - area of the Polygon.
 */
double plg_getArea(Polygon * pol);

/**
 * plg_vertShift shifts the vertices of the Polygon vertically
 * (along the y-axis)
 * @param pol - a Polygon structure.
 */
void plg_vertShift(Polygon * pol);

/**
 * plg_horizShift shifts the vertices of the Polygon horizontally
 * (along the x-axis)
 * @param pol - a Polygon structure.
 */
void plg_horizShift(Polygon * pol);

/**
 * plg_isClosed checks if the Polygon is closed
 * by checking if the first coordinate matches the last one.
 * Prints the result to screen.
 * @param pol - a Polygon structure..
 */
void plg_isClosed(Polygon * pol);



