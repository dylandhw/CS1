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