#include <REGX52.H>
/**
	*	@brief	delay延时
	*	@param	无
	*	@retval	无
	*/
void Delay(unsigned char xms)
{
	unsigned int i,j;
	for(i=0;i<xms;i++){
		for(j=0;j<255;j++);
	}
}