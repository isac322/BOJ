main(int c) {
    c = getchar();
    if (c!=-1) {
        putchar(c);
        main(c);
    }
}