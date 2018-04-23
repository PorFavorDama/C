int clearStdin(void){
    int c;
    while(c = getchar() != '\n' && c != EOF);
}
