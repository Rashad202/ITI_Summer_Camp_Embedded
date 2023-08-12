/** @file Bit_Math.h
 * 
 * @brief A header file including some Bit operations. 
 *
 * @author Rashad
 * @version 1.0
 * @date Sep 8, 2022        
 *
 */ 

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG, BIT) (REG) |=  (1 << (BIT))
#define CLR_BIT(REG, BIT) (REG) &= ~(1 << (BIT))
#define TOG_BIT(REG, BIT) (REG) ^=  (1 << (BIT))
#define GET_BIT(REG, BIT) (((REG) >> (BIT)) & 0x01 )

#endif /* BIT_MATH_H */
