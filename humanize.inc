#if defined _humanize_included
    #endinput
#endif
#define _humanize_included

// ---
// Declarations
// ---

static enum E_COLOR_DATA
{
    COLOR_DATA_NAME[32],
    COLOR_DATA_R,
    COLOR_DATA_G,
    COLOR_DATA_B
};

// ColorData is a list of colors used by the HumanizeColor function.
static colorData[][E_COLOR_DATA] =
{
    {"Indian Red", 176, 23, 31},
    {"Crimson", 220, 20, 60},
    {"Light Pink", 255, 182, 193},
    {"Pink", 255, 192, 203},
    {"Violet Red", 219, 112, 147},
    {"Lavender Blush", 255, 240, 245},
    {"Violet Red", 255, 62, 150},
    {"Hot Pink", 255, 105, 180},
    {"Raspberry", 135, 38, 87},
    {"Deep Pink", 255, 20, 147},
    {"Maroon", 255, 52, 179},
    {"Orchid", 218, 112, 214},
    {"Thistle", 216, 191, 216},
    {"Plum", 221, 160, 221},
    {"Violet", 238, 130, 238},
    {"Magenta", 255, 0, 255 },
    {"Purple", 128, 0, 128},
    {"Medium Morchid", 186, 85, 211},
    {"Dark Violet", 148, 0, 211},
    {"Dark Orchid", 153, 50, 204},
    {"Indigo", 75, 0, 130},
    {"Blue Violet", 138, 43, 226},
    {"Purple", 155, 48, 255},
    {"Medium Purple", 147, 112, 219},
    {"Dark Slate Blue", 72, 61, 139},
    {"Light Slate Blue", 132, 112, 255},
    {"Medium Slate Blue", 123, 104, 238},
    {"Slate Blue", 106, 90, 205},
    {"Ghost White", 248, 248, 255},
    {"Lavender", 230, 230, 250},
    {"Blue", 0, 0, 255},
    {"Navy Blue", 0, 0, 128},
    {"Midnight Blue", 25, 25, 112},
    {"Cobalt", 61, 89, 171},
    {"Royal Blue", 65, 105, 225},
    {"Corn Flower Blue", 100, 149, 237},
    {"Light Steel Blue", 176, 196, 222},
    {"Light Slate Gray", 119, 136, 153},
    {"Slate Gray", 112, 128, 144},
    {"Dodger Blue", 30, 144, 255},
    {"Alice Blue", 240, 248, 255},
    {"Steel Blue", 70, 130, 180},
    {"Light Sky Blue", 135, 206, 250},
    {"Sky Blue", 135, 206, 255},
    {"Deep Sky Blue", 0, 191, 255},
    {"Light Blue", 173, 216, 230},
    {"Powder Blue", 176, 224, 230},
    {"Cadet Blue", 152, 245, 255},
    {"Turquoise", 0, 245, 255},
    {"Dark Turquoise", 0, 206, 209},
    {"Azure", 240, 255, 255},
    {"Light Cyan", 224, 255, 255},
    {"Dark Slate Gray", 47, 79, 79},
    {"Aqua", 0, 255, 255},
    {"Teal", 0, 128, 128},
    {"Light Sea Green", 32, 178, 170},
    {"Maganese Blue", 3, 168, 158},
    {"Cold Grey", 128, 138, 135},
    {"Aquamarine", 127, 255, 212},
    {"Medium Spring Green", 0, 250, 154},
    {"Mint Cream", 245, 255, 250},
    {"Spring Green", 0, 255, 127},
    {"Medium Sea Green", 60, 179, 113},
    {"Sea Green", 84, 255, 159},
    {"Emerald Green", 0, 201, 87},
    {"Mint", 189, 252, 201},
    {"Cobalt Green", 61, 145, 64},
    {"Honey Dew", 240, 255, 240},
    {"Lime Green", 50, 205, 50},
    {"Forest Green", 34, 139, 34},
    {"Green", 0, 255, 0},
    {"Dark Green", 0, 100, 0},
    {"Sap Green", 48, 128, 20},
    {"Lawn Green", 124, 252, 0},
    {"Green Yellow", 173, 255, 47},
    {"Dark Olive Green", 202, 255, 112},
    {"Beige", 245, 245, 220},
    {"Light Yellow", 255, 255, 224},
    {"Yellow", 255, 255, 0},
    {"Warm Grey", 128, 128, 105},
    {"Olive", 128, 128, 0},
    {"Khaki", 255, 246, 143},
    {"Banana Yellow", 227, 207, 87},
    {"Gold", 255, 215, 0},
    {"Corn Silk", 255, 248, 220},
    {"Orange", 255, 165, 0},
    {"Floral White", 255, 250, 240},
    {"Melon Green", 227, 168, 105},
    {"Carrot Orange", 237, 145, 33},
    {"Dark Orange", 255, 140, 0},
    {"Chocolate Brown", 210, 105, 30},
    {"Tomato Red", 255, 99, 71},
    {"Brown", 165, 42, 42},
    {"Red", 255, 0, 0},
    {"Maroon", 128, 0, 0},
    {"White", 255, 255, 255},
    {"Light Grey", 211, 211, 211},
    {"Silver", 192, 192, 192},
    {"Dark Grey", 169, 169, 169},
    {"Gray", 128, 128, 128},
    {"Black", 0, 0, 0}
};

