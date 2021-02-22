/*
Code written by Mahmoud Abdelmoneum On 2/21/2021
Code Written To Be A Palindrome Checker
Takes in a string input, checks to see if it is the same forwards
as it is backwards (A Palindrome)
*/

#include <iostream>
#include <cstring>

using namespace std;

int isValid(char h);

int main()
{

  char str[100]; //input string
  char str2[100];
  char NewStr[100]; //NewStr is the processed input, won't contain spaces/punctuation

  cout << "Welcome To Mahmoud's Palindrome Checker!" << endl;
  cout << "Please Enter Your Input (What you would like to check)" << endl;

  cin.get(str, 100);
  cin.get();

  int length = strlen(str);
  int a = 0; //counter variable 


  //deletes all punctuations and spaces
  for(int i = 0; i < length; i++) {
    if(isValid(str[i])) {
      NewStr[a] = str[i]; //transfers just letters into NewStr
      a++;
    }
  }

  //convert all letters to lowercase 
  for(int j = 0; j < length; j++) {
    NewStr[j] = tolower(NewStr[j]);
  }

  length = a; //update length with the actual input length from the counter variable, saves before it is changed

  //reverse input string
  for(int z = 0; z < length; z++) {
    str2[z] = NewStr[a-1];
    a--;
  }

  //compare reveresed input to input using memcmp()
  if (memcmp(NewStr, str2, length) == 0) //check if memory matches 
  {
    cout << "This is a palindrome!" << endl;
  }
  else {
    cout << "This is not a palindrome!" << endl;
  }

  return 0;
}


//The below portion was inspired by Allison Delgado's Palindrome Checker Code
//Checks for alphanumerical input
int isValid(char ch) {

  //check if number
  if (ch >= 65 && ch <= 57) {
    return 1;
  }

  //check if alphabetical
  else if (ch >= 65 && ch <= 122) {
    return 1;
  }

  else {
    return 0;
  }

  
}
