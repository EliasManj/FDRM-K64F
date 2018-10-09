/* ###################################################################
**     Filename    : UTIL1.c
**     Project     : PE_FreeRTOS
**     Processor   : MK64FN1M0VLQ12
**     Component   : Utility
**     Version     : Component 01.158, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-10-05, 09:30, # CodeGen: 1
**     Abstract    :
**          Contains various utility functions.
**     Settings    :
**          Component name                                 : UTIL1
**     Contents    :
**         strcpy                  - void UTIL1_strcpy(uint8_t *dst, size_t dstSize, const unsigned char *src);
**         strcat                  - void UTIL1_strcat(uint8_t *dst, size_t dstSize, const unsigned char *src);
**         strcatPad               - void UTIL1_strcatPad(uint8_t *dst, size_t dstSize, const unsigned char *src,...
**         chcat                   - void UTIL1_chcat(uint8_t *dst, size_t dstSize, uint8_t ch);
**         Num8sToStr              - void UTIL1_Num8sToStr(uint8_t *dst, size_t dstSize, signed char val);
**         Num8uToStr              - void UTIL1_Num8uToStr(uint8_t *dst, size_t dstSize, uint8_t val);
**         Num16sToStr             - void UTIL1_Num16sToStr(uint8_t *dst, size_t dstSize, int16_t val);
**         Num16uToStr             - void UTIL1_Num16uToStr(uint8_t *dst, size_t dstSize, uint16_t val);
**         Num32uToStr             - void UTIL1_Num32uToStr(uint8_t *dst, size_t dstSize, uint32_t val);
**         Num32sToStr             - void UTIL1_Num32sToStr(uint8_t *dst, size_t dstSize, int32_t val);
**         NumFloatToStr           - void UTIL1_NumFloatToStr(uint8_t *dst, size_t dstSize, float val, uint8_t...
**         Num16sToStrFormatted    - void UTIL1_Num16sToStrFormatted(uint8_t *dst, size_t dstSize, int16_t val,...
**         Num16uToStrFormatted    - void UTIL1_Num16uToStrFormatted(uint8_t *dst, size_t dstSize, uint16_t val,...
**         Num32uToStrFormatted    - void UTIL1_Num32uToStrFormatted(uint8_t *dst, size_t dstSize, uint32_t val,...
**         Num32sToStrFormatted    - void UTIL1_Num32sToStrFormatted(uint8_t *dst, size_t dstSize, int32_t val,...
**         strcatNum8u             - void UTIL1_strcatNum8u(uint8_t *dst, size_t dstSize, uint8_t val);
**         strcatNum8s             - void UTIL1_strcatNum8s(uint8_t *dst, size_t dstSize, signed char val);
**         strcatNum16u            - void UTIL1_strcatNum16u(uint8_t *dst, size_t dstSize, uint16_t val);
**         strcatNum16s            - void UTIL1_strcatNum16s(uint8_t *dst, size_t dstSize, int16_t val);
**         strcatNum32u            - void UTIL1_strcatNum32u(uint8_t *dst, size_t dstSize, uint32_t val);
**         strcatNum32s            - void UTIL1_strcatNum32s(uint8_t *dst, size_t dstSize, int32_t val);
**         strcatNum16uFormatted   - void UTIL1_strcatNum16uFormatted(uint8_t *dst, size_t dstSize, uint16_t val,...
**         strcatNum16sFormatted   - void UTIL1_strcatNum16sFormatted(uint8_t *dst, size_t dstSize, int16_t val,...
**         strcatNum32uFormatted   - void UTIL1_strcatNum32uFormatted(uint8_t *dst, size_t dstSize, uint32_t val,...
**         strcatNum32sFormatted   - void UTIL1_strcatNum32sFormatted(uint8_t *dst, size_t dstSize, int32_t val,...
**         strcatNum8Hex           - void UTIL1_strcatNum8Hex(uint8_t *dst, size_t dstSize, uint8_t num);
**         strcatNum16Hex          - void UTIL1_strcatNum16Hex(uint8_t *dst, size_t dstSize, uint16_t num);
**         strcatNum24Hex          - void UTIL1_strcatNum24Hex(uint8_t *dst, size_t dstSize, uint32_t num);
**         strcatNum32Hex          - void UTIL1_strcatNum32Hex(uint8_t *dst, size_t dstSize, uint32_t num);
**         strcatNum32sDotValue100 - void UTIL1_strcatNum32sDotValue100(uint8_t *dst, size_t dstSize, int32_t num);
**         strcatNumFloat          - void UTIL1_strcatNumFloat(uint8_t *dst, size_t dstSize, float val, uint8_t...
**         IsLeapYear              - bool UTIL1_IsLeapYear(uint16_t year);
**         WeekDay                 - uint8_t UTIL1_WeekDay(uint16_t year, uint8_t month, uint8_t day);
**         ReadEscapedName         - uint8_t UTIL1_ReadEscapedName(const unsigned char *filename, uint8_t...
**         xatoi                   - uint8_t UTIL1_xatoi(const unsigned char **str, int32_t *res);
**         ScanDate                - uint8_t UTIL1_ScanDate(const unsigned char **str, uint8_t *day, uint8_t...
**         ScanTime                - uint8_t UTIL1_ScanTime(const unsigned char **str, uint8_t *hour, uint8_t...
**         ScanDecimal8uNumber     - uint8_t UTIL1_ScanDecimal8uNumber(const unsigned char **str, uint8_t *val);
**         ScanDecimal8sNumber     - uint8_t UTIL1_ScanDecimal8sNumber(const unsigned char **str, signed char *val);
**         ScanDecimal16uNumber    - uint8_t UTIL1_ScanDecimal16uNumber(const unsigned char **str, uint16_t *val);
**         ScanDecimal16sNumber    - uint8_t UTIL1_ScanDecimal16sNumber(const unsigned char **str, int16_t *val);
**         ScanDecimal32uNumber    - uint8_t UTIL1_ScanDecimal32uNumber(const unsigned char **str, uint32_t *val);
**         ScanDecimal32sNumber    - uint8_t UTIL1_ScanDecimal32sNumber(const unsigned char **str, int32_t *val);
**         ScanDecimal32sDotNumber - uint8_t UTIL1_ScanDecimal32sDotNumber(const unsigned char **str, int32_t...
**         ScanHex8uNumber         - uint8_t UTIL1_ScanHex8uNumber(const unsigned char **str, uint8_t *val);
**         ScanHex8uNumberNoPrefix - uint8_t UTIL1_ScanHex8uNumberNoPrefix(const unsigned char **str, uint8_t *val);
**         ScanHex16uNumber        - uint8_t UTIL1_ScanHex16uNumber(const unsigned char **str, uint16_t *val);
**         ScanHex32uNumber        - uint8_t UTIL1_ScanHex32uNumber(const unsigned char **str, uint32_t *val);
**         ScanSeparatedNumbers    - uint8_t UTIL1_ScanSeparatedNumbers(const unsigned char **str, uint8_t...
**         ScanDoubleQuotedString  - uint8_t UTIL1_ScanDoubleQuotedString(const uint8_t **cmd, uint8_t *buf,...
**         strcmp                  - int16_t UTIL1_strcmp(const char *, const char *);
**         strncmp                 - int16_t UTIL1_strncmp(const char *, const char *, size_t size);
**         strFind                 - int16_t UTIL1_strFind(uint8_t *str, uint8_t *subStr);
**         strtailcmp              - uint8_t UTIL1_strtailcmp(const uint8_t *str, const uint8_t *tail);
**         strlen                  - uint16_t UTIL1_strlen(const char *);
**         strCutTail              - uint8_t UTIL1_strCutTail(uint8_t *str, uint8_t *tail);
**         GetValue16LE            - uint16_t UTIL1_GetValue16LE(uint8_t *dataP);
**         GetValue24LE            - uint32_t UTIL1_GetValue24LE(uint8_t *dataP);
**         GetValue32LE            - uint32_t UTIL1_GetValue32LE(uint8_t *dataP);
**         SetValue16LE            - void UTIL1_SetValue16LE(uint16_t data, uint8_t *dataP);
**         SetValue24LE            - void UTIL1_SetValue24LE(uint32_t data, uint8_t *dataP);
**         SetValue32LE            - void UTIL1_SetValue32LE(uint32_t data, uint8_t *dataP);
**         map                     - int32_t UTIL1_map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min,...
**         map64                   - int64_t UTIL1_map64(int64_t x, int64_t in_min, int64_t in_max, int64_t...
**         constrain               - int32_t UTIL1_constrain(int32_t val, int32_t min, int32_t max);
**         random                  - int32_t UTIL1_random(int32_t min, int32_t max);
**         randomSetSeed           - void UTIL1_randomSetSeed(unsigned int seed);
**         Deinit                  - void UTIL1_Deinit(void);
**         Init                    - void UTIL1_Init(void);
**
**     * Copyright (c) 2014-2018, Erich Styger
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file UTIL1.c
** @version 01.00
** @brief
**          Contains various utility functions.
*/         
/*!
**  @addtogroup UTIL1_module UTIL1 module documentation
**  @{
*/         

/* MODULE UTIL1. */

#include "UTIL1.h"
#include <stdlib.h> /* for rand() */

/* Internal method prototypes */
static void ShiftRightAndFill(uint8_t *dst, uint8_t fill, uint8_t nofFill);

