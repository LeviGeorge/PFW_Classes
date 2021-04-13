#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    const int MAX_LENGTH = 500;
    char joinedStr[MAX_LENGTH + 1];
    int i, pos = 0;
    
    for (i = 1; i < argc; i++)
    {
        strncpy(joinedStr + pos, argv[i], MAX_LENGTH - pos);
        pos = pos + strlen(argv[i]);
        
        if (pos >= MAX_LENGTH)
            break;
    }
    
    if (pos >= MAX_LENGTH)
        joinedStr[MAX_LENGTH] = '\0';
    else
        joinedStr[pos] = '\0';
    
    printf("The concatenated string is %s\n.", joinedStr);
    return 0;
}
