float** AllocateArrayOfArrays(int P, int *lengths){
    float** array = (float**)malloc(sizeof(float*)*P);

    int i, j;
    for(i = 0; i < P; i++){
        array[i] = (float**)malloc(sizeof(float)*lengths[i]);
        for(j = 0; j < lengths[i]; j++){
            array[i][j] = rand()%100;
        }
    }
    return array; 
}
void free(myArrays){
    for(int i = 0; i < P; i++){
        free(myArrays[i]);
    }
    free(myArrays);
}


Employee *makeArray(char **firstNames, char **lastNames, int *IDs, int n){
    int i;
    Employee *array = (Employee*)malloc(n * sizeof(Employee));

    for(int i = 0; i < n; i++){
        array[i].first = malloc((strlen(firstNames[i])+1)*sizeof(char));
        array[i].last = malloc((strlen(firstNames[i])+1)*sizeof(char));

        strcpy(array[i].first, firstNames[i]);
        strcpy(array[i].lastm, lastNames[i]);

        array[i].ID = IDs[i];
    }
    return array; 
}
void freeEmployee(Employee *array, int n){
    for(int i =0 ; i < n; i++){
        free(array[i].first);
        free(array[i].last);
    }
    free(array);
}

struct Student* AllocateStudents(int N, int Q){
    struct Students *ptr;
    ptr = (struct Student*)malloc(N * sizeof(Student));

    for(int i = 0; i < N; i++){
        scanf("%d", &ptr[i].student_id);
        ptr[i].quizzes = (float*)malloc(Q * sizeof(float));
        for(int j = 0; j < Q; j++){
            scanf("%d", &ptr[i].quizzes[j]);
        }
    }
    return ptr;
}

void freeStudents(struct Students *s, n){       
    for(int i = 0; i < n; i++){
        free(s[i].quizzes);
    }
    free(s);
}

Student** AllocateCourses(int C, int N, int Q){
    Student** courseStudent = (Student**)malloc(C * sizeof(Student*));
    for(int i = 0; i < C; i++){
        courseStudent[i] = (Student*)malloc(N * sizeof(Student));
        for(int j = 0; j < N; j++){
            courseStudent[i][j].quizzes = (float*)malloc(Q * sizeof(float));
        }
    }
    return courseStudent; 
}

void freeCourseStudents(struct Student** st, int NOC, int NOS){
    for(int i = 0; i < NOC; i++){
        for(int j = 0; j < NOS; i++){
            free(st[i][j].quizzes);
        }
        free(st[i]);
    }
    free(st);
}