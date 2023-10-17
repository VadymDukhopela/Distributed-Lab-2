#include <iostream>
#include <string>
#include <cstdint>
#include <cmath>

using namespace std;

class myClass
{
private:
    string hex;
    string bin;
    unsigned long long num;

public:
    myClass()
    {
    }
    myClass(unsigned long long Num)
    {
        num = Num;
        hex = toHex(num);
        bin = toBin(num);
    }

    unsigned long long getNum()
    {
        return num;
    }
    string getHex()
    {
        return hex;
    }
    string getBin()
    {
        return bin;
    }

    void setNum(unsigned long long Num)
    {

        num = Num;
        hex = toHex(Num);
        bin = toBin(Num);
    }

    void setHex(string Hex)
    {
        hex = Hex;
        num = hexToDecimal(Hex);
        bin = toBin(num);
    }

    string toHex(unsigned long long Num)
    {
        string result;
        unsigned long long tempNum = Num;
        while (tempNum != 0)
        {
            int rem;
            int ch;
            rem = tempNum % 16;
            if (rem < 10)
            {
                ch = rem + 48;
            }
            else
            {
                ch = rem + 87;
            }
            result += ch;
            tempNum /= 16;
        }

        return reverseString(result);
    }

    unsigned long long hexToDecimal(string Hex)
    {
        unsigned long long result = 0;
        long long base = 1;
        for (int i = Hex.length() - 1; i >= 0; i--)
        {
            if (Hex[i] >= '0' && Hex[i] <= '9')
            {
                result += (int(Hex[i]) - 48) * base;

                base = base * 16;
            }
            else if (Hex[i] >= 'a' && Hex[i] <= 'f')
            {
                result += (int(Hex[i]) - 87) * base;
                base = base * 16;
            }
        }

        return result;
    }

    string toBin(unsigned long long Num)
    {
        string result;
        unsigned long long tempNum = Num;
        unsigned long long coefficient = -1;
        while (coefficient != 0)
        {
            result += to_string(tempNum % 2);
            coefficient = tempNum / 2;
            tempNum = coefficient;
        }

        return reverseString(result);
    }

    unsigned long long binToDec(string Bin)
    {
        unsigned long long result = 0;

        int power = 0;
        for (int i = Bin.length() - 1; i >= 0; i--)
        {
            if (Bin[i] == '1')
            {
                result += (unsigned long long)pow(2, power);
            }
            power++;
        }

        return result;
    }

    string reverseString(string str)
    {
        for (int i = 0; i < (str.length()) / 2; i++)
        {
            swap(str[i], str[str.length() - i - 1]);
        }

        return str;
    }

    void bitwiseInv(unsigned long long Num)
    {
        cout << "bitwise inv: " << (~Num) << endl;
    }

    unsigned long long bitwiseXOR(unsigned long long Num1, unsigned long long Num2)
    {
        return (Num1 ^ Num2);
    }

    unsigned long long bitwiseOR(unsigned long long Num1, unsigned long long Num2)
    {
        return (Num1 | Num2);
    }

    unsigned long long bitwiseAND(unsigned long long Num1, unsigned long long Num2)
    {
        return (Num1 & Num2);
    }
    unsigned long long bitwiseShiftR(unsigned long long Num1, int Nbits)
    {
        return (Num1 >> Nbits);
    }
    unsigned long long bitwiseShiftL(unsigned long long Num1, int Nbits)
    {
        return (Num1 << Nbits);
    }
};

int main()
{
    myClass test(11231233);
    myClass test2(18446744073709551615);

    cout << endl
         << endl
         << endl
         << endl;

    myClass test3(test.bitwiseXOR(test.getNum(), test2.getNum()));
    cout << "bitwise XOR result: ";
    cout << test3.getNum() << endl;
    cout << "bitwise OR result: ";
    cout << test3.bitwiseOR(test3.getNum(), test2.getNum()) << endl;
    cout << "bitwise AND result: ";
    cout << test3.bitwiseAND(test3.getNum(), test.getNum()) << endl;

    cout << endl
         << endl
         << endl
         << endl;
    cout << "bitwise shiftR result: ";
    cout << test3.bitwiseShiftR(test3.getNum(), 10) << endl;
    cout << "bitwise shiftL result: ";
    cout << test3.bitwiseShiftL(test3.getNum(), 10) << endl;

    cout << endl
         << endl
         << endl
         << endl;

    return 0;
}
