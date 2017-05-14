/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 *   lsbZero - set 0 to the least significant bit of x 
 *   Example: lsbZero(0x87654321) = 0x87654320
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 1
 */
int lsbZero(int x) {  
  return (x>>1)<<1;                     //先右移一位，再左移一位(低位补0,从而将最低位置0)
}
/* 
 * byteNot - bit-inversion to byte n from word x  
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByteNot(0x12345678,1) = 0x1234A978
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int byteNot(int x, int n) {
  //核心思想:与0异或的结果是其本身，与1异或的结果是该位取反
  return (255<<(n<<3))^x;               //(n<<3)为n*8
}
/* 
 *   byteXor - compare the nth byte of x and y, if it is same, return 0, if not, return 1

 *   example: byteXor(0x12345678, 0x87654321, 1) = 1

 *			  byteXor(0x12345678, 0x87344321, 2) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2 
 */
int byteXor(int x, int y, int n) {
  //核心思想:与0异或的结果是其本身，与1异或的结果是该位取反
  //return !!(((255<<(n<<3)) & x) ^ ((255<<(n<<3)) & y));  //将对应字节取反,用!!保证结果为1或0
  return !!(((x^y)>>(n<<3)) & 0xff);
}
/* 
 *   logicalAnd - x && y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalAnd(int x, int y) {
  //核心思想: &&等价与(x!=0)&(y!=0)
  return (!!(x^0) & !!(y^0));
}
/* 
 *   logicalOr - x || y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalOr(int x, int y) {
  //核心思想: ||等价与(x!=0)|(y!=0)
  return (!!(x^0) | !!(y^0));
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
  int tmp;
  int i = 0;
  tmp = x<<n;                                       //低位向高位左移n位，得到结果的前(32-n)位 
  tmp += ((x>>(((~n) & 31)))>>1 & (~((~i)<<n)));    //(~((~i)<<n))得到前(32-n)位为0后位为1的掩码
  //tmp += ((x>>(33 + ~n)) & (~((~i)<<n)));           //x>>(33 + ~n) = x>>(32 + ~n +1) = x>>(32 - n)
  return tmp;                                       //32-n=~n+1,故上条语句&前表示x右移(32-n)位
}
/*
 * parityCheck - returns 1 if x contains an odd number of 1's
 *   Examples: parityCheck(5) = 0, parityCheck(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int parityCheck(int x) {
  int tmp;              
  tmp = x>>16;
  x ^= tmp;             //高16位和低16位异或,得到16位结果
  tmp = x>>8;
  x ^= tmp;             //上述16位结果高8位和低8位异或，得到8位结果
  tmp = x>>4;       
  x ^= tmp;             //高4位和低4位异或
  tmp = x>>2;
  x ^= tmp;             //高2位和低2位异或
  tmp = x>>1;
  x ^= tmp;             //高位和低位异或，得到最后结果
  return (x & 1);
}
/*
 * mul2OK - Determine if can compute 2*x without overflow
 *   Examples: mul2OK(0x30000000) = 1
 *             mul2OK(0x40000000) = 0
 *         
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2
 */
int mul2OK(int x) {
  //核心思想:判断x*2和x的符号位是否相同
  int tmp;
  tmp = x + x;
  return (~(((tmp>>31) & 1) ^ ((x>>31) & 1))) & 1;
  //return ~(((x<<1)^x)>>31) & 1;
}
/*
 * mult3div2 - multiplies by 3/2 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/2),
 *   including overflow behavior.
 *   Examples: mult3div2(11) = 16
 *             mult3div2(-9) = -13
 *             mult3div2(1073741824) = -536870912(overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int mult3div2(int x) {
  int mult;
  int div;
  mult = ((x<<1) + x);  //x*3
  div  = mult>>1;       //x*3/2,但该结果是向下取整，并非向0取整
  div += (((x>>31) & x) & 1) & !((mult ^ x)>>31);   //当x是负奇数且乘法结果没溢出时修正结果
  /* Or use another way
  mult = ((x<<1) + x);      //x*3
  mult += (mult>>31) & 1;   //如果mult为负数，加一个偏移量（2^k-1)=1进行校正
  div  = mult>>1;           //x*3/2
  */
  return div;
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20 *   Rating: 3
 */
int subOK(int x, int y) {
  int cpl;
  int tmp;
  cpl = ~y + 1;         //利用补码，将减法转变为加法
  tmp = x + cpl;
  return (((~(x ^ y) | ~(x ^ tmp))>>31) & 1);   //当x、y异号且结果符号与x不相同时发生溢出
  //return ((~((x^y) & (x^tmp)))>>31) & 1;
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  int sgn;
  int tmp;
  sgn = x>>31;      //得到符号掩码0xffffffff(-)或0(+)
  tmp = ~x;
  tmp += 1;         //tmp=-x
  tmp = tmp & sgn; 
  tmp += x & (~sgn);//相当于tmp=-x+0或tmp=0+x
  return tmp;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  unsigned tail = 0;
  unsigned exp = 0;
  unsigned tmp = 0;
  tail = (uf<<9)>>9;    //取尾数
  tmp  = tail;          
  exp = uf & (255<<23); //取阶码
  tmp += exp;
  if ((!((exp>>23) ^ 255)) && (tail ^ 0))
    return uf;          //阶码全1且尾数非0表示NaN
  else
    return tmp;         //符号位为0
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  unsigned tail = 0;
  int exp = 0;
  int tmp = 0;          //用于存放最后结果
  int offset = 127;     //阶码的偏移值
  int num = 0;          //用于计算阶码对应的2的指数
  tail = (uf<<9)>>9;    //取尾数
  exp = (uf>>23) & 255; //取阶码
  offset = ~offset;
  offset += 1;          //-offset
  num = exp;
  num += offset;        //指数=阶码-127
  if ((num>>31) & 1)
    return 0;           //指数小于0,表明转化为整数后为0
  if (!(exp ^ 255))
    return 0x80000000;  //阶码全1,对应正负无穷以及NaN
  else
  {
    tmp += 1;           //1.f中的1
    while(num ^ 0)
    {
      tmp = tmp<<1;     //tmp左移一位，相当于*2
      tmp += (tail>>22) & 1; //尾数最高位放到tmp最低位
      tail = tail<<1;   //尾数左移，当前最高位的下一位成为最高位
      num += ~0;        //num-1
    }
    if (!(tmp ^ 0))     //如果tmp为0,表明尾数全被左移出去，则指数过大
      return 0x80000000;//溢出，超过int表示的范围
    else if ((uf>>31) & 1) //若uf为负的
    {
        tmp = ~tmp;     
        tmp += 1;       //tmp=-tmp
    }
    return tmp;
  }
}
