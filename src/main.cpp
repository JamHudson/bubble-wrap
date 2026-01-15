#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_log.h>
#include <bn_vector.h>

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(20, 20, 31));

    bn::vector<bn::sprite_ptr, 10> circles = {};
    for (int x = -40; x < 40; x += 10)
    {
        bn::sprite_ptr newCircle = bn::sprite_items::dot.create_sprite(x, 40);
        circles.push_back(newCircle);
    }

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