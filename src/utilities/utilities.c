#include "utilities.h"

#ifdef __gnu_linux__

/**
 * @brief Lê um único caractere do teclado (stdin)
 *
 * @return char caractere lido
 * @pre buffer de escrita ne tela (stdout) limpo
 * @post stdin limpo
 */
char getChar() {
    char character = 0;
    struct termios old = {0};
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&character,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
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
    if (h == NULL)
        return 0; // console not found
    GetConsoleMode( h, &mode );
    SetConsoleMode( h, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT) );
    TCHAR c = 0;
    ReadConsole( h, &c, 1, &cc, NULL );
    SetConsoleMode( h, mode );
    return c;
}

#endif

/**
 * @brief Reseta a string
 * 
 * @param str ponteiro para char
 * @param size tamanho da string
 * @pre Nenhuma
 * @post string vazia
 */
void reset(char *str, int size) {
    int i;
    for(i = 0; i < size; i++)
        str[i] = '\0';
}

/**
 * @brief Lê uma confirmação do usuário
 *
 * @return int boolenano, 1 quando o usuário confirmou
 * 0 quando negou a operação
 * @pre stdin limpo
 * @post Nenhuma
 */
int confirm() {
    printf("Opa chefia quer fazer isso msm? [S/n]\n");
    return getChar() != 'n';
}

/**
 * @brief Imprime o cabeçalho do menu
 *
 * @param message Título do cabeçalho
 * @pre Nenhuma
 * @post Cabeçalho do menu impresso
 */
void printHead(const char *message) {
    system(CLEAR);
    printLine();
    printAlignedCenter(message);
    printLine();
}

/**
 * @brief Imprime mensagem
 * 
 * @param message ponteiro para char, informação impressa no menu
 * @pre Nenhuma
 * @post Nenhuma
 */
void printString(const char* message) {
    if(message == NULL || message[0] == '\0')
        printf("vazio");
    else
        printf("%s", message);
}

/**
 * @brief Imprime uma linha com um mensagem alinhada à direita
 *
 * @param mensagem mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlignedLeft(const char *message) {
    printf("|%s", message);
    printExtended(' ', SIZE_LINE - strlen(message) - 2); // -2 por causa dos |
    printf("|\n");
}

/**
 * @brief Imprime uma linha com um mensagem alinhada ao meio
 * 
 * @param mensagem mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlignedCenter(const char *message) {
    int sizeRead = (strlen(message) + 2);
    int space = (SIZE_LINE - sizeRead) / 2;
    printf("|");
    printExtended(' ', space);
    printf("%s", message);
    printExtended(' ', space);
    if (!(sizeRead % 2))
        printf(" ");
    printf("|\n");
}

/**
 * @brief Imprime uma linha com um mensagem alinhada à direita
 * 
 * @param mensagem mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlignedRight(const char *message) {
    printf("|");
    printExtended(' ', (SIZE_LINE - (strlen(message) + 2)));
    printf("%s|\n", message);
}

/**
 * @brief Imprime uma linha separadora, preenchida com '-'
 * 
 * @pre Nenhuma
 * @post Uma única linha separadora impressa no menu
 */
void printLine() {
    printf("|");
    printExtended('-', SIZE_LINE - 2);
    printf("|\n");
}

/**
 * @brief Imprime um caractere (qnt) vezes
 * 
 * @param c caractere a ser impresso no Menu
 * @param number quantidade de vezes que o caractere deve ser impresso
 * @pre Nenhuma
 * @post Caractere impresso (qnt) vezes na tela
 */
void printExtended(char c, int number) {
    for(int i = 0; i < number; i++)
        printf("%c", c);
}