/*
** ===================================================================
**     Method      :  UTIL1_strcpy (component Utility)
**     Description :
**         Same as normal strcpy, but safe as it does not write beyond
**         the buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**       * src             - Pointer to source string.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief copy the string src into dst. It performs the same task as strncpy, except
     - always terminates the result string.
     - does not zero out the remaining part in dst.
     Note: dstSize is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] src The source string to copy
*/
void UTIL1_strcpy(uint8_t *dst, size_t dstSize, const unsigned char *src)
{
  dstSize--; /* for zero byte */
  while (dstSize > 0 && *src != '\0') {
    *dst++ = *src++;
    dstSize--;
  }
  *dst = '\0';
}

/*
** ===================================================================
**     Method      :  UTIL1_strcat (component Utility)
**     Description :
**         Same as normal strcat, but safe as it does not write beyond
**         the buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**       * src             - Pointer to source string.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Concat the string src into dst. Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] src The source string to add
  */
void UTIL1_strcat(uint8_t *dst, size_t dstSize, const unsigned char *src)
{
  dstSize--; /* for zero byte */
  /* point to the end of the source */
  while (dstSize > 0 && *dst != '\0') {
    dst++;
    dstSize--;
  }
  /* copy the src in the destination */
  while (dstSize > 0 && *src != '\0') {
    *dst++ = *src++;
    dstSize--;
  }
  /* terminate the string */
  *dst = '\0';
}

/*
** ===================================================================
**     Method      :  UTIL1_chcat (component Utility)
**     Description :
**         Adds a single character to a zero byte terminated string
**         buffer. It cares about buffer overflow.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         ch              - character to append
**     Returns     : Nothing
** ===================================================================
*/
void UTIL1_chcat(uint8_t *dst, size_t dstSize, uint8_t ch)
{
  dstSize--; /* for zero byte */
  /* point to the end of the source */
  while (dstSize > 0 && *dst != '\0') {
    dst++;
    dstSize--;
  }
  /* copy the ch in the destination */
  if (dstSize > 0) {
    *dst++ = ch;
  }
  /* terminate the string */
  *dst = '\0';
}

/*
** ===================================================================
**     Method      :  UTIL1_Num8uToStr (component Utility)
**     Description :
**         Converts an unsigned 8bit value into a string.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to be converted.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Converts an 8bit unsigned number into a string.
  \param[in,out] dst String buffer to store the number.
  \param[in] dstSize Size of the destination buffer in uint8_ts.
  \param[in] val 8bit unsigned number to convert.
 */
void UTIL1_Num8uToStr(uint8_t *dst, size_t dstSize, uint8_t val)
{
  UTIL1_Num16uToStr(dst, dstSize, (uint16_t)val);
}

/*
** ===================================================================
**     Method      :  UTIL1_Num8sToStr (component Utility)
**     Description :
**         Converts a signed 8bit value into a string.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to be converted.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Converts an 8bit signed number into a string.
  \param[in,out] dst String buffer to store the number.
  \param[in] dstSize Size of the destination buffer in uint8_ts.
  \param[in] val 8bit signed number to convert.
 */
void UTIL1_Num8sToStr(uint8_t *dst, size_t dstSize, signed char val)
{
  UTIL1_Num16sToStr(dst, dstSize, (int16_t)val);
}

/*
** ===================================================================
**     Method      :  UTIL1_Num16uToStr (component Utility)
**     Description :
**         Converts a signed 16bit value into a string.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to be converted.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Converts a 16bit unsigned number into a string.
  \param[in,out] dst String buffer to store the number.
  \param[in] dstSize Size of the destination buffer in uint8_ts.
  \param[in] val 16bit unsigned number to convert.
 */
void UTIL1_Num16uToStr(uint8_t *dst, size_t dstSize, uint16_t val)
{
  unsigned char *ptr = ((unsigned char *)dst);
  unsigned char i=0, j;
  unsigned char tmp;

  dstSize--; /* for zero byte */
  if (val == 0 && dstSize > 0){
    ptr[i++] = '0';
    dstSize--;
  }
  while (val > 0 && dstSize > 0) {
    ptr[i++] = (unsigned char)((val % 10) + '0');
    dstSize--;
    val /= 10;
  }
  for(j=0; j<(i/2); j++) { /* swap buffer */
    tmp = ptr[j];
    ptr[j] = ptr[(i-j)-1];
    ptr[(i-j)-1] = tmp;
  }
  ptr[i] = '\0';
}

/*
** ===================================================================
**     Method      :  UTIL1_Num16sToStr (component Utility)
**     Description :
**         Converts a signed 16bit value into a string.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to be converted.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Converts a 16bit signed number into a string.
  \param[in,out] dst String buffer to store the number.
  \param[in] dstSize Size of the destination buffer in uint8_ts.
  \param[in] val 16bit signed number to convert.
 */
void UTIL1_Num16sToStr(uint8_t *dst, size_t dstSize, int16_t val)
{
  unsigned char *ptr =  ((unsigned char *)dst);
  unsigned char i=0, j;
  unsigned char tmp;
  unsigned char sign = (unsigned char)(val < 0);

  if (val==(int16_t)(0x8000)) { /* special case 0x8000/-32768: prevent overflow below. */
    UTIL1_strcpy(dst, dstSize, (unsigned char*)"-32768");
    return;
  }
  dstSize--; /* for zero byte */
  if (sign) {
    val = (int16_t)(-val);
  }
  if (val == 0 && dstSize > 0){
    ptr[i++] = '0';
    dstSize--;
  }
  while (val > 0 && dstSize > 0) {
    ptr[i++] = (unsigned char)((val % 10) + '0');
    dstSize--;
    val /= 10;
  }
  if (sign && dstSize > 0){
    ptr[i++] = '-';
  }
  for(j=0; j<(i/2); j++) { /* swap buffer */
    tmp = ptr[j];
    ptr[j] = ptr[(i-j)-1];
    ptr[(i-j)-1] = tmp;
  }
  ptr[i] = '\0';
}

/*
** ===================================================================
**     Method      :  ShiftRightAndFill (component Utility)
**
**     Description :
**         Moves the content of a string to the right and fills the space 
**         on the left side with a pattern
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void ShiftRightAndFill(uint8_t *dst, uint8_t fill, uint8_t nofFill)
{
  signed char i, j;

  j = 0;
  while(dst[j] != '\0') {
    j++;
  }
  i = (signed char)nofFill;
  if (i==j) {
    /* nothing to do, we are done */
  } else if (i>j) {
    while (j>=0) {
      dst[i] = dst[j];
      i--; j--;
    }
    while(i>=0) {
      dst[i] = fill;
      i--;
    }
  } else {
    /* hmmm, not enough space, return what we have, do nothing */
  }
}

/*
** ===================================================================
**     Method      :  UTIL1_Num16sToStrFormatted (component Utility)
**     Description :
**         Converts a 16bit signed value to string.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**         fill            - Fill character
**         nofFill         - Number of fill characters
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Converts a 16bit signed number to a string, in a formatted way (like printf with "%0d").
     Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize Size of the destination buffer, in uint8_ts.
  \param[in] val The 16bit signed number to add
  \param[in] fill Fill character, typically ' ' (like for "%2d" or '0' (for "%02d")
  \param[in] nofFill Size for the format (right aligned) string, e.g. '2' for "%2d"
*/
void UTIL1_Num16sToStrFormatted(uint8_t *dst, size_t dstSize, int16_t val, char fill, uint8_t nofFill)
{
  UTIL1_Num16sToStr(dst, dstSize, val);
  ShiftRightAndFill(dst, fill, nofFill);
}

/*
** ===================================================================
**     Method      :  UTIL1_Num16uToStrFormatted (component Utility)
**     Description :
**         Converts a 16bit unsigned value to string.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**         fill            - Fill character
**         nofFill         - Number of fill characters
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Converts a 16bit unsigned number to a string, in a formatted way (like printf with "%0d").
     Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize Size of the destination buffer, in uint8_ts.
  \param[in] val The 16bit unsigned number to add
  \param[in] fill Fill character, typically ' ' (like for "%2d" or '0' (for "%02d")
  \param[in] nofFill Size for the format (right aligned) string, e.g. '2' for "%2d"
*/
void UTIL1_Num16uToStrFormatted(uint8_t *dst, size_t dstSize, uint16_t val, char fill, uint8_t nofFill)
{
  UTIL1_Num16uToStr(dst, dstSize, val);
  ShiftRightAndFill(dst, fill, nofFill);
}

/*
** ===================================================================
**     Method      :  UTIL1_Num32uToStrFormatted (component Utility)
**     Description :
**         Converts a 32bit unsigned value to string.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**         fill            - Fill character
**         nofFill         - Number of fill characters
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Converts a 32bit unsigned number to a string, in a formatted way (like printf with "%0d").
     Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize Size of the destination buffer, in uint8_ts.
  \param[in] val The 32bit unsigned number to add
  \param[in] fill Fill character, typically ' ' (like for "%2d" or '0' (for "%02d")
  \param[in] nofFill Size for the format (right aligned) string, e.g. '2' for "%2d"
*/
void UTIL1_Num32uToStrFormatted(uint8_t *dst, size_t dstSize, uint32_t val, char fill, uint8_t nofFill)
{
  UTIL1_Num32uToStr(dst, dstSize, val);
  ShiftRightAndFill(dst, fill, nofFill);
}

