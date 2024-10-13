Employee* createEmployee(char names[][50], double *salaries, int empCount){
    Employee *employees = malloc(empCount * sizeof(Employee)); /*Allocates memory for the array of employees*/

    for(int i = 0; i < empCount; i++){
        employees[i].ename = malloc(sizeof(StringType)); /*Allocates memory for the name*/
        int length = strlen(names[i]+1); /*Takes length of name + 1 for null terminator*/

        employees[i].ename->string = malloc(length * sizeof(char)); /*Allocates specific amount of space needed for each name*/
        strcpy(employees[i].ename->string, names[i]); /*Copies the name into the employee name*/

        employees[i].ename->length = length - 1; /*Adjusts the length*/

        employees[i].salary = salaries[i]; /*Copies salaries*/
    }
    return employees; /*Returns a pointer to the array of employee structs*/
}
