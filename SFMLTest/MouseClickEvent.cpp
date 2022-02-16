#include "pch.h"
#include "MouseClickEvent.h"
using namespace TD;
MouseClickEvent::MouseClickEvent(sf::Mouse::Button Button, sf::Event::EventType Event)
{
    this->Button = Button;
    this->Event = Event;


}

bool MouseClickEvent::operator<(const MouseClickEvent& my_MouseClickEvent) const
{

    if (Event > my_MouseClickEvent.Event)
    {
        return true;
    }
    return false;
}

