#include <kipr/wombat.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "wheels.h"

#define RED_CHANNEL 0
#define GREEN_CHANNEL 1

void test_channel(int channel);

int main() {
    Wheels wheels = {
        .left_motor = {
            .port = 0,
            .speed = 1.0,
        },
        .right_motor = {
            .port = 1,
            .speed = 1.0,
        },
        .left_offset = 0.9,
        .right_offset = 1.0,
    };

    camera_open();

    for (int i = 0; i < 4; i++) {
        drive_wheels(wheels, FORWARD, IN(6));

        for (int i = 0; i < 10; i++) {
            camera_update();
        }

        if (get_object_count(RED_CHANNEL) > 0) {
            printf("Red!\n");
        } else {
            printf("Green!\n");
        }

        fflush(stdout);

        msleep(1000);
    }

    camera_close();

    return 0;
}

void test_channel(int channel) {
    if (get_object_count(channel) > 0) {
        int x = get_object_center_x(channel, 0);
        printf("Channel %d: x = %d\n", channel, x);
    } else {
        printf("none\n");
    }
}
