#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int A_ASSCI_CODE = 65;
const int ZERO_ASSCI_CODE = 48;

float logax(int base,int x);
int findDigitsCount(int base,int num);
void convertToBaseN(int base,int num);
int convertToBase10(int base,string num);
char getSymbolMatchingNumber(int val);
int getNumberMatchingSymbol(char symbol);

int main(int argc, char **argv)
{
	string num;
	int base,cBase;
	while(1) {
		cout << endl;
		cout << "+-----------------------+" << endl;
		cout << "| Number Base Converter |" << endl;
		cout << "+-----------------------+" << endl;
		//cout << "15 in base 10 is \"15 10\"" <<endl << endl;

		cout << "Convert :";
		cin >> num >> base;
		cout << "to base :";
		cin >> cBase;
		cout << endl;

		int numIn10 = convertToBase10(base,num);
		cout << "{" << num << "}" << base << " = {" << numIn10 << "}10" << " = {";
		convertToBaseN(cBase,numIn10);
		cout << "}" << cBase << endl;
		cout << endl;
	}
	return 0;
}

float logax(int base,int x)
{
	return log(x)/log(base);
}

int findDigitsCount(int base,int num)
{
	float r = logax(base,num);
	return ((r==(int)r) ? r : r+1);
}

char getSymbolMatchingNumber(int val)
{
	if(val <= 9 ) return (val+ZERO_ASSCI_CODE);
	else return (val-10+A_ASSCI_CODE);
}

int getNumberMatchingSymbol(char symbol)
{
	int code = (int)symbol;
	if(code <= ZERO_ASSCI_CODE+9)return code-ZERO_ASSCI_CODE;
	else return code-A_ASSCI_CODE+10;
}

void convertToBaseN(int base,int num)
{
	int digitsCount = findDigitsCount(base,num);
	char digits[digitsCount];

	int numToDivide = num;
	for(int i = 0; i < digitsCount; i++) {
		int remainder = numToDivide % base;
		numToDivide = numToDivide / base;
		digits[i] = getSymbolMatchingNumber(remainder);
	}

	for(int i = digitsCount-1; i>=0; i--) {
		cout << digits[i];
	}
}

int convertToBase10(int base,string num)
{
	int numDigitsCount = num.size();
	int val = 0;
	for (int i = 0; i < numDigitsCount; i++) {
		val += getNumberMatchingSymbol(num[i]) * pow(base,numDigitsCount-i-1);
	}
	return val;
}
