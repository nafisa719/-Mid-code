#include <iostream>

#include <fstream>

using namespace std;

int main() {

    ifstream file("myFile.txt");

    string s = "";

    char ch;

    if (!file) {

        cout << "File not found!";

        return 0;

    }

  int lineNo = 1;

    cout << "Line " << lineNo << ":" << endl;

        while (file.get(ch)) {

                if (ch == '"') {

            cout << "CONSTANT : ";

            cout << ch;


            while (file.get(ch)) {

                cout << ch;

                if (ch == '"')

                    break;

            }

            cout << endl;

        }

       else if (ch == ' ' || ch == '\n' || ch == ';' || ch == '(' || ch == ')'

            || ch == '+' || ch == '-' || ch == '=' || ch == '*') {

            if (s != "") {

                if (s == "int" || s == "float" || s == "return" || s == "if" || s == "else" || s=="double" || s=="string" || s=="cout")

                    {cout << "KEYWORD : " << s << endl;}

                else if (s[0] >= '0' && s[0] <= '9')

                    {cout << "CONSTANT : " << s << endl;}

                else

                    {cout << "IDENTIFIER : " << s << endl;}

                s = "";

            }

            if (ch == '+' || ch == '-' || ch == '=' || ch == '*')

                {cout << "OPERATOR : " << ch << endl;}

            if (ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}'|| ch ==',')

                {cout << "PUNCTUATION : " << ch << endl;}

            if (ch == '\n') {

                lineNo++;

                cout << endl;

                cout << "Line " << lineNo << ":" << endl;

        }

            }

        else {

            s += ch;

        }

    }

    file.close();

    return 0;

}
