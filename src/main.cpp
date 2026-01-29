#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_log.h>
#include <bn_vector.h>
#include <bn_math.h>
#include <bn_fixed.h>
#include <bn_log.h>

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(20, 20, 31));

    bn::vector<bn::sprite_ptr, 10> circles = {};

    for (bn::fixed theta = 0.1; theta < 1.0; theta += 0.1)
    {
        bn::fixed targetX = 15 * bn::sin(theta);
        bn::fixed targetY = 15 * bn::cos(theta);
        bn::sprite_ptr newCircle = bn::sprite_items::dot.create_sprite(targetX, targetY);
        newCircle.set_scale(0.75);
        newCircle.set_vertical_scale(1.5);
        newCircle.set_rotation_angle(360 * theta);
        circles.push_back(newCircle);
    }

    double theta = 0.1;
    while (true)
    {
        if (bn::keypad::a_held())
        {
            bn::backdrop::set_color(bn::color(31, 15, 15));
            theta = theta - 0.01;
        }
        else if (bn::keypad::b_held())
        {
            bn::backdrop::set_color(bn::color(0, 31, 15));
            theta = theta + 0.01;
        }
        else
        {
            bn::backdrop::set_color(bn::color(20, 20, 31));
            theta = 0.0;
        }
        for (int i = 0; i < circles.size(); i++)
        {
            bn::sprite_ptr circle = circles.at(i);
            bn::fixed targetX = 15 * bn::sin(theta + (i * 0.1));
            bn::fixed targetY = 15 * bn::cos(theta + (i * 0.1));
            circle.set_x(targetX);
            circle.set_y(targetY);
        }
        bn::core::update();
    }
}