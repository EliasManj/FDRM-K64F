#include "user_tasks.h"

void vTask1(void *pvParameters) {
	volatile uint32_t ul;
	for (;;) {
		for (ul = 0; ul < 0xffffff; ul++) {
			RGB(1, 0, 0);
		}
	}
}

void vTask2(void *pvParameters) {
	volatile uint32_t ul;
	for (;;) {
		for (ul = 0; ul < 0xffffff; ul++) {
			RGB(0, 0, 1);
		}
	}
}

void vTask3(void *pvParameters) {

}
