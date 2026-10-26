#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#ifdef _WIN32
     #include <windows.h>
     #define sleep_seconds(s) Sleep((s)*1000)
#else
     #include <unistd.h>
     #define sleep_seconds(s) sleep(s)
#endif
int main(void) 
{
 char Selection;
 double X, Y;
 char Operation;
 double Solution;
 bool Scientific;
 double radians;
 setbuf(stdout, NULL); 
 
 printf("================================== \n");
 printf("    CALCULATOR VERSION ALPHA \n");
 printf("================================== \n");
 printf("For scientific notations, input S. \n");
 printf("For normal operations input N. \n");
 
 scanf("%c", &Selection);
  if (Selection == 'S' || Selection == 's'){
     Scientific = true;}
  else if (Selection == 'N' || Selection == 'n'){
     Scientific = false;}
  else {
     printf("Choose S(Scientific) or N(Normal)");
     return 1;
  }

  while (Scientific == false){
      printf("Enter the first number. \n");
      scanf(" %lf", &X);
           printf("Enter the operation. \n");
           scanf(" %c", &Operation);
                printf("Enter the second number. \n");
                scanf("%lf", &Y);

                switch (Operation) {
                    default:
                     printf("Invalid operation\n");
                     return 1;
                    
                    case '+':
                     Solution = X + Y;
                     break;
                
                    case '-':
                     Solution = X - Y;
                     break;
                
                    case '*':
                    case 'x':
                    case 'X':
                     Solution = X * Y;
                     break;
                 
                    case '/':
                    case ':':
                     if (Y==0) {
                          printf("ERROR_DENOM_ZERO");
                          return 1;} 
                     Solution = (double)X / Y;
                     break;}
           
               printf("Your answer is");   
             
               for (int i=0; i<3; i++){
                     sleep_seconds(1);
                     printf(" .");}
                
                     printf(" %.2lf \n", Solution);  
                     printf("Press Enter to exit...");
                     int ch;
                     while ((ch = getchar()) != '\n' && ch != EOF) {
                     }
                     getchar();
                      return 0;}
while (Scientific == true){
 printf("Enter your number.\n");
 scanf("%lf", &X);
 radians = X * 3.14159265358979323846 / 180.0;
      printf("Enter your operation.\n");
      printf("-------------------------------------------------------------------------------\n");
      printf("                                 INSTRUCTIONS\n");
      printf("For square root, use 'q' or 'Q'.\n");
      printf("For trigonometric functions, write 's'=sin, 'c'=cos, 't'=tan, 'o'=cot \n");
      printf("For ln(x) write 'n' and for logarythm use 'l'.\n");
      printf("For exponents, write 'e'for e^x; 'p' or '^' for exponents.\n");
      printf("For factorials, input '!'.\n");
      printf("For absolute value input 'a'.\n");
      printf("-------------------------------------------------------------------------------\n");
      scanf(" %c", &Operation);
      
      switch(Operation){
          default:
           printf("Invalid operation.\n");
           return 1;
          case 'q':
          case 'Q':
           if (X<0)
           {
               printf("Chosen number below 0. Invalid operation.0");
               return 1;
           }
           Solution = sqrt(X);
           break;
          case 's':
           Solution = sin(radians);
           break;
          case 'c':
           Solution = cos(radians);
           break;
          case 't':
           if (fmod(fabs(X), 180.0) == 90.0) {
           printf("Unknown solution. Try another value.\n");
           return 1;
           }
           else {
           Solution = tan(radians);}
           break;
          case 'o':
           if (fabs(sin(radians)) < 1e-12) {
           printf("Unknown solution. Try another value.\n");
           return 1;
           }
           else{
           Solution = cos(radians)/sin(radians);
           }
           break;
          case 'n':
           if (X <= 0){
           printf("Invalid. Use a value 0<.");
           return 1;}
           else {
           Solution = log(X);
           }
           break;
          case 'l':
           if (X <= 0) {
               printf("Invalid. Use a value that is 0<");
               return 1;}
           printf("Insert the base of the function.");
           scanf("%lf", &Y);
                if(Y == 1 || Y <= 0) {
                    printf("Please use a base that is not 1 or <0.");
                    return 1;
                }
                Solution = log(X)/log(Y);
                break;
          case 'p':
          case '^':
           printf("Insert the exponent of the function.");
           scanf("%lf", &Y);
                Solution = pow(X, Y);
                break;
          case 'e':
           Solution = exp(X);
           break;
          case '!':
           if (X == 0){
               Solution = 1;
               break;
           }
           if (X < 0 || X != (int)X || X>18) {
             printf("Enter a non-negative whole number.\n");
             return 1;
             } else {
                Solution = 1;
                for (int i = 1; i <= (int)X; i++) {
                Solution *= i;
                }
                }
                break;
          case 'a':
           Solution = fabs(X);
           break;}
     printf("Your answer is");   
             
          for (int i=0; i<3; i++){
                sleep_seconds(1);
                printf(" .");}
                
                printf(" %.2lf \n", Solution);  
                printf("Press 'Enter' to exit.");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF) {
                }
                getchar();
                
                
                return 0;
          }
     }
