#if defined _humanize_included
    #endinput
#endif
#define _humanize_included

// HumanizeComma takes in an integer and returns a string containing
// the number provided with commas put in.
//
// Example :
// 0 -> 0
// 100 -> 100
// 1000 -> 1,000
// 1000000 -> 1,000,000
// -100000 -> -100,000
//
stock HumanizeComma(integer) {
	new string[14], cursor;

	valstr(string, integer);

	cursor = strlen(string) - 3;
	while(cursor > 0) {
        // If the character in front of the cursor is not a minus.
        if(string[cursor - 1] != 0x2D) {
            strins(string, ",", cursor);
        }

		cursor -= 3;
	}

	return string;
}
