# Pico_Template (0.9.1)
An MDK template for Raspberry Pi Pico

- Compiler: Arm Compiler 6.16 (Using non-intrusive wrapper to support pico-sdk which is written in GCC)
- ***It works as you wanted!***
- Compatible with CMSIS 5.7.0 and CMSIS 5.8.0



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




# Known issue
- Debugger support is not available for now.
- Not all peripheral modules are added to the compilation. But I guess it is just a piece of cake for you : P
- ***Please use the elf2uf2 tool in this template*** to convert the generated axf into uf2.
- Might need more documents...

