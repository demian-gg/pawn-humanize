#if defined _humanize_included
    #endinput
#endif
#define _humanize_included

// HumanizeComma takes in an integer and passes the result to dest[]
// by reference.
//
// The result contains the number provided with commas put in.
//
// Example :
// 0 -> 0
// 100 -> 100
// 1000 -> 1,000
// 1000000 -> 1,000,000
// -100000 -> -100,000
//
stock HumanizeComma(integer, dest[], maxLength = sizeof dest)
{
    new string[14 + 1], cursor;

    valstr(string, integer);

    cursor = strlen(string) - 3;
    while(cursor > 0)
    {
        if(string[cursor - 1] != '-')
        {
            strins(string, ",", cursor);
        }

        cursor -= 3;
    }

    dest[0] = EOS;
    strcat(dest, string, maxLength);
}
