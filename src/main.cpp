#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(20, 20, 31));

    bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(10, 40);

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