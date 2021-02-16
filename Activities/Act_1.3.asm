/ Define un programa que lea 150 datos 
/ consecutivos y los almacene en memoria.
/ Después de almacenados, el programa debe de 
/ entregar en el puerto de salida, el promedio de
/ los mismos.

/ AddI: use el valor en X como la dirección real del operando de datos para agregar a AC
/ StoreI: obtiene el valor del puntero de dirección, almacena el valor de CA en la dirección

almacenar, 	Input / Recibe dato
            StoreI X / Almacena indirectamente el dato
            
            Load RES / Carga el valor de RES al AC
            AddI X / Al valor de RES que se agregó, se le suma X
            Store RES / Almacena el valor del AC a RES
            
            Load X / Carga el valor de RES al AC
            Add UNO / Al valor de RES que se agregó, se le suma X
            Store X / Almacena el valor del AC a X
            
            Load REP /cargo Y para hacer la resta
            Subt UNO / Al valor de REP que se agregó, se le resta UNO
            Store REP / Almacena el valor del AC a REP
            
            Skipcond 000 / Si es menor
            Jump almacenar

Load RES
Output
Halt

/ Declare labels here
RES, DEC 0
UNO, DEC 1
REP, DEC 149
X, HEX 30
