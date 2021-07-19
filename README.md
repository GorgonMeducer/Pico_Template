# Pico_Template (0.9.3)
An MDK template for Raspberry Pi Pico

- Compiler: Arm Compiler 6.15 and above (Using non-intrusive wrapper to support pico-sdk which is written in GCC)
- ***It works as you wanted!***
- Compatible with CMSIS 5.7.0 and CMSIS 5.8.0
- Verified with Arm Compiler 6.15 and above.
- Provide users an option to use the ***stdio*** solution from ***pico-sdk (by default)*** or retarget the ***stdin/stdout*** to a user specified location directly. (See note in ***env_wrapper.c***).
- [Support debug in MDK using J-Link](https://wiki.segger.com/Raspberry_Pi_Pico)




# How to Use

## 1. Get the Pico_Template

I assume that you have the MDK installed on your PC. Please clone the Pico_Template with following command line:

```
git clone https://github.com/GorgonMeducer/Pico_Template --recursive
```

Instead of using git clone, if you download a release package, then you have to download the [pico-sdk](https://github.com/raspberrypi/pico-sdk) and [perf_counter](https://github.com/GorgonMeducer/perf_counter) manually and put them into the corresponding folder:

| submodules   | URL                                           | Directory                     |
| ------------ | --------------------------------------------- | ----------------------------- |
| pico-sdk     | https://github.com/raspberrypi/pico-sdk       | ROOT\Pico-sdk\                |
| perf_counter | https://github.com/GorgonMeducer/perf_counter | ROOT\project\mdk\perf_counter |





## 2. Use the Template

The MDK project could be found in the path "ROOT\project\mdk". I assume you know how to use MDK for normal compilation. 

### 2.1 How to set the Stack and Heap size

Usually, people want to adjust the size of stack and heap, and it is very easy in this template. Please find the file "RP2040.sct" in the same MDK project directory. Find the macro ***STACK_0_SIZE*** for stack and ***HEAP_0_SIZE*** for the heap.  



```
#define STACK_0_SIZE        (1024*4)
#define STACK_1_SIZE        (1024*1)

#define HEAP_0_SIZE         (1024*32)
#define HEAP_1_SIZE         (1024*1)
```

***NOTE***: 

1. Please do **NOT** add "**u**" behind those constant values. 
2. The STACK_1_SIZE and HEAP_1_SIZE are not in use. You can set their value to reasonable smaller ones if you do want to reduce the RAM footprint. 



### 2.2 How to retarget stdout/stdin

To take advantage of pico-sdk, this template uses bridges to retarget low level functions of stdout/stdin to _read and _write implemented by stdio.c inside pico-sdk.  

```
/*----------------------------------------------------------------------------*
 * bridge the Arm Compiler's stdio and the pico-sdk's stdio                   *
 *----------------------------------------------------------------------------*/
__attribute__((weak))
int stdin_getchar(void)
{
    /*! \note If you don't want to use pico-sdk stdio, then you can implement 
     *!       function by yourself in other c source code. Your scanf will work
     *!       directly.
     *!       by default, we use this function to bridge the _read implemented 
     *!       in stdio.c of pico-sdk
     */
    
    int byte;
    _read(0, (char *)&byte, 1);
    return byte;
}

__attribute__((weak))
int stdout_putchar(int ch)
{
    /*! \note If you don't want to use pico-sdk stdio, then you can implement 
     *!       function by yourself in other c source code. Your printf will work
     *!       directly.
     *!       by default, we use this function to bridge the _write implemented 
     *!       in stdio.c of pico-sdk
     */
    
    return _write(1, (char *)&ch, 1);
}

```

Those bridge functions are decorated as "weak", hence if you want to retarget ***printf/scanf*** directly to a place where you can "***see through***" and/or ***you have total control***, please implement those bridge functions (without delete the weak version) in one of your c source code, for example, sending chars to USART or storing them to a memory block directly. 

**NOTE**: I try to provide you the freedom of choice, and I don't need you to digging deep inside scripts to gain such freedom. 




# Known issue
- Debugger support is only available for J-Link.
- Not all peripheral modules are added to the compilation. But I guess it is just a piece of cake for you : P
- ***Please use the elf2uf2 tool in this template*** to convert the generated axf into uf2.
- Might need more documents...

