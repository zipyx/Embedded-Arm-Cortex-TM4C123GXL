#define RCGCGPIO (*((unsigned int *)0x400FE608U))
#define GPIOF_BASE 0x40025000U
#define GPIOF_DIR (*((unsigned int *)(GPIOF_BASE + 0x400U)))
#define GPIOF_DEN (*((unsigned int *)(GPIOF_BASE + 0x51CU)))
#define GPIOF_DATA (*((unsigned int *)(GPIOF_BASE + 0x3FCU)))

int main()
{
  /*
    Embedded Project -     
        Device          : Arm Cortex - TI Stellaris
        Model           : TM4C123GXL
        Description     : LED Light Blinker
    Data Sheet - 
        PIN             : RCGCGPIO
        Base            : 0x400FE000
        Offset          : 0x608
        Symbolic Memory : 0x400FE608
        Base Ram Block  : 0x40025000
    KeyWords -
        Volatile : Tells the compiler that the object pointed to
                   by the pointer, might change spontaneously.
  */
  
  // GPIO F Block On
  RCGCGPIO = 0x20U;
  
  // GPIO Port F Pin Direction Register
  GPIOF_DIR = 0x0EU;
  
  // Digital Function Register
  GPIOF_DEN = 0x0EU;

  // ---------------------------------------------------
  // LED Lights Schema
  // ---------------------------------------------------
  GPIOF_DATA = 0x02U; // Red
  GPIOF_DATA = 0x04U; // Blue
  GPIOF_DATA = 0x08U; // Green
  // ---------------------------------------------------
  
  // Blinker Conditional
  while (1) {
    // Set Counter for Timer
    int counter = 0;
    
    // Blink with favourite LED Light - Turqoise
    GPIOF_DATA = 0x0CU;
    while (counter < 1000000) {
      ++counter;
    }
    
    // Blinker Off
    timer();
    
    // Blink with Red LED
    counter = 0;
    GPIOF_DATA = 0x02U;
    while (counter < 1000000) {
      ++counter;
    }
    
    // Blinker Off
    timer();
    
    // Blink with Blue LED
    counter = 0;
    GPIOF_DATA = 0x04U;
    while (counter < 1000000) {
      ++counter;
    }
    
    // Blinker Off
    timer();
    
    // Blink with Green LED
    counter = 0;
    GPIOF_DATA = 0x08U;
    while (counter < 1000000) {
      ++counter;
    }
    timer();
  }
  return 0;
}

int timer() {
  
  // Blinker Off
  int counter = 0;
  GPIOF_DATA = 0x00U;
  while (counter < 1000000) {
    ++counter;
  }
  return 0;
}