MEMORY
{
PAGE 0 :
   FLASH_E      : origin = 0x3E8000, length = 0x004000
   FLASH_D      : origin = 0x3EC000, length = 0x004000
   FLASH_C      : origin = 0x3F0000, length = 0x004000
   FLASH_B      : origin = 0x3F4000, length = 0x002000
   FLASH_A      : origin = 0x3F6000, length = 0x001FF8
   PASSWORDS    : origin = 0x3F7FF8, length = 0x000008
}
 
SECTIONS
{
   flash_A          : > FLASH_A,     PAGE = 0
   flash_B          : > FLASH_B,     PAGE = 0
   flash_C          : > FLASH_C,     PAGE = 0
   flash_D          : > FLASH_D,     PAGE = 0
   flash_E          : > FLASH_E,     PAGE = 0
}