#define OK 1                                     /*The function will return if the entered parameters meet the settings */
#define ERR_LINE 2                               /*The function will return if the _line parameter does not meet the settings*/
#define ERR_SIGN 3                               /*The function will return if the _sign parameter does not meet the settings*/
#define MAX_LINE 50                              /*Maximum value for _line parameter*/
#define MAX_SIGN '~'                             /*Maximum value for _sign parameter*/
#define MIN_LINE 2                               /*Minimal value for _line parameter*/
#define MIN_SIGN '!'                             /*Minimal value for _sign parameter*/


/*
triag1 function:
Description: The function prints a triangle aligned to the left and grows according to the row number.
Input Parameters: _sign a character/sign from which the triangle will be printed 
                  _line the number of lines to be printed in a triangle.
Output parameter: OK if the parameters are correct,
                  ERR_LINE if the _line parameter does not meet the settings
                  ERR_SIGN if the _sign parameter does not meet the settings
*/
int triag1 (char _sign, int _line);
/*
triag2 function:
Description: The function prints a triangle aligned to the left and shrinks in inverse proportion to the row number.
Input Parameters: _sign a character/sign from which the triangle will be printed 
                  _line the number of lines to be printed in a triangle.
Output parameter: OK if the parameters are correct,
                  ERR_LINE if the _line parameter does not meet the settings
                  ERR_SIGN if the _sign parameter does not meet the settings
*/
int triag2 (char _sign, int _line);
/*
triag3 function:
Description: The function prints a triangular aligned to the left increases by the row number and then decreases inversely to the row number.
Input Parameters: _sign a character/sign from which the triangle will be printed 
                  _line the number of lines to be printed in a triangle.
Output parameter: OK if the parameters are correct,
                  ERR_LINE if the _line parameter does not meet the settings
                  ERR_SIGN if the _sign parameter does not meet the settings
*/
int triag3 (char _sign, int _line);
/*
triag4 function:
Description: The function prints a right-angled triangle where the base contains from a number of characters as the number of lines and in each line between characters there is a space.
Input Parameters: _sign a character/sign from which the triangle will be printed 
                  _line the number of lines to be printed in a triangle.
Output parameter: OK if the parameters are correct,
                  ERR_LINE if the _line parameter does not meet the settings
                  ERR_SIGN if the _sign parameter does not meet the settings
*/
int triag4 (char _sign, int _line);
/*
triag5 function:
Description: The function prints a upside down right-angled triangle where the base contains from a number of characters as the number of lines and in each line between characters there is a space.
Input Parameters: _sign a character/sign from which the triangle will be printed 
                  _line the number of lines to be printed in a triangle.
Output parameter: OK if the parameters are correct,
                  ERR_LINE if the _line parameter does not meet the settings
                  ERR_SIGN if the _sign parameter does not meet the settings
*/
int triag5 (char _sign, int _line);
/*
triag5 function:
Description: The function prints a  rhombus shape consisting of two right-angled triangles where the top is straight and the bottom is upside down and the base where the two triangles meet contains a number of characters as the number of lines and between each character there is a space.
Input Parameters: _sign a character/sign from which the triangle will be printed 
                  _line the number of lines to be printed in a triangle.
Output parameter: OK if the parameters are correct,
                  ERR_LINE if the _line parameter does not meet the settings
                  ERR_SIGN if the _sign parameter does not meet the settings
*/
int triag6 (char _sign, int _line);

