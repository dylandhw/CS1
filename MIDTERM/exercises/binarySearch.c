/*Binary Search*/

int binarySearch(int list[], int item, int len){
    int l = 0; h = len - 1; /*Sets low to start of array and high to the end*/
    int mid;
    while(l <= h){ /*While low is less than high*/
        mid = (l + h)/2; /*Split array down the middle*/
        if(list[mid] == item){ /*Check if the middle is the searching item*/
            return mid;
        }
        if(list[mid] < item){ /*If middle is less than the item, we can completely disregard the left side*/
            l = mid + 1;
        } else {
            h = mid - 1; /*If mid is greater than the left side, we can completely disregard the right side*/
        }
    }
    return -1;
}

/*Binary Search via recursion*/
int BSR(int list[], int item, int l, int h){
    if(l > h){
        return;
    }
    int mid = (l+h)/2;

    if(list[mid] = item){
        return mid;
    }
    if(list[mid] < item){
        return BSR(int list[], int item, mid+1, h);
    }

    returnBSR(int list[], int item, int l, mid-1);
}