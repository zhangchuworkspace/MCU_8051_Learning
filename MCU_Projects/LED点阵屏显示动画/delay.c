
void Delay(unsigned int xms){
	unsigned char i,j;
	for(i=0;i<xms;i++){
		for(j=0;j<255;j++);
	}
}
