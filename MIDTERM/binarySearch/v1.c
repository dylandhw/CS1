/*This is optimal if our array isn't sorted as we don't know where
the value might be.
Runtime is O(n) best case: O(1)*/
int linearSearch(int array[], int len, int value){
    for(int i = 0; i < len; i++){
        if(array[i] == value){
            return 1;
        }
    }
}

/*If array is sorted
after k steps, the search space is no bigger than
n/2^k
so worst case is O(log2n)*/
int binarySearch(int list[], int item, int len){
    int l = 0; h = len - 1;
    int mid;
    while(l <= h){
        mid = (l+h)/2;

        if(list[mid] == item){
            return mid;
        } else if (list[mid] < item){
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
}

    

/*Sorted list matching problem
this is of runtime O(n*n) or O(n^2)
because we are looping through n items twice if(length is the same)
can use binary search to make this faster... can use binary search on step a so it is
now: O(nlogn)*/
void printMatches(int list1[], int list2[], int len1, int len2){
    int i, j;
    for(i = 0; i < len1; i++){
        for(j = 0; j < len2; j++){
            if(list1[i] == list2[j]){
                printf("Match: %d", list1[i]);
                break;
            }
        }
    }
}

/*O(n)*/
void slmpLinear(int list1[], int n, int list2[], int m){
    int i = 0, j =0;
    while(i < n && j < m){
        if(list1[i] < list2[j]){
            i++;
        } else if (list2[j] < list1[i]){
            j++;
        } else {
            printf("%d", list1[i]);
            i++;
            j++:
        }
    }
}