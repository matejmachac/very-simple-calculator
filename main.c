#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc,  char * argv[]) {
    float n1 = 0;
    float n2 = 0;
    float result = 0;

    int i = 0;

    char operand;

    //check the number of parameters
    if (argc!=4)
    {
        printf("The number of parameters is wrong. Expected 3 parameters, given %d.", argc -1);
        return(0);
    }

    //load n1 and n2; then check if those are valid float
    if ((sscanf(argv[1], "%f", &n1)!=1) || (sscanf(argv[3], "%f", &n2)!=1))
    {
        printf("Unaccepted parameter given. Correct syntax is number1_operand_number2.");
        return(0);
    }

    //check loaded arguments for spaces; if found, erase them; (multiplication/power safe guard)
    if (argv[2][0] == ' ')
    {
        argv[2][0]=argv[2][1];
        argv[2][1] = 0;
    }
    //load operand after the adjustment
    sscanf(argv[2],"%c",&operand);

    //check operand value; then proceed to calculations
    switch (operand) {
        case '+':
            result=n1+n2;
            break;
        case '-':
            result=n1-n2;
            break;
        case '/':
            if (n2 == 0)
            {
                printf("Division by 0 is not possible.");
                return(0);
            }
            else
            {
                result=n1/n2;
            }

            break;
        case '*':
            result=n1*n2;
            operand='*';   //operand char hack
            break;
        case '^':
            if (n2==0)
            {
                result=1;
            }else
            {
                result=n1;
                for (i=1;i<n2;i++)
                {
                    result=result*n1;
                }
            }
            operand='^';   //operand char hack
            break;
        default:
            printf("Unaccepted parameter given. Correct syntax is number1_operand_number2. \n Valid operands are +, -, /, \" *\", \" ^\".");
            return(0);
            break;
    }

    printf("%f %c %f = %f", n1, operand, n2, result);

    return 0;
}
