#pragma once

#include <stack>
#include <string>

class clsMyString
{
private:
    stack<string> _Undo;
    stack<string> _Redo;
    string _Value;

public:
    clsMyString() {};

    void Value(string NewValue)
    {
        _Undo.push(_Value);
        _Value = NewValue;
    }

    string Value()
    {
        return _Value;
    }

    void Undo()
    {
        if (!_Undo.empty())
        {
            _Redo.push(_Value);
            _Value = _Undo.top();
            _Undo.pop();
        }
    }

    void Redo()
    {
        if (!_Redo.empty())
        {
            _Undo.push(_Value);
            _Value = _Redo.top();
            _Redo.pop();
        }
    }
};

/*

🧾 ملخص التغيرات

+-------------------+--------+-----------+-----------+
| الحالة            | _Value | _Undo     | _Redo     |
+-------------------+--------+-----------+-----------+
| بعد البداية       | ""     | []        | []        |
| بعد Value("A")    | "A"    | [""]      | []        |
| بعد Value("B")    | "B"    | ["", "A"] | []        |
| بعد Undo() الأول  | "A"    | [""]      | ["B"]     |
| بعد Undo() الثاني | ""     | []        | ["B", "A"]|
| بعد Redo() الأول  | "A"    | [""]      | ["B"]     |
| بعد Redo() الثاني | "B"    | ["", "A"] | []        |
+-------------------+--------+-----------+-----------+


*/