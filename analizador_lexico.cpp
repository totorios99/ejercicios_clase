#include <cctype>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

bool is_integer(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (!isdigit(s[i]))
      return false;
  }
  return true;
}

bool is_identifier(string s) {
  if (!isalpha(s[0]))
    return false;

  for (int i = 1; i < s.length(); i++) {
    if (!isalnum(s[i]))
      return false;
  }
  return true;
}

bool symbols(string s) {
  char parenthesis_open = '(';
  char parenthesis_close = ')';
  char comma = ',';
  char point = '.';
  char semicolon = ';';
  char quotes = '"';
  char percentage = '%';
  char times = '*';
  char gt = '>';
  char lt = '<';
  char eq = '=';
  char underscore = '_';
  char dash = '-';
  char hash = '#';
  char ampersand = '&';
  char slash = '/';

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == parenthesis_open) {
      cout << "Inicio grupo   | " << parenthesis_open << "      | 1      | "
           << i + 1 << endl;
    } else if (s[i] == parenthesis_close) {
      cout << "Fin grupo      | " << parenthesis_close << "      | 1      | "
           << i + 1 << endl;
    } else if (s[i] == comma) {
      cout << "Coma           | " << comma << "      | 1      | " << i + 1
           << endl;
    } else if (s[i] == point) {
      cout << "Punto          | " << point << "      | 1      | " << i + 1
           << endl;
    } else if (s[i] == semicolon) {
      cout << "Punto y coma   | " << semicolon << "      | 1      | " << i + 1
           << endl;
    } else if (s[i] == quotes) {
      cout << "Comillas       | " << quotes << "      | 1      | " << i + 1
           << endl;
    } else if (s[i] == percentage) {
      cout << "Porcentaje     | " << percentage << "      | 1      | " << i + 1
           << endl;
    } else if (s[i] == times) {
      cout << "Multiplicación | " << times << "      | 1      | " << i + 1
           << endl;
    } else if (s[i] == gt) {
      cout << "Mayor o igual  | " << gt << "      | 1      | " << i + 1 << endl;
    } else if (s[i] == lt) {
      cout << "Menor o igual  | " << lt << "      | 1      | " << i + 1 << endl;
    } else if (s[i] == eq) {
      cout << "Menor o igual  | " << eq << "      | 1      | " << i + 1 << endl;
    } else if (s[i] == underscore) {
      cout << "Guión bajo     | " << underscore << "      | 1      | " << i + 1
           << endl;
    } else if (s[i] == dash) {
      cout << "Guión medio    | " << dash << "      | 1      | " << i + 1
           << endl;
    } else if (s[i] == hash) {
      cout << "Hashtag        | " << hash << "      | 1      | " << i + 1
           << endl;
    } else if (s[i] == ampersand) {
      cout << "Ampersand      | " << ampersand << "      | 1      | " << i + 1
           << endl;
    } else if (s[i] == slash) {
      cout << "División       | " << slash << "      | 1      | " << i + 1
           << endl;
    }
  }
  return 0;
}

bool line_break(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '\n')
      return true;
  }
  return false;
}

bool is_for(string s) {
  char for_s[] = "for";

  if (strcmp(s.c_str(), for_s) == 0)
    return true;

  return false;
}

bool is_int(string s) {
  char int_s[] = "int";

  if (strcmp(s.c_str(), int_s) == 0)
    return true;

  return false;
}

bool is_char(string s) {
  char char_s[] = "char";

  if (strcmp(s.c_str(), char_s) == 0)
    return true;

  return false;
}

bool is_float(string s) {
  char float_s[] = "float";

  if (strcmp(s.c_str(), float_s) == 0)
    return true;

  return false;
}

bool is_include(string s) {
  char include_s[] = "#include";

  if (strcmp(s.c_str(), include_s) == 0)
    return true;

  return false;
}

bool is_while(string s) {
  char while_s[] = "while";

  if (strcmp(s.c_str(), while_s) == 0)
    return true;

  return false;
}

bool is_do(string s) {
  char do_s[] = "do";

  if (strcmp(s.c_str(), do_s) == 0)
    return true;

  return false;
}

bool is_endl(string s) {
  char endl_s[] = "endl";

  if (strcmp(s.c_str(), endl_s) == 0)
    return true;

  return false;
}

bool is_println(string s) {
  char println_s[] = "println";

  if (strcmp(s.c_str(), println_s) == 0)
    return true;

  return false;
}

bool is_cout(string s) {
  char cout_s[] = "cout";

  if (strcmp(s.c_str(), cout_s) == 0)
    return true;

  return false;
}
int main() {
  string line;
  ifstream in_file("input.txt");
  cout << "Token          | Lexema | Fila   | Columna" << endl;
  cout << "------------------------------------------" << endl;
  while (getline(in_file, line)) {
    int start = 0;
    int end = 0;
    int fila = 0;
    while (end < line.length()) {

      while (end < line.length() /* && !isspace(line[end]) */)
        end++;

      if (end == line.length()) {
        fila++;
        // std::cout << "Fila " << fila << std::endl;
      }

      string token = line.substr(start, end - start);
      if (is_integer(token))
        cout << "Entero         | " << token << "     | 1      |" << endl;
      else if (symbols(token))
        cout << token << endl;

      start = ++end;
    }
  }

  string line2;
  ifstream in_file2("input.txt");

  while (getline(in_file2, line2)) {
    int start2 = 0;
    int end2 = 0;
    while (end2 < line2.length()) {
      while (end2 < line2.length() && !isspace(line2[end2]))
        end2++;

      string token = line2.substr(start2, end2 - start2);
      if (is_for(token))
        cout << token << "            |" << token << "     |   1    | "
             << end2 - 2 << endl;
      else if (is_int(token))
        cout << token << "            |" << token << "     |   1    | "
             << end2 - 2 << endl;
      else if (is_char(token))
        cout << token << "           |" << token << "    |   1    | "
             << end2 - 2 << endl;
      else if (is_float(token))
        cout << token << "          |" << token << "   |   1    | " << end2 - 2
             << endl;
      else if (is_while(token))
        cout << token << "          |" << token << "   |   1    | " << end2 - 2
             << endl;
      else if (is_do(token))
        cout << token << "             |" << token << "      |   1    | "
             << end2 - 2 << endl;
      else if (is_endl(token))
        cout << token << "           |" << token << "    |   1    | "
             << end2 - 2 << endl;
      else if (is_println(token))
        cout << token << "        |" << token << " |   1    | " << end2 - 2
             << endl;
      else if (is_cout(token))
        cout << token << "           |" << token << "    |   1    | "
             << end2 - 2 << endl;
      else if (is_include(token))
        cout << token << "       |" << token << "|   1    | " << end2 - 2
             << endl;
      start2 = ++end2;
    }
  }

  return 0;
}
