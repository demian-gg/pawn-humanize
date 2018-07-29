#include "humanize.inc"

main() {
    // ---
    // Commas
    // ---
    new numbers[] = {
        10, 100, 1000, 10000, 100000, 1000000, -100000
    };

    new result[14 + 1];
    for(new i = 0; i < sizeof(numbers); i++){
        HumanizeComma(numbers[i], result);
        print(result);
    }

    // ---
    // Colors
    // ---
    new color[32];
    HumanizeColor(0xA86420FF, color); // "Chocolate Brown"
    print(color);

    HumanizeColor(0x42F44EFF, color); // "Lime Green"
    print(color);

    HumanizeColor(0x137A8EFF, color); // "Teal"
    print(color);

    // ---
    // Ordinals
    // ---
    new ordinal[32];

    for(new i = 0; i < 5; i++)
    {
        HumanizeOrdinal(i + 1, ordinal);
        printf("You got %s place!", ordinal);
    }
}