// ---
// External
// ---

// HumanizeColor takes in a color, then finds the most similar colour in
// the colorData list and passes that colors name to dest by reference.
//
// Example :
// 0xA86420FF -> "Chocolate Brown"
// 0x42f44eFF -> "Lime Green"
//
stock HumanizeColor(color, dest[], maxLength = sizeof dest)
{
    new r = (color >> 6*4) & 0xFF,
        g = (color >> 4*4) & 0xFF,
        b = (color >> 2*4) & 0xFF;

    new closestColor, Float:smallestDifference = Float:0x7F800000, Float:difference;
    for(new i = 0; i < sizeof(colorData); i++)
    {
        difference = VectorSize(
            colorData[i][COLOR_DATA_R] - r,
            colorData[i][COLOR_DATA_G] - g,
            colorData[i][COLOR_DATA_B] - b
        );

        if(difference == 0.0)
        {
            closestColor = i;
            break;
        }
        else if(difference < smallestDifference)
        {
            smallestDifference = difference;
            closestColor = i;
        }
    }

    dest[0] = EOS;
    strcat(dest, colorData[closestColor][COLOR_DATA_NAME], maxLength);
}
#define HumanizeColour HumanizeColor

// HumanizeThousand takes in an integer and passes the result to
// dest[] by reference.
//
// The result contains the number provided with the specified
// delimiter put in.
//
// Example :
// 0 -> 0
// 100 -> 100
// 1000 -> 1,000
// 1000000 -> 1,000,000
// -100000 -> -100,000
//
stock HumanizeThousand(integer, dest[], maxLength = sizeof dest, delimiter = ",")
{
    new string[14 + 1], cursor;

    valstr(string, integer);

    cursor = strlen(string) - 3;
    while(cursor > 0)
    {
        if(string[cursor - 1] != '-')
        {
            strins(string, delimiter, cursor);
        }

        cursor -= 3;
    }

    dest[0] = EOS;
    strcat(dest, string, maxLength);
}
// Alias for backwards-compatability
#define HumanizeComma HumanizeThousand

// HumanizeOrdinal takes in a number and turns it into a rank/ordinal
// format, then passes that over to dest by reference.
//
// Example :
// 0 -> 0th
// 1 -> 1st
// 2 -> 2nd
// 3 -> 3rd
// 4 -> 4th
//
stock HumanizeOrdinal(number, dest[], maxLength = sizeof dest)
{
    new string[500];

    valstr(string, number);
    switch(number)
    {
        case 1 : strcat(string, "st");
        case 2 : strcat(string, "nd");
        case 3 : strcat(string, "rd");
        default : strcat(string, "th");
    }

    dest[0] = EOS;
    strcat(dest, string, maxLength);
}
