// Verifica qual é o Sistema Operacional e define constantes

#if defined(__WIN32__) || defined(__NT__)    // Windows
	#define CLEAR "cls"
	#define GREEN ""                         // O Windows não suporta cores ANSI.
	#define RESET ""                         // Portanto, para não gerar erros é necessário definir a constante vazia.
#endif

#if defined(__linux__) || defined(__linux)   // GNU/Linux
	#define CLEAR "clear"
	#define GREEN "\e[0;49;92m"
	#define RESET "\e[0m"
#endif

#if defined(__APPLE__)                       // MacOS (Eu não pude testar as constantes no MacOS, mas pode funcionar)
	#define CLEAR "printf '\33c\e[3J'"
	#define GREEN "\e[0;49;92m"
	#define RESET "\e[0m"
#endif