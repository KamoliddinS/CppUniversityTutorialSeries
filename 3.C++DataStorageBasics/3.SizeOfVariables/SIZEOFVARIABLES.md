

## Sizes and Ranges of C++ Built-in Primitive Types

C++ offers a variety of built-in primitive types. The size and range of these types can vary based on the system and compiler, but there are standard libraries that provide details about these. This document details the typical sizes and the range (both maximum and minimum values) of these types.

### Integer Types

**1. int:**
   - **Size:** `sizeof(int)` bytes
   - **Range:** `INT_MIN` to `INT_MAX`

**2. short int (or short):**
   - **Size:** `sizeof(short)` bytes
   - **Range:** `SHRT_MIN` to `SHRT_MAX`

**3. long int (or long):**
   - **Size:** `sizeof(long)` bytes
   - **Range:** `LONG_MIN` to `LONG_MAX`

**4. long long int:**
   - **Size:** `sizeof(long long)` bytes
   - **Range:** `LLONG_MIN` to `LLONG_MAX`

### Unsigned Integer Types

**1. unsigned int:**
   - **Size:** `sizeof(unsigned int)` bytes
   - **Range:** `0` to `UINT_MAX`

**2. unsigned short int (or unsigned short):**
   - **Size:** `sizeof(unsigned short)` bytes
   - **Range:** `0` to `USHRT_MAX`

**3. unsigned long int (or unsigned long):**
   - **Size:** `sizeof(unsigned long)` bytes
   - **Range:** `0` to `ULONG_MAX`

**4. unsigned long long int:**
   - **Size:** `sizeof(unsigned long long)` bytes
   - **Range:** `0` to `ULLONG_MAX`

### Floating-Point Types

**1. float:**
   - **Size:** `sizeof(float)` bytes
   - **Range:** `-FLT_MAX` to `FLT_MAX`
   - **Smallest Positive Value:** `FLT_MIN`

**2. double:**
   - **Size:** `sizeof(double)` bytes
   - **Range:** `-DBL_MAX` to `DBL_MAX`
   - **Smallest Positive Value:** `DBL_MIN`

**3. long double:**
   - **Size:** `sizeof(long double)` bytes
   - **Range:** Typically `-LDBL_MAX` to `LDBL_MAX` (Exact values can vary based on the platform)
   - **Smallest Positive Value:** Typically `LDBL_MIN`

### Character Types

**1. char:**
   - **Size:** `sizeof(char)` bytes (guaranteed to be 1 byte)
   - **Range:** `CHAR_MIN` to `CHAR_MAX`

**2. unsigned char:**
   - **Size:** `sizeof(unsigned char)` bytes (guaranteed to be 1 byte)
   - **Range:** `0` to `UCHAR_MAX`

**3. wchar_t:**
   - **Size:** `sizeof(wchar_t)` bytes
   - **Range:** Typically from the minimum to the maximum representable wide character value. Exact values can vary based on the platform.

### Boolean Type

**1. bool:**
   - **Size:** `sizeof(bool)` bytes
   - **Values:** `true` or `false`

### Conclusion

Understanding the size and range of primitive data types in C++ is crucial for efficient memory usage and avoiding overflow or underflow errors. Always remember that the actual size and range may vary depending on the architecture and compiler. To get exact sizes and limits for your specific system and compiler, you can use the `sizeof()` function and limits defined in the `<limits>` header.