/*
** ===================================================================
**     Method      :  UTIL1_Num32sToStrFormatted (component Utility)
**     Description :
**         Converts a 32bit signed value to string.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**         fill            - Fill character
**         nofFill         - Number of fill characters
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Converts a 32bit signed number to a string, in a formatted way (like printf with "%0d").
     Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize Size of the destination buffer, in uint8_ts.
  \param[in] val The 32bit signed number to add
  \param[in] fill Fill character, typically ' ' (like for "%2d" or '0' (for "%02d")
  \param[in] nofFill Size for the format (right aligned) string, e.g. '2' for "%2d"
*/
void UTIL1_Num32sToStrFormatted(uint8_t *dst, size_t dstSize, int32_t val, char fill, uint8_t nofFill)
{
  UTIL1_Num32sToStr(dst, dstSize, val);
  ShiftRightAndFill(dst, fill, nofFill);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum8u (component Utility)
**     Description :
**         Appends a 8bit unsigned value to a string buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief appends a 8bit unsigned number to a string. Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] val The 8bit unsigned number to add
  */
void UTIL1_strcatNum8u(uint8_t *dst, size_t dstSize, uint8_t val)
{
  unsigned char buf[sizeof("256")]; /* maximum buffer size we need */

  UTIL1_Num8uToStr(buf, sizeof(buf), val);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum8s (component Utility)
**     Description :
**         Appends a 8bit signed value to a string buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief appends a 8bit signed number to a string. Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] val The 8bit signed number to add
  */
void UTIL1_strcatNum8s(uint8_t *dst, size_t dstSize, signed char val)
{
  unsigned char buf[sizeof("-128")]; /* maximum buffer size we need */

  UTIL1_Num8sToStr(buf, sizeof(buf), val);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum16u (component Utility)
**     Description :
**         Appends a 16bit unsigned value to a string buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief appends a 16bit unsigned number to a string. Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] val The 16bit unsigned number to add
  */
void UTIL1_strcatNum16u(uint8_t *dst, size_t dstSize, uint16_t val)
{
  unsigned char buf[sizeof("32768")]; /* maximum buffer size we need */

  UTIL1_Num16uToStr(buf, sizeof(buf), val);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum16s (component Utility)
**     Description :
**         Appends a 16bit signed value to a string buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief appends a 16bit signed number to a string. Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] val The 16bit signed number to add
  */
