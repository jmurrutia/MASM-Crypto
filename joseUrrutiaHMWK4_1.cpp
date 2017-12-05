#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
     //  Creating the 3 arrays which hold the original, encrypted
     //  and decrypted message.
     char inputBuffer[81];
     char encryptedBuffer[81];
     char clearBuffer[81];
     int count;

     //  Message asking to input the message
     cout << "Input a text for Encryption: ";
     cin.getline(inputBuffer, sizeof(inputBuffer));

     //  Setting the counter with gcount
     count = (cin.gcount() - 1);

     //  Loop to display the original message
     cout << "\nThe original message is: ";
     for (int index = 0; index < count; index++)
          cout << inputBuffer[index];

     __asm {
          mov       esi, 0                        ; Set ESI register = 0
          mov       edi, 0                        ; Set EDI register = 0
          mov       ecx, count                    ; Set the loop counter

     L1:                                          ; Begin loop
          mov       al, inputBuffer[esi]          ; Move char in array into AL register
          xor       al, 0ACh                      ; Exclusive Or each char with 0ACh
          mov       encryptedBuffer[edi], al      ; Putting encrypted char in array

          inc       esi                           ; Increment ESI
          inc       edi                           ; Increment EDI
          loop      L1                            ; End loop
     }

     //  Loop to display the encrypted message
     cout << "\n\nThe encrypted message is: ";
     for (int index = 0; index < count; index++)
          cout << encryptedBuffer[index];
     

     __asm {
          mov       esi, 0                        ; Set ESI register = 0
          mov       edi, 0                        ; Set EDI register = 0
          mov       ecx, count                    ; Set the loop counter

     L2:                                          ; Begin loop
          mov       al, encryptedBuffer[esi]      ; Move char in array into AL register
          xor       al, 0ACh                      ; Exclusive Or each char with 0ACh
          mov       clearBuffer[edi], al          ; Putting decrypted char in array

          inc       esi                           ; Increment ESI
          inc       edi                           ; Increment EDI
          loop      L2                            ; End loop
     }

     // Loop to display the decrypted message
     cout << "\n\nThe decrypted message is: ";
     for (int index = 0; index < count; index++)
          cout << clearBuffer[index];
     cout << endl << endl;

     return 0;
}