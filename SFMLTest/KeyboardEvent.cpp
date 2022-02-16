#include "pch.h"
#include "KeyboardEvent.h"
using namespace TD;
bool KeyboardEvent::operator<(const KeyboardEvent& my_KeyboardEvent) const
{
    if (my_KeyboardEvent.Keycode > this->Keycode)
        return true;
    return false;
}
