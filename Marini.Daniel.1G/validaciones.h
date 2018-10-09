#ifndef INPUT_H_INCLUDED
void getInt(int* puntero);
void getFloat(float* puntero);
void getChar(char* mensaje);
int getString(char* input);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);
int getSringLetras(char input[]);
int menuPrincipal();

#endif // INPUT_H_INCLUDED

