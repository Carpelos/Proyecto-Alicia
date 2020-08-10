#include "kb.h"

__attribute__ ((weak))
void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	matrix_init_user();
	led_init_ports();
};

__attribute__ ((weak))
void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)
	matrix_scan_user();
};

__attribute__ ((weak))
void keyboard_pre_init_kb(void) {
    setPinOutput(D1);
    setPinOutput(D2);
    setPinOutput(D3);

    keyboard_pre_init_user();
}

bool led_update_kb(led_t led_state) {
    if (led_update_user(led_state)) {
      writePin(D2, led_state.num_lock);
      writePin(D1, led_state.caps_lock);
      writePin(D3, led_state.scroll_lock);
    }
    return true;
}

