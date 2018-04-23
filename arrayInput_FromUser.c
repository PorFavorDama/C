/*
* Gets specified size from the user
* If you will need to read more data then toggle the buffer size.
*/
int* getArray(int size){
    char* buffer = malloc(200*sizeof(char));
    int* array = malloc(size*sizeof(int));
    char* endptr;
    int loopFlag = 0;
    printf("*********************************************************\n");
    printf("* Type in your array with only \'one\' space between numbers!\n");
    printf("* For example: 1 2 3 87 52 21(then hit enter)\n");
    printf("********************************************************\n");
    printf("Type in your array: ");
    while(fgets(buffer,200,stdin)){
        for(int i = 0; i < size; i++){
            if(!(array[i] = (int) strtol(buffer,&endptr,10)) || endptr == buffer || *endptr != ' ' && *endptr != '\n'){
                loopFlag = 1;
                break;
            }else{
                buffer = endptr+1;
            }
        }
        if(loopFlag) {
            loopFlag = 0;
            printf("You've typed something wrong!\n");
            printf("Please try again: ");
            continue;
        }
        break;
    }
    return array;
}
