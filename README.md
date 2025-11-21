<picture>
  <!-- The media queries determine the image based on website theme -->
  <source media="(prefers-color-scheme: dark)" srcset=".assets/banner/dark_mode.png">
  <source media="(prefers-color-scheme: light)" srcset=".assets/banner/light_mode.png">
  <!-- Fallback to light mode variant if no match -->
  <img alt="Pawn Humanize Banner" src=".assets/banner/light_mode.png">
</picture>

######

Pawn-humanize is a utility library inspired by
[go-humanize](https://github.com/dustin/go-humanize). It provides a collection
of functions that turn machine-friendly data into formats that are easier for
humans to read and understand.

Whether you need to display numbers with thousands separators, convert integers
into words, format ordinals, or turn color codes into recognizable color names.
Pawn-humanize handles the little details that make your output feel natural and
readable.

### Installation

You can install the library either manually or using Sampctl, depending on your workflow.

#### Standard

1\. Download the `humanize.inc` file and place it in your `includes` folder.  
2\. Then include it in your code and start using the library:

```pawn
#include <humanize>
```

#### Sampctl

1\. Run the following command to install the library:

```bash
sampctl package install demian-gg/pawn-humanize
```

2\. Then include it in your code and start using it:

```pawn
#include <humanize>
```

### Features

The following helpers format numeric and color values into human-friendly strings for use in chat, dialogs, and logs. See below for usage examples and function signatures.

#### Thousands Seperators

```
0 -> 0
100 -> 100
1000 -> 1,000
1000000 -> 1,000,000
-100000 -> -100,000
```

```C
HumanizeThousand(integer, dest[], maxLength = sizeof dest, delimiter[] = ",")
```

#### Colors

```
0xA86420FF -> "Chocolate Brown"
0x42F44EFF -> "Lime Green"
0x137A8EFF -> "Teal"
```

```C
HumanizeColor(color, dest[], maxLength = sizeof dest)
```

#### Numbers to words

```
1000 -> "one thousand"
1234 -> "one thousand two hundred thirty-four"
-1234 -> "negative one thousand two hundred thirty-four"
```

```C
HumanizeNumber(number, dest[], maxLength = sizeof dest)
```

#### Ordinals

```
0 -> 0th
1 -> 1st
2 -> 2nd
3 -> 3rd
4 -> 4th
etc...
```

```C
HumanizeOrdinal(number, dest[], maxLength = sizeof dest)
```

### License

This project is licensed under the MIT License. This license reflects our commitment to keeping the software open and accessible, while giving developers maximal freedom in how they use it. The MIT License is a permissive open-source license that allows anyone to use, modify, and distribute the software, including in commercial and closed-source projects, as long as the original copyright notice and license terms are preserved.

For more details, see `LICENSE.md`.
