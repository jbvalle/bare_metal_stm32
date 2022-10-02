#include "blink.h"


int main(void)
{
	blink_init();

	for(;;){

		blink();
	}
}