void UTIL1_strcatNum16s(uint8_t *dst, size_t dstSize, int16_t val)
{
  unsigned char buf[sizeof("-32768")]; /* maximum buffer size we need */

  UTIL1_Num16sToStr(buf, sizeof(buf), val);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum16uFormatted (component Utility)
**     Description :
**         Appends a 16bit unsigned value to a string buffer in a
**         formatted way.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**         fill            - Fill character
**         nofFill         - Number of fill characters
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief appends a 16bit unsigned number to a string, in a formatted way (like printf with "%0d".
     Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] val The 16bit unsigned number to add
  \param[in] fill Fill character
  \param[in] nofFill Number of fill characters
  */
void UTIL1_strcatNum16uFormatted(uint8_t *dst, size_t dstSize, uint16_t val, char fill, uint8_t nofFill)
{
  unsigned char buf[sizeof("32768")]; /* maximum buffer size we need */

  UTIL1_Num16uToStrFormatted(buf, dstSize, val, fill, nofFill);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum16sFormatted (component Utility)
**     Description :
**         Appends a 16bit signed value to a string buffer in a
**         formatted way.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**         fill            - Fill character
**         nofFill         - Number of fill characters
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief appends a 16bit signed number to a string, in a formatted way (like printf with "%0d".
     Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] val The 16bit signed number to add
  \param[in] fill Fill character
  \param[in] nofFill Number of fill characters
  */
void UTIL1_strcatNum16sFormatted(uint8_t *dst, size_t dstSize, int16_t val, char fill, uint8_t nofFill)
{
  unsigned char buf[sizeof("-32768")]; /* maximum buffer size we need */

  UTIL1_Num16sToStrFormatted(buf, dstSize, val, fill, nofFill);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum32uFormatted (component Utility)
**     Description :
**         Appends a 32bit unsigned value to a string buffer in a
**         formatted way.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**         fill            - Fill character
**         nofFill         - Number of fill characters
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief appends a 32bit unsigned number to a string, in a formatted way (like printf with "%0d".
     Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] val The 32bit unsigned number to add
  \param[in] fill Fill character
  \param[in] nofFill Number of fill characters
  */
void UTIL1_strcatNum32uFormatted(uint8_t *dst, size_t dstSize, uint32_t val, char fill, uint8_t nofFill)
{
  unsigned char buf[sizeof("4294967295")]; /* maximum buffer size we need */

  UTIL1_Num32uToStrFormatted(buf, dstSize, val, fill, nofFill);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum32sFormatted (component Utility)
**     Description :
**         Appends a 32bit signed value to a string buffer in a
**         formatted way.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**         fill            - Fill character
**         nofFill         - Number of fill characters
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief appends a 32bit signed number to a string, in a formatted way (like printf with "%0d".
     Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] val The 32bit signed number to add
  \param[in] fill Fill character
  \param[in] nofFill Number of fill characters
  */
void UTIL1_strcatNum32sFormatted(uint8_t *dst, size_t dstSize, int32_t val, char fill, uint8_t nofFill)
{
  unsigned char buf[sizeof("-4294967295")]; /* maximum buffer size we need */

  UTIL1_Num32sToStrFormatted(buf, dstSize, val, fill, nofFill);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum8Hex (component Utility)
**     Description :
**         Appends a 8bit unsigned value to a string buffer as hex
**         number (without a 0x prefix).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         num             - Value to convert.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Adds a 8bit number as hex value to a string.
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] num The 8bit number to add
  */
void UTIL1_strcatNum8Hex(uint8_t *dst, size_t dstSize, uint8_t num)
{
  unsigned char buf[sizeof("FF")]; /* maximum buffer size we need */
  unsigned char hex;

  buf[2] = '\0';
  hex = (char)(num & 0x0F);
  buf[1] = (char)(hex + ((hex <= 9) ? '0' : ('A'-10)));
  hex = (char)((num>>4) & 0x0F);
  buf[0] = (char)(hex + ((hex <= 9) ? '0' : ('A'-10)));
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum16Hex (component Utility)
**     Description :
**         Appends a 16bit unsigned value to a string buffer as hex
**         number (without a 0x prefix).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         num             - Value to convert.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Adds a 16bit number as hex value to a string.
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] num The 16bit number to add
  */
void UTIL1_strcatNum16Hex(uint8_t *dst, size_t dstSize, uint16_t num)
{
  unsigned char buf[sizeof("FFFF")]; /* maximum buffer size we need */
  unsigned char hex;
  int8_t i;

  buf[4] = '\0';
  i = 3;
  do {
    hex = (char)(num & 0x0F);
    buf[i] = (char)(hex + ((hex <= 9) ? '0' : ('A'-10)));
    num >>= 4;                          /* next nibble */
    i--;
  } while (i>=0);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum24Hex (component Utility)
**     Description :
**         Appends a 32bit unsigned value to a string buffer as hex
**         number (without a 0x prefix). Only 24bits are used.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         num             - Value to convert.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Adds a 24bit number as hex value to a string.
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] num The 24bit number to add
  */
void UTIL1_strcatNum24Hex(uint8_t *dst, size_t dstSize, uint32_t num)
{
  unsigned char buf[sizeof("FFFFFF")]; /* maximum buffer size we need */
  unsigned char hex;
  int8_t i;

  buf[6] = '\0';
  i = 5;
  do {
    hex = (char)(num & 0x0F);
    buf[i] = (char)(hex + ((hex <= 9) ? '0' : ('A'-10)));
    num >>= 4;                          /* next nibble */
    i--;
  } while (i>=0);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum32Hex (component Utility)
**     Description :
**         Appends a 16bit unsigned value to a string buffer as hex
**         number (without a 0x prefix).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         num             - Value to convert.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Adds a 32bit number as hex value to a string.
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] num The 32bit number to add
  */
void UTIL1_strcatNum32Hex(uint8_t *dst, size_t dstSize, uint32_t num)
{
  unsigned char buf[sizeof("FFFFFFFF")]; /* maximum buffer size we need */
  unsigned char hex;
  int8_t i;

  buf[8] = '\0';
  i = 7;
  do {
    hex = (char)(num & 0x0F);
    buf[i] = (char)(hex + ((hex <= 9) ? '0' : ('A'-10)));
    num >>= 4;                          /* next nibble */
    i--;
  } while (i>=0);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum32s (component Utility)
**     Description :
**         Appends a 32bit signed value to a string buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief appends a 32bit (long) number to a string. Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] val The 32bit number to add
  */
void UTIL1_strcatNum32s(uint8_t *dst, size_t dstSize, int32_t val)
{
  unsigned char buf[sizeof("-4294967295")]; /* maximum buffer size we need */

  UTIL1_Num32sToStr(buf, sizeof(buf), val);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum32u (component Utility)
**     Description :
**         Appends a 32bit signed value to a string buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to convert.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief appends a 32bit (unsigned long) number to a string. Always terminates the result string.
     Note: count is the size of dst INCLUDING zero byte.
     Precondition: src, dst != NULL
  \param[in,out] dst Start of string buffer, where to append the number string
  \param[in] dstSize The size of the buffer, including the zero byte
  \param[in] val The 32bit unsigned number to add
  */
void UTIL1_strcatNum32u(uint8_t *dst, size_t dstSize, uint32_t val)
{
  unsigned char buf[sizeof("4294967295")]; /* maximum buffer size we need */

  UTIL1_Num32uToStr(buf, sizeof(buf), val);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_Num32sToStr (component Utility)
**     Description :
**         Converts a signed 32bit value into a string.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to be converted.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Converts a 32bit number to a string.
  \param[in,out] dst String buffer to store the number.
  \param[in] dstSize Size of the destination buffer in uint8_ts.
  \param[in] val 32bit signed number to convert.
 */
void UTIL1_Num32sToStr(uint8_t *dst, size_t dstSize, int32_t val)
{
  unsigned char *ptr = ((unsigned char *)dst);
  unsigned char i=0, j;
  unsigned char tmp;
  unsigned char sign = (unsigned char)(val < 0);

  if (val==(int32_t)(0x80000000)) { /* special case 0x80000000/-2147483648: prevent overflow below. */
    UTIL1_strcpy(dst, dstSize, (unsigned char*)"-2147483648");
    return;
  }
  dstSize--; /* for zero byte */
  if (sign) {
    val = -val;
  }
  if (val == 0 && dstSize > 0){
    ptr[i++] = '0';
    dstSize--;
  }
  while (val > 0 && dstSize > 0) {
    ptr[i++] = (unsigned char)((val % 10) + '0');
    dstSize--;
    val /= 10;
  }
  if (sign && dstSize > 0){
    ptr[i++] = '-';
  }
  for(j=0; j<(i/2); j++) { /* swap buffer */
    tmp = ptr[j];
    ptr[j] = ptr[(i-j)-1];
    ptr[(i-j)-1] = tmp;
  }
  ptr[i] = '\0';
}

/*
** ===================================================================
**     Method      :  UTIL1_Num32uToStr (component Utility)
**     Description :
**         Converts an unsigned 32bit value into a string.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to be converted.
**     Returns     : Nothing
** ===================================================================
*/
/*!
  \brief Converts a 32bit signed number to a string.
  \param[in,out] dst String buffer to store the number.
  \param[in] dstSize Size of the destination buffer in uint8_ts.
  \param[in] val 32bit unsigned number to convert.
 */
void UTIL1_Num32uToStr(uint8_t *dst, size_t dstSize, uint32_t val)
{
  unsigned char *ptr = ((unsigned char *)dst);
  unsigned char i=0, j;
  unsigned char tmp;

  dstSize--; /* for zero byte */
  if (val == 0 && dstSize > 0){
    ptr[i++] = '0';
    dstSize--;
  }
  while (val > 0 && dstSize > 0) {
    ptr[i++] = (unsigned char)((val % 10) + '0');
    dstSize--;
    val /= 10;
  }
  for(j=0; j<(i/2); j++) { /* swap buffer */
    tmp = ptr[j];
    ptr[j] = ptr[(i-j)-1];
    ptr[(i-j)-1] = tmp;
  }
  ptr[i] = '\0';
}

/*
** ===================================================================
**     Method      :  UTIL1_IsLeapYear (component Utility)
**     Description :
**         Returns true if a given year is a leap year
**     Parameters  :
**         NAME            - DESCRIPTION
**         year            - Year, in the YYYY format.
**     Returns     :
**         ---             - If the year is a leap year or not.
** ===================================================================
*/
bool UTIL1_IsLeapYear(uint16_t year)
{
  return ((((year%4)==0) && (year%100)!=0) || (year%400)==0);
}

/*
** ===================================================================
**     Method      :  UTIL1_WeekDay (component Utility)
**     Description :
**         Returns the weekday for a given date >= 1.Jan.1900
**     Parameters  :
**         NAME            - DESCRIPTION
**         year            - year in YYYY format
**         month           - month of the year (1: January, 2:
**                           February, etc)
**         day             - day of the moth (starting with 1)
**     Returns     :
**         ---             - Returns the weekday, 0 for Sunday, 1 for
**                           Monday, 2 for Tuesday, etc.
** ===================================================================
*/
uint8_t UTIL1_WeekDay(uint16_t year, uint8_t month, uint8_t day)
{
  /* see http://klausler.com/new-dayofweek.html */
  static const uint8_t skew[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
  uint16_t sum;

  sum = (uint16_t)(year-1900);
  sum += sum/4;
  sum %= 7;
  if (UTIL1_IsLeapYear(year) && (month==1 || month==2)) {
    sum--;
  }
  sum += day;
  sum %= 7;
  sum += skew[month-1];
  sum %= 7;
  return (uint8_t)sum; /* 0: Sunday, 1: Monday, 2: Tuesday, 3: Wednesday, ... */
}

/*
** ===================================================================
**     Method      :  UTIL1_ReadEscapedName (component Utility)
**     Description :
**         Scans an escaped name from a string. This is useful e.g. for
**         double quoted file names.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * filename        - the name to be copied. Names may
**                           be in quoted format
**       * destname        - the destination of the copy.
**                           Names are not in quoted format. destname
**                           may be NULL to get the other return values
**                           only
**         maxlen          - length allocated for destname
**       * lenRead         - length read in filename to copy
**                           the whole name. Note that filenames maybe
**                           space terminated, so *lenRead <
**                           strlen(filename)
**         lenWritten      - the size written in destname.
**                           In case of overflows in destname,
**                           lenWritten is still increased but destname
**                           no longer written. The have the string
**                           length in these cases use strlen(destname)
**         terminators     - additional characters
**                           where a name should terminate. May be NULL
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ReadEscapedName(const unsigned char *filename, uint8_t *destname, size_t maxlen, size_t *lenRead, size_t *lenWritten, const char *terminators)
{
  size_t lenCopied = 0, lenOverread = 0;
  bool quoteMode = FALSE;  /* quoteMode means the name is surrounded by ". In this mode, only a second single quote "
                              terminates the string. In !quoteMode a space or a '\0' may also terminate it correctly */
  bool res = ERR_OK;
  #define IS_SPACE(ch) ((ch)==' '||(ch)=='\t'||(ch)=='\n'||(ch)=='\v'||(ch)=='\f'||(ch)=='\r')

  if (filename==NULL || (destname!=NULL && maxlen==0)) {
    return ERR_FAILED;
  }
  if (filename[0] == '"') { /* translated mode */
    filename++; /* overread '"' */
    lenOverread++;
    quoteMode=TRUE;
  }
  if (terminators == NULL) {
    terminators = "";
  }
  for (;;) {
    if (quoteMode) {
      if (filename[0] == '"') {
        filename++; /* overread '"' */
        lenOverread++;
        if (filename[0] != '"') { /* quoteMode is terminated by a single quote. A double quote is treated like a single quote and does not terminate it ! */
          break; /* successfully finished with this name */
        } /* else we copy the second quote " */
      }
      if (filename[0] == '\0') { /* unexpected 0. stop */
        res = ERR_FAILED;
        break; /* error case: no terminating double quote (") was found */
      }
    } else { /* copy mode */
      if (IS_SPACE(filename[0]) || filename[0] == '\0' || strchr(terminators, filename[0]) != NULL) { /* !quoteMode is terminated by space, '\0' or by any char in terminators */
        break;
      }
    }
    if (destname != NULL) {
      if (lenCopied + 1 < maxlen) {
        destname[0] = filename[0];
        destname++;
      } else {
        destname[0] = '\0'; /* terminate string */
        destname = NULL; /* avoid it to overwrite not allocated space */
      }
    }
    lenCopied++;
    filename++;
  }
  if (destname != NULL) {
    destname[0] = '\0';
  }
  if (lenRead != NULL) {
    *lenRead = lenCopied+lenOverread;
  }
  if (lenWritten != NULL) {
    *lenWritten = lenCopied + 1; /* additionally a zero byte written */
  }
  return res;
}

/*
** ===================================================================
**     Method      :  UTIL1_xatoi (component Utility)
**     Description :
**         Custom atoi() (ascii to int) implementation by Elm Chan
**     Parameters  :
**         NAME            - DESCRIPTION
**       * str             - Pointer to string to scan. Returns until
**                           where it has scanned.
**       * res             - Pointer to where to store the result
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
/*------------------------------------------------------------------------/
/  Universal string handler for user console interface
/-------------------------------------------------------------------------/
/
/  Copyright (C) 2010, ChaN, all right reserved.
/
/ * This software is a free software and there is NO WARRANTY.
/ * No restriction on use. You can use, modify and redistribute it for
/   personal, non-profit or commercial products UNDER YOUR RESPONSIBILITY.
/ * Redistributions of source code must retain the above copyright notice.
/
/-------------------------------------------------------------------------*/
#ifdef __HC12__
  #pragma MESSAGE DISABLE C12056  /* message about SP debug info */
#endif
uint8_t UTIL1_xatoi(const unsigned char **str, int32_t *res)
{
/* 123 -5   0x3ff 0b1111 0377 3.25  w "
      ^                               1st call returns 123 and next ptr
         ^                            2nd call returns -5 and next ptr
                 ^                    3rd call returns 1023 and next ptr
                        ^             4th call returns 15 and next ptr
                             ^        5th call returns 255 and next ptr
                               ^      6th call returns 3 and next ptr, caller needs to read '.'
                                 ^    7th call returns 25 and next ptr
                                    ^ 8th call fails and returns ERR_FAILED
*/
  uint32_t val;
  uint8_t c, r, s = 0;

  *res = 0;
  while (**str==' ') {
    (*str)++;                          /* Skip leading spaces */
  }
  c = **str;
  if (c == '-') {                      /* negative? */
    s = 1;
    c = *(++(*str));
  }
  if (c == '0') {
    c = *(++(*str));
    switch (c) {
      case 'x':                        /* hexadecimal */
        r = 16; c = *(++(*str));
        break;
      case 'b':                        /* binary */
        r = 2; c = *(++(*str));
        break;
      default:
        if (c <= ' ' || c == '.') {
          return ERR_OK;               /* single zero */
        }
        if (c < '0' || c > '9') {
          return ERR_FAILED;           /* invalid char */
        }
        r = 8;                         /* octal */
        break;
    } /* switch */
  } else {
    if (c < '0' || c > '9') {
      return ERR_FAILED;               /* EOL or invalid char */
    }
    r = 10;                            /* decimal */
  }
  val = 0;
  while (c > ' ' && c != '.') {
    if (c >= 'a') c -= 0x20;
    c -= '0';
    if (c >= 17) {
      c -= 7;
      if (c <= 9) return ERR_FAILED;   /* invalid char */
    }
    if (c >= r) return ERR_FAILED;     /* invalid char for current radix */
    val = val * r + c;
    c = *(++(*str));
  } /* while */
  if (s) val = 0 - val;                /* apply sign if needed */
  *res = (long)val;
  return ERR_OK;
}
#ifdef __HC12__
  #pragma MESSAGE DEFAULT C12056  /* message about SP debug info */
#endif

/*
** ===================================================================
**     Method      :  UTIL1_ScanDate (component Utility)
**     Description :
**         Scans a date in the format "dd.mm.yyyy" or "dd-mm-yyyy". For
**         yy it will expand it to 20yy.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * str             - Pointer to the string to be scanned. The
**                           function advances the pointer.
**       * day             - Pointer to where to store the day value
**       * month           - Pointer to where to store the month
**                           value
**       * year            - Pointer to where to store the year value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanDate(const unsigned char **str, uint8_t *day, uint8_t *month, uint16_t *year)
{
  /* precondition: string points to starting of date, e.g. "01.01.10" or "12.5.2010", and date is in format dd.mm.yy or dd.mm.yyyy */
  const unsigned char *p;

  p = *str;
  while(*p==' ') {
    p++; /* skip leading spaces */
  }
  if (   UTIL1_ScanDecimal8uNumber(&p, day)==ERR_OK
      && *day > 0 && *day <= 31
      && (*p=='.' || *p=='-')
     )
  {
    p++;
    if (   UTIL1_ScanDecimal8uNumber(&p, month)==ERR_OK
        && *month > 0 && *month <= 12
        && (*p=='.' || *p=='-')
       )
    {
      p++;
      if (   UTIL1_ScanDecimal16uNumber(&p, year)==ERR_OK
          && *year > 0 && *year <= 3000 /* hopefully this is enough :-) */
         )
      {
        if (*year < 100) {
          *year += 2000; /* transform '10' into '2010' */
        }
        *str = p; /* advance pointer for caller */
        return ERR_OK;
      }
    }
  }
  *day = 0;
  *month = 0;
  *year = 0;
  return ERR_FAILED; /* wrong format */
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanTime (component Utility)
**     Description :
**         Scans a time string in the format "hh:mm:ss,hh" with the
**         part for the ",hh" is optional.
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - Pointer to the string to be scanned. The
**                           function advances the pointer.
**       * hour            - Pointer to where to store the hour value
**       * minute          - Pointer to where to store the minute
**                           value
**       * second          - Pointer to where to store the second
**                           value
**       * hSecond         - Pointer to scans the hundreds of
**                           second part. If not present in string, zero
**                           is stored
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanTime(const unsigned char **str, uint8_t *hour, uint8_t *minute, uint8_t *second, uint8_t *hSecond)
{
  /* precondition: string points to starting of time string, e.g. "03:15:05" or "03:15:05,3" or "03:15:05,17", and time is in format hh:mm:ss[,hh] */
  const unsigned char *p;
  #define SCAN_IS_DIGIT(ch) ((ch)>='0'&&(ch)<='9')

  *hour = 0;
  *minute = 0;
  *second = 0;
  *hSecond = 0;
  p = *str;
  while(*p==' ') {
    p++; /* skip leading spaces */
  }
  if (   UTIL1_ScanDecimal8uNumber(&p, hour)==ERR_OK
      && *hour <= 24
      && *p==':'
     )
  {
    p++; /* skip ':' */
    if (   UTIL1_ScanDecimal8uNumber(&p, minute)==ERR_OK
        && *minute <= 60
       )
    {
      if (*p==':') { /* there is more after the minute */
        p++; /* skip ':' */
        if (   UTIL1_ScanDecimal8uNumber(&p, second)==ERR_OK
            && *second <= 60
           )
        {
          if (*p==',') { /* we do have either ",z" or ",hh" */
            p++; /* skip ',' */
            if (SCAN_IS_DIGIT(*p)) {
              if (SCAN_IS_DIGIT(*(p+1))) { /* ,hh format */
                *hSecond = (uint8_t)((*p-'0')*10 + *(p+1)-'0');
                return ERR_OK;
              } else { /* ,z format */
                *hSecond = (uint8_t)((*p-'0')*10);
                p++;
                *str = p; /* advance pointer for caller */
                return ERR_OK;
              }
            } else {
              return ERR_FAILED; /* illegal format, not a number, e.g. ",x" */
            }
          }
          *str = p; /* advance pointer for caller */
          return ERR_OK;
        }
      } else if (*p==' ' || *p=='\0') { /* nothing more after the minute? Assume zero seconds */
        *str = p; /* advance pointer for caller */
        return ERR_OK;
      }
    }
  }
  return ERR_FAILED; /* wrong format */
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanDecimal8uNumber (component Utility)
**     Description :
**         Scans a decimal 8bit unsigned number
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - String to scan. It returns as well until
**                           where it has scanned
**       * val             - Pointer to value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanDecimal8uNumber(const unsigned char **str, uint8_t *val)
{
  /* scans a decimal number, and stops at any non-number. Number can have any preceding zeros or spaces. */
  #define _8_NOF_DIGITS  (3+1)
  uint8_t nofDigits = _8_NOF_DIGITS; /* maximum number of digits to avoid overflow */
  const unsigned char *p = *str;

  while(*p==' ') { /* skip leading spaces */
    p++;
  }
  *val = 0;
  while(*p>='0' && *p<='9' && nofDigits > 0) {
    *val = (uint8_t)((*val)*10 + *p-'0');
    nofDigits--;
    p++;
  } /* while */
  if (nofDigits==0) {
    return ERR_OVERFLOW;
  }
  if (nofDigits==_8_NOF_DIGITS) { /* no digits at all? */
    return ERR_FAILED;
  }
  *str = p;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanDecimal8sNumber (component Utility)
**     Description :
**         Scans a decimal 8bit signed number
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - String to scan. It returns as well until
**                           where it has scanned
**       * val             - Pointer to value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanDecimal8sNumber(const unsigned char **str, signed char *val)
{
  /* Scans a decimal number, and stops at any non-number. Number can have any preceding spaces. */
  const unsigned char *p = *str;
  bool isNeg;
  uint8_t val8u;
  uint8_t res;

  while(*p==' ') { /* skip leading spaces */
    p++;
  }
  *val = 0;
  if (*p=='-') {
    isNeg = TRUE;
    p++; /* skip minus */
  } else {
    isNeg = FALSE;
  }
  res = UTIL1_ScanDecimal8uNumber(&p, &val8u);
  if (res != ERR_OK) {
    return res;
  }
  if (isNeg) {
    *val = (int8_t)(-(int8_t)val8u);
  } else {
    *val = (int8_t)val8u;
  }
  *str = p;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanDecimal16uNumber (component Utility)
**     Description :
**         Scans a decimal 16bit unsigned number
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - String to scan. It returns as well until
**                           where it has scanned
**       * val             - Pointer to value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanDecimal16uNumber(const unsigned char **str, uint16_t *val)
{
  /* scans a decimal number, and stops at any non-number. Number can have any preceding zeros or spaces. */
  #define _16_NOF_DIGITS  (5+1)
  uint8_t nofDigits = _16_NOF_DIGITS; /* maximum number of digits to avoid overflow */
  const unsigned char *p = *str;

  while(*p==' ') { /* skip leading spaces */
    p++;
  }
  *val = 0;
  while(*p>='0' && *p<='9' && nofDigits > 0) {
    *val = (uint16_t)((*val)*10 + *p-'0');
    nofDigits--;
    p++;
  } /* while */
  if (nofDigits==0) {
    return ERR_OVERFLOW;
  }
  if (nofDigits==_16_NOF_DIGITS) { /* no digits at all? */
    return ERR_FAILED;
  }
  *str = p;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanDecimal16sNumber (component Utility)
**     Description :
**         Scans a decimal 16bit signed number
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - String to scan. It returns as well until
**                           where it has scanned
**       * val             - Pointer to value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanDecimal16sNumber(const unsigned char **str, int16_t *val)
{
  /* Scans a decimal number, and stops at any non-number. Number can have any preceding spaces. */
  const unsigned char *p = *str;
  bool isNeg;
  uint16_t val16u;
  uint8_t res;

  while(*p==' ') { /* skip leading spaces */
    p++;
  }
  *val = 0;
  if (*p=='-') {
    isNeg = TRUE;
    p++; /* skip minus */
  } else {
    isNeg = FALSE;
  }
  res = UTIL1_ScanDecimal16uNumber(&p, (uint16_t*)&val16u);
  if (res != ERR_OK) {
    return res;
  }
  if (isNeg) {
    *val = (int16_t)(-(int16_t)val16u);
  } else {
    *val = (int16_t)val16u;
  }
  *str = p;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanDecimal32uNumber (component Utility)
**     Description :
**         Scans a decimal 32bit unsigned number
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - string to scan. It returns as well until
**                           where it has scanned
**       * val             - Pointer to value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanDecimal32uNumber(const unsigned char **str, uint32_t *val)
{
  /* scans a decimal number, and stops at any non-number. Number can have any preceding zeros or spaces. */
  #define _32_NOF_DIGITS  (10+1)
  uint8_t nofDigits = _32_NOF_DIGITS; /* maximum number of digits to avoid overflow */
  const unsigned char *p = *str;

  while(*p==' ') { /* skip leading spaces */
    p++;
  }
  *val = 0;
  while(*p>='0' && *p<='9' && nofDigits > 0) {
    *val = (uint32_t)((*val)*10 + *p-'0');
    nofDigits--;
    p++;
  } /* while */
  if (nofDigits==0) {
    return ERR_OVERFLOW;
  }
  if (nofDigits==_32_NOF_DIGITS) { /* no digits at all? */
    return ERR_FAILED;
  }
  *str = p;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanDecimal32sNumber (component Utility)
**     Description :
**         Scans a decimal 32bit signed number
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - string to scan. It returns as well until
**                           where it has scanned
**       * val             - Pointer to value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanDecimal32sNumber(const unsigned char **str, int32_t *val)
{
  /* Scans a decimal number, and stops at any non-number. Number can have any preceding spaces. */
  const unsigned char *p = *str;
  bool isNeg;
  uint32_t val32u;
  uint8_t res;

  while(*p==' ') { /* skip leading spaces */
    p++;
  }
  *val = 0;
  if (*p=='-') {
    isNeg = TRUE;
    p++; /* skip minus */
  } else {
    isNeg = FALSE;
  }
  res = UTIL1_ScanDecimal32uNumber(&p, &val32u);
  if (res != ERR_OK) {
    return res;
  }
  if (isNeg) {
    *val = (int32_t)(-(int32_t)val32u);
  } else {
    *val = (int32_t)val32u;
  }
  *str = p;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanDecimal32sDotNumber (component Utility)
**     Description :
**         Scans a decimal 32bit signed number with a following dot
**         (fractional part), e.g. "-34587.0248", it will return the
**         (signed) integral and fractional part with number of
**         fractional zeros. The function accepts as well numbers  like
**         "17" (no fractional part" or "17.0" 
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - string to scan. It returns as well until
**                           where it has scanned
**       * integral        - Pointer to value before the dot
**       * fractional      - Pointer to value after the
**                           dot, e.g. 32 for "-134.0032"
**         nofFractionalZeros - Number of
**                           fractional leading zeros, e.g. 2 for "-134.
**                           0032"
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanDecimal32sDotNumber(const unsigned char **str, int32_t *integral, uint32_t *fractional, uint8_t *nofFractionalZeros)
{
  /* scans e.g. "-3445.071" and returns -3445 in integral part, and 71 in fractional part */
  uint8_t res;
  const unsigned char *p = *str;

  *integral = 0;
  *fractional = 0;
  *nofFractionalZeros = 0;
  res = UTIL1_ScanDecimal32sNumber(&p, integral);
  if (res != ERR_OK) {
    return res;
  }
  if (*p=='.') {
    p++; /* skip '.' */
    while (*p=='0') { /* count leading zeros */
      (*nofFractionalZeros)++;
      p++; /* skip leading zero */
    }
    if (*p>='0' && *p<='9') { /* number */
      res = UTIL1_ScanDecimal32uNumber(&p, fractional);
      if (res != ERR_OK) {
        return res;
      }
    }
  }
  *str = p; /* store parsing pointer */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_strcmp (component Utility)
**     Description :
**         Wrapper to the standard strcmp() routine
**     Parameters  :
**         NAME            - DESCRIPTION
**       * str1            - Pointer to string
**       * str2            - Pointer to string
**     Returns     :
**         ---             - Returns zero if the two strings are the
**                           same
** ===================================================================
*/
/***
int16_t UTIL1_strcmp(const char *, const char *)
{
  Method is implemented as macro in the header file as wrapper to the standard strcmp() function
}
*/

/*
** ===================================================================
**     Method      :  UTIL1_strncmp (component Utility)
**     Description :
**         Wrapper to the standard strncmp() routine
**     Parameters  :
**         NAME            - DESCRIPTION
**       * str1            - Pointer to string
**       * str2            - Pointer to string
**         size            - 
**     Returns     :
**         ---             - Returns zero if the two strings are the
**                           same
** ===================================================================
*/
/***
int16_t UTIL1_strncmp(const char *, const char *, size_t size)
{
  /Method is implemented as macro in the header file as wrapper to the standard strncmp() function
}
*/

/*
** ===================================================================
**     Method      :  UTIL1_strlen (component Utility)
**     Description :
**         Wrapper to the standard strlen() function.
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - 
**     Returns     :
**         ---             - size of strinig
** ===================================================================
*/
/***
uint16_t UTIL1_strlen(const char *)
{
  Method is implemented as macro in the header file as wrapper to the standard strlen() function
}
*/

static bool isHexCharacter(unsigned char ch) {
  /* returns TRUE if character is a hexadecimal character */
  return (ch>='0' && ch<='9') || (ch>='a' && ch<='f') || (ch>='A' && ch<='F');
}

static uint8_t PreScanHexNumber(const unsigned char **str) {
  const unsigned char *p = *str;

  while(*p==' ') { /* skip leading spaces */
    p++; /* skip space */
  }
  if (*p!='0') { /* must start with 0x */
    return ERR_FAILED;
  }
  p++; /* skip '0' */
  if (*p!='x') { /* must start with 0x */
    return ERR_FAILED;
  }
  p++; /* skip 'x' */
  *str = p;
  return ERR_OK;
}

static uint8_t HexToDec(const unsigned char **p, unsigned char *val) {
  /* convert a hexadecimal character into a decimal value */
  unsigned char ch = **p;

  if (ch>='0' && ch<='9') {
    *val = (unsigned char)(ch-'0');
    (*p)++;
    return ERR_OK;
  } else if (ch>='a' && ch<='f') {
    *val = (unsigned char)(ch-'a'+10);
    (*p)++;
    return ERR_OK;
  } else if (ch>='A' && ch<='F') {
    *val = (unsigned char)(ch-'A'+10);
    (*p)++;
    return ERR_OK;
  }
  return ERR_FAILED;
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanHex32uNumber (component Utility)
**     Description :
**         Scans a hexadecimal 32bit number, starting with 0x
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - String to scan, starting with 0x. It
**                           returns as well until where it has scanned
**       * val             - Pointer to value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanHex32uNumber(const unsigned char **str, uint32_t *val)
{
  /* scans a decimal number, and stops at any non-number. Number can have any preceding zeros or spaces. */
  uint8_t nofDigits = 8; /* maximum number of digits to avoid overflow */
  const unsigned char *p = *str;
  uint8_t v;

  *val = 0;
  if (PreScanHexNumber(&p)!=ERR_OK) { /* skip leading spaces, and scan '0x' */
    return ERR_FAILED;
  }
  if (!isHexCharacter(*p)) { /* not a valid hex number sequence */
    return ERR_FAILED;
  }
  while (nofDigits>0 && HexToDec(&p, &v)==ERR_OK) {
    *val = (uint32_t)((*val)*16 + v);
    nofDigits--;
  } /* while */
  *str = p;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanHex16uNumber (component Utility)
**     Description :
**         Scans a hexadecimal 16bit number, starting with 0x
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - String to scan, starting with 0x.. It
**                           returns as well until where it has scanned
**       * val             - Pointer to value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanHex16uNumber(const unsigned char **str, uint16_t *val)
{
  /* scans a decimal number, and stops at any non-number. Number can have any preceding zeros or spaces. */
  uint8_t nofDigits = 4; /* maximum number of digits to read */
  const unsigned char *p = *str;
  uint8_t v;

  *val = 0;
  if (PreScanHexNumber(&p)!=ERR_OK) { /* skip leading spaces, and scan '0x' */
    return ERR_FAILED;
  }
  if (!isHexCharacter(*p)) { /* not a valid hex number sequence */
    return ERR_FAILED;
  }
  while (nofDigits>0 && HexToDec(&p, &v)==ERR_OK) {
    *val = (uint16_t)((*val)*16 + v);
    nofDigits--;
  } /* while */
  *str = p;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanHex8uNumber (component Utility)
**     Description :
**         Scans a hexadecimal 8bit number, starting with 0x
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - String to scan, starting with 0x. It
**                           returns as well until where it has scanned
**       * val             - Pointer to value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanHex8uNumber(const unsigned char **str, uint8_t *val)
{
  /* scans a hex number with 0x, and stops at any non-number. Number can have any preceding zeros or spaces. */
  uint8_t nofDigits = 2; /* maximum number of digits to read */
  const unsigned char *p = *str;
  uint8_t v;

  *val = 0;
  if (PreScanHexNumber(&p)!=ERR_OK) { /* skip leading spaces, and scan '0x' */
    return ERR_FAILED;
  }
  if (!isHexCharacter(*p)) { /* not a valid hex number sequence */
    return ERR_FAILED;
  }
  while (nofDigits>0 && HexToDec(&p, &v)==ERR_OK) {
    *val = (uint8_t)((*val)*16 + v);
    nofDigits--;
  } /* while */
  *str = p;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanHex8uNumberNoPrefix (component Utility)
**     Description :
**         Scans a hexadecimal 8bit number, without 0x
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - String to scan, starting with 0x. It
**                           returns as well until where it has scanned
**       * val             - Pointer to value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanHex8uNumberNoPrefix(const unsigned char **str, uint8_t *val)
{
  /* scans a hex number without 0x, and stops at any non-number. Number can have any preceding zeros or spaces. */
  uint8_t nofDigits = 2; /* maximum number of digits to read */
  const unsigned char *p = *str;
  uint8_t v;

  *val = 0;
  while(*p==' ') { /* skip leading spaces */
    p++; /* skip space */
  }
  if (!isHexCharacter(*p)) { /* not a valid hex number sequence */
    return ERR_FAILED;
  }
  while (nofDigits>0 && HexToDec(&p, &v)==ERR_OK) {
    *val = (uint8_t)((*val)*16 + v);
    nofDigits--;
  } /* while */
  *str = p;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_strtailcmp (component Utility)
**     Description :
**         Compares the tail of a string and returns 0 if it matches, 1
**         otherwise
**     Parameters  :
**         NAME            - DESCRIPTION
**       * str             - Pointer to string. This string is compared
**                           if it contains the tail.
**       * tail            - Pointer to tail string.
**     Returns     :
**         ---             - returns 0 if tail matches, -1 otherwise
** ===================================================================
*/
uint8_t UTIL1_strtailcmp(const uint8_t *str, const uint8_t *tail)
{
  int i, j;

  i = (int)UTIL1_strlen((char*)str);
  j = (int)UTIL1_strlen((char*)tail);
  if (j>i) { /* str is smaller than tail */
    return 1; /* cannot match */
  }
  /* compare strings */
  while(str[i]==tail[j]) {
    i--;
    j--;
    if (j<0) {
      return 0; /* match */
    }
  }
  return 1; /* !=0 means no match */
}

/*
** ===================================================================
**     Method      :  UTIL1_strCutTail (component Utility)
**     Description :
**         Removes a tailing substring from a string. The string passed
**         will be modified (the tail is cut by writing a zero byte to
**         the string!)
**     Parameters  :
**         NAME            - DESCRIPTION
**       * str             - Pointer to string where to remove the tail
**       * tail            - Pointer to substring to remove
**     Returns     :
**         ---             - Error code, ERR_OK if no error, otherwise
**                           ERR_FAIL if tail is not found
** ===================================================================
*/
uint8_t UTIL1_strCutTail(uint8_t *str, uint8_t *tail)
{
  /* cut the tail from the string */
  size_t strLen, tailLen;

  if (UTIL1_strtailcmp(str, tail)!=0) { /* check if tail is present */
    return ERR_FAILED; /* tail not found */
  }
  tailLen = UTIL1_strlen((char*)tail);
  strLen = UTIL1_strlen((char*)str);
  /* write \0 to cut the tail */
  str[strLen-tailLen] = '\0';
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNum32sDotValue100 (component Utility)
**     Description :
**         Appends a 32bit signed value to a string buffer. The value
**         is in 1/100 units.  For example for the value -13456 it will
**         append the string "-134.56"
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         num             - Value to convert.
**     Returns     : Nothing
** ===================================================================
*/
void UTIL1_strcatNum32sDotValue100(uint8_t *dst, size_t dstSize, int32_t num)
{
  if (num<0 && (num/100)==0) { /* e.g. -53 ==> write sign, as strcatNum32() below will not know that it is negative */
    UTIL1_chcat(dst, dstSize, '-');
  }
  UTIL1_strcatNum32s(dst, dstSize, num/100);
  UTIL1_chcat(dst, dstSize, '.');
  if (num<0) {
    num = -num;
  }
  UTIL1_strcatNum16uFormatted(dst, dstSize, (uint16_t)((unsigned)num%100U), '0', 2);
}

/*
** ===================================================================
**     Method      :  UTIL1_strFind (component Utility)
**     Description :
**         Searches a substring inside a string and returns the
**         position.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * str             - Pointer to string which will be searched
**       * subStr          - Pointer to substring to search
**                           inside str
**     Returns     :
**         ---             - -1 if not found, otherwise the character
**                           index.
** ===================================================================
*/
int16_t UTIL1_strFind(uint8_t *str, uint8_t *subStr)
{
  int16_t i, len;

  len = (int16_t)UTIL1_strlen((char*)subStr);
  for (i=0; *str!='\0'; i++, str++) {
    if (UTIL1_strncmp((char*)str, (char*)subStr, len)==0) {
      return i; /* found */
    }
  }
  return -1; /* not found */
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanSeparatedNumbers (component Utility)
**     Description :
**         Scans multiple numbers separated by character, e.g. "123.68.
**         5.3"
**     Parameters  :
**         NAME            - DESCRIPTION
**         str             - String to scan. It returns as well until
**                           where it has scanned
**       * values          - Pointer to array where to store the
**                           values
**         nofValues       - Number of values in the array
**         separator       - Character separator, e.g. '.'
**         numberType      - type of number to scan
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanSeparatedNumbers(const unsigned char **str, uint8_t *values, uint8_t nofValues, char separator, UTIL1_SeparatedNumberType numberType)
{
  int i;
  uint8_t res;
  const unsigned char *p;

  if (nofValues<=1) {
    return ERR_FAILED; /* need at least two values */
  }
  p = *str;
  for(i=0;i<nofValues;i++) {
    if (numberType==UTIL1_SEP_NUM_TYPE_UINT8) {
      res = UTIL1_ScanDecimal8uNumber(&p, &values[i]);
    } else if (numberType==UTIL1_SEP_NUM_TYPE_UINT8_HEX_NO_PREFIX) {
      res = UTIL1_ScanHex8uNumberNoPrefix(&p, &values[i]);
    } else {
      res = ERR_FAILED;
    }
    if (res==ERR_OK) { /* parsing ok */
      if (i!=nofValues-1) {
        if ((*p)!=separator) { /* not last one */
          return ERR_FAILED; /* wrong separator */
        } /* if */
        p++; /* skip separator and continue scanning */
      } /* if */
    } else {
      return ERR_FAILED; /* failed parsing number */
    } /* if */
  } /* for */
  *str = p;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_ScanDoubleQuotedString (component Utility)
**     Description :
**         Scans a string inside double quotes and returns it without
**         the double quotes.
**     Parameters  :
**         NAME            - DESCRIPTION
**         cmd             - Pointer to pointer to string to parse.
**                           This pointer will be advanced as much as
**                           parsing is done.
**       * buf             - Pointer to buffer where to store the string
**         bufSize         - Size of buffer in bytes
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t UTIL1_ScanDoubleQuotedString(const uint8_t **cmd, uint8_t *buf, size_t bufSize)
{
  const uint8_t *p = *cmd;

  if (bufSize==1) {
    return ERR_FAILED; /* buffer too small */
  }
  buf[bufSize-1] = '\0'; /* terminate buffer */
  bufSize--;
  if (*p!='\"') {
    return ERR_FAILED; /* does not start with double quote */
  }
  p++; /* skip double quote */
  while(*p!='\"' && *p!='\0' && bufSize>0) {
    *buf++ = *p++;
    bufSize--;
  }
  if (*p!='\"') {
    return ERR_FAILED; /* no terminating double quote */
  } else {
    p++; /* skip double quote */
    *buf = '\0'; /* terminate buffer */
  }
  *cmd = p; /* advance pointer */
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatPad (component Utility)
**     Description :
**         Same as normal strcat, but safe as it does not write beyond
**         the buffer. The buffer will be filled with a pad character
**         for a given length.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**       * src             - Pointer to source string.
**         padChar         - Character to be used for padding
**         srcPadSize      - To which size the src string
**                           has to be padded.
**     Returns     : Nothing
** ===================================================================
*/
void UTIL1_strcatPad(uint8_t *dst, size_t dstSize, const unsigned char *src, char padChar, uint8_t srcPadSize)
{
  uint8_t *p;
  size_t nof = 0;

  if (dstSize<2) {
    return; /* hmm, really to small for anything than the zero byte? */
  }
  p = dst;
  while(*p != '\0') { /* find end of string */
    p++;
    nof++;
  }
  UTIL1_strcat(dst+nof, dstSize-nof, src); /* add string */
  dstSize -= nof;
  while(*p != '\0' && srcPadSize>0 && dstSize>1) {
    p++;
    srcPadSize--;
    dstSize--;
  }
  while(srcPadSize>0 && dstSize>1) {
    *p++ = padChar; /* add padding char */
    srcPadSize--;
    dstSize--;
  }
  *p = '\0'; /* terminate string */
}

/*
** ===================================================================
**     Method      :  UTIL1_NumFloatToStr (component Utility)
**     Description :
**         Converts a float value into a string.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to be converted.
**         nofFracDigits   - Number of fractional
**                           digits to print
**     Returns     : Nothing
** ===================================================================
*/
void UTIL1_NumFloatToStr(uint8_t *dst, size_t dstSize, float val, uint8_t nofFracDigits)
{
  uint32_t integral;
  uint32_t fractional, shift;
  int i;
  bool isNeg;

  isNeg = (bool)(val<0);
  if (isNeg) {
    val = -val; /* make it positive */
  }
  integral = (uint32_t)(int32_t)val;
  val = val-(float)integral; /* get rid of integral part */
  shift = 1;
  for(i=0;i<nofFracDigits;i++) {
    shift *= 10;
  }
  /* get fractional part */
  fractional = (uint32_t)(val*shift);
  /* write integral part */
  if (integral==0 && fractional==0) { /* special check to avoid writing -0 or -0.000 */
    UTIL1_Num32sToStr(dst, dstSize, 0); /* just write the zero */
  } else if (isNeg) { /* for negative numbers, write it with sign */
    UTIL1_strcpy(dst, dstSize, (unsigned char*)"-");
    UTIL1_strcatNum32s(dst, dstSize, (int32_t)integral);
  } else {
    UTIL1_Num32sToStr(dst, dstSize, (int32_t)integral);
  }
  /* write fractional part */
  if (nofFracDigits>0) {
    UTIL1_chcat(dst, dstSize, '.');
    UTIL1_strcatNum32uFormatted(dst, dstSize, fractional, '0', nofFracDigits);
  }
}

/*
** ===================================================================
**     Method      :  UTIL1_strcatNumFloat (component Utility)
**     Description :
**         Converts a float value into a string.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dst             - Pointer to destination string
**         dstSize         - Size of the destination buffer (in
**                           bytes).
**         val             - Value to be converted.
**         nofFracDigits   - Number of factional
**                           digits to print
**     Returns     : Nothing
** ===================================================================
*/
void UTIL1_strcatNumFloat(uint8_t *dst, size_t dstSize, float val, uint8_t nofFracDigits)
{
  uint8_t buf[32];

  UTIL1_NumFloatToStr(buf, sizeof(buf), val, nofFracDigits);
  UTIL1_strcat(dst, dstSize, buf);
}

/*
** ===================================================================
**     Method      :  UTIL1_GetValue16LE (component Utility)
**     Description :
**         Returns a 16bit Little Endian value from memory
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dataP           - Pointer to memory
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint16_t UTIL1_GetValue16LE(uint8_t *dataP)
{
  return (uint16_t)((dataP[1]<<8)+(dataP[0]));
}

/*
** ===================================================================
**     Method      :  UTIL1_GetValue24LE (component Utility)
**     Description :
**         Returns a 24bit Little Endian value from memory
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dataP           - Pointer to memory
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint32_t UTIL1_GetValue24LE(uint8_t *dataP)
{
  return (uint32_t)(((uint32_t)dataP[2])<<16)+(dataP[1]<<8)+(dataP[0]);
}

/*
** ===================================================================
**     Method      :  UTIL1_GetValue32LE (component Utility)
**     Description :
**         Returns a 32bit Little Endian value from memory
**     Parameters  :
**         NAME            - DESCRIPTION
**       * dataP           - Pointer to memory
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint32_t UTIL1_GetValue32LE(uint8_t *dataP)
{
  return (uint32_t)(((uint32_t)dataP[3])<<24)+(((uint32_t)dataP[2])<<16)+(dataP[1]<<8)+(dataP[0]);
}

/*
** ===================================================================
**     Method      :  UTIL1_SetValue16LE (component Utility)
**     Description :
**         Stores a 16bit value in memory as Little Endian
**     Parameters  :
**         NAME            - DESCRIPTION
**         data            - Value to store
**       * dataP           - Pointer to memory
**     Returns     : Nothing
** ===================================================================
*/
void UTIL1_SetValue16LE(uint16_t data, uint8_t *dataP)
{
  dataP[0] = (uint8_t)(data&0xff); /* LSB */
  dataP[1] = (uint8_t)((data>>8)&0xff); /* MSB */
}

/*
** ===================================================================
**     Method      :  UTIL1_SetValue24LE (component Utility)
**     Description :
**         Stores a 24bit value in memory as Little Endian
**     Parameters  :
**         NAME            - DESCRIPTION
**         data            - Value to store
**       * dataP           - Pointer to memory
**     Returns     : Nothing
** ===================================================================
*/
void UTIL1_SetValue24LE(uint32_t data, uint8_t *dataP)
{
  dataP[0] = (uint8_t)(data&0xff); /* LSB */
  dataP[1] = (uint8_t)((data>>8)&0xff);
  dataP[2] = (uint8_t)((data>>16)&0xff);
}

/*
** ===================================================================
**     Method      :  UTIL1_SetValue32LE (component Utility)
**     Description :
**         Stores a 32bit value in memory as Little Endian
**     Parameters  :
**         NAME            - DESCRIPTION
**         data            - Value to store
**       * dataP           - Pointer to memory
**     Returns     : Nothing
** ===================================================================
*/
void UTIL1_SetValue32LE(uint32_t data, uint8_t *dataP)
{
  dataP[0] = (uint8_t)(data&0xff); /* LSB */
  dataP[1] = (uint8_t)((data>>8)&0xff);
  dataP[2] = (uint8_t)((data>>16)&0xff);
  dataP[3] = (uint8_t)((data>>24)&0xff);
}

/*
** ===================================================================
**     Method      :  UTIL1_Deinit (component Utility)
**     Description :
**         Driver De-Initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void UTIL1_Deinit(void)
{
  /* nothing needed */
}

/*
** ===================================================================
**     Method      :  UTIL1_Init (component Utility)
**     Description :
**         Driver Initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void UTIL1_Init(void)
{
  /* nothing needed */
}

/*
** ===================================================================
**     Method      :  UTIL1_map (component Utility)
**     Description :
**         Maps a value from one range to another
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - value to be mapped
**         in_min          - input range minimum value
**         in_max          - input range maximum value
**         out_min         - output range maximum value
**         out_max         - 
**     Returns     :
**         ---             - remapped value
** ===================================================================
*/
int32_t UTIL1_map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max)
{
#if 0 /* original Arduino implementation */
  return (x-in_min)*(out_max-out_min)/(in_max-in_min)+out_min;
#else /* improved version, see https://github.com/arduino/Arduino/issues/2466 */
  if ((in_max - in_min) > (out_max - out_min)) {
    return (x - in_min) * (out_max - out_min+1) / (in_max - in_min+1) + out_min;
  } else {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }
#endif
}

/*
** ===================================================================
**     Method      :  UTIL1_constrain (component Utility)
**     Description :
**         Makes sure that a given input value is inside a given range.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - input value
**         min             - range minimum value
**         max             - range maximum value
**     Returns     :
**         ---             - the constrained value
** ===================================================================
*/
int32_t UTIL1_constrain(int32_t val, int32_t min, int32_t max)
{
  if (val<min) {
    return min;
  } else if (val>max) {
    return max;
  }
  return val;
}

/*
** ===================================================================
**     Method      :  UTIL1_random (component Utility)
**     Description :
**         Provides a random value. You have to call intialize the
**         random number generator with randomSetSeed() first!
**     Parameters  :
**         NAME            - DESCRIPTION
**         min             - range minimum value
**         max             - range maximum value
**     Returns     :
**         ---             - random value between min and max
** ===================================================================
*/
int32_t UTIL1_random(int32_t min, int32_t max)
{
  int32_t val;

  val = rand()%(max-min+1)+min;
  return UTIL1_constrain(val, min, max);
}

/*
** ===================================================================
**     Method      :  UTIL1_randomSetSeed (component Utility)
**     Description :
**         Sets a seed for the random number generator
**     Parameters  :
**         NAME            - DESCRIPTION
**         seed            - seed to be used for random number
**                           generator
**     Returns     : Nothing
** ===================================================================
*/
void UTIL1_randomSetSeed(unsigned int seed)
{
  srand(seed); /* set random number generator seed */
}

/*
** ===================================================================
**     Method      :  UTIL1_map64 (component Utility)
**     Description :
**         Maps a value from one range to another, using 64bit math
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - value to be mapped
**         in_min          - input range minimum value
**         in_max          - input range maximum value
**         out_min         - output range maximum value
**         out_max         - 
**     Returns     :
**         ---             - remapped value
** ===================================================================
*/
#ifdef __GNUC__ /* HIWARE compiler does not support 64bit data types */
int64_t UTIL1_map64(int64_t x, int64_t in_min, int64_t in_max, int64_t out_min, int64_t out_max)
{
  if ((in_max - in_min) > (out_max - out_min)) {
    return (x - in_min) * (out_max - out_min+1) / (in_max - in_min+1) + out_min;
  } else {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }
}
#endif

/* END UTIL1. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
