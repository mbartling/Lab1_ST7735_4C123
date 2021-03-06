// ADC.h
// Runs on LM4F120/TM4C123
// Basic ADC driver. Includes support for selecting ADC0-11
// Michael Bartling
// January 2015

#ifndef __ADC_H__
#define __ADC_H__

/**
 * @brief Set up ADC on specified channel number
 * @details The parameters are default as follows
 * Timer0A: enabled
 * Mode: 32-bit, down counting
 * One-shot or periodic: periodic
 * Interval value: programmable using 32-bit period
 * Sample time is busPeriod*period
 * sample rate: <=125,000 samples/second
 * 
 * @param channelNum the desired ADC channel
 * @return 0 if successful, -1 for device driver error
 * likely indicating driver already configured. 
 */
int ADC_Open(unsigned int channelNum);
/**
 * Pseudocode
 int ADC_Open(uint32_t channelNum){
  switch(channelNum):
    select and activate clock for channel
  delay();
  switch(channelNum):
    configure port/pins for ADC I/O
  initialize(); //set ADC sample config
  activate();   //register adc
  }
 */

/**
 * @brief ADC_In gets one sample from the current ADC driver
 * @details Retrieve a 10 bit scaled value from the ADC driver
 * Must run ADC_Open before calling ADC_In, else returns error codes
 * @return 10 bit scaled sample from configured ADC. Error Codes are 
 * indicated by masking with 0xFC00. 0xFC00 denotes device not initialized.
 * Other error codes are reserved.
 */
unsigned short ADC_In(void);
/**
 * Pseudocode for ADC_In
 unsigned short ADC_In(void){
  target_sample_sequencer(3); //SS3 has a 1 sample FIFO
  synchronize_conversion();   //synchronize with ADC, could be busy wait
                              //or a timeout method
  if(synchronize failed) return error;
  result = MASK(ADC_SSFIFO);
  return result;

 }
 */


/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param int [description]
 * @param int [description]
 * @param short [description]
 * @param int [description]
 * @return [description]
 */
// int ADC_Collect(unsigned int channelNum, unsigned int fs,
				// unsigned short buffer[], unsigned int numberOfSamples);


#endif /*__ADC_H__*/
