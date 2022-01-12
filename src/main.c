#include <kipr/wombat.h>
#include "wheels.h"

// #define RED_CHANNEL 0
// #define GREEN_CHANNEL 1
// #define BLUE_CHANNEL 2

// void test_channel(int channel) {
//     if (get_object_count(channel) > 0) {
//         int x = get_object_center_x(channel, 0);
//         printf("Channel %d: x = %d\n", channel, x);
//     }
// }

int main() {
    // camera_open();

    // while (1) {
    //     camera_update();

    //     test_channel(RED_CHANNEL);
    //     test_channel(GREEN_CHANNEL);
    //     test_channel(BLUE_CHANNEL);

    //     msleep(100);
    // }

    Wheels wheels = {
        .left_motor = {
            .port = 0,
            .speed = 1.0,
        },
        .right_motor = {
            .port = 1,
            .speed = 1.0,
        },
        .left_offset = 1.0,
        .right_offset = 1.0,
    };

    drive_wheels(wheels, FORWARD, CM(5));
    drive_wheels(wheels, REVERSE, CM(5));

    return 0;
}
