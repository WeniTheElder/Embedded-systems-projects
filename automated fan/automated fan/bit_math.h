#ifndef EMBEDDED_SYS_BIT_WISE_FUNCITONS_H
#define EMBEDDED_SYS_BIT_WISE_FUNCITONS_H

#define SET_BIT(VAR,BIT_NUM)    VAR |= (1<<BIT_NUM)     //0->1
#define CLEAR_BIT(VAR,BIT_NUM)  VAR &= (~(1<<BIT_NUM))  //1->0
#define TOGGLE_BIT(VAR,BIT_NUM) VAR ^= (1<<BIT_NUM)     //1->0 or 0->1
#define GET_BIT(VAR,BIT_NUM)    ((VAR>>BIT_NUM)&1)      //GETS BIT

#endif

