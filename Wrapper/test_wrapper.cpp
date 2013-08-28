#include "wrapper.h"

int main(void)
{
	Wrapper<int> i1, i2, i3;
	i1.Assign(3, 2);
	i2 = i1;
	i1.MoveTo(i3);
}
