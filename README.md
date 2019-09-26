# QStyleSheetString

QStyleSheetString is a class for pretty creating, saving, editing and getting CSS StyleSheet for Qt object. This class ONLY for Qt (because he uses another Qt classes). 

![photo]

## Installation

Just download this ![files](https://github.com/TheBestTvarynka/QStyleSheetString/tree/develop/QStyleSheetString).
And include this class to project:
```cpp
#include "path/to/class/QStyleSheetString.h"
```
Don't forget to inslude this class to .pro file (or another configuration file of project).

## Usage example

Simle example how to use QStyleSheetString:
```cpp
    // in constructor we set name of object
    QStyleSheetString style("QPushButton");
    // set propereties
    style.SetPropereties("", "color", "#86ab29");
    style.SetPropereties("", "background", "#ffffff");
    style.SetPropereties("", "border", "2px solid grey");
    style.SetPropereties("", "border-radius", "5px");
    style.SetPropereties(":hover", "color", "#ffffff");
    style.SetPropereties(":hover", "border", "2px solid #1d7f88");
    style.SetPropereties(":hover", "background", "#f24bef");
    // apple style to our button
    ui->button1->setStyleSheet(style.GetStyleSheet());
```
Result:
![](https://github.com/TheBestTvarynka/QStyleSheetString/blob/master/img/example.gif)

_For more examples and usage, please refer to the [Wiki][wiki]._


## Release History

* v.0.1
    * Can create, edit and remove selectors...

## Meta

Pavlo Myroniuk – [@TheBestTvarynka](https://t.me/TheBestTvarynka) – pspos.developqkation@gmail.com

Distributed under the GNU General Public License v3.0 license. See ``LICENSE`` for more information.

[https://github.com/TheBestTvarynka/QStyleSheetString](https://github.com/TheBestTvarynka/QStyleSheetString)

## Contributing

1. Fork it (<https://github.com/TheBestTvarynka/QStyleSheetString>)
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request
