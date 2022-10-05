#include "blink.h"

volatile int var = 100;
volatile int var2;
volatile int arr[100];

int main(void)
{

    var = 5000 * 5000;

	blink_init();

	for(;;){

		blink();
	}
}
