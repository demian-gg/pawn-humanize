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
}
