#ifndef STRUCTSABM_H_INCLUDED
#define STRUCTSABM_H_INCLUDED

typedef struct
{
    int id;
    /*char name[51];
    char lastName[51];
    float salary;
    int sector;*/
    int isEmpty;

}structure;



/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list structure array of '_'
 * \param len int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_init(structure array[], int len);


/** \brief sets the next id for the array
 * \param list structure array of '_'
 * \param len int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_setId(structure array[], int len);


/** \brief sets the next id for the array
 * \param liststructure array of '_'
 * \param len int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_add(structure array[], int len);


/** \brief sets the next id for the array
 * \param array structure array of '_'
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_modify(structure array[], int len);


/** \brief finds an structure by id
 * \param array structure array of '_'
 * \param len int Array length
 * \param id int structure id
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_findById(structure array[] , int len, int id);


/** \brief removes an structure by id
 * \param array structure array of '_'
 * \param len int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_remove(structure array[], int len);


/** \brief sorts Array by the chosen order
 * \param listEmployees Employee array of employees
 * \param len int Array length
 * \param order int chosen order
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_sort(structure array[] , int len, int order);


/** \brief prints a list of '_' in ascended order
 * \param array structure array of '_'
 * \param len int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_print(structure array[] , int len);


/** \brief prints a sorted list of '_'
 * \param array structure array of '_'
 * \param len int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_printSorted(structure array[] , int len);


/** \brief prints an '_' by id
 * \param array structure array of '_'
 * \param len int Array length
 * \param id int structure id
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_printOne(structure array[] ,int len, int id);


/** \brief looks for the closest empty space
 * \param list structure array of '_'
 * \param len int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int search_closestEmptySpace(structure array[] ,int len);


/** \brief calculates the total salary, the average salary and prints all of the structure spaces that have a salary above the average
 * \param list structure array of '_'
 * \param len int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int structure_averageSalary(structure array[], int len);

#endif
