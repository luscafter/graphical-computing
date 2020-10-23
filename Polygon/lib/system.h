// Verifica qual é o Sistema Operacional e define constantes

#if defined(__WIN32__) || defined(__NT__)    // Windows
    #include <windows.h>
    #define CLEAR "cls"
    #define GREEN ""                         // O Windows não suporta cores ANSI.
    #define RESET ""                         // Portanto, para não gerar erros é necessário definir a constante vazia.
    #define delay() { Sleep(2500); }
#endif

#if defined(__linux__) || defined(__linux)   // GNU/Linux
    #include <unistd.h>
    #define CLEAR "clear"
    #define RED   "\e[0;49;91m"
    #define GREEN "\e[0;49;92m"
    #define RESET "\e[0m"
    #define delay() { sleep(2.5); }
#endif

#if defined(__APPLE__)                       // MacOS (Eu não pude testar as constantes no MacOS, mas pode funcionar)
    #include <unistd.h>
    #define CLEAR "printf '\33c\e[3J'"
    #define RED   "\e[0;49;91m"
    #define GREEN "\e[0;49;92m"
    #define RESET "\e[0m"
    #define delay() { sleep(2.5); }
#endif
