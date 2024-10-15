void push(int value){
    if(top >= size - 1){
        return full;
    } else {
        stack[++top] = value;
    }
    return success;
}

int pop(){
    if(top < 0){
        return empty;
    } else {
        return stack[top--];
    }
}