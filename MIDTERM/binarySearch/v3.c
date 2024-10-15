int binarySearchRecursive(int *values, int low, int high, int searchval){
    int mid;
    if(low <= high){
        mid = (low+high)/2;
        if(searchval < values[mid]){
            return binarySearchRecursive(values, low, mid-1, searchval);
        } else if (searchval > values[mid]){
            return binarySearchRecursive(values, mid + 1, high, searchval);
        } else {
            return 1;
        }
    }
}