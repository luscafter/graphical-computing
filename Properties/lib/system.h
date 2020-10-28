#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

// Verifica qual � o Sistema Operacional e define constantes

#if defined(__WIN32__) || defined(__NT__)    // Windows
    #define CLEAR "cls"
    #define RED   ""                         // O Windows n�o suporta cores ANSI.
    #define BLUE  ""                         // Portanto, para n�o gerar erros � necess�rio definir a constante vazia.
    #define GREEN ""                         
    #define RESET ""                         
#endif

#if defined(__linux__) || defined(__linux)   // GNU/Linux
    #define CLEAR "clear"
    #define RED   "\e[0;49;91m"
    #define BLUE  "\e[0;49;36m"
    #define GREEN "\e[0;49;92m"
    #define RESET "\e[0m"
#endif

#if defined(__APPLE__)                       // MacOS (Eu n�o pude testar as constantes no MacOS, mas pode funcionar)
    #define CLEAR "printf '\33c\e[3J'"
    #define RED   "\e[0;49;91m"
    #define BLUE  "\e[0;49;36m"
    #define GREEN "\e[0;49;92m"
    #define RESET "\e[0m"
#endif

#endif // SYSTEM_H_INCLUDED
