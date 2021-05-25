#include "utilities.h"

#ifdef __gnu_linux__

char getChar() {

    char character = 0;
    struct termios old = {0};

    if(tcgetattr(0, &old)<0) {
        perror("tcsetattr()");
    }

    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;

    if(tcsetattr(0, TCSANOW, &old)<0) {
        perror("tcsetattr ICANON");
    }

    if(read(0,&character,1)<0) {
        perror("read()");
    }

    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;

    if(tcsetattr(0, TCSADRAIN, &old)<0) {
        perror ("tcsetattr ~ICANON");
    }

    return character;
}

#else

/**
 * @brief Lê um único caractere do teclado (stdin)
 *
 * @return char caractere lido
 * @pre buffer de escrita ne tela (stdout) limpo
 * @post stdin limpo
 */
char getChar() {

    DWORD mode, cc;
    HANDLE h = GetStdHandle( STD_INPUT_HANDLE );

    if (h == NULL) {
        return 0; // console not found
    }

    GetConsoleMode( h, &mode );
    SetConsoleMode( h, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT) );
    TCHAR c = 0;
    ReadConsole( h, &c, 1, &cc, NULL );
    SetConsoleMode( h, mode );
    return c;
}

#endif

int confirm() {
    printf("Opa chefia quer fazer isso msm? [S/n]\n");
    return getChar() != 'n';
}

void printHead(const char *message) {
    system(CLEAR);
    printLine();
    printAlignedCenter(message);
    printLine();
}

void printAlignedRight(const char *message) {
    printf("|%s", message);
    // -2 por causa dos |
    printExtended(' ', SIZE_LINE - strlen(message) - 2);
    printf("|\n");
}

void printAlignedCenter(const char *message) {
    int sizeRead = (strlen(message) + 2);
    int space = (SIZE_LINE - sizeRead) / 2;
    printf("|");
    printExtended(' ', space);
    printf("%s", message);
    printExtended(' ', space);
    if (!(sizeRead % 2)) {
        printf(" ");
    }
    printf("|\n");
}

void printAlignedLeft(const char *message) {
    printf("|");
    printExtended(' ', (SIZE_LINE - (strlen(message) + 2)));
    printf("%s|\n", message);
}

void printLine() {
    printf("|");
    printExtended('-', SIZE_LINE - 2);
    printf("|\n");
}

void printExtended(char c, int number) {
    for(int i = 0; i < number; i++) {
        printf("%c", c);
    }
}
