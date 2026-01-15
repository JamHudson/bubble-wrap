#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(20, 20, 31));

    while (true)
    {
        if (bn::keypad::a_held())
        {
            bn::backdrop::set_color(bn::color(31, 15, 15));
        }
        else if (bn::keypad::b_held())
        {
            bn::backdrop::set_color(bn::color(0, 31, 15));
        }
        else
        {
            bn::backdrop::set_color(bn::color(20, 20, 31));
        }
        bn::core::update();
    }
}