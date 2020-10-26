#include<iostream>
#include<stack>
#include<string>
#include<math.h>

using namespace std;

int hesapla(string expression);

int islem(char operation, int operand1, int operand2);

bool operatormu(char C);

bool rakam(char C);

bool eksimi(char C);


int main()
{
	string expression;
	cout<<"Enter a Postfix Expression \n";
	getline(cin,expression);
	int result = hesapla(expression);
	cout<<"Output = "<<result<<"\n";
}

int hesapla(string expression)
{
	stack<int> S;

	for(int i = 0;i< expression.length();i++) {

		if(expression[i] == ' ' || expression[i] == ',') continue;

		else if(operatormu(expression[i])) {
			int operand2 = S.top(); S.pop();
			int operand1 = S.top(); S.pop();
			int result = islem(expression[i], operand1, operand2);
			S.push(result);
		}

		if(eksimi(expression[i])){
            int number=S.top(); S.pop();
               number= number * (-1);
               S.push(number);
            }
		else if(rakam(expression[i])){
			int operand = 0;
			while(i<expression.length() && rakam(expression[i])) {
				operand = (operand*10) + (expression[i] - '0');
				i++;
			}

			i--;


			S.push(operand);
		}
	}

	return S.top();
}


bool rakam(char C)
{
	if(C >= '0' && C <= '9') return true;
	return false;
}


bool operatormu(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C == '^')
		return true;

	return false;
}

bool eksimi(char C){

if(C == '@' )
return true;

return false;
}


int islem(char operation, int operand1, int operand2)
{
	if(operation == '+')
    return operand1 +operand2;
	else if(operation == '-')
    return operand1 - operand2;
	else if(operation == '*')
	return operand1 * operand2;
	else if(operation == '/')
	return operand1 / operand2;
	else if(operation == '^')
	return pow(operand1,operand2);

}
