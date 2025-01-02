### Me encuentro este error: 

```sh
➜  so_long git:(main) ✗ make tval_get_map
make[1]: Entering directory '/home/saalarco/projects-42/so_long/so_long/libft'
make[1]: Nothing to be done for 'all'.
make[1]: Leaving directory '/home/saalarco/projects-42/so_long/so_long/libft'
cc -g -Wall -Wextra -Werror  tests/test_get_map.c src/get_map/free_parsed_map.c src/get_map/parse_map.c src/get_map/validate_map_contents.c src/get_map/validate_map_playable.c ./libft/libft.a -o ./tests/tests_get_map
Running tests...
==1774916== Memcheck, a memory error detector
==1774916== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1774916== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1774916== Command: ././tests/tests_get_map
==1774916== 
==1774916== Stack overflow in thread #1: can't grow stack to 0x1ffe801000
==1774916== 
==1774916== Process terminating with default action of signal 11 (SIGSEGV)
==1774916==  Access not within mapped region at address 0x1FFE801FF8
==1774916== Stack overflow in thread #1: can't grow stack to 0x1ffe801000
==1774916==    at 0x405D6B: flood_fill_mark (validate_map_playable.c:26)
==1774916==  If you believe this happened as a result of a stack
==1774916==  overflow in your program's main thread (unlikely but
==1774916==  possible), you can try to increase the size of the
==1774916==  main thread stack using the --main-stacksize= flag.
==1774916==  The main thread stack size used in this run was 8388608.
==1774916== 
==1774916== HEAP SUMMARY:
==1774916==     in use at exit: 1,008,080 bytes in 1,004 blocks
==1774916==   total heap usage: 352,059 allocs, 351,055 frees, 173,538,042 bytes allocated
==1774916== 
==1774916== 8 bytes in 1 blocks are still reachable in loss record 1 of 5
==1774916==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1774916==    by 0x4058C7: create_position (validate_map_contents.c:22)
==1774916==    by 0x40597C: alloc_list_collectables (validate_map_contents.c:49)
==1774916==    by 0x405A71: validate_map_contents (validate_map_contents.c:139)
==1774916==    by 0x405268: test_validate_map_playable_ko (test_get_map.c:709)
==1774916==    by 0x4013AC: main (test_get_map.c:727)
==1774916== 
==1774916== 16 bytes in 1 blocks are still reachable in loss record 2 of 5
==1774916==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1774916==    by 0x4065CC: ft_lstnew (ft_lstnew_bonus.c:34)
==1774916==    by 0x4058FF: create_position (validate_map_contents.c:27)
==1774916==    by 0x40597C: alloc_list_collectables (validate_map_contents.c:49)
==1774916==    by 0x405A71: validate_map_contents (validate_map_contents.c:139)
==1774916==    by 0x405268: test_validate_map_playable_ko (test_get_map.c:709)
==1774916==    by 0x4013AC: main (test_get_map.c:727)
==1774916== 
==1774916== 48 bytes in 1 blocks are still reachable in loss record 3 of 5
==1774916==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1774916==    by 0x40544A: parse_map (parse_map.c:125)
==1774916==    by 0x405249: test_validate_map_playable_ko (test_get_map.c:707)
==1774916==    by 0x4013AC: main (test_get_map.c:727)
==1774916== 
==1774916== 8,008 bytes in 1 blocks are still reachable in loss record 4 of 5
==1774916==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1774916==    by 0x40625F: ft_split (ft_split.c:109)
==1774916==    by 0x405481: parse_map (parse_map.c:129)
==1774916==    by 0x405249: test_validate_map_playable_ko (test_get_map.c:707)
==1774916==    by 0x4013AC: main (test_get_map.c:727)
==1774916== 
==1774916== 1,000,000 bytes in 1,000 blocks are still reachable in loss record 5 of 5
==1774916==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1774916==    by 0x4062B3: ft_split (ft_split.c:116)
==1774916==    by 0x405481: parse_map (parse_map.c:129)
==1774916==    by 0x405249: test_validate_map_playable_ko (test_get_map.c:707)
==1774916==    by 0x4013AC: main (test_get_map.c:727)
==1774916== 
==1774916== LEAK SUMMARY:
==1774916==    definitely lost: 0 bytes in 0 blocks
==1774916==    indirectly lost: 0 bytes in 0 blocks
==1774916==      possibly lost: 0 bytes in 0 blocks
==1774916==    still reachable: 1,008,080 bytes in 1,004 blocks
==1774916==         suppressed: 0 bytes in 0 blocks
==1774916== 
==1774916== For lists of detected and suppressed errors, rerun with: -s
==1774916== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
make: *** [Makefile:104: tval_get_map] Segmentation fault (core dumped)
```

The Valgrind logs indicate that your program encountered a stack overflow, which led to a segmentation fault. The relevant part of the log is:

```
==1774916== Stack overflow in thread #1: can't grow stack to 0x1ffe801000
==1774916== 
==1774916== Process terminating with default action of signal 11 (SIGSEGV)
==1774916==  Access not within mapped region at address 0x1FFE801FF8
==1774916== Stack overflow in thread #1: can't grow stack to 0x1ffe801000
==1774916==    at 0x405D6B: flood_fill_mark (validate_map_playable.c:26)
```

This indicates that the function `flood_fill_mark` in src/get_map/validate_map_playable.c at line 26 is causing a stack overflow. This is likely due to deep or infinite recursion.

To fix this issue, you should review the implementation of `flood_fill_mark` to ensure that it has a proper base case to terminate the recursion. Additionally, you might consider converting the recursive algorithm to an iterative one to avoid deep recursion.

The memory leak summary indicates that there are no definitely lost or indirectly lost blocks, but there are still reachable blocks, which means that some memory was allocated but not freed before the program terminated. This is not necessarily a problem but could indicate areas for improvement in memory management.

To address the stack overflow, you should focus on the `flood_fill_mark` function in src/get_map/validate_map_playable.c.


